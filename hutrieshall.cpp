#include "hutrieshall.h"

#include <cstdlib>
#include <sstream>

HutriesHall::HutriesHall(sf::RenderWindow *hutrieApplication, std::vector <Unit*> unitsFromGame, std::string pathName, int buildingType) : Building(hutrieApplication,unitsFromGame, pathName, buildingType)
{
    title.text.setString("Hutries Hall:");

    sprite.setScale(0.45,0.5);
    sprite.setOrigin(30,128);

    sound.openFromFile("audio/castle.flac");
    setSoundVolume(100);
}

void HutriesHall::showStatus()
{
     std::ostringstream desc;
    desc << "Available carriers: " << rand()%20 << "\nAvailable workers: " << rand()%20 << "\nAvailable warriors: " << rand()%20 << "\nAvailable archers: " << rand()%20;
    description.text.setString (desc.str());
}
