#ifndef CARRIER_H
#define CARRIER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

#include "hutrie.h"


class Carrier : public Hutrie
{
    public:
        Carrier(sf::RenderWindow *hutrieApplication, std::vector <Unit*> unitsFromGame, std::string pathName, bool onBuilding = true);
        void moveHutrie();
    private:
};

#endif // CARRIER_H
