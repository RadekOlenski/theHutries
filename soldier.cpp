#include "unit.h"
#include "soldier.h"


Soldier::Soldier(sf::RenderWindow *hutrieApplication, std::vector <Unit*> unitsFromGame, std::string pathName, bool onBuilding) : Hutrie(hutrieApplication,unitsFromGame,pathName,onBuilding)
{
    title.text.setString("Warrior:");

    upTexture.loadFromFile("sprites/warrior/up.png");
    downTexture.loadFromFile("sprites/warrior/down.png");
    leftTexture.loadFromFile("sprites/warrior/left.png");
}

void Soldier::moveHutrie()
{
    occupyUnits();
    toDirection(objectUnits.at(0)->field.getPosition().x, objectUnits.at(0)->field.getPosition().y );
}
