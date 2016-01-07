#include "unit.h"
#include "carrier.h"
#include "gamebalance.h"


Carrier::Carrier(sf::RenderWindow *hutrieApplication, std::vector <Unit*> unitsFromGame, std::string pathName, bool onBuilding)
        : Hutrie(hutrieApplication,unitsFromGame, pathName), carrierThread(&Carrier::comeBack, this)
{
    upTexture.loadFromFile(Textures::carrierUp);
    downTexture.loadFromFile(Textures::carrierDown);
    leftTexture.loadFromFile(Textures::carrierLeft);
    arrived = false;
}

void Carrier::moveHutrie()
{
    busy = true;
    toDirection(objectUnits.at(2)->field.getPosition().x, objectUnits.at(2)->field.getPosition().y );
    sprite.setTexture( transTexture );
    sf::sleep(sf::seconds(GameBalance::carrierLading));
    arrived = true;
}

void Carrier::comeBack()
{
   arrived = false;
   toDirection( 6*64, 7*64 );
   busy = false;
   returned = true;
   sprite.setTexture( transTexture );
}
