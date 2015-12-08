#include <cstdlib>
#include <iostream>

#include "world.h"
#include "hutrieshall.h"

World::World(sf::RenderWindow *hutrieApplication, int applicationWidth, int applicationHeight, int unitRectangleSize) : lastClickedUnit(NULL)
{
    this->hutrieApplication = hutrieApplication;

    /////////////////////////// HOW MANY RECTANGLES IN X AND Y DIRECTION//////////////////////////////////////////////////////

    horizontalUnitsCounter = applicationWidth  / unitRectangleSize;
    verticalUnitsCounter   = applicationHeight / unitRectangleSize;

    /////////////////////////// CREATING GRID OF UNITS//////////////////////////////////////////////////////

    sf::Vector2f position(0, 0);
    for (int j = 0; j < verticalUnitsCounter; j++)
    {
        for (int i = 0; i < horizontalUnitsCounter ; i++)
        {
            units.push_back(new Unit (position,i+(j*horizontalUnitsCounter)));
            position.x += unitRectangleSize;
        }
        position.y += unitRectangleSize;
        position.x = 0;
    }

    ////////////////////////////// ADDING TOWNHALL ///////////////////////////////////////////////////////////////////////////

    int unitIndex = 70;
    std::vector <Unit*> usedUnits;
    prepareUnits(unitIndex,3,3,&usedUnits);
    buildings.push_back(new HutriesHall(hutrieApplication, usedUnits,"sprites/buildings/castle.png", 0));
    buildings.at(buildings.size()-1)->placeOnMap();

    /////////////////////////// ADDING ENVIRONMENT /////////////////////////////////////////////////////////////////
//    do
//    {
//       usedUnits.clear();
//       unitIndex = (rand() % (horizontalUnitsCounter - 3)) + ((rand() % (verticalUnitsCounter)) * horizontalUnitsCounter);
//       prepareUnits(unitIndex,2,3,&usedUnits);
//    }
//    while(!(isFieldEmpty(usedUnits)));
//    environment.push_back(new Environment(hutrieApplication, usedUnits, "sprites/environment/trees.png"));

}

void World::prepareUnits(int unitIndex, int height, int width, std::vector <Unit*> *usedUnits )
{
    std::vector <int> field;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            field.push_back(unitIndex + j + (i*horizontalUnitsCounter));
        }
    }
    std::vector <int>::iterator it;
    for(it = field.begin(); it != field.end(); ++it)
    {
        usedUnits->push_back(units.at((unsigned int) *it));
    }
}

bool World::isFieldEmpty(std::vector <Unit*> &usedUnits)
{
    std::vector <Unit*>::iterator it;
    for(it = usedUnits.begin(); it != usedUnits.end(); ++it)
    {
        if(!((*it)->isEmpty())) return false;
    }
    return true;
}
