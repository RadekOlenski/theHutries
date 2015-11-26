#ifndef BUILDING_H
#define BUILDING_H

#include <SFML/Graphics.hpp>

#include "mapobject.h"

class Building : public MapObject
{
    public:
        Building(sf::RenderWindow *hutrieApplication, Unit *unit);
        void placeOnMap();
};

#endif // BUILDING_H
