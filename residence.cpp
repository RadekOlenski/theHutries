#include "residence.h"
#include "sound.h"
#include <sstream>
#include <cstdlib>

Residence::Residence(sf::RenderWindow *hutrieApplication, std::vector <Unit*> unitsFromGame, int *worldSlots)
        : Building(hutrieApplication,unitsFromGame)
{
    this->worldSlots = worldSlots;
    title.text.setString("Residence:");
    textureBasic.loadFromFile(Textures::residenceBasic);

    buildingConstructed = false;
    leftConstructionTime = 0;
    doorIndex = 3;
}

void Residence::updateStatus()
{
    if(buildingConstructed)
    {
        std::ostringstream desc;
        desc << "\n\nAvailable space in village: \n\t\t\t" << *worldSlots;
        description.text.setString (desc.str() );
    }
    else
    {
        std::ostringstream desc;
        desc << "Construction finish in " <<  leftConstructionTime  << " sec.";
        description.text.setString (desc.str() );
    }
}

int Residence::getAddedSlotsNumber()
{
    return slotsAddition;
}

void Residence::updateConstructionClock(int fulltime)
{
    leftConstructionTime = (unsigned int) (fulltime - constructionTimeClock.getElapsedTime().asSeconds());
    if (leftConstructionTime < 0) leftConstructionTime = 0;
}

void Residence::setConstructedBuildingSound()
{
    sound.pause();
    sound.openFromFile(Sound::residence);
    sound.play();
}
