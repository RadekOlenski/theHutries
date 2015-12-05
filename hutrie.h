#ifndef HUTRIE_H
#define HUTRIE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

#include "mapobject.h"
//#include "unit.h"

//class MapObject;
class Unit;
class Hutrie : public MapObject
{

    public:

        sf::Thread hutrieThread;

        Hutrie(sf::RenderWindow *hutrieApplication,std::vector <Unit*> unitsFromGame, std::string pathName, bool onBuilding = true);
        void moveHutrie();
        void showStatus();

        bool isActive() {return active;}
        void setActive(bool active) {this->active = active;}

    protected:

        sf::Texture upTexture;
        sf::Texture downTexture;
        sf::Texture leftTexture;
        sf::Texture transTexture;

    private:

        int strength;
        int agility;
        int endurance;
        bool onBuilding;
        bool active;

};

#endif // HUTRIE_H
