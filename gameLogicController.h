#ifndef THEHUTRIES_GAMELOGICCONTROLLER_H
#define THEHUTRIES_GAMELOGICCONTROLLER_H

#include <vector>



#include <string>
#include <SFML/Graphics.hpp>
#include "world.h"
#include "modelController.h"
#include "gui.h"
#include "hutrieshall.h"
#include "guiController.h"

class GameLogicController
{

public:

    GameLogicController(World* world, sf::RenderWindow* hutrieApplication, ModelController* modelController, GUIController* guiController);

    void createBuilding(std::vector<Unit*> usedUnits);

    void findSelectedUnit();

    bool isUnitEmpty();

    void handleBuildingCreation();

    void deactivateChosenModeFlag();

    void setBuildingButtonsFlags(bool buttonFlag);

    void highlightUnits();

    void endHighlightUnit();

    void handleHutrieMoving();

    void handleHutriesCreation();

    void handleWorkerCreation();

    void handleCarrierCreation();

    void createHutrie(std::string objectType, std::string sprite);

    void handleGUIButtonsAction();
private:
    World* world;
    sf::RenderWindow* hutrieApplication;
    ModelController* modelController;
    GUIController* guiController;
    HutriesHall* hutriesHall;
};


#endif //THEHUTRIES_GAMELOGICCONTROLLER_H
