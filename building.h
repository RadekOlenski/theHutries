#ifndef BUILDING_H
#define BUILDING_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

#include "mapobject.h"
#include "unit.h"
#include "carrier.h"
#include "textures.h"

class Carrier;

class Building : public MapObject
{
public:
    Building(sf::RenderWindow* hutrieApplication, std::vector<Unit*> unitsFromGame,
             std::string pathName = Textures::underConstruction);

    void placeOnMap();

    bool getNeedWorkerFlag() { return needWorker; }

    void setNeedWorker(bool need) { needWorker = need; }

    bool getNeedCarrierFlag() { return needCarrier; }

    void setNeedCarrier(bool need) { needCarrier = need; }

    int getCapacity() { return capacity; }

    void addCarrier(Carrier* carrier);

    void removeCarrier();

    Carrier* getCarrier();

    int getCarriersSize();

    int getDoorIndex() { return doorIndex; };

    virtual float getElapsedConstructionTime() { };

    virtual bool getBuildingConstructedFlag() { };

    virtual void setBuildingConstructedFlag(bool buildingConstructed) { };

    virtual float getConstructionTime() { };

    virtual void updateConstructionClock();

    virtual void pauseConstructionClock();

    virtual void resumeConstructionClock();

    virtual void pauseTrainingClock();

    virtual void resumeTrainingClock();

    virtual void resetTrainingTime();

    virtual void updateTrainingClock(float trainingTime);

    void setConstructedBuildingTexture();

    virtual void setConstructedBuildingSound() { };

    void setDescriptionTexture();

    sf::Clock trainingClock;

protected:
    int capacity;
    int doorIndex;
    float constructionTime;
    float leftConstructionTime;
    bool buildingConstructed;

    std::vector<Carrier*> myCarriers;

    int checkHutries();
    bool needWorker;

    bool needCarrier;
    sf::Texture textureBasic;
    sf::Clock constructionClock;

    float workerTrainingTime;
    float carrierTrainingTime;
    float leftTrainingTime;

    float archerTrainingTime;
    float warriorTrainingTime;
};

#endif // BUILDING_H
