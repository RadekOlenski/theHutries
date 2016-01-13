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

GameLogicController::GameLogicController(World* world, sf::RenderWindow* hutrieApplication,
                                         ModelController* modelController, GUIController* guiController)
{
    this->world = world;
    this->hutrieApplication = hutrieApplication;
    this->modelController = modelController;
    this->guiController = guiController;
    hutriesHall = dynamic_cast <HutriesHall*>(world->buildings.at(0));
}

void GameLogicController::assignHutriesHall()
{
//    hutriesHall = dynamic_cast <HutriesHall*>(world->buildings.at(0));
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
    Goods worldGoods = world->availableGoods;
    switch (modelController->getChosenBuildingType())                                                                      //przekazuje wszystkie 4 unity do buldingu gdzie zostaja umieszczone w vectorze
    {
        case BuildingType::SAWMILL:
            if (worldGoods - GameBalance::sawmillCost >= 0)
            {
                createSawmill(usedUnits);
            }
            else
            {
                guiController->errorNotEnoughGoods();
            }
            break;
        case BuildingType::STONECUTTERHUT:
            if (worldGoods - GameBalance::stonecutterhutCost >= 0)
            {
                createStonecutterHut(usedUnits);
            }
            else
            {
                guiController->errorNotEnoughGoods();
            }
            break;
        case BuildingType::BARRACKS:
            if (worldGoods - GameBalance::barracksCost >= 0)
            {
                world->buildings.push_back(new Barracks(hutrieApplication, usedUnits));
                world->barracksIndex.push_back(world->buildings.size() - 1);
                world->availableGoods = world->availableGoods - GameBalance::barracksCost;
                guiController->updateGoodsNumber();
                Sound::ting();
            }
            else
            {
                guiController->errorNotEnoughGoods();
            }
            break;
        case BuildingType::RESIDENCE:
        {
            if (worldGoods - GameBalance::residenceCost >= 0)
            {
                world->increaseAvailableSlots(GameBalance::hutrieSlotsAddition);
                world->buildings.push_back(new Residence(hutrieApplication, usedUnits,
                                                         &(world->availableSlots)));
                world->availableGoods = world->availableGoods - GameBalance::residenceCost;
                guiController->updateGoodsNumber();
                Sound::ting();
            }
            else
            {
                guiController->errorNotEnoughGoods();
            }
            break;
        }
        case BuildingType::GOLDMINE:
            if (worldGoods - GameBalance::goldmineCost >= 0)
            {
                createGoldmine(usedUnits);
            }
            else
            {
                guiController->errorNotEnoughGoods();
            }
            break;
        case BuildingType::FARM:
            if (worldGoods - GameBalance::farmCost >= 0)
            {
                world->buildings.push_back(
                        new Farm(hutrieApplication, usedUnits));
                world->goodsBuildingIndex.push_back(world->buildings.size() - 1);
                world->availableGoods = world->availableGoods - GameBalance::farmCost;
                guiController->updateGoodsNumber();
                Sound::ting();
            }
            else
            {
                guiController->errorNotEnoughGoods();
            }
            break;
        default:
            break;
    }
    world->buildings.back()->placeOnMap();
}

