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
        Soldier(sf::RenderWindow *hutrieApplication, const std::vector <Unit*> unitsFromGame, const std::vector<Unit*> &unitsForMoving, std::string pathName);
        void moveHutrie();
    protected:
    private:
};

#endif // SOLDIER_H
