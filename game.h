#ifndef GAME_H
#define GAME_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "world.h"
#include "gui.h"
#include "keyboard.h"
#include "gameLogicController.h"
#include "mouse.h"



class Game
{
public:

    Game(sf::RenderWindow* hutrieApplication, int applicationWidth = 1024, int applicationHeight = 640, float horizontalScreenZoom = 0.7, float verticalScreenZoom = 0.7, bool fullscreen = true);

    void menu();

    void pauseMenu();

    void play();

    void exitWindow();

World world;

private:
    void gameOver(bool win);

    /////////////////WINDOW////////////////////////

    sf::RenderWindow* hutrieApplication;

    ////////////////LOGIC//////////////////////////

    int gameTime;
    sf::Clock deadline;
    bool highligthedClockFlag;
    void updateClock();

    //////////GRAPHICS AND AUDIO//////////////////
    sf::Music music;
    sf::Music reminderSound;
    GUI gui;

    bool fullscreen;
    int applicationWidth;
    int applicationHeight;
    float horizontalScreenZoom;
    float verticalScreenZoom;

    /////////////FUNCTIONS////////////////////////

    void prepareToPlay();

    void handleActions();

    void drawApplication();

    void changeBackgroundMusic(std::string musicPath);

    bool changeMusicFlag;

    ModelController* modelController;
    GUIController* guiController;
    GameLogicController* gameLogicController;
    Keyboard* keyboard;
    Mouse* mouse;
};

#endif // GAME_H
