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
    Building(sf::RenderWindow *hutrieApplication, std::vector <Unit*> unitsFromGame, std::string pathName = Textures::underConstruction);
    void placeOnMap();

    bool getNeedWorkerFlag() {return needWorker;}
    void setNeedWorker (bool need) { needWorker = need;}
    bool getNeedCarrierFlag() {return needCarrier;}
    void setNeedCarrier (bool need) { needCarrier = need;}
    int getCapacity() {return capacity;}
    void addCarrier(Carrier* carrier);
    Carrier* getCarrier();
    int getCarriersSize();
    int getDoorIndex() {return doorIndex;};

    virtual float getElapsedConstructionTime() {} ;
    virtual bool getBuildingConstructedFlag() {};
    virtual void setBuildingConstructedFlag(bool buildingConstructed) {};
    virtual float getConstructionTime() {};
    virtual void updateConstructionClock(int fulltime) {};

    void setCoustructedBuildingTexture();
    void setDescriptionTexture();
protected:

    int buildTime;
    Goods buildCost;
    int capacity;
    int doorIndex;

    std::vector <Carrier*> myCarriers;
    int checkHutries();
    bool needWorker;
    bool needCarrier;

    sf::Texture textureBasic;
private:
};

#endif // BUILDING_H
