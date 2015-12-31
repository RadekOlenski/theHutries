#ifndef THEHUTRIES_GAMELOGICCONTROLLER_H
#define THEHUTRIES_GAMELOGICCONTROLLER_H

#include <vector>



#include <string>
#include <SFML/Graphics.hpp>
#include "world.h"
#include "modelController.h"
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

    void handleAssigningHutrie();

    void needCarrier(std::vector<Building*>::iterator it);

    void callCarrier(std::vector<Carrier*>::iterator itc, std::vector<Building*>::iterator it, unsigned int unitIndex);

    void needWorker(std::vector<Building*>::iterator it);

    void callWorker(std::vector<Worker*>::iterator itc, std::vector<Building*>::iterator it, unsigned int unitIndex);

    void handleCarrierReturn();
private:
    World* world;
    sf::RenderWindow* hutrieApplication;
    ModelController* modelController;
    GUIController* guiController;
    HutriesHall* hutriesHall;
};


#endif //THEHUTRIES_GAMELOGICCONTROLLER_H
