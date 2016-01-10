#ifndef THEHUTRIES_WARRIOR_H
#define THEHUTRIES_WARRIOR_H


#include "soldier.h"

class Warrior : public Soldier
{

public:
    Warrior(sf::RenderWindow *hutrieApplication, const std::vector<Unit*> &unitsFromGame, std::string pathName = Textures::warriorRight);

    static const std::vector<Unit*> usedUnits;
};
#endif //THEHUTRIES_WARRIOR_H
