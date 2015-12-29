#include <iostream>
#include "buildingType.h"
#include "sawmill.h"
#include "stonecutter.h"
#include "barracks.h"
#include "residence.h"
#include "goldmine.h"
#include "farm.h"
#include "gameLogicController.h"


GameLogicController::GameLogicController(World*world, sf::RenderWindow*hutrieApplication,
                                         ModelController*modelController)
{
    this->world = world;
    this->hutrieApplication = hutrieApplication;
    this->modelController = modelController;
}


void GameLogicController::createBuilding(std::vector<Unit*> usedUnits)
{
    switch (modelController->getChosenBuildingType())                                                                      //przekazuje wszystkie 4 unity do buldingu gdzie zostaja umieszczone w vectorze
    {
        case BuildingType::SAWMILL:
            world->buildings.push_back(new Sawmill(hutrieApplication, usedUnits, "sprites/buildings/sawmill.png"));
            break;
        case BuildingType::STONECUTTERHUT:
            world->buildings.push_back(new StoneCutter(hutrieApplication, usedUnits, "sprites/buildings/stone.png"));
            break;
        case BuildingType::BARRACKS:
            world->buildings.push_back(new Barracks(hutrieApplication, usedUnits, "sprites/buildings/barracks.png"));
            break;
        case BuildingType::RESIDENCE:
        {
            world->availableSlots += Residence::getAddedSlotsNumber();
            std::cout << "dostepne miejsca:" << world->availableSlots << std::endl;
            world->buildings.push_back(new Residence(hutrieApplication, usedUnits, "sprites/buildings/residence.png",
                                                                                          &(world->availableSlots)));
            break;
        }
        case BuildingType::GOLDMINE:
            world->buildings.push_back(new Goldmine(hutrieApplication, usedUnits, "sprites/buildings/goldmine/goldmineRail.png"));
            break;
        case BuildingType::FARM:
            world->buildings.push_back(new Farm(hutrieApplication, usedUnits, "sprites/buildings/goldmine/goldmineRail.png"));
            break;
        default:
            break;
    }
    world->buildings.back()->placeOnMap();
}
