#include "world.h"

World::World(int applicationWidth, int applicationHeight, int unitRectangleSize) : lastClickedUnit(NULL)
{
    /////////////////////////// HOW MANY RECTANGLES IN X AND Y DIRECTION//////////////////////////////////////////////////////

    horizontalUnitsCounter = applicationWidth  / unitRectangleSize;
    verticalUnitsCounter   = applicationHeight / unitRectangleSize;

    /////////////////////////// CREATING GRID  OF UNITS//////////////////////////////////////////////////////

    sf::Vector2f position(0, 0);
    for (int j = 0; j < verticalUnitsCounter; j++)
    {
        for (int i = 0; i < horizontalUnitsCounter ; i++)
        {
            units.push_back(new Unit (position));
            position.x += unitRectangleSize;
        }
        position.y += unitRectangleSize;
        position.x = 0;
    }
}
