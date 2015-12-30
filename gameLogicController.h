#ifndef THEHUTRIES_GAMELOGICCONTROLLER_H
#define THEHUTRIES_GAMELOGICCONTROLLER_H

#include <vector>

#include <string>
#include <SFML/Graphics.hpp>
#include "world.h"
#include "modelController.h"
#include "gui.h"

class GameLogicController
{

public:

    GameLogicController(World* world, sf::RenderWindow* hutrieApplication, ModelController* modelController, GUI* gui);

    void createBuilding(std::vector<Unit*> usedUnits);

    void findSelectedUnit();

    bool isUnitEmpty();

    void handleBuildingCreation();

    void deactivateChosenModeFlag();

    void setBuildingButtonsFlags(bool buttonFlag);

    void highlightUnits();

    void endHighlightUnit();

    void handleHutrieMoving();

private:
    World* world;
    sf::RenderWindow* hutrieApplication;
    ModelController* modelController;
    GUI* gui;
};


#endif //THEHUTRIES_GAMELOGICCONTROLLER_H
