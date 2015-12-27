#include "barracks.h"
#include <sstream>
#include <cstdlib>
#include "warrior.h"


Barracks::Barracks(sf::RenderWindow *hutrieApplication, std::vector <Unit*> unitsFromGame, std::string pathName)
        : Building(hutrieApplication,unitsFromGame, pathName)
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
