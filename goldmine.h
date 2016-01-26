#ifndef THEHUTRIES_GOLDMINE_H
#define THEHUTRIES_GOLDMINE_H

#include <SFML/Graphics.hpp>
#include "goodsbuilding.h"


class Goldmine : public GoodsBuilding
{

public:

    Goldmine(sf::RenderWindow* hutrieApplication, const std::vector<Unit*> &unitsFromGame);

    void createProduct();

    void updateStatus();

    float getElapsedConstructionTime() { return constructionClock.getElapsedTime().asSeconds(); };

    bool getBuildingConstructedFlag() { return buildingConstructed; };

    void setBuildingConstructedFlag(bool buildingConstructed) { this->buildingConstructed = buildingConstructed; };

    float getConstructionTime() { return constructionTime; };

    void setConstructedBuildingSound();
};


#endif //THEHUTRIES_GOLDMINE_H
