#include <sstream>
#include "forest.h"
#include "sound.h"
#include "world.h"
#include "gamebalance.h"

Forest::Forest(sf::RenderWindow* hutrieApplication, std::vector<Unit*> &unitsFromGame, std::string pathName)
        : Environment(hutrieApplication, unitsFromGame, pathName)
{
    title.text.setString("Forest:");

    sprite.setOrigin(20, 60);
    sprite.setScale(0.9, 1);

    sound.setVolume(GameBalance::sfxVolume);
    sound.openFromFile(Sound::trees);

    sprite.setPosition(objectUnits.at(0)->field.getPosition());
    occupyUnits();
}

void Forest::updateStatus()
{
    std::ostringstream desc;
    desc << "\n\nYou can build sawmill \n next to the forest";
    description.text.setString(desc.str());
}
