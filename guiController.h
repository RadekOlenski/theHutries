//
// Created by radek on 30.12.2015.
//

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

    void setBuildingButtonsFlags(bool buttonFlag);

    void drawApplication();

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

    void displayApplication();

    void setCursorPosition();

    void launchTitleThread();

    void displayGameOver(bool win);

    std::string getEndingStats();

    void errorNoCarriers();

    void errorNoSlots();

    void errorNoWorkers();

    void errorUnitOccupied();

    void errorOutOfMap();

    void checkCarrierGoods();

    void errorAlreadyCreatingArcher();

    void errorAlreadyCreatingWarrior();

    void errorAlreadyCreatingCarrier();

    void errorAlreadyCreatingWorker();

    void errorNoProductsToCarry();

    void errorNotEnoughGoods();

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

    sf::Thread titleThread;

    void getView();
};


#endif //THEHUTRIES_GUICONTROLLER_H