void GameLogicController::constructBuilding()
{
    std::vector<Building*>::iterator it;
    for (it = world->buildings.begin() + 1; it != world->buildings.end(); ++it)
    {
        if (!(*it)->getBuildingConstructedFlag())
        {
            if ((*it)->getElapsedConstructionTime() >= (*it)->getConstructionTime())
            {
                (*it)->setBuildingConstructedFlag(true);
                (*it)->setConstructedBuildingTexture();
                (*it)->setDescriptionTexture();
                (*it)->setConstructedBuildingSound();
                (*it)->updateStatus();
            }
            else
            {
                (*it)->updateConstructionClock((int) (*it)->getConstructionTime());
                (*it)->updateStatus();
            }
        }
    }
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

//void GameLogicController::handleHutrieMoving()
//{
//    unsigned int unitIndex = modelController->getSelectedUnitIndex();
//    std::vector<Unit*> usedUnits;
//    usedUnits.push_back(world->units.at(unitIndex));
//    world->soldiers.push_back(new Warrior(hutrieApplication, usedUnits, world->units));
//    world->hutries.push_back(world->soldiers.back());
//    world->hutries.back()->hutrieThread.launch();                    //tworzy watek w ktorym porusza sie Hutrie
//}

void GameLogicController::handleHutriesCreation()
{
    GameLogicController::handleWorkerCreation();
    GameLogicController::handleCarrierCreation();
    GameLogicController::handleSoldierCreation();
}

void GameLogicController::handleWorkerCreation()
{
    if (hutriesHall->getTrainingWorkerFlag())
    {
        Goods worldGoods = world->availableGoods;
        if (worldGoods - GameBalance::workerCost >= 0)
        {
             if (hutriesHall->getFirstCheckFlag())
             {
                world->availableGoods = world->availableGoods - GameBalance::workerCost;
                guiController->updateGoodsNumber();
                world->availableSlots--;
                hutriesHall->setFirstCheckFlag(false);
                hutriesHall->setEnoughGoodsForCreation(true);
             }
        }
        else if (!hutriesHall->getEnoughGoodsForCreation())
        {
            guiController->errorNotEnoughGoods();
            hutriesHall->setTrainingWorkerFlag(false);
            hutriesHall->updateStatus();
            return;
        }
        if (hutriesHall->getEnoughGoodsForCreation() && hutriesHall->trainingClock.getElapsedTime().asSeconds() >= hutriesHall->getWorkerTrainingTime())
        {
            hutriesHall->setEnoughGoodsForCreation(false);
            hutriesHall->setTrainingWorkerFlag(false);
            std::string objectType = "worker";
            unsigned int unitIndex = (unsigned int) hutriesHall->getUnitIndex(6);
            createHutrie(objectType, unitIndex);
            hutriesHall->updateStatus();
            hutriesHall->setFirstCheckFlag(true);
        }
        else
        {
            hutriesHall->updateClock(hutriesHall->getWorkerTrainingTime());
            hutriesHall->updateStatus();
        }
    }
    else if (!hutriesHall->getTrainingCarrierFlag())
        hutriesHall->trainingClock.restart();
    if (hutriesHall->getMakeWorkerFlag())
    {
        if (hutriesHall->getTrainingCarrierFlag())
        {
            guiController->errorAlreadyCreatingCarrier();
            hutriesHall->setMakeWorkerFlag(false);
            return;
        }
        if (world->availableSlots == 0)
        {
            guiController->errorNoSlots();
            hutriesHall->setMakeWorkerFlag(false);
            return;
        }
        if (hutriesHall->getTrainingWorkerFlag())
        {
            guiController->errorAlreadyCreatingWorker();
            hutriesHall->setMakeWorkerFlag(false);
            return;
        }
        else hutriesHall->setTrainingWorkerFlag(true);
        hutriesHall->setMakeWorkerFlag(false);
    }
}

void GameLogicController::handleCarrierCreation()
{
    if (hutriesHall->getTrainingCarrierFlag())
    {

        Goods worldGoods = world->availableGoods;
        if (worldGoods - GameBalance::carrierCost >= 0)
        {
            if (hutriesHall->getFirstCheckFlag())
            {
                world->availableGoods = world->availableGoods - GameBalance::carrierCost;
                guiController->updateGoodsNumber();
                world->availableSlots--;
                hutriesHall->setFirstCheckFlag(false);
                hutriesHall->setEnoughGoodsForCreation(true);
            }
        }
        else if (!hutriesHall->getEnoughGoodsForCreation())
        {
                guiController->errorNotEnoughGoods();
                hutriesHall->setTrainingCarrierFlag(false);
                hutriesHall->updateStatus();
                return;
        }
        if (hutriesHall->getEnoughGoodsForCreation() && hutriesHall->trainingClock.getElapsedTime().asSeconds() >= hutriesHall->getCarrierTrainingTime())
        {
            hutriesHall->setEnoughGoodsForCreation(false);
            hutriesHall->setTrainingCarrierFlag(false);
            std::string objectType = "carrier";
            unsigned int unitIndex = (unsigned int) hutriesHall->getUnitIndex(6);
            createHutrie(objectType, unitIndex);
            hutriesHall->updateStatus();
            hutriesHall->setFirstCheckFlag(true);
        }
        else
        {
            hutriesHall->updateClock(hutriesHall->getCarrierTrainingTime());
            hutriesHall->updateStatus();
        }
    }
    else if (!hutriesHall->getTrainingWorkerFlag())
        hutriesHall->trainingClock.restart();
    if (hutriesHall->getMakeCarrierFlag())
    {
        if (hutriesHall->getTrainingWorkerFlag())
        {
            guiController->errorAlreadyCreatingWorker();
            hutriesHall->setMakeCarrierFlag(false);
            return;
        }
        if (world->availableSlots == 0)
        {
            guiController->errorNoSlots();
            hutriesHall->setMakeCarrierFlag(false);
            return;
        }
        if (hutriesHall->getTrainingCarrierFlag())
        {
            guiController->errorAlreadyCreatingCarrier();
            hutriesHall->setMakeCarrierFlag(false);
            return;
        }
        else hutriesHall->setTrainingCarrierFlag(true);
        hutriesHall->setMakeCarrierFlag(false);
    }
}

void GameLogicController::handleSoldierCreation()
{
    for (unsigned int i = 0; i < world->barracksIndex.size(); i++)
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
        Goods worldGoods = world->availableGoods;
        if (worldGoods - GameBalance::warriorCost >= 0)
        {
            if (barracks->getFirstCheckFlag())
            {
                world->availableGoods = world->availableGoods - GameBalance::warriorCost;
                guiController->updateGoodsNumber();
                world->availableSlots--;
                barracks->setFirstCheckFlag(false);
                barracks->setEnoughGoodsForCreation(true);
            }
        }
        else if (!barracks->getEnoughGoodsForCreation())
        {
            guiController->errorNotEnoughGoods();
            barracks->setTrainingWarriorFlag(false);
            barracks->updateStatus();
            return;
        }
        if (barracks->getEnoughGoodsForCreation() && barracks->trainingClock.getElapsedTime().asSeconds() >= barracks->getWarriorTrainingTime())
        {
            barracks->setEnoughGoodsForCreation(false);
            barracks->setTrainingWarriorFlag(false);
            std::string objectType = "warrior";
            createHutrie(objectType, unitIndex);
            barracks->updateStatus();
            barracks->setFirstCheckFlag(true);
        }
        else
        {
            barracks->updateTrainingClock(barracks->getWarriorTrainingTime());
            barracks->updateStatus();
        }
    }
    else if (!barracks->getTrainingArcherFlag())
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
        barracks->updateStatus();
        barracks->setMakeWarriorFlag(false);
    }
}

