#include "carrier.h"

Carrier::Carrier(sf::RenderWindow *hutrieApplication, std::vector <Unit*> unitsFromGame, std::string pathName, bool onBuilding) : Hutrie(hutrieApplication,unitsFromGame,pathName)
{
    upTexture.loadFromFile("sprites/carrier/up.png");
    downTexture.loadFromFile("sprites/carrier/down.png");
    leftTexture.loadFromFile("sprites/carrier/left.png");
}
