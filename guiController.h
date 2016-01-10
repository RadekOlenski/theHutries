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

    void handleGUIButtonsActions();

    void handleMenuButtonsActions();

    void setBuildingButtonsFlags(bool buttonFlag);

    void setMenuButtonsFlags(bool buttonFlag);

    void drawApplication();

    void drawHutriesHall();

    void displayElementsOfGUI();

    void drawGrid(std::vector<Unit*>::iterator it);

    void drawMapObjects(std::vector<Unit*>::iterator it);

    void createBackground();

    void drawToApplication(sf::RectangleShape shape);

    void drawToApplication(sf::Sprite sprite);

    void drawToApplication(sf::Text text);

    void createCursor();

    void prepareToDisplay();

    void displayGUI();

    void displayIntro();

    void displayApplication();

    void setCursorPosition();

    void launchTitleThread();

    void launchBigTitleThread();

    void launchQuoteThread();

    void displayGameOver(bool win);

    void displayMenu();

    std::string getEndingStats();

    void errorNoCarriers();

    void errorNoSlots();

    void errorNoWorkers();

    void errorUnitOccupied();

    void errorOutOfMap();

    void updateGoodsNumber();

    void errorAlreadyCreatingArcher();

    void errorAlreadyCreatingWarrior();

    void errorAlreadyCreatingCarrier();

    void errorAlreadyCreatingWorker();

    void errorNoProductsToCarry();

    void errorNotEnoughGoods();

    void errorMustBuildNearForest();

    void errorMustBuildNearRocks();

    void errorMustBuildOnMountain();

    bool introFlag;

    bool getDisplayHutriesHall() {return displayHutriesHall;};

private:
    sf::RenderWindow* hutrieApplication;
    ModelController* modelController;

    World* world;
    GUI* gui;

    sf::View fixed;
    sf::RectangleShape background;
    sf::Texture backgroundTexture;
    sf::Sprite cursor;
    sf::Texture cursorTexture;

    GUIText titleText;
    GUIText bigTitleText;
    GUIText quote;

    sf::Thread titleThread;
    sf::Thread bigTitleThread;
    sf::Thread quoteThread;

    void getView();

    bool firstIteration;
    bool displayHutriesHall;
};


#endif //THEHUTRIES_GUICONTROLLER_H
