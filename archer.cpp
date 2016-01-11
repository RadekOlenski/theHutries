#include "archer.h"

Archer::Archer(sf::RenderWindow *hutrieApplication, const std::vector<Unit *> &unitsFromGame, const std::vector<Unit*> &unitsForMoving, std::string pathName)
                : Soldier(hutrieApplication, unitsFromGame, unitsForMoving, pathName)
{

}
