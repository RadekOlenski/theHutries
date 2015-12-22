#include <iostream>
#include <sstream>

#include "game.h"
#include "unit.h"
#include "mapobject.h"
#include "hutrie.h"
#include "carrier.h"
#include "worker.h"
#include "soldier.h"
#include "building.h"
#include "sawmill.h"
#include "stonecutter.h"
#include "residence.h"
#include "barracks.h"
#include "goldmine.h"
#include "hutrieshall.h"
#include "farm.h"


//=================================================================================
//                              CONSTRUCTOR
//=================================================================================

Game::Game(int applicationWidth, int applicationHeight) :
        gameTime(10*60), chosenMode(0), tempChosenMode(0),
        hutrieApplication(sf::VideoMode(applicationWidth + 256, applicationHeight + 30, 32), "The Hutries"),
        // sf::Style::Fullscreen ),
        gui(applicationWidth, applicationHeight, &hutrieApplication),
        world(&hutrieApplication, applicationWidth, applicationHeight),
        titleText(1024 + 20, 40, 45), titleThread(&GUIText::display, &titleText)
{
    ///////////////////////SIZE OF MAP SCREEN////////////////////////////////////////////////////////////////////

    this->applicationWidth = applicationWidth;
    this->applicationHeight = applicationHeight;

    /////////////////////////// CREATING GAME WINDOW AND GUI //////////////////////////////////////////////////////

    //sf::RenderWindow hutrieApplication( sf::VideoMode::getDesktopMode(), "The Hutries",sf::Style::Fullscreen );
    hutrieApplication.setFramerateLimit(60);

    /////////////////////////// CREATING BACKGROUND //////////////////////////////////////////////////////

    background.setSize(sf::Vector2f(1024, 640));
//    backgroundTexture.loadFromFile( "sprites/background/background.jpg" );
    backgroundTexture.loadFromFile("sprites/background/background.jpg");
    background.setTexture(&backgroundTexture);

    /////////////////////////// CREATING CURSOR //////////////////////////////////////////////////////

    hutrieApplication.setMouseCursorVisible(false);
    fixed = hutrieApplication.getView();
    //fixed.zoom(2);
    cursorTexture.loadFromFile("sprites/cursor.png");
    cursor.setTexture(cursorTexture);

    /////////////////////////// BACKGROUND MUSIC //////////////////////////////////////////////////////

    if (!music.openFromFile("audio/celtic.wav")) std::cout << "Loading music failed" << std::endl;
    music.setLoop(true);

    sound.setBuffer(buffer);

    pHall = dynamic_cast <HutriesHall*>(world.buildings.at(
            0));        //rzutowanie hutries hall z vectora building na pelnoprawny object HutriesHall

}

//=================================================================================
//                              SOUND FUNCTIONS
//=================================================================================

void Game::errorSound()
{
    buffer.loadFromFile("audio/error.wav");
    sound.play();
}

void Game::clickSound()
{
    buffer.loadFromFile("audio/click.wav");
    sound.setVolume(70);
    sound.play();
}

void Game::tingSound()
{
    buffer.loadFromFile("audio/ting.wav");
    sound.play();
}

//=================================================================================
//                             KEYBOARD ACTION FUNCTIONS
//=================================================================================

void Game::keyboardSwitchMode(sf::Event event)
{
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F1)
    {
        chosenMode = 1;                 //HUTRIE BUILDING MODE
        clickSound();
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F2)
    {
        chosenMode = 2;               //BUILD MODE
        clickSound();
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F3)
    {
        chosenMode = 3;                //INFO MODE
        clickSound();
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F4)
    {
        chosenMode = 4;                //HUTRIE MODE
        clickSound();
    }
}

void Game::keyboardSwitchBuildingType(sf::Event event, int chosenMode)
{
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num1 && chosenMode == 2)
    {
        buildingType = 1;                //SAWMILL
        clickSound();
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num2 && chosenMode == 2)
    {
        buildingType = 2;                //STONECUTTER
        clickSound();
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num3 && chosenMode == 2)
    {
        buildingType = 3;                //BARRACKS
        clickSound();
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num4 && chosenMode == 2)
    {
        buildingType = 4;                //RESIDENCE
        clickSound();
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num5 && chosenMode == 2)
    {
        buildingType = 5;                //GOLDMINE
        clickSound();
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num6 && chosenMode == 2)
    {
        buildingType = 6;                //FARM
        //model.buildingType = BuildingType.SAWMILL;
        //modelFacade -> setBuildingType(BuildingType.SAWMILL);
        clickSound();
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
    {
        //std::cout<<world.availableSlots << std::endl;
        std::vector <Carrier*>::iterator itc;
        for(itc = world.carriers.begin(); itc != world.carriers.end(); ++itc)
        {
            std::cout << "Wood: " << (*itc)->myLuggage.getWood() << ", Stone: " <<  (*itc)->myLuggage.getStone() << ", Food: " << (*itc)->myLuggage.getFood() << ", Gold: " << (*itc)->myLuggage.getGold() << std::endl;
        }
    }
}

