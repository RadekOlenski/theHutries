#include "unit.h"
#include "soldier.h"
#include "unittype.h"


Soldier::Soldier(sf::RenderWindow* hutrieApplication, std::vector<Unit*> unitsFromGame,
                 std::vector<Unit*> unitsForMoving, std::string pathName)
        : Hutrie(hutrieApplication, unitsFromGame, pathName)
{
    title.text.setString("Warrior:");

    upTexture.loadFromFile(Textures::warriorUp);
    downTexture.loadFromFile(Textures::warriorDown);
    leftTexture.loadFromFile(Textures::warriorLeft);

    std::vector<Unit*>::iterator it;
    for (it = unitsForMoving.begin(); it != unitsForMoving.end(); ++it)
    {
        this->unitsForMoving.push_back(*it);
    }
}

void Soldier::moveHutrie()
{
    //occupyUnits();
    srand(time(NULL));
    //toDirection(objectUnits.at(0)->field.getPosition().x, objectUnits.at(0)->field.getPosition().y );
    int unitNumber;
    while (1)
    {
        if (pauseThread)
        {
            sf::sleep(sf::seconds(2));
        };
        do
        {
            unitNumber = (unsigned int) (rand() % 160);
        }
        while (unitsForMoving.at(unitNumber)->getType() == UnitType::FULL);
        toDirection(unitsForMoving.at(unitNumber)->field.getPosition().x,
                    unitsForMoving.at(unitNumber)->field.getPosition().y);
        sf::sleep(sf::seconds(rand() % 6));
    }
}

