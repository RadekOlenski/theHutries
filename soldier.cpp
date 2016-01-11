#include "unit.h"
#include "soldier.h"
#include "textures.h"


Soldier::Soldier(sf::RenderWindow *hutrieApplication, std::vector <Unit*> unitsFromGame, const std::vector<Unit*> &unitsForMoving, std::string pathName) : Hutrie(hutrieApplication,unitsFromGame,pathName)
{
    title.text.setString("Warrior:");

    upTexture.loadFromFile(Textures::warriorUp);
    downTexture.loadFromFile(Textures::warriorDown);
    leftTexture.loadFromFile(Textures::warriorLeft);
}

void Soldier::moveHutrie()
{
    occupyUnits();
    toDirection(objectUnits.at(0)->field.getPosition().x, objectUnits.at(0)->field.getPosition().y );
    //while(1)
    //{
	//
    //}
}
