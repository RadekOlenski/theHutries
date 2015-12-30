#include <sstream>
#include <iostream>

#include "hutrie.h"
#include "carrier.h"
#include "worker.h"
#include "soldier.h"
#include "sawmill.h"
#include "hutrieshall.h"
#include "interactionMode.h"
#include "modelController.h"
#include "keyboard.h"
#include "gameLogicController.h"
#include "game.h"

//=================================================================================
//                              CONSTRUCTOR
//=================================================================================
Game::Game(int applicationWidth, int applicationHeight) :
        gameTime(10 * 60),
        hutrieApplication(sf::VideoMode(applicationWidth + 256, applicationHeight + 30, 32), "The Hutries"),
        // sf::Style::Fullscreen ),
        gui(applicationWidth, applicationHeight, &hutrieApplication),
        world(&hutrieApplication, applicationWidth, applicationHeight),
        titleText(1024 + 20, 40, 45), titleThread(&GUIText::display, &titleText)
{
    //-----------------------------CREATING BASIC APPLICATION OBJECTS---------------------------------------------//
    ModelController* modelController = new ModelController();
    GameLogicController* gameLogicController = new GameLogicController(&world, &hutrieApplication, modelController, &gui);
    Keyboard* keyboard = new Keyboard(&hutrieApplication, modelController);
    Mouse* mouse = new Mouse(&hutrieApplication, modelController, &gui, gameLogicController, &cursor);
    //--------------------------------ASSIGN OBJECTS TO LOCAL VARIABLES-----------------------------------------//
    this->modelController = modelController;
    this->gameLogicController = gameLogicController;
    this->keyboard = keyboard;
    this->mouse = mouse;
    ///////////////////////SIZE OF MAP SCREEN////////////////////////////////////////////////////////////////////

    modelController->setApplicationWidth(applicationWidth);
    modelController->setApplicationHeight(applicationHeight);

    /////////////////////////// CREATING GAME WINDOW AND GUI //////////////////////////////////////////////////////

    //sf::RenderWindow hutrieApplication( sf::VideoMode::getDesktopMode(), "The Hutries",sf::Style::Fullscreen );
    hutrieApplication.setFramerateLimit(60);

    /////////////////////////// CREATING BACKGROUND //////////////////////////////////////////////////////

    background.setSize(sf::Vector2f(1024, 640));
    //  backgroundTexture.loadFromFile( "sprites/background/background.jpg" );
    backgroundTexture.loadFromFile("sprites/background/background.jpg");
    background.setTexture(&backgroundTexture);

    /////////////////////////// CREATING CURSOR //////////////////////////////////////////////////////

    hutrieApplication.setMouseCursorVisible(false);
    fixed = hutrieApplication.getView();
    //fixed.zoom(2);
    cursorTexture.loadFromFile("sprites/cursor.png");
    cursor.setTexture(cursorTexture);

    /////////////////////////// BACKGROUND MUSIC //////////////////////////////////////////////////////

    if (!music.openFromFile(Sound::musicPath)) std::cout << "Loading music failed" << std::endl;
    music.setLoop(true);

    //rzutowanie hutries hall z vectora building na pelnoprawny object HutriesHall
    pHall = dynamic_cast <HutriesHall*>(world.buildings.at(0));
}
//=================================================================================
//                             GAME LOGIC FUNCTIONS
//=================================================================================

void Game::createCarrier()
{
    if (pHall->getMakeCarrierFlag())
    {
        if (world.availableSlots > 0)
        {
            std::string objectType = "carrier";
            std::string sprite = "sprites/carrier/up.png";
            createHutrie(objectType, sprite);
        }
        else
        {
            Sound::error();
            gui.errorInfo.text.setString("Error: No more slots! Build residence!");
        }
        pHall->setMakeCarrierFlag(false);
    }
}

void Game::createWorker()
{
    if (pHall->getMakeWorkerFlag())
    {
        if (world.availableSlots > 0)
        {
            std::string objectType = "worker";
            std::string sprite = "sprites/worker/up.png";
            createHutrie(objectType, sprite);
        }
        else
        {
            errorNoSlots();
        }
        pHall->setMakeWorkerFlag(false);
    }
}

void Game::createHutrie(std::string objectType, std::string sprite)
{
    std::vector<Unit*> usedUnits;
    int unitIndex = pHall->getUnitIndex(6);                 // ktore z pol budynku ma byc zajete przez carriera
    usedUnits.push_back(world.units.at((unsigned int) unitIndex));
    if (objectType == "carrier")
    {
        std::cout << "Utworze dla ciebie Carriera!" << std::endl;
        world.carriers.push_back(new Carrier(&hutrieApplication, usedUnits, sprite));//"sprites/carrier/empty.png"));
        world.hutries.push_back(world.carriers.back());
    }
    else if (objectType == "worker")
    {
        std::cout << "Utworze dla ciebie Workera!" << std::endl;
        world.workers.push_back(new Worker(&hutrieApplication, usedUnits, sprite));//"sprites/carrier/empty.png"));
        world.hutries.push_back(world.workers.back());
    }
    world.units.at((unsigned int) unitIndex)->addHutrie(world.hutries.back());
    world.availableSlots--;
}

