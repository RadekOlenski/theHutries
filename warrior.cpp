//
// Created by radek on 16.12.2015.
//

#include "warrior.h"

Warrior::Warrior(sf::RenderWindow *hutrieApplication, const std::vector<Unit*> &unitsFromGame,
                 std::string pathName, bool onBuilding)  : Soldier(hutrieApplication, unitsFromGame, pathName, onBuilding)
{

};
