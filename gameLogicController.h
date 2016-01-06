#ifndef THEHUTRIES_GAMELOGICCONTROLLER_H
#define THEHUTRIES_GAMELOGICCONTROLLER_H

#include <vector>



#include <string>
#include <SFML/Graphics.hpp>
#include "world.h"
#include "modelController.h"
#include "hutrieshall.h"
#include "goodsbuilding.h"
#include "guiController.h"
#include "barracks.h"

class GameLogicController
{

public:

    GameLogicController(World* world, sf::RenderWindow* hutrieApplication, ModelController* modelController, GUIController* guiController);

    void createBuilding(std::vector<Unit*> usedUnits);

    void createSawmill(std::vector<Unit*> usedUnits);

    void findSelectedUnit();

    bool isUnitEmpty();

    void handleBuildingCreation();

    void handleGoodsProduction();

    void deactivateChosenModeFlag();

    void setBuildingButtonsFlags(bool buttonFlag);

    void highlightUnits();

    void endHighlightUnit();

    void handleHutrieMoving();

    void handleHutriesCreation();

    void handleWorkerCreation();

    void handleCarrierCreation();

    void handleSoldierCreation();

    void handleWarriorCreation(unsigned int unitindex);

    void handleArcherCreation(unsigned int unitIndex);

    void createHutrie(std::string objectType, std::string sprite, unsigned int unitIndex);

    void handleGUIButtonsAction();

    void handleAssigningHutrie();

    void needCarrier(std::vector<Building*>::iterator it);

    void callCarrier(std::vector<Carrier*>::iterator itc, std::vector<Building*>::iterator it, unsigned int unitIndex);

    void needWorker(std::vector<Building*>::iterator it);

    void callWorker(std::vector<Worker*>::iterator itc, GoodsBuilding* gBuilding, unsigned int unitIndex);

    void handleCarrierReturn();
private:
    World* world;
    sf::RenderWindow* hutrieApplication;
    ModelController* modelController;
    GUIController* guiController;
    HutriesHall* hutriesHall;
    Barracks* barracks;
};


#endif //THEHUTRIES_GAMELOGICCONTROLLER_H
