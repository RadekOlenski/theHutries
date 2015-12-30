#include <sstream>
#include <iostream>

#include "hutrie.h"
#include "carrier.h"
#include "worker.h"
#include "sawmill.h"
#include "modelController.h"
#include "keyboard.h"
#include "gameLogicController.h"
#include "game.h"

//=================================================================================
//                              CONSTRUCTOR
//=================================================================================
Game::Game(int applicationWidth, int applicationHeight) :
        gameTime(0.5 * 60),
        hutrieApplication(sf::VideoMode(applicationWidth + 256, applicationHeight + 30, 32), "The Hutries"),
        // sf::Style::Fullscreen ),
        gui(applicationWidth, applicationHeight, &hutrieApplication),
        world(&hutrieApplication, applicationWidth, applicationHeight)
{
    //-----------------------------CREATING BASIC APPLICATION OBJECTS---------------------------------------------//
    ModelController* modelController = new ModelController();
    GUIController* guiController = new GUIController(&hutrieApplication, modelController, &world, &gui);
    GameLogicController* gameLogicController = new GameLogicController(&world, &hutrieApplication, modelController, guiController);
    Keyboard* keyboard = new Keyboard(&hutrieApplication, modelController);
    Mouse* mouse = new Mouse(&hutrieApplication, modelController, gameLogicController);
    //--------------------------------ASSIGN OBJECTS TO LOCAL VARIABLES-----------------------------------------//
    this->modelController = modelController;
    this->guiController = guiController;
    this->gameLogicController = gameLogicController;
    this->keyboard = keyboard;
    this->mouse = mouse;
    ///////////////////////SIZE OF MAP SCREEN////////////////////////////////////////////////////////////////////

    modelController->setApplicationWidth(applicationWidth);
    modelController->setApplicationHeight(applicationHeight);

    /////////////////////////// CREATING GAME WINDOW AND GUI //////////////////////////////////////////////////////

    //sf::RenderWindow hutrieApplication( sf::VideoMode::getDesktopMode(), "The Hutries",sf::Style::Fullscreen );
    hutrieApplication.setFramerateLimit(60);

    guiController->createBackground();
    guiController->createCursor();

    /////////////////////////// BACKGROUND MUSIC //////////////////////////////////////////////////////

    if (!music.openFromFile(Sound::musicPath)) std::cout << "Loading music failed" << std::endl;
    music.setLoop(true);
}
//=================================================================================
//                             GAME LOGIC FUNCTIONS
//=================================================================================

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
    guiController->launchTitleThread();
    while (hutrieApplication.isOpen() && deadline.getElapsedTime().asSeconds() < gameTime)
    {
        handleActions();
        drawApplication();
    }
}

void Game::handleActions()
{
    mouse->updateMouseLock();

    keyboard->actionsLoop();

    guiController->setCursorPosition();

    gameLogicController->deactivateChosenModeFlag();

    gameLogicController->handleHutriesCreation();

    assignIntoBuilding();

    carrierReturn();

    mouse->leftClickActions();

    updateClock();
}

void Game::drawApplication()
{
    guiController->drawApplication();
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

void Game::gameOver(bool win)
{
    while (hutrieApplication.isOpen())
    {
        sf::Event event;
        while (hutrieApplication.pollEvent(event))
        {
            keyboard->closeGame(event);
        }
        guiController->displayGameOver(win);
    };
}

