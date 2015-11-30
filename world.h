#ifndef WORLD_H
#define WORLD_H

#include <vector>

#include "unit.h"
#include "hutrie.h"
#include "building.h"
#include "environment.h"

class World
{
    public:
        World(sf::RenderWindow *hutrieApplication, int applicationWidth, int applicationHeight, int unitRectangleSize = 64);
        std::vector <Unit*> units;
        std::vector <Hutrie*> hutries;
        std::vector <Building*> buildings;
        std::vector <Environment*> environment;
        Unit* lastClickedUnit;
        int getHorizontalUnitsCounter() {return horizontalUnitsCounter; }
        int getVerticalUnitsCounter()   {return verticalUnitsCounter; }
        void prepareUnits(int unitIndex, int height, int width, std::vector <Unit*> *usedUnits );
        bool isFieldEmpty(std::vector <Unit*> &usedUnits);
    private:
        int horizontalUnitsCounter;
        int verticalUnitsCounter;
        sf::RenderWindow *hutrieApplication;
};

#endif // WORLD_H
