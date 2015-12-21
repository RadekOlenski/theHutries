#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "world.h"
#include "guitext.h"
#include "gui.h"
#include "hutrieshall.h"

class Game
{
    public:
        Game(int applicationWidth = 1024, int applicationHeight = 640);
        void play();
    private:

protected:
    /////////////////WINDOW////////////////////////

    int applicationWidth;
    int applicationHeight;
    sf::RenderWindow hutrieApplication;
    sf::View fixed;

    ////////////////LOGIC//////////////////////////

        World world;
        int chosenMode;
        int tempChosenMode;
        int buildingType;
        bool buttonFlag;
        sf::Clock deadline;
        sf::Clock clock;
        sf::Thread titleThread;
        HutriesHall *pHall;

    //////////GRAPHICS AND AUDIO//////////////////
    sf::Music music;
    GUI gui;
    GUIText titleText;
    sf::RectangleShape background;
    sf::Texture backgroundTexture;
    sf::Sprite cursor;
    sf::Texture cursorTexture;

    sf::Sound sound;
    sf::SoundBuffer buffer;


private:


    void errorSound();

    void clickSound();

    /////////////FUNCTIONS////////////////////////

    void actions();

    void displayAll();

    //////// KEYBOARD ACTION FUNCTIONS   ///////

    void keyboardSwitchMode(sf::Event event);

    void keyboardSwitchBuildingType(sf::Event event, int chosenMode);

    void keyboardCloseGame(sf::Event event);

    void keyboardActionsLoop();

    //////////////////////////////////////////////

    void mouseSetCursorPosition(sf::Sprite &cursor);

    void guiDeactivateButtonsFlags();

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

    void createBuilding(std::vector<Unit*> usedUnits);

    void tingSound();

    void errorUnitOccupied();

    void errorOutOfMap();

    void guiEndHighlightUnit();

    void mouseSelectUnit(unsigned int &unitIndex);

    void mouseMapActions(unsigned int &unitIndex);

    void guiCreateBuilding(unsigned int &unitIndex);

    void guiMoveHutrie(unsigned int &unitIndex);

    void guiHightlighUnit(unsigned int &unitIndex);

    void mouseRightClickActions();

    void mouseLeftClickActions();
};


#endif // GAME_H
