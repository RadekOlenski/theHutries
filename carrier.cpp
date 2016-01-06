#include "unit.h"
#include "carrier.h"
#include "gamebalance.h"


Carrier::Carrier(sf::RenderWindow *hutrieApplication, std::vector <Unit*> unitsFromGame, std::string pathName, bool onBuilding) : Hutrie(hutrieApplication,unitsFromGame,pathName), carrierThread(&Carrier::comeBack, this)
{
    upTexture.loadFromFile("sprites/carrier/up.png");
    downTexture.loadFromFile("sprites/carrier/down.png");
    leftTexture.loadFromFile("sprites/carrier/left.png");
    arrived = false;
}

void Carrier::moveHutrie()
{
    busy = true;
    toDirection(objectUnits.at(0)->field.getPosition().x, objectUnits.at(0)->field.getPosition().y );
    //sprite.setTexture( transTexture );
    sf::sleep(sf::seconds(GameBalance::carrierLading));
    arrived = true;
}

void Carrier::comeBack()
{
   arrived = false;
   toDirection(390,370);
   busy = false;
   returned = true;
    //sprite.setTexture( transTexture );
}
