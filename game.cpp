#include <sstream>
#include <iostream>

#include "modelController.h"
#include "keyboard.h"
#include "gameLogicController.h"
#include "game.h"
#include "sound.h"
#include "icon.h"

//=================================================================================
//                              CONSTRUCTOR
//=================================================================================
Game::Game(int applicationWidth, int applicationHeight, float horizontalScreenZoom, float verticalScreenZoom, bool fullscreen)
        : gameTime(GameBalance::gameTime),
          hutrieApplication(sf::VideoMode::getDesktopMode(), "The Hutries", sf::Style::Fullscreen),
          gui(applicationWidth, applicationHeight, &hutrieApplication),
          world(&hutrieApplication, applicationWidth, applicationHeight)
{
    //-----------------------------CREATING BASIC APPLICATION OBJECTS---------------------------------------------//
    if (!fullscreen) hutrieApplication.create(sf::VideoMode::getDesktopMode(), "The Hutries");
    ModelController* modelController = new ModelController();
    GUIController* guiController = new GUIController(&hutrieApplication, modelController, &world, &gui);
    GameLogicController* gameLogicController = new GameLogicController(&world, &hutrieApplication, modelController,
                                                                       guiController);
    Keyboard* keyboard = new Keyboard(&hutrieApplication, modelController, guiController);
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
    modelController->setHorizontalScreenZoom(horizontalScreenZoom);
    modelController->setVerticalScreenZoom(verticalScreenZoom);

    /////////////////////////// CREATING GAME WINDOW AND GUI //////////////////////////////////////////////////////

    hutrieApplication.setFramerateLimit(60);

    hutrieApplication.setIcon(tH_icon.width, tH_icon.height, tH_icon.pixel_data);

    guiController->createBackground();
    guiController->createCursor();
    guiController->updateGoodsNumber();

    /////////////////////////// BACKGROUND MUSIC //////////////////////////////////////////////////////

    if (!music.openFromFile(Sound::menuMusic)) std::cout << "Loading music failed" << std::endl;
    music.setLoop(true);
    changeMusicFlag = true;
}
//=================================================================================
//                              MAIN GAME LOOP
//=================================================================================


void Game::play()
{
    changeBackgroundMusic(Sound::musicPath);
    deadline.restart();
    modelController->setChosenInteractionMode(3);
    while (hutrieApplication.isOpen() && deadline.getElapsedTime().asSeconds() < gameTime && !modelController->getBackToMenu())
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

    mouse->rightClickActions();

    gameLogicController->constructBuilding();

    keyboard->actionsLoop();

    guiController->setCursorPosition();

    gameLogicController->deactivateChosenModeFlag();

    gameLogicController->handleHutriesCreation();

    gameLogicController->handleAssigningHutrie();

    gameLogicController->handleCarrierReturn();

    gameLogicController->handleGoodsProduction();

    guiController->handleErrorsVisiblity();

    updateClock();
}

void Game::changeBackgroundMusic(std::string musicPath)
{
    for (int i = 100; i > 0; i--)
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
    int time = (int) (gameTime - deadline.getElapsedTime().asSeconds());
    if (time % 60 == 0  &&  time != 0)
    {
        Sound::reminderSound();
        guiController->highlightClock(true);
    }
    if (time % 60 == 56) guiController->highlightClock(false);
    if (changeMusicFlag && time == 28)
    {
        changeBackgroundMusic(Sound::introMusic);
        changeMusicFlag = false;
    }
    std::ostringstream newTime;
    newTime << time / 60 << ":" << time % 60;
    gui.timeLeft.text.setString(newTime.str());
}

bool Game::getResult()
{
    double result = world.archers.size() * GameBalance::archerQuotient + world.warriors.size() * GameBalance::warriorQuotient;
    return result >= GameBalance::winResult;
}

void Game::gameOver(bool win)
{
    if (win)
    {
        music.openFromFile(Sound::winSound);
        music.setLoop(false);
    }
    else
    {
        music.openFromFile(Sound::loseSound);
        music.setVolume(100);
    }

    music.play();
    bool next = false;
    sf::Event event;

    while (hutrieApplication.isOpen())
    {
        while (hutrieApplication.pollEvent(event))
        {
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            {
                return;
            }
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            next = true;
        }
        guiController->displayGameOver(win,next);
    };
}

bool Game::menu()
{
    music.play();
    guiController->launchTitleThread();
    guiController->launchBigTitleThread();
    guiController->setMenuButtonsFlags(true);
    bool firstLoop = true;
    sf::Event event;
    while (hutrieApplication.isOpen() && modelController->getChosenInteractionMode() == 0)
    {
        mouse->updateMouseLock();
        mouse->leftClickActions();
        while (hutrieApplication.pollEvent(event))
        {
            keyboard->closeGame(event);
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
            {
                return true;
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            {
                return false;
            }
        }
        if (guiController->getIntroFlag())
        {
            if (firstLoop)
            {
                music.openFromFile(Sound::introMusic);
                music.play();
                guiController->setMenuButtonsFlags(false);
                guiController->launchQuoteThread();
                firstLoop = false;
            }
        }
        guiController->displayMenu();
    };
    return true;
}
