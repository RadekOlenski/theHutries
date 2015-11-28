#ifndef WORLD_H
#define WORLD_H

#include <vector>

#include "unit.h"
#include "hutrie.h"
#include "building.h"

class World
{
    public:
        World(int applicationWidth, int applicationHeight, int unitRectangleSize = 64);
        std::vector <Unit*> units;
        std::vector <Hutrie*> hutries;
        std::vector <Building*> buildings;
        Unit* lastClickedUnit;
        int getHorizontalUnitsCounter() {return horizontalUnitsCounter; }
        int getVerticalUnitsCounter()   {return verticalUnitsCounter; }
    private:
        int horizontalUnitsCounter;
        int verticalUnitsCounter;
};

#endif // WORLD_H
