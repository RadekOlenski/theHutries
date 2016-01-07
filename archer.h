//
// Created by Master on 04.01.2016.
//

#ifndef THEHUTRIES_ARCHER_H
#define THEHUTRIES_ARCHER_H

#include "soldier.h"
#include "textures.h"

class Archer : public Soldier
{
public:
    Archer(sf::RenderWindow *hutrieApplication, const std::vector<Unit*> &unitsFromGame, std::string pathName = Textures::archerDown);

    std::string pathName = "sprites/warrior/right.png";
    static const std::vector<Unit*> usedUnits;

};


#endif //THEHUTRIES_ARCHER_H