void Game::keyboardCloseGame(sf::Event event)
{
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        hutrieApplication.close();
}

void Game::keyboardActionsLoop()
{
    sf::Event event;

    while (hutrieApplication.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            hutrieApplication.close();

        /////////////SWITCHING BETWEEN MODES/////////////////////////////////////////////////////////////////////

        keyboardSwitchMode(event);

        ///////////// SWITCHING BETWEEN TYPES OF BUILDINGS/////////////////////////////////////////////////////////////////////

        keyboardSwitchBuildingType(event, chosenMode);

        ///////////////////////OTHER KEYBOARD FEATURES/////////////////////////////////////////////////////////////////////////////////////////

        keyboardCloseGame(event);
    }
}
//=================================================================================
//                             MOUSE ACTION FUNCTIONS
//=================================================================================

void Game::mouseSetCursorPosition(sf::Sprite &cursor)
{
    //ustawia sprite kursora na pozycji myszki
    cursor.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(hutrieApplication)));
}

void Game::mouseSelectUnit(unsigned int &unitIndex)
{
    std::vector<Unit*>::iterator it;
    for (it = world.units.begin(); it != world.units.end(); ++it)
    {
        if ((*it)->field.getPosition().x <= sf::Mouse::getPosition(hutrieApplication).x &&
            ((*it)->field.getPosition().x + (*it)->field.getSize().x) >=
            sf::Mouse::getPosition(hutrieApplication).x &&
            (*it)->field.getPosition().y <= sf::Mouse::getPosition(hutrieApplication).y &&
            ((*it)->field.getPosition().y + (*it)->field.getSize().y) >=
            sf::Mouse::getPosition(hutrieApplication).y)
        {
            unitIndex = (unsigned int) std::distance(world.units.begin(), it);
            break;
        }
    }
}

void Game::mouseMapActions(unsigned int &unitIndex)
{
/*
    if (chosenMode == 1 && !(world.units.at( unitIndex )->isEmpty()))    //poruszanie Hutrim do budynku
            {
                std::vector <Unit*> usedUnits;
                usedUnits.push_back(world.units.at(unitIndex));
                world.hutries.push_back(new Worker(&hutrieApplication, usedUnits,"sprites/worker/right.png" ));
                world.hutries.back()->hutrieThread.launch();                         //tworzy watek w ktorym porusza sie Hutrie
                world.units.at(unitIndex)->addHutrie(world.hutries.back());
            }
*/
    if (world.units.at(
            unitIndex)->isEmpty())                                                 //jesli unit jest wolny, bez zadnego mapobjectu
    {
        switch (chosenMode) //BUTTONS F1,F2,F3 OR GUIBUTTONS
        {

            case 2:   //postawienie budynku                                                                                                                                   //BUILDING zajmuje 4 pola na mapie!
            {
                guiCreateBuilding(unitIndex);
                break;
            }
            case 4:     //poruszanie Hutrim
            {
                guiMoveHutrie(unitIndex);
                break;
            }
            default:
                break;
        };
    }
    else
////////////////////////////EMPHASIZE UNIT WITH MAPOBJECT///////////////////////////////////////////////////////////////////////////////////
    {
        guiHightlighUnit(unitIndex);
    }
}

void Game::mouseRightClickActions()
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
    {
        //sf::Vector2f distance = gui.guiFrame.getPosition() - static_cast<sf::Vector2f>(sf::Mouse::getPosition(hutrieApplication));
        //std::cout << distance.x << "," << distance.y << std::endl;
        //fixed.setCenter(static_cast<sf::Vector2f>(sf::Mouse::getPosition(hutrieApplication)));
        //gui.guiFrame.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(hutrieApplication))+distance);
    }
}

