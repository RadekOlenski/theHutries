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
#include "sound.h"
#include "warrior.h"
#include "archer.h"

GameLogicController::GameLogicController(World*world, sf::RenderWindow*hutrieApplication,
                                         ModelController*modelController, GUIController* guiController)
{
    this->world = world;
    this->hutrieApplication = hutrieApplication;
    this->modelController = modelController;
    this->guiController = guiController;
    hutriesHall = dynamic_cast <HutriesHall*>(world->buildings.at(0));
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
            guiController->errorUnitOccupied();
        }
    }
    else
    {
        guiController->errorOutOfMap();
    }
}

void GameLogicController::createBuilding(std::vector<Unit*> usedUnits)
{
    switch (modelController->getChosenBuildingType())                                                                      //przekazuje wszystkie 4 unity do buldingu gdzie zostaja umieszczone w vectorze
    {
        case BuildingType::SAWMILL:
            world->buildings.push_back(new Sawmill(hutrieApplication, usedUnits, "sprites/buildings/sawmill.png"));
            world->goodsBuildingIndex.push_back(world->buildings.size() - 1);
            break;
        case BuildingType::STONECUTTERHUT:
            world->buildings.push_back(new StoneCutter(hutrieApplication, usedUnits, "sprites/buildings/stone.png"));
            world->goodsBuildingIndex.push_back(world->buildings.size() - 1);
            break;
        case BuildingType::BARRACKS:
            world->buildings.push_back(new Barracks(hutrieApplication, usedUnits, "sprites/buildings/barracks.png"));
            world->barracksIndex.push_back(world->buildings.size() - 1);
            break;
        case BuildingType::RESIDENCE:
        {
            world->increaseAvailableSlots(Residence::getAddedSlotsNumber());
            world->buildings.push_back(new Residence(hutrieApplication, usedUnits, "sprites/buildings/residence.png",
                                                     &(world->availableSlots)));
            break;
        }
        case BuildingType::GOLDMINE:
            world->buildings.push_back(
                    new Goldmine(hutrieApplication, usedUnits, "sprites/buildings/goldmine/goldmineRail.png"));
            world->goodsBuildingIndex.push_back(world->buildings.size() - 1);
            break;
        case BuildingType::FARM:
            world->buildings.push_back(
                    new Farm(hutrieApplication, usedUnits, "sprites/buildings/goldmine/goldmineRail.png"));
            world->goodsBuildingIndex.push_back(world->buildings.size() - 1);
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
    guiController->setBuildingButtonsFlags(buttonFlag);
}

void GameLogicController::highlightUnits()
{
    unsigned int selectedUnitIndex = modelController->getSelectedUnitIndex();
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

void GameLogicController::handleHutrieMoving()
{
    unsigned int unitIndex = modelController->getSelectedUnitIndex();
    std::vector<Unit*> usedUnits;
    usedUnits.push_back(world->units.at(unitIndex));
    world->soldiers.push_back(new Soldier(hutrieApplication, usedUnits, "sprites/warrior/right.png"));
    world->hutries.push_back(world->soldiers.back());
    world->hutries.back()->hutrieThread.launch();                    //tworzy watek w ktorym porusza sie Hutrie
}

void GameLogicController::handleHutriesCreation()
{
    GameLogicController::handleWorkerCreation();
    GameLogicController::handleCarrierCreation();
    GameLogicController::handleSoldierCreation();
}

void GameLogicController::handleWorkerCreation()
{
    if (hutriesHall->getMakeWorkerFlag())
    {
        if (world->availableSlots > 0)
        {
            unsigned int unitIndex = (unsigned int) hutriesHall->getUnitIndex(6);                 // ktore z pol budynku ma byc zajete przez carriera
            std::string objectType = "worker";
            std::string sprite = "sprites/worker/up.png";
            createHutrie(objectType, sprite, unitIndex);
        }
        else
        {
            guiController->errorNoSlots();
        }
        hutriesHall->setMakeWorkerFlag(false);
    }
}

void GameLogicController::handleCarrierCreation()
{
    if (hutriesHall->getMakeCarrierFlag())
    {
        if (world->availableSlots > 0)
        {
            unsigned int unitIndex = (unsigned int) hutriesHall->getUnitIndex(6);                 // ktore z pol budynku ma byc zajete przez carriera
            std::string objectType = "carrier";
            std::string sprite = "sprites/carrier/up.png";
            createHutrie(objectType, sprite, unitIndex);
        }
        else
        {
            guiController->errorNoSlots();
        }
        hutriesHall->setMakeCarrierFlag(false);
    }
}

void GameLogicController::handleSoldierCreation()
{
    for(unsigned int i = 0; i < world->barracksIndex.size(); i++)
    {
        unsigned int index = world->barracksIndex.at(i);
        barracks = dynamic_cast<Barracks*> (world->buildings.at(index));
        unsigned int unitIndex = (unsigned int) barracks->getUnitIndex(2);
        handleWarriorCreation(unitIndex);
        handleArcherCreation(unitIndex);
    }
}

void GameLogicController::handleWarriorCreation(unsigned int unitIndex)
{
    if (barracks->getTrainingWarriorFlag())
    {
        if (barracks->trainingClock.getElapsedTime().asSeconds() >= barracks->getWarriorTrainingTime())
        {
            std::string objectType = "warrior";
            std::string sprite = "sprites/warrior/up.png";
            createHutrie(objectType, sprite, unitIndex);
            barracks->setTrainingWarriorFlag(false);
        }
    }
    else if(!barracks->getTrainingArcherFlag())
        barracks->trainingClock.restart();
    if (barracks->getMakeWarriorFlag())
    {
        if (barracks->getTrainingArcherFlag())
        {
            guiController->errorAlreadyCreatingArcher();
            barracks->setMakeWarriorFlag(false);
            return;
        }
        if (world->availableSlots == 0)
        {
            guiController->errorNoSlots();
            barracks->setMakeWarriorFlag(false);
            return;
        }
        if (barracks->getTrainingWarriorFlag())
        {
            guiController->errorAlreadyCreatingWarrior();
            barracks->setMakeWarriorFlag(false);
            return;
        }
        else barracks->setTrainingWarriorFlag(true);
        barracks->setMakeWarriorFlag(false);
    }
}

void GameLogicController::handleArcherCreation(unsigned int unitIndex)
{
    if (barracks->getTrainingArcherFlag())
    {
        if (barracks->trainingClock.getElapsedTime().asSeconds() >= barracks->getArcherTrainingTime())
        {
            std::string objectType = "archer";
            std::string sprite = "sprites/warrior/up.png";
            createHutrie(objectType, sprite, unitIndex);
            barracks->setTrainingArcherFlag(false);
        }
    }
    else if(!barracks->getTrainingWarriorFlag())
        barracks->trainingClock.restart();
    if (barracks->getMakeArcherFlag())
    {
        if (barracks->getTrainingWarriorFlag())
        {
            guiController->errorAlreadyCreatingWarrior();
            barracks->setMakeArcherFlag(false);
            return;
        }
        if (world->availableSlots == 0)
        {
            guiController->errorNoSlots();
            barracks->setMakeArcherFlag(false);
            return;
        }
        if (barracks->getTrainingArcherFlag())
        {
            guiController->errorAlreadyCreatingArcher();
            barracks->setMakeArcherFlag(false);
            return;
        }
        else barracks->setTrainingArcherFlag(true);
        barracks->setMakeArcherFlag(false);
    }
}

void GameLogicController::createHutrie(std::string objectType, std::string sprite, unsigned int unitIndex)
{
    std::vector<Unit*> usedUnits;
    usedUnits.push_back(world->units.at(unitIndex));
    if (objectType == "carrier")
    {
        std::cout << "Utworze dla ciebie Carriera!" << std::endl;
        world->carriers.push_back(new Carrier(hutrieApplication, usedUnits, sprite));//"sprites/carrier/empty.png"));
        world->hutries.push_back(world->carriers.back());
        world->units.at(unitIndex)->addHutrie(world->hutries.back());
        world->availableSlots--;
    }
    else if (objectType == "worker")
    {
        std::cout << "Utworze dla ciebie Workera!" << std::endl;
        world->workers.push_back(new Worker(hutrieApplication, usedUnits, sprite));//"sprites/carrier/empty.png"));
        world->hutries.push_back(world->workers.back());
        world->units.at(unitIndex)->addHutrie(world->hutries.back());
        world->availableSlots--;
    }
    else if (objectType == "warrior")
    {
        std::cout << "Utworze dla ciebie Warriora!" << std::endl;
        world->soldiers.push_back(new Warrior(hutrieApplication, usedUnits, sprite));//"sprites/carrier/empty.png"));
        world->hutries.push_back(world->soldiers.back());
        world->units.at(unitIndex)->addHutrie(world->hutries.back());
        world->availableSlots--;
    }
    else if (objectType == "archer")
    {
        std::cout << "Utworze dla ciebie Archera!" << std::endl;
        world->soldiers.push_back(new Archer(hutrieApplication, usedUnits, sprite));//"sprites/carrier/empty.png"));
        world->hutries.push_back(world->soldiers.back());
        world->units.at(unitIndex)->addHutrie(world->hutries.back());
        world->availableSlots--;
    }
}

void GameLogicController::handleGUIButtonsAction()
{
    guiController->handleGUIButtonsActions();
}

void GameLogicController::handleAssigningHutrie()
{
    std::vector<Building*>::iterator it;
    for (it = world->buildings.begin(); it != world->buildings.end(); ++it)
    {
        if ((*it)->getNeedCarrierFlag())
        {
            needCarrier(it);
        }
        if ((*it)->getNeedWorkerFlag())
        {
            needWorker(it);
        }
    }
}

void GameLogicController::needCarrier(std::vector<Building*>::iterator it)
{
    unsigned int unitIndex = (unsigned int) (*it)->getUnitIndex(2);                   // ktore z pol budynku ma byc zajete przez carriera
    std::vector<Carrier*>::iterator itc;
    callCarrier(itc, it, unitIndex);
    (*it)->setNeedCarrier(false);
}

void GameLogicController::callCarrier(std::vector<Carrier*>::iterator itc, std::vector<Building*>::iterator it, unsigned int unitIndex)
{
    for (itc = world->carriers.begin(); itc != world->carriers.end(); ++itc)
    {
        if (!((*itc)->isBusy()))
        {
            std::cout << "Nie jestem zajety! Ruszam po zasoby!" << std::endl;
            unsigned int carrierIndex = (unsigned int) std::distance(world->carriers.begin(), itc);
            world->carriers.at(carrierIndex)->reconnectUnits((*it)->getObjectUnits());
            world->carriers.at(carrierIndex)->hutrieThread.launch();          //tworzy watek w ktorym porusza sie Hutrie
            world->units.at(unitIndex)->addHutrie(world->carriers.at(carrierIndex));
            (*it)->updateStatus();
            break;
        }
    }
    if (itc == world->carriers.end())
    {
        guiController->errorNoCarriers();
    }
}

void GameLogicController::needWorker(std::vector<Building*>::iterator it)
{
    GoodsBuilding* gBuilding = dynamic_cast<GoodsBuilding*>( *it );
    if (gBuilding->getWorkersSize() < (*it)->getCapacity())       //jesli aktualna ilosc w budynku mniejsza od pojemnosci
    {
        unsigned int unitIndex = (unsigned int) (*it)->getUnitIndex(2);
        std::vector<Worker*>::iterator itc;
        callWorker(itc, gBuilding, unitIndex);
    }
    (*it)->setNeedWorker(false);
}

void GameLogicController::callWorker(std::vector<Worker*>::iterator itc, GoodsBuilding* gBuilding,
                                     unsigned int unitIndex)
{
    for (itc = world->workers.begin(); itc != world->workers.end(); ++itc)
    {
        if (!((*itc)->isBusy()))
        {
            (*itc)->setBusy(true);
            std::cout << "Nie jestem zajety! Ruszam do pracy!" << std::endl;
            unsigned int workerIndex = (unsigned int) std::distance(world->workers.begin(), itc);
            world->workers.at(workerIndex)->reconnectUnits(gBuilding->getObjectUnits());
            world->workers.at(workerIndex)->hutrieThread.launch();             //uruchamia watek w ktorym porusza sie Hutrie
            world->units.at(unitIndex)->addHutrie(world->workers.at(workerIndex));
            gBuilding->addWorker(world->workers.at(workerIndex));
            gBuilding->updateStatus();
            break;
        }
    }
    if (itc == world->workers.end())
    {
        guiController->errorNoWorkers();
    }
}

void GameLogicController::handleCarrierReturn()
{
    std::vector<Carrier*>::iterator itc;
    for (itc = world->carriers.begin(); itc != world->carriers.end(); ++itc)
    {
        if ((*itc)->haveArrived())
        {
            (*itc)->myLuggage.setProduct(1,2);
            std::cout << "Czas wracac do domu" << std::endl;
            (*itc)->carrierThread.launch();
        }
        else if ((*itc)->haveReturned())
        {
            world->availableGoods = world->availableGoods + (*itc)->myLuggage;
            (*itc)->myLuggage.setProduct(5);
            guiController->checkCarrierGoods();
            (*itc)->setReturned(false);
        }
    }
}

void GameLogicController::handleGoodsProduction()
{
   GoodsBuilding* gBuilding;
   for(unsigned int i = 0; i < world->goodsBuildingIndex.size(); i++)
    {
        unsigned int index = world->goodsBuildingIndex.at(i);
        gBuilding = dynamic_cast<GoodsBuilding*> (world->buildings.at(index));
        if (gBuilding->getWorkersSize()>0)
        {
            gBuilding->checkProduction();
        }
    }
}
