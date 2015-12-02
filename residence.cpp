#include "residence.h"
#include <sstream>
#include <cstdlib>

Residence::Residence(sf::RenderWindow *hutrieApplication, std::vector <Unit*> unitsFromGame, std::string pathName, int buildingType) : Building(hutrieApplication,unitsFromGame, pathName, buildingType), slotsAddition(10)
{
    slotsLeft = rand() % 11;
    title.text.setString("Residence:");
    sound.openFromFile("audio/residence.wav");
    sound.setVolume(20);
}

void Residence::showStatus()
{
    std::ostringstream desc;
    desc << "Slots left: " << slotsLeft;
    description.text.setString (desc.str() );
}
