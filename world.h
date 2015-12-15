#ifndef WORLD_H
#define WORLD_H

#include <SFML/Graphics.hpp>
#include <vector>

#include "unit.h"
#include "hutrie.h"
#include "carrier.h"
#include "worker.h"
#include "soldier.h"
#include "building.h"
#include "environment.h"
#include "wood.h"

class World
{
    public:
        World(sf::RenderWindow *hutrieApplication, int applicationWidth, int applicationHeight, int unitRectangleSize = 64);
        std::vector <Unit*> units;
        std::vector <Hutrie*> hutries;
        std::vector <Carrier*> carriers;
        std::vector <Soldier*> soldiers;
        std::vector <Worker*> workers;
        std::vector <Building*> buildings;
        std::vector <Environment*> environment;
        std::vector <Wood*> woodWarehouse;
        int availableSlots;
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
