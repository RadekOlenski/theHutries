#include <sstream>
#include "mountain.h"
#include "sound.h"
#include "unit.h"
#include "textures.h"

Mountain::Mountain(sf::RenderWindow *hutrieApplication, const std::vector<Unit *> &unitsFromGame, std::string pathName)
        : Environment(hutrieApplication, unitsFromGame, pathName)
{
    title.text.setString("Mountain:");

    sprite.setOrigin(0, 20);
    sprite.setScale(0.50, 0.50);

    sound.setVolume(30);
    sound.openFromFile(Sound::mountain);

    sprite.setPosition(objectUnits.at(0)->field.getPosition());
    occupyUnits();
}

void Mountain::updateStatus()
{
    std::ostringstream desc;
    desc << "\n\nYou can build goldmine \n on the mountain";
    description.text.setString(desc.str());
}
