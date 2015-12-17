#include "barracks.h"
#include <sstream>
#include <cstdlib>

Barracks::Barracks(sf::RenderWindow *hutrieApplication, std::vector <Unit*> unitsFromGame, std::string pathName, int buildingType) : Building(hutrieApplication,unitsFromGame, pathName, buildingType)
{
    title.text.setString("Barracks:");
    sound.openFromFile("audio/barracks.wav");
}

void Barracks::updateStatus()
{
    std::ostringstream desc;
    desc << "Capacity: " << (rand()%5)+1 << " soldiers\nWarriors during training: " << (rand()%5)+1 << "\nWarriors during training:: " << (rand()%5)+1;
    description.text.setString (desc.str() );
}
