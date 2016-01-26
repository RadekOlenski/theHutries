#include "unit.h"
#include "carrier.h"
#include "gamebalance.h"


Carrier::Carrier(sf::RenderWindow* hutrieApplication, std::vector<Unit*> unitsFromGame, std::string pathName)
        : Hutrie(hutrieApplication, unitsFromGame, pathName), carrierThread(&Carrier::comeBack, this)
{
    upTexture.loadFromFile(Textures::carrierUp);
    downTexture.loadFromFile(Textures::carrierDown);
    leftTexture.loadFromFile(Textures::carrierLeft);
    arrived = false;
    sprite.setTexture(transTexture);
}

void Carrier::moveHutrie()
{
    if(pauseThread)
    {
        sf::sleep(sf::seconds(0.7));
    }
    busy = true;
    unsigned int door = (unsigned int) myBuilding->getDoorIndex();
    toDirection(objectUnits.at(door)->field.getPosition().x, objectUnits.at(door)->field.getPosition().y);
    sprite.setTexture(transTexture);
    sf::sleep(sf::seconds(GameBalance::carrierLoading));
    arrived = true;
}

void Carrier::comeBack()
{
    if(pauseThread)
    {
        sf::sleep(sf::seconds(0.7));
    }
    arrived = false;
    toDirection(6 * 64, 7 * 64);
    busy = false;
    returned = true;
    sprite.setTexture(transTexture);
}
