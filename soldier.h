#ifndef SOLDIER_H
#define SOLDIER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

#include "hutrie.h"
#include "textures.h"


class Soldier : public Hutrie
{
    public:

        Soldier(sf::RenderWindow *hutrieApplication, const std::vector <Unit*> unitsFromGame, std::vector<Unit*> unitsForMoving, std::string pathName);
        void moveHutrie();

    protected:

        std::vector <Unit*> unitsForMoving;
};

#endif // SOLDIER_H
