#ifndef STONECUTTER_H
#define STONECUTTER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

#include "goodsbuilding.h"

class StoneCutter : public GoodsBuilding
{
public:

    StoneCutter(sf::RenderWindow* hutrieApplication, std::vector<Unit*> unitsFromGame);

    void createProduct();

    void updateStatus();

    float getElapsedConstructionTime() { return constructionClock.getElapsedTime().asSeconds(); };

    bool getBuildingConstructedFlag() { return buildingConstructed; };

    void setBuildingConstructedFlag(bool buildingConstructed) { this->buildingConstructed = buildingConstructed; };

    float getConstructionTime() { return constructionTime; };

    void setConstructedBuildingSound();
};

#endif // STONECUTTER_H
