#ifndef HUTRIE_H
#define HUTRIE_H

#include <SFML/Graphics.hpp>

#include "mapobject.h"
#include "unit.h"

class Hutrie : public MapObject
{

    public:
        sf::Thread hutrieThread;
        Hutrie(sf::RenderWindow *hutrieApplication,Unit *unit);
        void moveHutrie();


};

#endif // HUTRIE_H
