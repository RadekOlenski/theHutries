#include "building.h"
#include <cstdlib>
#include <sstream>

Building::Building(sf::RenderWindow*hutrieApplication, std::vector<Unit*> unitsFromGame, std::string pathName)
        : MapObject(hutrieApplication, unitsFromGame, pathName)
{
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

void Building::setCoustructedBuildingTexture()
{
    sprite.setTexture(textureBasic);
}

void Building::setDescriptionTexture()
{
    this->updateDescriptionTexture(textureBasic);
}
