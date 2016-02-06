#include "building.h"
#include "sound.h"
#include "gamebalance.h"
#include <sstream>
#include <iostream>

Building::Building(sf::RenderWindow* hutrieApplication, std::vector<Unit*> unitsFromGame, std::string pathName)
        : MapObject(hutrieApplication, unitsFromGame, pathName),
          bringWoodButton(1024 + 40, 500, hutrieApplication, 180, 45, false),
          bringStoneButton(1024 + 40, 560, hutrieApplication, 150, 45, false),
          bringWoodText(1024 + 50, 500, 30, "Bring wood"),
          bringStoneText(1024 + 50, 560, 30, "Bring stone"),
          constructButton(1024 + 50, 510, hutrieApplication, 150, 60, false),
          constructText(1024 + 80, 510, 45, "Build!")

{
    sound.openFromFile(Sound::construction);
    sound.setVolume(50);
    needCarrier = false;
    needWorker = false;
    needContructionStone = false;
    needContructionWood = false;
    bringStoneButton.setActive(true);
    bringWoodButton.setActive(true);
}

void Building::placeOnMap()
{
    sprite.setPosition(objectUnits.at(0)->field.getPosition());
    occupyUnits();
}

int Building::checkHutries()
{
    int hutriesCounter = 0;
    std::vector<Unit*>::iterator it;
    for (it = objectUnits.begin(); it != objectUnits.end(); ++it)
    {
        hutriesCounter += (*it)->hutriesNumber();
    }
    return hutriesCounter;
}

void Building::addCarrier(Carrier* carrier)
{
    myCarriers.push_back(carrier);
}

void Building::removeCarrier()
{
    myCarriers.erase(myCarriers.begin());
}

Carrier* Building::getCarrier()
{
    Carrier* tempCarrier = myCarriers.back();
    myCarriers.pop_back();
    return tempCarrier;
}

int Building::getCarriersSize()
{
    return myCarriers.size();
}

void Building::setConstructedBuildingTexture()
{
    sprite.setTexture(textureBasic);
}

void Building::setDescriptionTexture()
{
    this->updateDescriptionTexture(textureBasic);
}

void Building::pauseConstructionClock()
{
    constructionTime -= constructionClock.getElapsedTime().asSeconds();
}

void Building::resumeConstructionClock()
{
    constructionClock.restart();
}

void Building::pauseTrainingClock()
{
    workerTrainingTime -= trainingClock.getElapsedTime().asSeconds();
    carrierTrainingTime -= trainingClock.getElapsedTime().asSeconds();
    warriorTrainingTime -= trainingClock.getElapsedTime().asSeconds();
    archerTrainingTime -= trainingClock.getElapsedTime().asSeconds();
}

void Building::resumeTrainingClock()
{
    trainingClock.restart();
}

void Building::resetTrainingTime()
{
    workerTrainingTime = GameBalance::workerTrainingTime;
    carrierTrainingTime = GameBalance::carrierTrainingTime;
    warriorTrainingTime = GameBalance::warriorTrainingTime;
    archerTrainingTime = GameBalance::archerTrainingTime;
}

void Building::updateConstructionClock()
{
    leftConstructionTime = constructionTime - constructionClock.getElapsedTime().asSeconds();
    if (leftConstructionTime <= 0.1) leftConstructionTime = 0;
}

void Building::updateTrainingClock(float trainingTime)
{
    leftTrainingTime = trainingTime - trainingClock.getElapsedTime().asSeconds();
    if (leftTrainingTime <= 0.1) leftTrainingTime = 0;
}

void Building::showConstructionButtons()
{
    if (!buildingConstructed)
    {
//        bringStoneButton.setActive(true);
//        bringWoodButton.setActive(true);
        if (bringStoneButton.isActive() && bringWoodButton.isActive())
        {
            hutrieApplication->draw(bringStoneButton.button);
            hutrieApplication->draw(bringWoodButton.button);
            hutrieApplication->draw(bringWoodText.text);
            hutrieApplication->draw(bringStoneText.text);
        }
        else
        {
            constructButton.setActive(true);
            hutrieApplication->draw(constructButton.button);
            hutrieApplication->draw(constructText.text);
        }

    }
}

void Building::deactivateConstructionButtons()
{
    bringStoneButton.setActive(false);
    bringWoodButton.setActive(false);
}

void Building::constructionButtonAction()
{
    if (bringStoneButton.checkBounds() && bringStoneButton.isActive())
    {
         std::cout << "Need Stone!" << std::endl;
         needContructionStone = true;
    }
    if (bringWoodButton.checkBounds() && bringWoodButton.isActive())
    {
          std::cout << "Need Wood!" << std::endl;
          needContructionWood = true;
    }
    if (constructButton.checkBounds() && constructButton.isActive())
    {
        std::cout << "I need worker!!!!";
        needWorker = true;
    }
}

bool Building::takeGoodsForConstruction(Goods* luggage)
{
    if (luggage->whichProduct() == 1 && constructionGoods.getWood() >= requiredForConstructionGoods.getWood()) return false;
    if (luggage->whichProduct() == 2 && constructionGoods.getStone() >= requiredForConstructionGoods.getStone()) return false;
    constructionGoods.setProduct(luggage->whichProduct(), 1);
    luggage->setProduct(luggage->whichProduct(), -1);
    updateStatus();
    return true;
}

void Building::restartConstructionClock()
{
    constructionClock.restart();
}

void Building::addWorker(Worker* worker)
{
    myWorkers.push_back(worker);
}

Worker* Building::getWorker()
{
    Worker* tempWorker = myWorkers.back();
    myWorkers.pop_back();
    return tempWorker;
}

int Building::getWorkersSize()
{
    return myWorkers.size();
}

bool Building::checkWorkersWorkingFlag()
{
    if ( myWorkers.size() > 0 )
    {
        for( auto it = myWorkers.begin(); it != myWorkers.end(); ++it )
        {
            if ((*it)->getWorkingFlag()) return true;
        }
    }
    return false;
}



