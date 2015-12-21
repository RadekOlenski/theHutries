#include "building.h"
#include <cstdlib>
#include <sstream>

Building::Building(sf::RenderWindow *hutrieApplication, std::vector <Unit*> unitsFromGame, std::string pathName, int buildingType) : MapObject(hutrieApplication, unitsFromGame, pathName)
{
    this->buildingType = buildingType;
    needCarrier = false;
    needWorker = false;
}

void Building::placeOnMap()
{

    sprite.setPosition (objectUnits.at(0)->field.getPosition());
    occupyUnits();

}

int Building::checkHutries()
{
    int hutriesCounter = 0;
    std::vector <Unit*>::iterator it;
    for(it = objectUnits.begin(); it != objectUnits.end(); ++it)
    {
        hutriesCounter += (*it)->hutriesNumber();
    }
    return hutriesCounter;
}
