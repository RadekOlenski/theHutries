#ifndef GAME_H
#define GAME_H

#include <SFML/Audio.hpp>
#include "world.h"

#include <SFML/Graphics.hpp>
#include "guitext.h"
#include "gui.h"
#include "hutrieshall.h"
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
    sf::View fixed;

    ////////////////LOGIC//////////////////////////

    World world;
    int gameTime;
    sf::Clock deadline;
    sf::Thread titleThread;
    HutriesHall*pHall;

    void updateClock();

    //////////GRAPHICS AND AUDIO//////////////////
    sf::Music music;
    GUI gui;
    GUIText titleText;
    sf::RectangleShape background;
    sf::Texture backgroundTexture;
    sf::Sprite cursor;
    sf::Texture cursorTexture;

private:

    /////////////FUNCTIONS////////////////////////

    void actions();

    void displayAll();

    //////////////////////////////////////////////

    void createCarrier();

    void createWorker();

    void carrierReturn();

    void assignIntoBuilding();

    void buildingNeedWorker(std::vector<Building*>::iterator it);

    void buildingNeedCarrier(std::vector<Building*>::iterator it);

    void callCarrier(std::vector<Carrier*>::iterator itc, std::vector<Building*>::iterator it, int unitIndex);

    void errorNoCarriers();

    void errorNoSlots();

    void callWorker(std::vector<Worker*>::iterator itc, std::vector<Building*>::iterator it, int unitIndex);

    void errorNoWorkers();

    void createHutrie(std::string objectType, std::string sprite);

    void errorUnitOccupied();

    void errorOutOfMap();

    std::string getStats();

    ModelController* modelController;
    GameLogicController* gameLogicController;
    Keyboard* keyboard;
    Mouse* mouse;

};


#endif // GAME_H
