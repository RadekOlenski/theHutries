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
        Building(sf::RenderWindow *hutrieApplication, std::vector <Unit*> unitsFromGame, std::string pathName, int buildingType = 1);
        void placeOnMap();
        void setType(int type) {buildingType = type;}
        bool getNeedWorker() {return needWorker;}
        void setNeedWorker (bool need) { needWorker = need;}
        bool getNeedCarrier() {return needCarrier;}
        void setNeedCarrier (bool need) { needCarrier = need;}
        int getCapacity() {return capacity;}
        int getHutriesCounter() {return hutriesCounter;}
        void setHutriesCounter(int counter) {hutriesCounter = counter;}

    protected:
        int buildTime;
        int buildCost;
        int capacity;
        int hutriesCounter;
        int checkHutries();
        bool needWorker;
        bool needCarrier;
    private:
        int buildingType;
};

#endif // BUILDING_H
