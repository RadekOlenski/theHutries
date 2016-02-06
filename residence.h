#ifndef RESIDENCE_H
#define RESIDENCE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

#include "building.h"
#include "gamebalance.h"


class Residence : public Building
{
public:

    Residence(sf::RenderWindow* hutrieApplication, std::vector<Unit*> unitsFromGame, int* worldSlots);

    void updateStatus();

    float getElapsedConstructionTime() { return constructionClock.getElapsedTime().asSeconds(); };

    bool getBuildingConstructedFlag() { return buildingConstructed; };

    void setBuildingConstructedFlag(bool buildingConstructed) { this->buildingConstructed = buildingConstructed; };

    float getConstructionTime() { return constructionTime; };

    void updateConstructionClock();

    void setConstructedBuildingSound();

//    void setConstructedBuildingTexture();

private:
    int* worldSlots;
};

#endif // RESIDENCE_H
