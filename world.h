#ifndef WORLD_H
#define WORLD_H

#include <SFML/Graphics.hpp>

#include <vector>

#include "unit.h"
#include "hutrie.h"
#include "carrier.h"
#include "worker.h"
#include "soldier.h"
#include "warrior.h"
#include "archer.h"
#include "building.h"
#include "environment.h"
#include "goods.h"

class World
{
public:

    World(sf::RenderWindow* hutrieApplication, int applicationWidth, int applicationHeight, int unitRectangleSize = 64);

    virtual ~World();

    std::vector<Unit*> units;
    std::vector<Hutrie*> hutries;
    std::vector<Carrier*> carriers;
    std::vector<Soldier*> soldiers;
    std::vector<Warrior*> warriors;
    std::vector<Archer*> archers;
    std::vector<Worker*> workers;
    std::vector<Building*> buildings;
    std::vector<Environment*> environment;
    std::vector<unsigned int> barracksIndex;
    std::vector<int> goodsBuildingIndex;
    std::vector<unsigned int> forestsIndex;
    std::vector<unsigned int> rocksIndex;
    std::vector<unsigned int> mountainsIndex;
    Goods availableGoods;
    Goods generalGoods;
    int availableSlots;
    Unit* lastClickedUnit;

    int getHorizontalUnitsCounter() { return horizontalUnitsCounter; }

    int getVerticalUnitsCounter() { return verticalUnitsCounter; }

    void prepareUnits(int unitIndex, int height, int width, std::vector<Unit*>* usedUnits);

    bool isFieldEmpty(std::vector<Unit*> &usedUnits);

    unsigned int findSelectedUnitIndex();

    void increaseAvailableSlots(int addedSlotsNumber);

    void createHutriesHall();

    void createEnvironment();

    void destroyElementsOfWorld();

private:

    void createForest();

    void createMountains();

    void createRocks();

    void markUnitsAround(int unitIndex, std::string environmentType);

    int horizontalUnitsCounter;
    int verticalUnitsCounter;
    sf::RenderWindow* hutrieApplication;
};

#endif // WORLD_H