void Game::mouseLeftClickActions()
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && clickingClock.getElapsedTime().asSeconds() > 0.5)
    {
        if (sf::Mouse::getPosition(hutrieApplication).x <
            applicationWidth)         //jesli klikniecie w obrebie mapy
        {

//////////////////////////////////////////STOP HIGHLIGHT LAST CLICKED UNIT///////////////////////////////////////////////////////////

            guiEndHighlightUnit();

///////////////////////////////////////////////////CHOOSING RIGHT UNIT///////////////////////////////////////////////////////////

            unsigned int unitIndex = 70;

            mouseSelectUnit(unitIndex);

//////////////////////////////////////////////////////////LEFT MOUSE MAP ACTIONS/////////////////////////////////////////////////////////////////////////

            mouseMapActions(unitIndex);

////////////////////////////BUTTONS ACTIONS///////////////////////////////////////////////////////////////////////////////////
        }
        else if (gui.buildButton.checkBounds())                                { chosenMode = 2; clickSound(); }
        else if (gui.hutrieButton.checkBounds())                               { chosenMode = 1; clickSound(); }
        else if (gui.sawmill.checkBounds()     && gui.sawmill.isActive())      { buildingType = 1; clickSound(); }
        else if (gui.stonecutter.checkBounds() && gui.stonecutter.isActive())  { buildingType = 2; clickSound(); }
        else if (gui.barracks.checkBounds()    && gui.barracks.isActive())     { buildingType = 3; clickSound(); }
        else if (gui.residence.checkBounds()   && gui.residence.isActive())    { buildingType = 4; clickSound(); }
        else if (gui.goldmine.checkBounds()    && gui.goldmine.isActive())     { buildingType = 5; clickSound(); }
        else if (gui.farm.checkBounds()        && gui.farm.isActive())         { buildingType = 6; clickSound(); }
        else if (world.lastClickedUnit)                                        { world.lastClickedUnit->getMapObject()->buttonAction();}

////////////////////////////RESTART CLOCK WHICH FORBIDS MULTICLICKING///////////////////////////////////////////////////////////////////////////////////

        clickingClock.restart();
    }
    updateClock();

}

//=================================================================================
//                             GUI LOGIC FUNCTIONS
//=================================================================================

void Game::guiDeactivateButtonsFlags()
{
    if (chosenMode != tempChosenMode)
    {
        buttonFlag = chosenMode == 2;
        gui.sawmill.setActive(buttonFlag);
        gui.stonecutter.setActive(buttonFlag);
        gui.goldmine.setActive(buttonFlag);
        gui.barracks.setActive(buttonFlag);
        gui.residence.setActive(buttonFlag);
        gui.farm.setActive(buttonFlag);
        tempChosenMode = chosenMode;
    }
}

void Game::guiEndHighlightUnit()
{
    if (world.lastClickedUnit != NULL)
    {
        world.lastClickedUnit->getMapObject()->highlightUnits(false);
        world.lastClickedUnit->getMapObject()->setHighlight(false);
        world.lastClickedUnit->getMapObject()->soundPlay(false);
    }
}

void Game::guiCreateBuilding(unsigned int &unitIndex)
{
    if ((unitIndex % world.getHorizontalUnitsCounter()) !=
        world.getHorizontalUnitsCounter() - 1 &&
        unitIndex < world.getHorizontalUnitsCounter() * (world.getVerticalUnitsCounter() - 1))
    {
        std::vector<Unit*> usedUnits;
        world.prepareUnits(unitIndex, 2, 2, &usedUnits);
        if (world.isFieldEmpty(usedUnits))
        {
            createBuilding(usedUnits);
            tingSound();
        }
        else
        {
            errorUnitOccupied();
        }
    }
    else
    {
        errorOutOfMap();
    }
}

void Game::guiMoveHutrie(unsigned int &unitIndex)
{
    std::vector<Unit*> usedUnits;
    usedUnits.push_back(world.units.at(unitIndex));
    world.soldiers.push_back(new Soldier(&hutrieApplication, usedUnits, "sprites/warrior/right.png"));
    world.hutries.push_back(world.soldiers.back());
    world.hutries.back()->hutrieThread.launch();                    //tworzy watek w ktorym porusza sie Hutrie
}

