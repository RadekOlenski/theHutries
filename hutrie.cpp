#include "hutrie.h"
#include <string>

Hutrie::Hutrie(sf::RenderWindow *hutrieApplication, Unit *unit) : MapObject(hutrieApplication, unit, "sprites/carrier/right.png",0.64,0.64,320,320), hutrieThread(&Hutrie::moveHutrie, this) //origin 45,40
{
}

void Hutrie::moveHutrie()
{
    unit->setEmpty(false);
    //float mouseY = sf::Mouse::getPosition(*hutrieApplication).y;
    //float mouseX = sf::Mouse::getPosition(*hutrieApplication).x;

    float mouseY = unit->field.getPosition().y;
    float mouseX = unit->field.getPosition().x;

    while( sprite.getPosition().y < mouseY )
    {
     sprite.move(0,1);
     texture.loadFromFile( "sprites/carrier/down.png" );
     sprite.setTexture( texture );
     sf::sleep(sf::milliseconds(5));
     //std::cout << "Jestem na pozycji: " << sprite.getPosition().x <<", " << sprite.getPosition().y << std::endl;
    };
    while( sprite.getPosition().x < mouseX)
    {
     texture.loadFromFile( "sprites/carrier/right.png" );
     sprite.setTexture( texture );
     sprite.move(1,0);
     sf::sleep(sf::milliseconds(5));
     //std::cout << "Jestem na pozycji: " << sprite.getPosition().x <<", " << sprite.getPosition().y << std::endl;
    };
    while( sprite.getPosition().y > mouseY)
    {
     texture.loadFromFile( "sprites/carrier/up.png" );
     sprite.setTexture( texture );
     sprite.move(0,-1);
     sf::sleep(sf::milliseconds(5));
     //std::cout << "Jestem na pozycji: " << sprite.getPosition().x <<", " << sprite.getPosition().y << std::endl;
    };
    while( sprite.getPosition().x > mouseX)
    {
     texture.loadFromFile( "sprites/carrier/left.png" );
     sprite.setTexture( texture );
     sprite.move(-1,0);
     sf::sleep(sf::milliseconds(5));
     //std::cout << "Jestem na pozycji: " << sprite.getPosition().x <<", " << sprite.getPosition().y << std::endl;
    };
}

