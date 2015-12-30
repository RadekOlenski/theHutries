#include "environment.h"
#include "unit.h"
#include "sound.h"
#include <sstream>
#include <cstdlib>


Environment::Environment(sf::RenderWindow *hutrieApplication, std::vector <Unit*> unitsFromGame, std::string pathName) :  MapObject(hutrieApplication, unitsFromGame, pathName)
{
    title.text.setString("Forest:");

    sprite.setOrigin(20,60);
    sprite.setScale(0.9,1);

    sound.setVolume(30);
    sound.openFromFile(Sound::trees);

    sprite.setPosition (objectUnits.at(0)->field.getPosition());
    occupyUnits();

}

void Environment::updateStatus()
{
    std::ostringstream desc;
    desc << "Trees left: "<< (rand()%40)+1;
    description.text.setString (desc.str() );
}
