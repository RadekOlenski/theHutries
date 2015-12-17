#include "residence.h"
#include <sstream>
#include <cstdlib>

Residence::Residence(sf::RenderWindow *hutrieApplication, std::vector <Unit*> unitsFromGame, std::string pathName, int buildingType, int *worldSlots) : Building(hutrieApplication,unitsFromGame, pathName, buildingType), slotsAddition(10)
{
    this->worldSlots = worldSlots;
    slotsLeft = rand() % 11;
    title.text.setString("Residence:");
    sound.openFromFile("audio/residence.wav");
    sound.setVolume(20);
}

void Residence::updateStatus()
{
    std::ostringstream desc;
    desc << "Slots left: " << slotsLeft << "\nGeneral: " << *worldSlots;
    description.text.setString (desc.str() );
}
