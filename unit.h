#ifndef UNIT_H
#define UNIT_H

#include <SFML/Graphics.hpp>

//#include "mapobject.h"


class Unit
{
    public:
        sf::RectangleShape field;
//        MapObject *mapObject;
        bool isEmpty() {return emptiness;}
        void setEmpty(bool emptiness) {this->emptiness = emptiness;}

        Unit(sf::Vector2f position);
    private:
        bool emptiness;

};

#endif // UNIT_H
