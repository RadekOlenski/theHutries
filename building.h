#ifndef BUILDING_H
#define BUILDING_H

#include <SFML/Graphics.hpp>
#include <vector>

#include "mapobject.h"
#include "unit.h"


class Building : public MapObject
{
    public:
        Building(sf::RenderWindow *hutrieApplication, std::vector <Unit*> unitsFromGame);
        void placeOnMap();
};

#endif // BUILDING_H