void GameLogicController::handleArcherCreation(unsigned int unitIndex)
{
    if (barracks->getTrainingArcherFlag())
    {
        Goods worldGoods = world->availableGoods;
        if (worldGoods - GameBalance::archerCost >= 0)
        {
            if (barracks->getFirstCheckFlag())
            {
            world->availableGoods = world->availableGoods - GameBalance::archerCost;
            guiController->updateGoodsNumber();
            world->availableSlots--;
            barracks->setFirstCheckFlag(false);
            barracks->setEnoughGoodsForCreation(true);
            }
        }
        else if(!barracks->getEnoughGoodsForCreation())
        {
            guiController->errorNotEnoughGoods();
            barracks->setTrainingArcherFlag(false);
            barracks->updateStatus();
            return;
        }
        if (barracks->getEnoughGoodsForCreation() && barracks->trainingClock.getElapsedTime().asSeconds() >= barracks->getArcherTrainingTime())
        {
            barracks->setEnoughGoodsForCreation(false);
            barracks->setTrainingArcherFlag(false);
            std::string objectType = "archer";
            createHutrie(objectType, unitIndex);
            barracks->updateStatus();
            barracks->setFirstCheckFlag(true);
        }
        else
        {
            barracks->updateTrainingClock(barracks->getArcherTrainingTime());
            barracks->updateStatus();
        }
    }
    else if (!barracks->getTrainingWarriorFlag())
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
        else
        {
            barracks->setTrainingArcherFlag(true);
            barracks->updateStatus();
        }
        barracks->setMakeArcherFlag(false);
    }
}

void GameLogicController::createHutrie(std::string objectType, unsigned int unitIndex)
{
    std::vector<Unit*> usedUnits;
    usedUnits.push_back(world->units.at(unitIndex));
    if (objectType == "carrier")
    {
        std::cout << "Utworze dla ciebie Carriera!" << std::endl;
        world->carriers.push_back(new Carrier(hutrieApplication, usedUnits));
        world->hutries.push_back(world->carriers.back());
        world->units.at(unitIndex)->addHutrie(world->hutries.back());
        world->carriers.back()->setBuilding(hutriesHall);
    }
    else if (objectType == "worker")
    {
        std::cout << "Utworze dla ciebie Workera!" << std::endl;
        world->workers.push_back(new Worker(hutrieApplication, usedUnits));
        world->hutries.push_back(world->workers.back());
        world->units.at(unitIndex)->addHutrie(world->hutries.back());
    }
    else if (objectType == "warrior")
    {
        std::cout << "Utworze dla ciebie Warriora!" << std::endl;
        world->warriors.push_back(new Warrior(hutrieApplication, usedUnits, world->units));
        world->hutries.push_back(world->warriors.back());
        world->soldiers.push_back(world->warriors.back());
        world->units.at(unitIndex)->addHutrie(world->hutries.back());
        world->warriors.back()->sprite.setPosition(world->units.at(unitIndex + 1)->field.getPosition().x,
                                                   world->units.at(unitIndex + 1)->field.getPosition().y);
        world->warriors.back()->hutrieThread.launch();
    }
    else if (objectType == "archer")
    {
        std::cout << "Utworze dla ciebie Archera!" << std::endl;
        world->archers.push_back(new Archer(hutrieApplication, usedUnits, world->units));
        world->hutries.push_back(world->archers.back());
        world->soldiers.push_back(world->archers.back());
        world->units.at(unitIndex)->addHutrie(world->hutries.back());
        world->archers.back()->sprite.setPosition(world->units.at(unitIndex + 1)->field.getPosition().x,
                                                  world->units.at(unitIndex + 1)->field.getPosition().y);
        world->archers.back()->hutrieThread.launch();
    }
}