void Game::guiHightlighUnit(unsigned int &unitIndex)
{
    chosenMode = 3;
    world.units.at(unitIndex)->getMapObject()->highlightUnits();
    world.units.at(unitIndex)->getMapObject()->updateStatus();
    world.units.at(unitIndex)->getMapObject()->setHighlight(true);
    world.units.at(unitIndex)->getMapObject()->soundPlay();
    world.lastClickedUnit = world.units.at(unitIndex);
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
            errorSound();
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

void Game::createBuilding(std::vector<Unit*> usedUnits)
{
    switch (buildingType)                                                                      //przekazuje wszystkie 4 unity do buldingu gdzie zostaja umieszczone w vectorze
    {
        case 1:
            //world.addBuilding(new Sawmill());
            world.buildings.push_back(
                    new Sawmill(&hutrieApplication, usedUnits, "sprites/buildings/sawmill.png", buildingType));
            break;
        case 2:
            world.buildings.push_back(
                    new StoneCutter(&hutrieApplication, usedUnits, "sprites/buildings/stone.png", buildingType));
            break;
        case 3:
            world.buildings.push_back(
                    new Barracks(&hutrieApplication, usedUnits, "sprites/buildings/barracks.png", buildingType));
            break;
        case 4:
        {
            world.availableSlots += Residence::getAddedSlotsNumber();
            std::cout << "dostepne miejsca:" << world.availableSlots << std::endl;
            world.buildings.push_back(
                    new Residence(&hutrieApplication, usedUnits, "sprites/buildings/residence.png", buildingType,
                                  &(world.availableSlots)));
            break;
        }
        case 5:
            world.buildings.push_back(
                    new Goldmine(&hutrieApplication, usedUnits, "sprites/buildings/goldmine/goldmineRail.png",
                                 buildingType));
            break;
        case 6:
            world.buildings.push_back(
                    new Farm(&hutrieApplication, usedUnits, "sprites/buildings/goldmine/goldmineRail.png",
                             buildingType));
            break;
        default:
            break;
    }
    world.buildings.back()->placeOnMap();
}

//=================================================================================
//                              ERRORS
//=================================================================================

void Game::errorNoCarriers()
{
    errorSound();
    gui.errorInfo.text.setString(
            "Error: No available carriers! Everyone is busy! Create carrier in HutriesHall or build residence");
}

void Game::errorNoSlots()
{
    errorSound();
    gui.errorInfo.text.setString("Error: No more slots! Build residence!");
}

void Game::errorNoWorkers()
{
    errorSound();
    gui.errorInfo.text.setString(
            "Error: No available workers! Everyone is busy! Create worker in HutriesHall or build residence");
}

void Game::errorUnitOccupied()
{
    errorSound();
    gui.errorInfo.text.setString("Error: Unit not empty. Choose another one");
}

void Game::errorOutOfMap()
{
    errorSound();
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
    while (hutrieApplication.isOpen() && deadline.getElapsedTime().asSeconds() < gameTime )
    {
        actions();
        displayAll();
    }
}

void Game::actions()
{
    keyboardActionsLoop();

    mouseSetCursorPosition(cursor);

    guiDeactivateButtonsFlags();

    createCarrier();

    createWorker();

    assignIntoBuilding();

    carrierReturn();

    mouseRightClickActions();

    mouseLeftClickActions();
}

void Game::displayAll()
{
    /////////////////////////DRAWING INTERFACE, GREEN GRID AND BACKGROUND///////////////////////////

    hutrieApplication.clear(sf::Color::Black);        //czyszczenie ekranu dla pierwszego wyswietlenia
    hutrieApplication.setView(fixed);
    gui.displayGUI();
    if (chosenMode == 2) gui.displayGUIBuildings();
    if (chosenMode == 1)
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
                chosenMode == 3)            //jesli tryb info rysuj w prawym gui
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
    newTime << time/60 << ":" << time % 60;
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

void Game::gameOver (bool win)
{
   GUIText stats(300,280,40,getStats());
   while( hutrieApplication.isOpen())
   {
     sf::Event event;
     while( hutrieApplication.pollEvent( event ) )
     {
        if( event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) )
        {
           hutrieApplication.close();
        }
     }
     cursor.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(hutrieApplication)));
     hutrieApplication.clear( sf::Color::Black );
     hutrieApplication.setView(fixed);
     gui.displayGUI();
     hutrieApplication.draw( background );
     hutrieApplication.draw( stats.text );
     hutrieApplication.draw(titleText.text);
     gui.displayEndingText(win);
     hutrieApplication.draw(cursor);
     hutrieApplication.display();
   };
}
