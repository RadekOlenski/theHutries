#ifndef MAPOBJECT_H
#define MAPOBJECT_H

#include "unit.h"
#include "guitext.h"

#include <SFML/Graphics.hpp>
#include <string>


class Unit;
class MapObject
{
    public:
        sf::RenderWindow *hutrieApplication;
        sf::Sprite sprite;
        sf::Texture texture;
        GUIText description;
        std::string introduceYourSelf;

        bool isActive() {return active;}
        void setActive(bool active) {this->active = active;}
        MapObject (sf::RenderWindow *hutrieApplication, Unit *unit, std::string pathName, float scaleX = 1, float scaleY = 1, float positionX = 0, float positionY = 0, float originX = 0, float originY = 0);

    protected:
        Unit *unit;
        bool active;
};

#endif // MAPOBJECT_H
