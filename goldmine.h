//
// Created by Master on 08.12.2015.
//

#ifndef THEHUTRIES_GOLDMINE_H
#define THEHUTRIES_GOLDMINE_H

#include <SFML/Graphics.hpp>
#include "goodsbuilding.h"


class Goldmine : public GoodsBuilding
{

public:
    Goldmine(sf::RenderWindow *hutrieApplication, const std::vector<Unit *> &unitsFromGame);
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
    const float constructionTime = GameBalance::stonecutterHutConstructionTime;
    sf::Clock constructionTimeClock;
};


#endif //THEHUTRIES_GOLDMINE_H
