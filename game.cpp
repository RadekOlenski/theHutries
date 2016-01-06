#include <sstream>
#include <iostream>

#include "modelController.h"
#include "keyboard.h"
#include "gameLogicController.h"
#include "game.h"

//=================================================================================
//                              CONSTRUCTOR
//=================================================================================
Game::Game(int applicationWidth, int applicationHeight) :
        gameTime(100 * 60),
        hutrieApplication(sf::VideoMode(applicationWidth + 256, applicationHeight + 30, 32), "The Hutries"
         /*,sf::Style::Fullscreen*/ ),
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
    guiController->checkCarrierGoods();

    /////////////////////////// BACKGROUND MUSIC //////////////////////////////////////////////////////

    if (!music.openFromFile(Sound::musicPath)) std::cout << "Loading music failed" << std::endl;
    music.setLoop(true);
}
//=================================================================================
//                              MAIN GAME LOOP
//=================================================================================

void Game::play()
{
    //music.play();
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

    mouse->leftClickActions();

    keyboard->actionsLoop();

    guiController->setCursorPosition();

    gameLogicController->deactivateChosenModeFlag();

    gameLogicController->handleHutriesCreation();

    gameLogicController->handleAssigningHutrie();

    gameLogicController->handleCarrierReturn();

    gameLogicController->handleGoodsProduction();

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

