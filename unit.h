#ifndef UNIT_H
#define UNIT_H

#include <SFML/Graphics.hpp>

#include "mapobject.h"

class MapObject;
class Unit
{
    public:
        sf::RectangleShape field;
        void setMapObject (MapObject *mapObject) {this->mapObject = mapObject;}
        MapObject* getMapObject() {return this->mapObject;}
        bool isEmpty() {return emptiness;}
        void setEmpty(bool emptiness) {this->emptiness = emptiness;}

        Unit(sf::Vector2f position);
    private:
        bool emptiness;
        MapObject *mapObject;

};

#endif // UNIT_H