#include "environment.h"
#include <sstream>
#include <cstdlib>

Environment::Environment(sf::RenderWindow *hutrieApplication, std::vector <Unit*> unitsFromGame, std::string pathName) :  MapObject(hutrieApplication, unitsFromGame, pathName)
{
    title.text.setString("Forest:");

    sprite.setOrigin(20,60);
    sprite.setScale(0.9,1);

    sound.setVolume(30);
    sound.openFromFile("audio/trees.wav");

    sprite.setPosition (objectUnits.at(0)->field.getPosition());
    occupyUnits();

}

void Environment::showStatus()
{
    std::ostringstream desc;
    desc << "Trees left: "<< (rand()%40)+1;
    description.text.setString (desc.str() );
}
