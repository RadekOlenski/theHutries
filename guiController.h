#ifndef THEHUTRIES_GUICONTROLLER_H
#define THEHUTRIES_GUICONTROLLER_H

#include <sstream>
#include <iostream>
#include <string>
#include "modelController.h"
#include "world.h"
#include "gui.h"

class GUIController
{
public:

    GUIController(sf::RenderWindow* hutrieApplication, ModelController* modelController, World* world, GUI* gui);

    ~GUIController();
    //------------------------------------------ DRAW ----------------------------------//

    void drawApplication();

    void drawHutriesHall();

    void drawGrid(std::vector<Unit*>::iterator it);

    void drawMapObjects(std::vector<Unit*>::iterator it);

    void drawToApplication(sf::RectangleShape shape);

    void drawToApplication(sf::Sprite sprite);

    void drawToApplication(sf::Text text);

    void createBackground();

    void createCursor();

    void setCursorSprite();

    void setCursorPosition();

    //------------------------------------------ DISPLAY ----------------------------------//

    void displayApplication();

    void displayElementsOfGUI();

    void displayGUI();

    void displayIntro();

    void displayMenu();

    void displayPauseMenu();

    void prepareToDisplay();

    //------------------------------------------ BUTTONS ----------------------------------//

    void handleGUIButtonsActions();

    void handleMenuButtonsActions();

    void handlePauseButtonsActions();

    void setBuildingButtonsFlags(bool buttonFlag);

    void setMenuButtonsFlags(bool buttonFlag);

    void setPauseButtonsFlags(bool buttonFlag);
    //------------------------------------- LAUNCH TEXT THREADS --------------------------//

    void launchTitleThread();

    void launchBigTitleThread();

    void launchQuoteThread();

    void displayGameOver(bool win,  bool next);

    //------------------------------------------ OTHER ----------------------------------//

    void setBuildingsCosts();

    void updateGoodsNumber();

    bool getIntroFlag() { return introFlag; };

    bool getReadyForGame() { return readyForGame; };

    std::string getEndingBuildingsStats();

    std::string getEndingHutriesStats();

    std::string getEndingProductionStats();

    void highlightClock(bool highlight);

    void updateBuildingsHighlight();

    void showEmptyUnits(bool mark = true);

    void attachBuildingToCursor (sf::Vector2f worldPos);

    bool getVisibleGridFlag() { return visibleGrid; };

    void setVisibleGridFlag(bool visibleGrid) { this->visibleGrid = visibleGrid; };

    void captureScreen();

    void updateClock(int time);

    //------------------------------------------ ERRORS ----------------------------------//

    void handleErrorsVisiblity();

    void errorNoCarriers();

    void errorNoSlots();

    void errorNoWorkers();

    void errorUnitOccupied();

    void errorOutOfMap();

    void errorAlreadyCreatingArcher();

    void errorAlreadyCreatingWarrior();

    void errorAlreadyCreatingCarrier();

    void errorAlreadyCreatingWorker();

    void errorNoProductsToCarry();

    void errorNotEnoughGoods();

    void errorMustBuildNearForest();

    void errorMustBuildNearRocks();

    void errorMustBuildOnMountain();

    void errorToMuchWorkers();

    sf::Sprite cursor;
private:

    void getView();

    void updateHowToText();
    sf::RenderWindow* hutrieApplication;

    ModelController* modelController;
    World* world;
    GUI* gui;
    sf::View fixed;
    sf::RectangleShape background;
    sf::Texture backgroundTexture;
    sf::Sprite buildingToCursor;
    sf::Texture buildingToCursorTexture;
    sf::Texture cursorTexture;
    sf::Texture cursorHammerTexture;

    GUIText titleText;
    GUIText bigTitleText;
    GUIText quote;

    sf::Thread titleThread;
    sf::Thread bigTitleThread;
    sf::Thread quoteThread;

    sf::Clock errorsVisiblityClock;

    bool visibleGrid;
    bool firstIteration;
    bool displayHutriesHall;
    bool introFlag;
    bool readyForGame;
    bool lockArrows;
    unsigned int chosenHowToText;
};


#endif //THEHUTRIES_GUICONTROLLER_H
