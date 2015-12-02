#ifndef HUTRIE_H
#define HUTRIE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

#include "mapobject.h"
#include "unit.h"

class Hutrie : public MapObject
{

    public:

        sf::Thread hutrieThread;

        Hutrie(sf::RenderWindow *hutrieApplication,std::vector <Unit*> unitsFromGame, std::string pathName);
        void moveHutrie();
        void showStatus();

    private:

        int strength;
        int agility;
        int endurance;
};

#endif // HUTRIE_H
