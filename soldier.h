#ifndef SOLDIER_H
#define SOLDIER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

#include "hutrie.h"



class Soldier : public Hutrie
{
    public:
        Soldier(sf::RenderWindow *hutrieApplication, const std::vector <Unit*> unitsFromGame, std::string pathName, bool onBuilding = false);
        void moveHutrie();
    protected:
    private:
};

#endif // SOLDIER_H
