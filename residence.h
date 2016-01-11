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

    Residence(sf::RenderWindow *hutrieApplication, std::vector <Unit*> unitsFromGame, int *worldSlots);
    void updateStatus();

    float getElapsedConstructionTime() { return constructionTimeClock.getElapsedTime().asSeconds(); };

    bool getBuildingConstructedFlag() { return buildingConstructed; };

    void setBuildingConstructedFlag(bool buildingConstructed) { this->buildingConstructed = buildingConstructed; };

    float getConstructionTime() { return constructionTime; };

    void updateConstructionClock(int fulltime);

private:

    bool buildingConstructed;
    unsigned int leftConstructionTime;
    const float constructionTime = GameBalance::residenceConstructionTime;
    sf::Clock constructionTimeClock;
    int *worldSlots;
};

#endif // RESIDENCE_H
