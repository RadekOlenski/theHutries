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
        Building(sf::RenderWindow *hutrieApplication, std::vector <Unit*> unitsFromGame);
        Building(sf::RenderWindow *hutrieApplication, std::vector <Unit*> unitsFromGame, std::string pathName, std::string soundPathName);
        void placeOnMap();
};

#endif // BUILDING_H
