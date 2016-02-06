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

    GameLogicController(World* world, sf::RenderWindow* hutrieApplication, ModelController* modelController,
                        GUIController* guiController);

    //-------------------------------------- CREATE BUILDING ------------------------------//

    void handleBuildingCreation();

    void createBuilding(std::vector<Unit*> usedUnits);

    void createSawmill(std::vector<Unit*> usedUnits);

    void createStonecutterHut(std::vector<Unit*> usedUnits);

    void createGoldmine(std::vector<Unit*> usedUnits);

    void setBuildingButtonsFlags(bool buttonFlag);

    void constructBuilding();

    void assignHutriesHall();

    //------------------------------------------ CREATE HUTRIE ----------------------------------//

    void handleHutriesCreation();

    void handleWorkerCreation();

    void handleCarrierCreation();

    void handleSoldierCreation();

    void handleWarriorCreation(unsigned int unitIndex);

    void handleArcherCreation(unsigned int unitIndex);

    void createHutrie(std::string objectType, unsigned int unitIndex);

    //------------------------------------------ ASSIGN HUTRIE ----------------------------------//

    void handleAssigningHutrie();

    void needCarrier(std::vector<Building*>::iterator it);

    void needConstructionWood(std::vector<Building*>::iterator it);

    void needConstructionStone(std::vector<Building*>::iterator it);

    void loadGoodsForCarrier(std::vector<Carrier*>::iterator &itc, std::vector<Building*>::iterator it);

    void callCarrier(std::vector<Carrier*>::iterator itc, std::vector<Building*>::iterator it);

    void needWorker(std::vector<Building*>::iterator it);

    void callWorker(std::vector<Worker*>::iterator itc, std::vector<Building*>::iterator it);

    void handleCarrierReturn();

    //------------------------------------------ OTHER ----------------------------------//

    double getResult();

    std::string computeFinalScore();

    void findSelectedUnit();

    bool isUnitEmpty();

    void handleGoodsProduction();

    void deactivateChosenModeFlag();

    void highlightUnits();

    void endHighlightUnit();

//    void handleHutrieMoving();

    void handleGUIButtonsAction();

    void handleMenuButtonsAction();

    void handlePauseButtonsAction();

    void handleExitButtonsAction();

    void updateBuildingGrid();

    void pauseClocks();

    void resumeClocks();

private:

    World* world;
    sf::RenderWindow* hutrieApplication;
    ModelController* modelController;
    GUIController* guiController;
    HutriesHall* hutriesHall;
    Barracks* barracks;
};


#endif //THEHUTRIES_GAMELOGICCONTROLLER_H
