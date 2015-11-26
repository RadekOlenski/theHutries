#ifndef MAPOBJECT_H
#define MAPOBJECT_H

#include <SFML/Graphics.hpp>
#include <string>

#include "unit.h"

class MapObject
{
    public:
        sf::RenderWindow *hutrieApplication;
        sf::Sprite sprite;
        sf::Texture texture;

        MapObject(sf::RenderWindow *hutrieApplication, Unit *unit, std::string pathName, float positionX = 0, float positionY = 0, float originX = 0, float originY = 0, float scaleX = 1, float scaleY = 1);
    protected:
        Unit *unit;
};

#endif // MAPOBJECT_H
