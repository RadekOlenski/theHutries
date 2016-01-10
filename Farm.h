#ifndef THEHUTRIES_FARM_H
#define THEHUTRIES_FARM_H

#include "SFML/graphics.hpp"
#include "goodsbuilding.h"

class Farm : public GoodsBuilding
{

public:
    Farm(sf::RenderWindow *hutrieApplication, const std::vector<Unit *> &unitsFromGame);

    void createProduct();

    void updateStatus();

    float getElapsedConstructionTime() { return constructionTimeClock.getElapsedTime().asSeconds(); };

    bool getBuildingConstructedFlag() { return buildingConstructed; };

    void setBuildingConstructedFlag(bool buildingConstructed) { this->buildingConstructed = buildingConstructed; };

    float getConstructionTime() { return constructionTime; };

    void updateConstructionClock(int fulltime);

private:

    bool buildingConstructed;
    unsigned int leftConstructionTime;
    const float constructionTime = GameBalance::farmConstructionTime;

    sf::Clock constructionTimeClock;
};

#endif //THEHUTRIES_FARM_H
