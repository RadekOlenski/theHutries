//
// Created by Master on 05.01.2016.
//

#include "forest.h"
#include "sound.h"
#include "unit.h"

Forest::Forest(sf::RenderWindow *hutrieApplication, std::vector<Unit *> &unitsFromGame, std::string pathName)
        : Environment(hutrieApplication, unitsFromGame, pathName)
{
    title.text.setString("Forest:");

    sprite.setOrigin(20, 60);
    sprite.setScale(0.9, 1);

    sound.setVolume(30);
    sound.openFromFile(Sound::trees);

    sprite.setPosition(objectUnits.at(0)->field.getPosition());
    occupyUnits();
}
