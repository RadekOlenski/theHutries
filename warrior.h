//
// Created by radek on 16.12.2015.
//

#ifndef THEHUTRIES_WARRIOR_H
#define THEHUTRIES_WARRIOR_H


#include "soldier.h"

class Warrior : public Soldier
{

public:
    Warrior(sf::RenderWindow *hutrieApplication, const std::vector<Unit*> &unitsFromGame, const char *const pathName,
            bool onBuilding);

    std::string pathName = "sprites/warrior/right.png";
    static const std::vector<Unit*> usedUnits;

};
#endif //THEHUTRIES_WARRIOR_H
