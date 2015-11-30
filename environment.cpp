#include "environment.h"

Environment::Environment(sf::RenderWindow *hutrieApplication, std::vector <Unit*> unitsFromGame) :  MapObject(hutrieApplication, unitsFromGame, "sprites/environment/trees.png" ,"audio/trees.wav",0.9,1,0,0,20,60)
{
    sound.setVolume(30);
    sprite.setPosition (objectUnits.at(0)->field.getPosition());
    occupyUnits();
    //introduceYourSelf = "Hi! I'm Environment";
    title.text.setString("Environment:");

}

void Environment::showStatus()
    {
        description.text.setString ("Trees left:" );
    }
