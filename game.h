#ifndef GAME_H
#define GAME_H

#include <SFML/Audio.hpp>

#include "world.h"

#include <SFML/Graphics.hpp>
#include "guitext.h"
#include "gui.h"
#include "keyboard.h"
#include "gameLogicController.h"
#include "mouse.h"

class Game
{
public:

    Game(int applicationWidth = 1024, int applicationHeight = 640);

    void play();

    void gameOver(bool win);

    bool getResult();

private:

protected:
    /////////////////WINDOW////////////////////////

    sf::RenderWindow hutrieApplication;

    ////////////////LOGIC//////////////////////////

    World world;
    int gameTime;
    sf::Clock deadline;

    void updateClock();

    //////////GRAPHICS AND AUDIO//////////////////
    sf::Music music;
    GUI gui;

private:

    /////////////FUNCTIONS////////////////////////

    void handleActions();

    void drawApplication();

    //////////////////////////////////////////////

    void carrierReturn();

    void assignIntoBuilding();

    void buildingNeedWorker(std::vector<Building*>::iterator it);

    void buildingNeedCarrier(std::vector<Building*>::iterator it);

    void callCarrier(std::vector<Carrier*>::iterator itc, std::vector<Building*>::iterator it, int unitIndex);

    void errorNoCarriers();

    void errorNoSlots();

    void callWorker(std::vector<Worker*>::iterator itc, std::vector<Building*>::iterator it, int unitIndex);

    void errorNoWorkers();

    void errorUnitOccupied();

    void errorOutOfMap();

    ModelController* modelController;
    GUIController* guiController;
    GameLogicController* gameLogicController;
    Keyboard* keyboard;
    Mouse* mouse;

};


#endif // GAME_H
