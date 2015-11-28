#ifndef HUTRIE_H
#define HUTRIE_H

#include <SFML/Graphics.hpp>
#include <vector>

#include "mapobject.h"
#include "unit.h"

class Hutrie : public MapObject
{

    public:
        sf::Thread hutrieThread;
        Hutrie(sf::RenderWindow *hutrieApplication,std::vector <Unit*> unitsFromGame);
        void moveHutrie();


};

#endif // HUTRIE_H
