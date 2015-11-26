#ifndef BUILDING_H
#define BUILDING_H

#include <SFML/Graphics.hpp>
#include <vector>

#include "mapobject.h"
#include "unit.h"

class Building : public MapObject
{
    public:
        Building(sf::RenderWindow *hutrieApplication, Unit *unit0, Unit *unit1, Unit *unit2, Unit *unit3);
        void placeOnMap();
    private:
        std::vector <Unit*> buildingField;
};

#endif // BUILDING_H
