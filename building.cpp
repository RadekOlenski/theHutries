#include "building.h"
#include <cstdlib>

Building::Building(sf::RenderWindow *hutrieApplication, std::vector <Unit*> unitsFromGame) : MapObject(hutrieApplication, unitsFromGame, "sprites/buildings/sawmill.png",0.5,0.5)
{
    introduceYourSelf = "Hi! I'm Building";
    description.text.setString("It's me! Building!");
    switch(rand()%4)
    {
        case 0: texture.loadFromFile("sprites/buildings/sawmill.png"); break;
        case 1: texture.loadFromFile("sprites/buildings/barracks.png"); break;
        case 2: texture.loadFromFile("sprites/buildings/stone.png"); sprite.setScale(0.45,0.45); sprite.setOrigin(-10,-30); break;
        case 3: texture.loadFromFile("sprites/buildings/residence.png"); break;
    }
}

void Building::placeOnMap()
{

    sprite.setPosition (objectUnits.at(0)->field.getPosition());
    occupyUnits();

}
