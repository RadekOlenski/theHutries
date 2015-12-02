#include "building.h"
#include <cstdlib>
#include <sstream>

Building::Building(sf::RenderWindow *hutrieApplication, std::vector <Unit*> unitsFromGame, std::string pathName, int buildingType) : MapObject(hutrieApplication, unitsFromGame, pathName)
{
    this->buildingType = buildingType;
}

void Building::placeOnMap()
{

    sprite.setPosition (objectUnits.at(0)->field.getPosition());
    occupyUnits();

}

void Building::showStatus()
{
    std::ostringstream desc;
    desc << "Capacity: " << (rand()%5)+1 << " workers\nWorkers: " << (rand()%5)+1 << "\nProducts in store: " << (rand()%5)+1;
    description.text.setString (desc.str() );
}
