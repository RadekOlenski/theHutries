
#include <iostream>

#include "buildingType.h"
#include "sawmill.h"
#include "stonecutter.h"
#include "barracks.h"
#include "residence.h"
#include "goldmine.h"
#include "farm.h"
#include "gameLogicController.h"
#include "interactionMode.h"
#include "gui.h"
#include "sound.h"

GameLogicController::GameLogicController(World*world, sf::RenderWindow*hutrieApplication,
                                         ModelController*modelController, GUI* gui)
{
    this->world = world;
    this->hutrieApplication = hutrieApplication;
    this->modelController = modelController;
    this->gui = gui;
}


void GameLogicController::handleBuildingCreation()
{
    int selectedUnitIndex = modelController->getSelectedUnitIndex();
    int horizontalUnitsCounter = world->getHorizontalUnitsCounter();
    int verticalUnitsCounter = world->getVerticalUnitsCounter();

    if ((selectedUnitIndex % horizontalUnitsCounter) != horizontalUnitsCounter - 1
        && selectedUnitIndex < horizontalUnitsCounter * (verticalUnitsCounter - 1))
    {
        std::vector<Unit*> usedUnits;
        world->prepareUnits(selectedUnitIndex, 2, 2, &usedUnits);
        if (world->isFieldEmpty(usedUnits))
        {
            this->createBuilding(usedUnits);
            Sound::ting();
        }
        else
        {
            //errorUnitOccupied();
        }
    }
    else
    {
        //errorOutOfMap();
    }
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
            world->increaseAvailableSlots(Residence::getAddedSlotsNumber());
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

void GameLogicController::findSelectedUnit()
{
    modelController->setSelectedUnitIndex(world->findSelectedUnitIndex());
}

bool GameLogicController::isUnitEmpty()
{
    return world->units.at(modelController->getSelectedUnitIndex())->isEmpty();
}

void GameLogicController::deactivateChosenModeFlag()
{
    int chosenMode = modelController->getChosenInteractionMode();
    int tempChosenMode = modelController->getTempChosenMode();
    if (chosenMode != tempChosenMode)
    {
        bool buttonFlag = (chosenMode == InteractionMode::BUILDMODE);
        this->setBuildingButtonsFlags(buttonFlag);
        modelController->setTempChosenMode(chosenMode);
    }
}

void GameLogicController::setBuildingButtonsFlags(bool buttonFlag)
{
    gui->residence.setActive(buttonFlag);
    gui->sawmill.setActive(buttonFlag);
    gui->stonecutter.setActive(buttonFlag);
    gui->goldmine.setActive(buttonFlag);
    gui->barracks.setActive(buttonFlag);
    gui->farm.setActive(buttonFlag);
}

void GameLogicController::highlightUnits()
{
    int selectedUnitIndex = modelController->getSelectedUnitIndex();
    modelController->setChosenInteractionMode(InteractionMode::INFOMODE);
    world->units.at(selectedUnitIndex)->getMapObject()->highlightUnits();
    world->units.at(selectedUnitIndex)->getMapObject()->updateStatus();
    world->units.at(selectedUnitIndex)->getMapObject()->setHighlight(true);
    world->units.at(selectedUnitIndex)->getMapObject()->soundPlay();
    world->lastClickedUnit = world->units.at(selectedUnitIndex);
}

void GameLogicController::endHighlightUnit()
{
    if (world->lastClickedUnit != NULL)
    {
        world->lastClickedUnit->getMapObject()->highlightUnits(false);
        world->lastClickedUnit->getMapObject()->setHighlight(false);
        world->lastClickedUnit->getMapObject()->soundPlay(false);
    }
}
