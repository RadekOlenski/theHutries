#include "unit.h"
#include "carrier.h"


Carrier::Carrier(sf::RenderWindow *hutrieApplication, std::vector <Unit*> unitsFromGame, std::string pathName, bool onBuilding) : Hutrie(hutrieApplication,unitsFromGame,pathName)
{
    upTexture.loadFromFile("sprites/carrier/up.png");
    downTexture.loadFromFile("sprites/carrier/down.png");
    leftTexture.loadFromFile("sprites/carrier/left.png");
}

void Carrier::moveHutrie()
{
    toDirection(objectUnits.at(0)->field.getPosition().x, objectUnits.at(0)->field.getPosition().y );
    //sprite.setTexture( transTexture );
    sf::sleep(sf::seconds(3));
    toDirection(390,370);
    sprite.setTexture( transTexture );
}
