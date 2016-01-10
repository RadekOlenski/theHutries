#include "warrior.h"

Warrior::Warrior(sf::RenderWindow *hutrieApplication, const std::vector<Unit*> &unitsFromGame,
                 std::string pathName)  : Soldier(hutrieApplication, unitsFromGame, pathName)
{
};
