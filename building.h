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
        virtual void showStatus();
    private:
        int buildingType;
};

#endif // BUILDING_H
