#ifndef SAWMILL_H
#define SAWMILL_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

#include "goodsbuilding.h"

class Sawmill : public GoodsBuilding
{
public:

    Sawmill(sf::RenderWindow* hutrieApplication, std::vector<Unit*> unitsFromGame);

    void createProduct();

    void updateStatus();

    float getElapsedConstructionTime() { return constructionClock.getElapsedTime().asSeconds(); };

    bool getBuildingConstructedFlag() { return buildingConstructed; };

    void setBuildingConstructedFlag(bool buildingConstructed) { this->buildingConstructed = buildingConstructed; };

    float getConstructionTime() { return constructionTime; };

    void setConstructedBuildingSound();
};

#endif // SAWMILL_H
