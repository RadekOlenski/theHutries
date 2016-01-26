#include "building.h"
#include "sound.h"
#include "gamebalance.h"
#include <sstream>

Building::Building(sf::RenderWindow* hutrieApplication, std::vector<Unit*> unitsFromGame, std::string pathName)
        : MapObject(hutrieApplication, unitsFromGame, pathName)
{
    sound.openFromFile(Sound::construction);
    sound.setVolume(50);
    needCarrier = false;
    needWorker = false;
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