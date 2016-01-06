//
// Created by Master on 06.01.2016.
//

#include <sstream>
#include "mountain.h"
#include "sound.h"
#include "unit.h"

Mountain::Mountain(sf::RenderWindow *hutrieApplication, const std::vector<Unit *> &unitsFromGame, const std::string &pathName)
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
    desc << "You can build goldmine \n on the mountain";
    description.text.setString(desc.str());
}