void Game::assignIntoBuilding()
{
    std::vector<Building*>::iterator it;
    for (it = world.buildings.begin(); it != world.buildings.end(); ++it)
    {
        if ((*it)->getNeedCarrierFlag())
        {
            buildingNeedCarrier(it);
        }
        if ((*it)->getNeedWorkerFlag())
        {
            buildingNeedWorker(it);
        }
    }
}

void Game::buildingNeedCarrier(std::vector<Building*>::iterator it)
{
    int unitIndex = (*it)->getUnitIndex(2);                   // ktore z pol budynku ma byc zajete przez carriera
    std::vector<Carrier*>::iterator itc;
    callCarrier(itc, it, unitIndex);
    (*it)->setNeedCarrier(false);
}

void Game::callCarrier(std::vector<Carrier*>::iterator itc, std::vector<Building*>::iterator it, int unitIndex)
{
    for (itc = world.carriers.begin(); itc != world.carriers.end(); ++itc)
    {
        if (!((*itc)->isBusy()))
        {
            std::cout << "Nie jestem zajety! Ruszam po zasoby!" << std::endl;
            unsigned int carrierIndex = (unsigned int) std::distance(world.carriers.begin(), itc);
            world.carriers.at(carrierIndex)->reconnectUnits((*it)->getObjectUnits());
            world.carriers.at(carrierIndex)->hutrieThread.launch();          //tworzy watek w ktorym porusza sie Hutrie
            world.units.at((unsigned int) unitIndex)->addHutrie(world.carriers.at(carrierIndex));
            (*it)->updateStatus();
            break;
        }
        if (itc == world.carriers.end())
        {
            errorNoCarriers();
        }
    }
}

void Game::carrierReturn()
{
    std::vector<Carrier*>::iterator itc;
    for (itc = world.carriers.begin(); itc != world.carriers.end(); ++itc)
    {
        if ((*itc)->haveArrived())
        {
            std::cout << "Czas wracac do domu" << std::endl;
            (*itc)->carrierThread.launch();
        }
        else
        {
            world.availableGoods = world.availableGoods + (*itc)->myLuggage;
            (*itc)->myLuggage.setProduct(5);

            //// na razie do sprawdzenia ////
            std::ostringstream desc;
            desc << world.availableGoods.getWood();
            gui.twood.text.setString(desc.str());

            std::ostringstream desc1;
            desc1 << world.availableGoods.getStone();
            gui.tstone.text.setString(desc1.str());

            std::ostringstream desc2;
            desc2 << world.availableGoods.getFood();
            gui.tfood.text.setString(desc2.str());

            std::ostringstream desc3;
            desc3 << world.availableGoods.getGold();
            gui.tgold.text.setString(desc3.str());

            ////////////////////////////////////////

            (*itc)->setArrived(false);
        }
    }
}

void Game::buildingNeedWorker(std::vector<Building*>::iterator it)
{
    if ((*it)->getHutriesCounter() < (*it)->getCapacity())       //jesli aktualna ilosc w budynku mniejsza od pojemnosci
    {
        unsigned int unitIndex = (unsigned int) (*it)->getUnitIndex(2);
        std::vector<Worker*>::iterator itc;
        callWorker(itc, it, unitIndex);
    }
    (*it)->setNeedWorker(false);
}

void Game::callWorker(std::vector<Worker*>::iterator itc, std::vector<Building*>::iterator it, int unitIndex)
{
    for (itc = world.workers.begin(); itc != world.workers.end(); ++itc)
    {
        if (!((*itc)->isBusy()))
        {
            std::cout << "Nie jestem zajety! Ruszam do pracy!" << std::endl;
            unsigned int workerIndex = (unsigned int) std::distance(world.workers.begin(), itc);
            world.workers.at(workerIndex)->reconnectUnits((*it)->getObjectUnits());
            world.workers.at(workerIndex)->hutrieThread.launch();             //tworzy watek w ktorym porusza sie Hutrie
            world.units.at((unsigned int) unitIndex)->addHutrie(world.workers.at(workerIndex));
            (*it)->setHutriesCounter((*it)->getHutriesCounter() + 1);
            (*it)->updateStatus();
            (*itc)->setBusy(true);
            break;
        }
    }
    if (itc == world.workers.end())
    {
        errorNoWorkers();
    }
}

//=================================================================================
//                              ERRORS
//=================================================================================

void Game::errorNoCarriers()
{
    Sound::error();
    gui.errorInfo.text.setString(
            "Error: No available carriers! Everyone is busy! Create carrier in HutriesHall or build residence");
}

void Game::errorNoSlots()
{
    Sound::error();
    gui.errorInfo.text.setString("Error: No more slots! Build residence!");
}

void Game::errorNoWorkers()
{
    Sound::error();
    gui.errorInfo.text.setString(
            "Error: No available workers! Everyone is busy! Create worker in HutriesHall or build residence");
}

