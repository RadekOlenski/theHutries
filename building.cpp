#include "building.h"
#include <cstdlib>

Building::Building(sf::RenderWindow *hutrieApplication, std::vector <Unit*> unitsFromGame, int buildingType) : MapObject(hutrieApplication, unitsFromGame, "sprites/buildings/sawmill.png" ,"audio/saw.wav", 0.5,0.5)
{
    //introduceYourSelf = "Hi! I'm Building";
    title.text.setString("Sawmill");

    ///////////////////////////CHOOSING RANDOM BUILDING///////////////////////////////////////////////////////

    this->buildingType = buildingType;
    switch(buildingType)
    {
        case 1: texture.loadFromFile("sprites/buildings/sawmill.png");   title.text.setString("Sawmill:");         sound.openFromFile("audio/saw.wav"); sound.setVolume(100); break;
        case 2: texture.loadFromFile("sprites/buildings/barracks.png");  title.text.setString("Barracks:");        sound.openFromFile("audio/barracks.wav"); break;
        case 3: texture.loadFromFile("sprites/buildings/stone.png");     title.text.setString("Stonecutter Hut:"); sprite.setScale(0.45,0.45); sprite.setOrigin(-10,-30); sound.openFromFile("audio/rock.wav"); break;
        case 4: texture.loadFromFile("sprites/buildings/residence.png"); title.text.setString("Residence:");       sound.openFromFile("audio/residence.wav"); sound.setVolume(20); break;
    }
    descriptionFrame.button.setTexture(&texture);
}

Building::Building(sf::RenderWindow *hutrieApplication, std::vector <Unit*> unitsFromGame, int buildingType, std::string pathName, std::string soundPathName) : MapObject(hutrieApplication, unitsFromGame, pathName, soundPathName)
{

}

void Building::placeOnMap()
{

    sprite.setPosition (objectUnits.at(0)->field.getPosition());
    occupyUnits();

}

void Building::showStatus()
{
    description.text.setString ("Workers:\nCapacity:\nStorage:\n" );
}
