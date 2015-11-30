#include "building.h"
#include <cstdlib>

Building::Building(sf::RenderWindow *hutrieApplication, std::vector <Unit*> unitsFromGame) : MapObject(hutrieApplication, unitsFromGame, "sprites/buildings/sawmill.png", "audio/sawShort.wav", 0.5,0.5)
{
    introduceYourSelf = "Hi! I'm Building";
    description.text.setString("It's me! Building!");

    ///////////////////////////CHOOSING RANDOM BUILDING///////////////////////////////////////////////////////

    switch(rand()%4)
    {
        case 0: texture.loadFromFile("sprites/buildings/sawmill.png"); description.text.setString("It's me! Sawmill!"); buffer.loadFromFile("audio/sawShort.wav"); break;
        case 1: texture.loadFromFile("sprites/buildings/barracks.png"); description.text.setString("It's me! Barracks!"); buffer.loadFromFile("audio/barracks.wav"); break;
        case 2: texture.loadFromFile("sprites/buildings/stone.png"); description.text.setString("It's me! Stonecutter Hut!");sprite.setScale(0.45,0.45); sprite.setOrigin(-10,-30); buffer.loadFromFile("audio/rock.wav"); break;
        case 3: texture.loadFromFile("sprites/buildings/residence.png"); description.text.setString("It's me! Residence!"); buffer.loadFromFile("audio/residence.wav");  break;
    }
}

void Building::placeOnMap()
{

    sprite.setPosition (objectUnits.at(0)->field.getPosition());
    occupyUnits();

}
