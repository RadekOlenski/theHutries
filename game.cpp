#include <sstream>
#include <iostream>

#include "modelController.h"
#include "keyboard.h"
#include "gameLogicController.h"
#include "game.h"
#include "sound.h"
#include "icon.h"
#include "interactionMode.h"

//=================================================================================
//                              CONSTRUCTOR
//=================================================================================
Game::Game(sf::RenderWindow* hutrieApplication, int applicationWidth, int applicationHeight, float horizontalScreenZoom,
           float verticalScreenZoom, bool fullscreen)
        : gameTime(GameBalance::gameTime),
          gui(applicationWidth, applicationHeight, hutrieApplication),
          world(hutrieApplication, applicationWidth, applicationHeight)
{
    this->hutrieApplication = hutrieApplication;
    this->fullscreen = fullscreen;
    this->applicationWidth = applicationWidth;
    this->applicationHeight = applicationHeight;
    this->horizontalScreenZoom = horizontalScreenZoom;
    this->verticalScreenZoom = verticalScreenZoom;

    //-----------------------------CREATING BASIC APPLICATION OBJECTS---------------------------------------------//
    if (!fullscreen) hutrieApplication->create(sf::VideoMode::getDesktopMode(), "The Hutries");
    ModelController* modelController = new ModelController();
    GUIController* guiController = new GUIController(hutrieApplication, modelController, &world, &gui);
    GameLogicController* gameLogicController = new GameLogicController(&world, hutrieApplication, modelController,
                                                                       guiController);
    Keyboard* keyboard = new Keyboard(hutrieApplication, modelController, guiController);
    Mouse* mouse = new Mouse(hutrieApplication, modelController, gameLogicController);
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

    hutrieApplication->setFramerateLimit(60);

    hutrieApplication->setIcon(tH_icon.width, tH_icon.height, tH_icon.pixel_data);

    guiController->createBackground();
    guiController->createCursor();
    guiController->updateGoodsNumber();

    /////////////////////////// BACKGROUND MUSIC //////////////////////////////////////////////////////

    if (!music.openFromFile(Sound::menuMusic)) std::cout << "Loading music failed" << std::endl;
    music.setLoop(true);
    music.setVolume(GameBalance::musicVolume);
    changeMusicFlag = true;

    /////////////////////////// REMINDER SOUND //////////////////////////////////////////////////////

    if (!reminderSound.openFromFile(Sound::reminder)) std::cout << "Loading music failed" << std::endl;
    highligthedClockFlag = true;
}

//=================================================================================
//                              MAIN GAME LOOP
//=================================================================================

void Game::play()
{
    prepareToPlay();
    while (hutrieApplication->isOpen() &&
           deadline.getElapsedTime().asSeconds() < gameTime)
    {
        handleActions();
        drawApplication();
        if (modelController->getBackToMenu())
            return;
    }
    bool result = gameLogicController->getResult() >= GameBalance::winResult;;
    gameOver(result);
    music.stop();
}

void Game::prepareToPlay()
{
    gameTime = GameBalance::gameTime;
    changeBackgroundMusic(Sound::musicPath);
    modelController->setChosenInteractionMode(InteractionMode::NEUTRALMODE);
    guiController->setVisibleGridFlag(!guiController->getVisibleGridFlag());
    guiController->setGridOutlineColor(guiController->getVisibleGridFlag());
    guiController->setVisibleGridFlag(!guiController->getVisibleGridFlag());
    guiController->setGridOutlineColor(guiController->getVisibleGridFlag());
    guiController->terminateQuoteThread();
    deadline.restart();
}

void Game::handleActions()
{
    if (modelController->getPauseGame())
    {
        pauseMenu();
        if (modelController->getBackToMenu())
            return;
    }

    mouse->updateMouseLock();

    mouse->leftClickActions();

    mouse->rightClickActions();

    gameLogicController->constructBuilding();

    keyboard->actionsLoop();

    guiController->setCursorPosition();

    guiController->highlightTargetButton();

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
    for (int i = GameBalance::musicVolume; i > 0; i--)
    {
        music.setVolume(i);
        sf::sleep(sf::milliseconds(5));
    }
    music.openFromFile(musicPath);
    music.play();
    music.setVolume(GameBalance::musicVolume);
}

