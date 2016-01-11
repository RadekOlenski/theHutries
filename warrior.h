#ifndef THEHUTRIES_WARRIOR_H
#define THEHUTRIES_WARRIOR_H


#include "soldier.h"

class Warrior : public Soldier
{

public:

    Warrior(sf::RenderWindow* hutrieApplication, const std::vector<Unit*> &unitsFromGame,
            const std::vector<Unit*> &unitsForMoving, std::string pathName = Textures::warriorRight);

};

#endif //THEHUTRIES_WARRIOR_H
