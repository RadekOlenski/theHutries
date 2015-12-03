#include <string>
#include <cstdlib>
#include <sstream>

#include "hutrie.h"
#include "mapobject.h"
#include "unit.h"


///////////////////////////CONSTRUCTOR/////////////////////////////////////////////////////////////////////////////////////

Hutrie::Hutrie(sf::RenderWindow *hutrieApplication, std::vector <Unit*> unitsFromGame, std::string pathName, bool onBuilding) : MapObject(hutrieApplication, unitsFromGame, pathName), hutrieThread(&Hutrie::moveHutrie, this)
{
    title.text.setString("Hutrie:");
    this->onBuilding = onBuilding;

    sprite.setPosition( 384, 384 );
    sprite.setScale(0.64,0.64);

    sound.openFromFile("audio/sir.wav");
    sound.setVolume(100);

    strength = (rand() % 10) + 1;
    agility = (rand() % 10) + 1;
    endurance = (rand() % 10) + 1;

    active = true;                                                             //WHILE TRUE OBJECT WIL BE DRAWN ON SCREEN
}

///////////////////////////MOVING TO SPECIFIC MOUSE DIRECTION/////////////////////////////////////////////////////////////////////////////////////

void Hutrie::moveHutrie()
{
     if (!onBuilding) occupyUnits();

    float targetY = objectUnits.at(0)->field.getPosition().y;
    float targetX = objectUnits.at(0)->field.getPosition().x;

    while( sprite.getPosition().y < targetY )
    {
        sprite.move(0,1);
        texture.loadFromFile( "sprites/carrier/down.png" );
        sprite.setTexture( texture );
        sf::sleep(sf::milliseconds(5));
    };

    while( sprite.getPosition().x < targetX)
    {
        texture.loadFromFile( "sprites/carrier/right.png" );
        sprite.setTexture( texture );
        sprite.move(1,0);
        sf::sleep(sf::milliseconds(5));
    };

    while( sprite.getPosition().y > targetY)
    {
        texture.loadFromFile( "sprites/carrier/up.png" );
        sprite.setTexture( texture );
        sprite.move(0,-1);
        sf::sleep(sf::milliseconds(5));
    };

    while( sprite.getPosition().x > targetX)
    {
        texture.loadFromFile( "sprites/carrier/left.png" );
        sprite.setTexture( texture );
        sprite.move(-1,0);
        sf::sleep(sf::milliseconds(5));
    };
    if (onBuilding) texture.loadFromFile("sprites/carrier/empty.png");
}

void Hutrie::showStatus()
{
    std::ostringstream desc;
    desc << "Strength: " << strength << "\nAgility: " << agility << "\nEndurance: " << endurance;
    description.text.setString (desc.str() );
}


