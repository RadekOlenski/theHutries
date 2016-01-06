//
// Created by Master on 06.01.2016.
//

#include <sstream>
#include "rocks.h"
#include "sound.h"
#include "unit.h"

Rocks::Rocks(sf::RenderWindow *hutrieApplication, const std::vector<Unit *> &unitsFromGame, const std::string &pathName)
        : Environment(hutrieApplication, unitsFromGame, pathName)
{
    title.text.setString("Rocks:");

    sprite.setOrigin(0, 0);
    sprite.setScale(0.6, 0.6);

    sound.setVolume(30);
    sound.openFromFile(Sound::rocks);

    sprite.setPosition(objectUnits.at(0)->field.getPosition());
    occupyUnits();
}

void Rocks::updateStatus()
{
    std::ostringstream desc;
    desc << "You can build stonecutterHut \n next to the rocks";
    description.text.setString(desc.str());
}