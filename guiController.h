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

    void drawHutries();

    void drawMapObjects(std::vector<Unit*>::iterator it);

    void drawToApplication(sf::RectangleShape shape);

    void drawToApplication(sf::Sprite sprite);

    void drawToApplication(sf::Text text);

    void createBackground();

     //------------------------------------------ CURSOR ----------------------------------//

    void createCursor();

    void setCursorSprite();

    void setCursorPosition();

    void attachBuildingToCursor (sf::Vector2f worldPos);

    //------------------------------------------ DISPLAY ----------------------------------//

    void displayApplication();

    void displayElementsOfGUI();

    void displayGUI();

    void displayIntro();

    void displayMenu();

    void displayHowToPlay();

    void displayPauseMenu();

    void prepareToDisplay();

    void displayExitWindow();

    //------------------------------------------ BUTTONS ----------------------------------//

    void handleGUIButtonsActions();

    void handleMenuButtonsActions();

    void handleDifficultyButtonsActions();

    void handlePauseButtonsActions();

    void handleExitButtonsActions();

    void handleHowToPlayButtonsActions();

    void activateHowToPlayButtons(bool active);

    void turnOffHelp();

    void setDifficultyButtonsFlags(bool buttonFlag);

    void setBuildingButtonsFlags(bool buttonFlag);

    void setMenuButtonsFlags(bool buttonFlag);

    void setPauseButtonsFlags(bool buttonFlag);

    void setExitButtonsFlags(bool buttonFlag);

    void setHelpBuildingsFlags (bool buttonFlag);

    //------------------------------------- LAUNCH TEXT THREADS --------------------------//

    void launchTitleThread();

    void launchBigTitleThread();

    void launchQuoteThread();

    void terminateQuoteThread();

    void displayGameOver(bool win,  bool next);

    //------------------------------------------ OTHER ----------------------------------//

    void setBuildingsCosts();

    void updateGoodsNumber();

    bool getIntroFlag() { return introFlag; };

    bool getReadyForGame() { return readyForGame; };

    void highlightClock(bool highlight);

    void updateBuildingsHighlight();

    void showEmptyUnits(bool mark = true);

    void captureScreen();

    void updateClock(int time);

    void highlightTargetButton();

    //------------------------------------GRID---------------------------------------//

    void setGridOutlineColor(bool outlineColorFlag);

    bool getVisibleGridFlag() { return visibleGrid; };

    void setVisibleGridFlag(bool visibleGrid) { this->visibleGrid = visibleGrid; };

    //------------------------------------ENDING---------------------------------------//

    void setEndingText(bool win, bool next);

    std::string getEndingBuildingsStats();

    std::string getEndingHutriesStats();

    std::string getEndingProductionStats();

    std::string finalScore;

    //------------------------------------DIFFICULTY---------------------------------------//

    void chooseDifficulty();

    void changeDifficultyButtonSprite();

    void setDifficulty(std::string difficult);

    void setEasy();

    void setNormal();

    void setHard();

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

    void errorOverflowHutriesHallQueue();

    void errorNoProductsToCarry();

    void errorNotEnoughGoods();

    void errorMustBuildNearForest();

    void errorMustBuildNearRocks();

    void errorMustBuildOnMountain();

    void errorToMuchWorkers();

    void errorTooMuchGoods();

    sf::Sprite cursor;
private:

    void getView();

    void updateHowToText();

    void hideDifficultyTexts();

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
    bool howToPlayFlag;
    bool readyForGame;
    bool lockArrows;
    unsigned int chosenHowToText;

    int animationCounter;
    int frameCounter;
};


#endif //THEHUTRIES_GUICONTROLLER_H