void Game::drawApplication()
{
    guiController->drawApplication();
}

void Game::updateClock()
{
    int time = (int) (gameTime - deadline.getElapsedTime().asSeconds());
    if (time % 60 == 0 && highligthedClockFlag && time != 0)
    {
        reminderSound.setVolume(GameBalance::sfxVolume);
        reminderSound.play();
        guiController->highlightClock(true);
        highligthedClockFlag = false;
    }
    if (time % 60 == 56)
    {
        guiController->highlightClock(false);
        highligthedClockFlag = true;
    }
    if (changeMusicFlag && time == 28)
    {
        music.openFromFile(Sound::introMusic);
        music.setVolume(GameBalance::musicVolume);
        music.play();
        changeMusicFlag = false;
    }
    guiController->updateClock(time);
}

void Game::gameOver(bool win)
{
    if (win)
    {
        music.openFromFile(Sound::winSound);
        music.setVolume(GameBalance::musicVolume);
        music.setLoop(false);
    }
    else
    {
        music.openFromFile(Sound::loseSound);
        music.setVolume(GameBalance::musicVolume);
    }

    music.play();
    bool next = false;
    sf::Event event;

    guiController->finalScore = gameLogicController->computeFinalScore();

    while (hutrieApplication->isOpen())
    {
        while (hutrieApplication->pollEvent(event))
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
        guiController->displayGameOver(win, next);
    };
}

void Game::menu()
{
    music.setVolume(GameBalance::musicVolume);
    music.play();
    guiController->launchTitleThread();
    guiController->launchBigTitleThread();
    guiController->setMenuButtonsFlags(true);
    bool firstLoop = true;
    sf::Event event;
    while (hutrieApplication->isOpen() && modelController->getChosenInteractionMode() == 0)
    {
        mouse->updateMouseLock();
        mouse->leftClickActions();
        guiController->highlightTargetButton();
        while (hutrieApplication->pollEvent(event))
        {
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space && guiController->getIntroFlag())
            {
                if(modelController->getExitWindow())
                    GameBalance::exitFlag = true;
                else return;
            }
            keyboard->closeGame(event);
        }
        if (guiController->getIntroFlag())
        {
            if (firstLoop)
            {
                music.openFromFile(Sound::introMusic);
                music.setVolume(GameBalance::musicVolume);
                music.play();
                guiController->setMenuButtonsFlags(false);
                guiController->launchQuoteThread();
                firstLoop = false;
            }
        }
        guiController->displayMenu();
        if(modelController->getExitWindow())
            exitWindow();
        if(GameBalance::exitFlag)
            return;
    };
    return;
}

void Game::pauseMenu()
{
    gameTime -= deadline.getElapsedTime().asSeconds();
    gameLogicController->pauseClocks();
    guiController->setPauseButtonsFlags(true);
    while (hutrieApplication->isOpen() && modelController->getPauseGame())
    {
        guiController->highlightTargetButton();
        guiController->captureScreen();
        guiController->displayPauseMenu();
        mouse->updateMouseLock();
        mouse->leftClickActions();
        keyboard->actionsLoop();
        music.setVolume(GameBalance::musicVolume);
        if (modelController->getBackToMenu())
        {
            return;
        }
    }
    guiController->setPauseButtonsFlags(false);
    deadline.restart();
    gameLogicController->resumeClocks();
    modelController->setPauseGame(false);
}

void Game::exitWindow()
{
    guiController->setExitButtonsFlags(true);
    modelController->setChosenInteractionMode(10);
    while (hutrieApplication->isOpen() && modelController->getExitWindow())
    {
        guiController->highlightTargetButton();
        guiController->displayExitWindow();
        mouse->updateMouseLock();
        mouse->leftClickActions();
        keyboard->handleExitWindowActions();
    }
    guiController->setExitButtonsFlags(false);
    modelController->setExitWindow(false);
    modelController->setChosenInteractionMode(0);
}
