#include "hutrie.h"
#include <string>

Hutrie::Hutrie(sf::RenderWindow *hutrieApplication, std::vector <Unit*> unitsFromGame) : MapObject(hutrieApplication, unitsFromGame, "sprites/carrier/right.png",0.64,0.64,320,320), hutrieThread(&Hutrie::moveHutrie, this) //origin 45,40
{
    introduceYourSelf = "I'm Hutrie";
    description.text.setString("It's me! Hutrie!");
}

void Hutrie::moveHutrie()
{
    occupyUnits();

    float targetY = objectUnits.at(0)->field.getPosition().y;
    float targetX = objectUnits.at(0)->field.getPosition().x;

    while( sprite.getPosition().y < targetY )
    {
     sprite.move(0,1);
     texture.loadFromFile( "sprites/carrier/down.png" );
     sprite.setTexture( texture );
     sf::sleep(sf::milliseconds(5));
     //std::cout << "Jestem na pozycji: " << sprite.getPosition().x <<", " << sprite.getPosition().y << std::endl;
    };
    while( sprite.getPosition().x < targetX)
    {
     texture.loadFromFile( "sprites/carrier/right.png" );
     sprite.setTexture( texture );
     sprite.move(1,0);
     sf::sleep(sf::milliseconds(5));
     //std::cout << "Jestem na pozycji: " << sprite.getPosition().x <<", " << sprite.getPosition().y << std::endl;
    };
    while( sprite.getPosition().y > targetY)
    {
     texture.loadFromFile( "sprites/carrier/up.png" );
     sprite.setTexture( texture );
     sprite.move(0,-1);
     sf::sleep(sf::milliseconds(5));
     //std::cout << "Jestem na pozycji: " << sprite.getPosition().x <<", " << sprite.getPosition().y << std::endl;
    };
    while( sprite.getPosition().x > targetX)
    {
     texture.loadFromFile( "sprites/carrier/left.png" );
     sprite.setTexture( texture );
     sprite.move(-1,0);
     sf::sleep(sf::milliseconds(5));
     //std::cout << "Jestem na pozycji: " << sprite.getPosition().x <<", " << sprite.getPosition().y << std::endl;
    };
}

