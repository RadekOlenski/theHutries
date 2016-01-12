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

    Game(int applicationWidth = 1024, int applicationHeight = 640, float horizontalScreenZoom = 0.7, float verticalScreenZoom = 0.7, bool fullscreen = true);

    bool menu();

    void play();

    void gameOver(bool win);

    bool getResult();

World world;
private:
    /////////////////WINDOW////////////////////////

    sf::RenderWindow hutrieApplication;

    ////////////////LOGIC//////////////////////////


    int gameTime;
    sf::Clock deadline;

    void updateClock();

    //////////GRAPHICS AND AUDIO//////////////////
    sf::Music music;
    GUI gui;

    /////////////FUNCTIONS////////////////////////

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
