#include <sstream>
#include <iostream>

#include "modelController.h"
#include "keyboard.h"
#include "gameLogicController.h"
#include "game.h"
#include "gamebalance.h"

//=================================================================================
//                              CONSTRUCTOR
//=================================================================================
Game::Game(int applicationWidth, int applicationHeight) :
        gameTime(GameBalance::gameTime),
        hutrieApplication(sf::VideoMode::getDesktopMode()/*(applicationWidth + 256, applicationHeight + 30 + 128, 32)*/, "The Hutries"
         ,sf::Style::Fullscreen ),
        gui(applicationWidth, applicationHeight, &hutrieApplication),
        world(&hutrieApplication, applicationWidth, applicationHeight)
{
    //-----------------------------CREATING BASIC APPLICATION OBJECTS---------------------------------------------//
    ModelController* modelController = new ModelController();
    GUIController* guiController = new GUIController(&hutrieApplication, modelController, &world, &gui);
    GameLogicController* gameLogicController = new GameLogicController(&world, &hutrieApplication, modelController, guiController);
    Keyboard* keyboard = new Keyboard(&hutrieApplication, modelController/*, &world*/);
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
    guiController->updateGoodsNumber();

    /////////////////////////// BACKGROUND MUSIC //////////////////////////////////////////////////////

    if (!music.openFromFile(Sound::menuMusic)) std::cout << "Loading music failed" << std::endl;
    music.setLoop(true);
}
//=================================================================================
//                              MAIN GAME LOOP
//=================================================================================


void Game::play()
{
    changeBackgroundMusic(Sound::musicPath);
    deadline.restart();
    world.createEnvironment();
    while (hutrieApplication.isOpen() && deadline.getElapsedTime().asSeconds() < gameTime)
    {
        handleActions();
        drawApplication();
    }
    music.stop();
}

void Game::handleActions()
{
    mouse->updateMouseLock();

    mouse->leftClickActions();

    gameLogicController->constructBuilding();

    keyboard->actionsLoop();

    guiController->setCursorPosition();

    gameLogicController->deactivateChosenModeFlag();

    gameLogicController->handleHutriesCreation();

    gameLogicController->handleAssigningHutrie();

    gameLogicController->handleCarrierReturn();

    gameLogicController->handleGoodsProduction();

    updateClock();
}

void Game::changeBackgroundMusic(std::string musicPath)
{
    for ( int i = 100; i > 0; i--)
    {
        music.setVolume(i);
        sf::sleep(sf::milliseconds(5));
    }
    music.openFromFile(musicPath);
    music.play();
    music.setVolume(40);
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
    double result = world.archers.size() * GameBalance::archerQuotient + world.warriors.size() * GameBalance::warriorQuotient;
    return (result >= GameBalance::winResult) ? true : false;
}

void Game::gameOver(bool win)
{
    if (win) music.openFromFile(Sound::winSound);
    else
    {
        music.openFromFile(Sound::loseSound);
        music.setVolume(100);
    }
    music.play();
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

bool Game::menu()
{
    music.play();
    guiController->launchTitleThread();
    guiController->launchBigTitleThread();
    guiController->setMenuButtonsFlags(true);
    bool firstLoop = true;

    while (hutrieApplication.isOpen() && modelController->getChosenInteractionMode() == 0)
    {
        mouse->updateMouseLock();
        //if (sf::Mouse::getPosition(hutrieApplication).x > 1024 )
        mouse->leftClickActions();
        sf::Event event;
        while (hutrieApplication.pollEvent(event))
        {
            keyboard->closeGame(event);
            if (event.type == sf::Event::KeyPressed)
            {
                return (event.key.code == sf::Keyboard::Space) ? true : false ;
            }
           if(guiController->introFlag)
            {
               if (firstLoop)
               {
                    changeBackgroundMusic(Sound::introMusic);
                    music.play();
                    guiController->setMenuButtonsFlags(false);
                    guiController->launchQuoteThread();
                    firstLoop = false;
               }
               if (guiController->getDisplayHutriesHall())
               {
                  // world.createHutriesHall();
               }
            }
        }
        guiController->displayMenu();
    };
    return true;
}