void GameLogicController::handleGUIButtonsAction()
{
    guiController->handleGUIButtonsActions();
}

void GameLogicController::handleMenuButtonsAction()
{
    guiController->handleMenuButtonsActions();
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
    std::vector<Carrier*>::iterator itc;
    callCarrier(itc, it);
    (*it)->setNeedCarrier(false);
}

void GameLogicController::callCarrier(std::vector<Carrier*>::iterator itc, std::vector<Building*>::iterator it)
{
    for (itc = world->carriers.begin(); itc != world->carriers.end(); ++itc)
    {
        if (!((*itc)->isBusy()))
        {
            std::cout << "Nie jestem zajety! Ruszam po zasoby!" << std::endl;
            unsigned int carrierIndex = (unsigned int) std::distance(world->carriers.begin(), itc);
            world->carriers.at(carrierIndex)->reconnectUnits((*it)->getObjectUnits());
            world->carriers.at(carrierIndex)->hutrieThread.launch();          //tworzy watek w ktorym porusza sie Hutrie
            //world->units.at(unitIndex)->addHutrie(world->carriers.at(carrierIndex));
            (*it)->addCarrier(world->carriers.at(carrierIndex));
            world->carriers.at(carrierIndex)->setBuilding(*it);
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
    if (gBuilding->getWorkersSize() <
        (*it)->getCapacity())       //jesli aktualna ilosc w budynku mniejsza od pojemnosci
    {
        std::vector<Worker*>::iterator itc;
        callWorker(itc, gBuilding);
    }
    else
    {
        guiController->errorToMuchWorkers();
    }
    (*it)->setNeedWorker(false);
}

void GameLogicController::callWorker(std::vector<Worker*>::iterator itc, GoodsBuilding* gBuilding)
{
    for (itc = world->workers.begin(); itc != world->workers.end(); ++itc)
    {
        if (!((*itc)->isBusy()))
        {
            (*itc)->setBusy(true);
            std::cout << "Nie jestem zajety! Ruszam do pracy!" << std::endl;
            unsigned int workerIndex = (unsigned int) std::distance(world->workers.begin(), itc);
            world->workers.at(workerIndex)->reconnectUnits(gBuilding->getObjectUnits());
            world->workers.at(
                    workerIndex)->hutrieThread.launch();             //uruchamia watek w ktorym porusza sie Hutrie
            //world->units.at(unitIndex)->addHutrie(world->workers.at(workerIndex));
            (*itc)->productionClock.restart();
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
            GoodsBuilding* gBuilding = dynamic_cast<GoodsBuilding*>((*itc)->getBuilding());
            if (!(gBuilding->myProducts.isEmpty()))
            {
                gBuilding->giveProduct(&((*itc)->myLuggage));
                gBuilding->updateStatus();
            }
            else
            {
                guiController->errorNoProductsToCarry();
            }
            std::cout << "Czas wracac do domu" << std::endl;
            (*itc)->setBuilding(hutriesHall);
            (*itc)->reconnectUnits(hutriesHall->getObjectUnits());
            (*itc)->carrierThread.launch();
            gBuilding->removeCarrier();
            gBuilding->updateStatus();
        }
        else if ((*itc)->haveReturned())
        {
            world->availableGoods = world->availableGoods + (*itc)->myLuggage;
            hutriesHall->updateStatus();
            (*itc)->myLuggage.setProduct(5);
            guiController->updateGoodsNumber();
            (*itc)->setReturned(false);
        }
    }
}

void GameLogicController::handleGoodsProduction()
{
    GoodsBuilding* gBuilding;
    for (unsigned int i = 0; i < world->goodsBuildingIndex.size(); i++)
    {
        unsigned int index = (unsigned int) world->goodsBuildingIndex.at(i);
        gBuilding = dynamic_cast<GoodsBuilding*> (world->buildings.at(index));
        if (gBuilding->getWorkersSize() > 0)
        {
            gBuilding->checkProduction();
        }
    }
}

void GameLogicController::createSawmill(std::vector<Unit*> usedUnits)
{
    std::vector<unsigned int>::iterator it;
    int selectedUnit = modelController->getSelectedUnitIndex();
    for (it = world->forestsIndex.begin(); it < world->forestsIndex.end(); ++it)
    {
        for (int forestUnit = 0; forestUnit < 6; forestUnit++)
        {
            int currentForestUnit = world->environment.at(*it)->getUnitIndex(forestUnit);
            for (int j = selectedUnit - 17; j <= selectedUnit + 31; j += 16)
            {
                if (j == currentForestUnit)
                {
                    world->buildings.push_back(new Sawmill(hutrieApplication, usedUnits));
                    world->goodsBuildingIndex.push_back(world->buildings.size() - 1);
                    world->availableGoods = world->availableGoods - GameBalance::sawmillCost;
                    guiController->updateGoodsNumber();
                    Sound::ting();
                    return;
                }
                else if (j + 3 == currentForestUnit)
                {
                    world->buildings.push_back(new Sawmill(hutrieApplication, usedUnits));
                    world->goodsBuildingIndex.push_back(world->buildings.size() - 1);
                    world->availableGoods = world->availableGoods - GameBalance::sawmillCost;
                    guiController->updateGoodsNumber();
                    Sound::ting();
                    return;
                }
            }
        }
    }
    guiController->errorMustBuildNearForest();
}

void GameLogicController::createStonecutterHut(std::vector<Unit*> usedUnits)
{
    std::vector<unsigned int>::iterator it;
    int selectedUnit = modelController->getSelectedUnitIndex();
    for (it = world->rocksIndex.begin(); it < world->rocksIndex.end(); ++it)
    {
        for (int rocksUnit = 0; rocksUnit < 6; rocksUnit++)
        {
            int currentRocksUnit = world->environment.at(*it)->getUnitIndex(rocksUnit);
            for (int j = selectedUnit - 17; j <= selectedUnit + 31; j += 16)
            {
                if (j == currentRocksUnit)
                {
                    world->buildings.push_back(new StoneCutter(hutrieApplication, usedUnits));
                    world->goodsBuildingIndex.push_back(world->buildings.size() - 1);
                    world->availableGoods = world->availableGoods - GameBalance::stonecutterhutCost;
                    guiController->updateGoodsNumber();
                    Sound::ting();
                    return;
                }
                else if (j + 3 == currentRocksUnit)
                {
                    world->buildings.push_back(new StoneCutter(hutrieApplication, usedUnits));
                    world->goodsBuildingIndex.push_back(world->buildings.size() - 1);
                    world->availableGoods = world->availableGoods - GameBalance::stonecutterhutCost;
                    guiController->updateGoodsNumber();
                    Sound::ting();
                    return;
                }
            }
        }
    }
    guiController->errorMustBuildNearRocks();
}

void GameLogicController::createGoldmine(std::vector<Unit*> usedUnits)
{
    std::vector<unsigned int>::iterator it;
    int selectedUnit = modelController->getSelectedUnitIndex();
    for (it = world->mountainsIndex.begin(); it < world->mountainsIndex.end(); ++it)
    {
        for (int mountainUnit = 0; mountainUnit < 4; mountainUnit++)
        {
            int currentMountainUnit = world->environment.at(*it)->getUnitIndex(mountainUnit);
            for (int j = selectedUnit - 17; j <= selectedUnit + 31; j += 16)
            {
                if (j == currentMountainUnit)
                {
                    world->buildings.push_back(
                            new Goldmine(hutrieApplication, usedUnits));
                    world->goodsBuildingIndex.push_back(world->buildings.size() - 1);
                    world->availableGoods = world->availableGoods - GameBalance::goldmineCost;
                    guiController->updateGoodsNumber();
                    Sound::ting();
                    return;
                }
                else if (j + 3 == currentMountainUnit)
                {
                    world->buildings.push_back(
                            new Goldmine(hutrieApplication, usedUnits));
                    world->goodsBuildingIndex.push_back(world->buildings.size() - 1);
                    world->availableGoods = world->availableGoods - GameBalance::goldmineCost;
                    guiController->updateGoodsNumber();
                    Sound::ting();
                    return;
                }
            }
        }
    }
    guiController->errorMustBuildOnMountain();

}
