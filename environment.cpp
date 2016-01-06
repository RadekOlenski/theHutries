#include "environment.h"
#include "unit.h"
#include <sstream>

Environment::Environment(sf::RenderWindow *hutrieApplication, std::vector<Unit *> unitsFromGame, std::string pathName)
        : MapObject(hutrieApplication, unitsFromGame, pathName)
{

}

void Environment::updateStatus()
{
    std::ostringstream desc;
    desc << "You can build sawmill \n next to the forest";
    description.text.setString(desc.str());
}
