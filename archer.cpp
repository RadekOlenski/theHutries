//
// Created by Master on 04.01.2016.
//

#include "archer.h"

Archer::Archer(sf::RenderWindow *hutrieApplication, const std::vector<Unit *> &unitsFromGame, std::string pathName,
               bool onBuilding) : Soldier(hutrieApplication, unitsFromGame, pathName, onBuilding)
{

}