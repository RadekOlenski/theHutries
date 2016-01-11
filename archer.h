#ifndef THEHUTRIES_ARCHER_H
#define THEHUTRIES_ARCHER_H

#include "soldier.h"
#include "textures.h"

class Archer : public Soldier
{
public:
    Archer(sf::RenderWindow* hutrieApplication, const std::vector<Unit*> &unitsFromGame,
           const std::vector<Unit*> &unitsForMoving, std::string pathName = Textures::archerRight);

};


#endif //THEHUTRIES_ARCHER_H
