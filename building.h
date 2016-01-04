#ifndef BUILDING_H
#define BUILDING_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

#include "mapobject.h"
#include "unit.h"


class Building : public MapObject
{
public:
    Building(sf::RenderWindow *hutrieApplication, std::vector <Unit*> unitsFromGame, std::string pathName);
    void placeOnMap();

    bool getNeedWorkerFlag() {return needWorker;}
    void setNeedWorker (bool need) { needWorker = need;}
    bool getNeedCarrierFlag() {return needCarrier;}
    void setNeedCarrier (bool need) { needCarrier = need;}
    int getCapacity() {return capacity;}

protected:
    int buildTime;
    int buildCost;
    int capacity;

    int checkHutries();
    bool needWorker;
    bool needCarrier;
private:
};

#endif // BUILDING_H