void Game::errorUnitOccupied()
{
    Sound::error();
    gui.errorInfo.text.setString("Error: Unit not empty. Choose another one");
}

void Game::errorOutOfMap()
{
    Sound::error();
    gui.errorInfo.text.setString("Error: Building out of map. Choose another place");
}

//=================================================================================
//                              MAIN GAME LOOP
//=================================================================================

void Game::play()
{

    music.play();
    music.setVolume(40);
    titleThread.launch();
    while (hutrieApplication.isOpen() && deadline.getElapsedTime().asSeconds() < gameTime)
    {
        actions();
        displayAll();
    }
}

void Game::actions()
{
    mouse->updateMouseLock();

    keyboard->actionsLoop();

    mouse->setCursorPosition();

    gameLogicController->deactivateChosenModeFlag();

    createCarrier();

    createWorker();

    assignIntoBuilding();

    carrierReturn();

    mouse->leftClickActions();

    updateClock();
}

void Game::displayAll()
{
    /////////////////////////DRAWING INTERFACE, GREEN GRID AND BACKGROUND///////////////////////////

    hutrieApplication.clear(sf::Color::Black);        //czyszczenie ekranu dla pierwszego wyswietlenia
    hutrieApplication.setView(fixed);
    gui.displayGUI();
    if (modelController->getChosenInteractionMode() == InteractionMode::BUILDMODE) gui.displayGUIBuildings();
    if (modelController->getChosenInteractionMode() == InteractionMode::HUTRIEINFO)
        gui.displayGUIHutries(world.hutries.size(), world.carriers.size(), world.workers.size(),
                              world.soldiers.size());
    hutrieApplication.draw(background);
    hutrieApplication.draw(titleText.text);             //migoczacy tekst tytulowy
    std::vector<Unit*>::iterator it;                  //rysowanie zielonych kratek pol
    for (it = world.units.begin(); it != world.units.end(); ++it)
    {
        hutrieApplication.draw((*it)->field);
    }

///////////////////////////DRAWING MAP OBJECTS//////////////////////////////////////////////////////

    for (it = world.units.begin(); it !=
                                   world.units.end(); ++it)     //rysosowanie wszystkich mapobjectow na mapie - druga petla zeby ruszajacy sie Hutrie byli rysowani nad zielona kratka a nie pod
    {
        if (!((*it)->isEmpty()))
        {
            hutrieApplication.draw(
                    (*it)->getMapObject()->sprite);          //rysuje obiekty (budynki, przyroda) widoczne na mapie
            if ((*it)->hutriesNumber() > 0)
            {
                for (int i = 0; i < (*it)->hutriesNumber(); i++)             //jesli w wektorze jest jakis hutri
                {
                    hutrieApplication.draw((*it)->getHutrieIndex(i)->sprite);     //rysuj hutrich z vectora dwellers
                }
            }

            if ((*it)->getMapObject()->isHighlighted() &&
                modelController->getChosenInteractionMode() == InteractionMode::INFOMODE)            //jesli tryb info rysuj w prawym gui
            {
                hutrieApplication.draw((*it)->getMapObject()->title.text);
                hutrieApplication.draw((*it)->getMapObject()->description.text);
                hutrieApplication.draw((*it)->getMapObject()->descriptionFrame.button);
                (*it)->getMapObject()->showButtons();
            }
            else (*it)->getMapObject()->deactivateButtons();
        }
    }

///////////////////////////ADD CURSOR SPRITE AND DISPLAY//////////////////////////////////////////////////////

    hutrieApplication.draw(cursor);
    hutrieApplication.display();
}

void Game::updateClock()
{
    std::ostringstream newTime;
    int time = gameTime - deadline.getElapsedTime().asSeconds();
    newTime << time / 60 << ":" << time % 60;
    gui.timeLeft.text.setString(newTime.str());
}

bool Game::getResult()
{
    return (rand() % 2) ? true : false;
}

std::string Game::getStats()
{
    std::ostringstream stats;
    stats << "You built " << world.buildings.size() << " buildings." << std::endl
    << "You had " << world.hutries.size() << " hutries including: " << std::endl
    << world.carriers.size() << " carriers" << std::endl
    << world.workers.size() << " workers" << std::endl
    << world.soldiers.size() << " soldiers" << std::endl;
    return stats.str();
}

void Game::gameOver(bool win)
{
    GUIText stats(300, 280, 40, getStats());
    while (hutrieApplication.isOpen())
    {
        sf::Event event;
        while (hutrieApplication.pollEvent(event))
        {
            if (event.type == sf::Event::Closed ||
                (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
            {
                hutrieApplication.close();
            }
        }
        cursor.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(hutrieApplication)));
        hutrieApplication.clear(sf::Color::Black);
        hutrieApplication.setView(fixed);
        gui.displayGUI();
        hutrieApplication.draw(background);
        hutrieApplication.draw(stats.text);
        hutrieApplication.draw(titleText.text);
        gui.displayEndingText(win);
        hutrieApplication.draw(cursor);
        hutrieApplication.display();
    };
}

