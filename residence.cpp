#include "residence.h"
#include "sound.h"
#include <sstream>
#include <cstdlib>

Residence::Residence(sf::RenderWindow *hutrieApplication, std::vector <Unit*> unitsFromGame, std::string pathName, int *worldSlots)
        : Building(hutrieApplication,unitsFromGame, pathName)
{
    this->worldSlots = worldSlots;
    slotsLeft = rand() % 11;
    title.text.setString("Residence:");
    sound.openFromFile(Sound::residence);
    sound.setVolume(20);
}

void Residence::updateStatus()
{
    std::ostringstream desc;
    desc << "Slots left: " << slotsLeft << "\nGeneral: " << *worldSlots;
    description.text.setString (desc.str() );
}

int Residence::getAddedSlotsNumber()
{
    return slotsAddition;
}
