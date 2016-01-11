#include "environment.h"
#include "unit.h"
#include <sstream>

Environment::Environment(sf::RenderWindow *hutrieApplication, std::vector<Unit *> unitsFromGame, std::string pathName)
        : MapObject(hutrieApplication, unitsFromGame, pathName)
{
    sound.setVolume(50);
}
