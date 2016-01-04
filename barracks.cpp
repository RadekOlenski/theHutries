#include "barracks.h"

#include <sstream>
#include <iostream>
#include "sound.h"

Barracks::Barracks(sf::RenderWindow *hutrieApplication, std::vector <Unit*> unitsFromGame, std::string pathName)
        : Building(hutrieApplication,unitsFromGame, pathName),
          createWarriorButton(1024 + 40, 475, hutrieApplication, 150, 45),
          createArcherButton(1024 + 40, 535, hutrieApplication, 150, 45),
          textWarrior(1024 + 60, 485, 20, "Create Warrior"),
          textArcher(1024 + 70, 545, 20, "Create Archer")

{
    title.text.setString("Barracks:");
    sound.openFromFile(Sound::barracks);

    makeWarriorFlag = false;
    makeArcherFlag = false;
}

void Barracks::updateStatus()
{
    std::ostringstream desc;
    desc << "Capacity: " << (rand()%5)+1 << " soldiers\nWarriors during training: " << (rand()%5)+1 << "\nWarriors during training:: " << (rand()%5)+1;
    description.text.setString (desc.str() );
}

void Barracks:: showButtons()
{
    createWarriorButton.setActive(true);
    createArcherButton.setActive(true);
    hutrieApplication->draw(createWarriorButton.button);
    hutrieApplication->draw(createArcherButton.button);
    hutrieApplication->draw(textWarrior.text);
    hutrieApplication->draw(textArcher.text);
}

void Barracks::deactivateButtons()
{
    createWarriorButton.setActive(false);
    createArcherButton.setActive(false);
}

void Barracks::buttonAction()
{
    if (createWarriorButton.checkBounds() && createWarriorButton.isActive())
    {
        std::cout << "Create Warrior!!!!" << std::endl;
        makeWarriorFlag = true;
    }
    if (createArcherButton.checkBounds() && createArcherButton.isActive())
    {
        std::cout << "Create Archer!!!!" << std::endl;
        makeArcherFlag = true;
    }
}

bool Barracks::getMakeWarriorFlag()
{
    return makeWarriorFlag;
}

void Barracks::setMakeWarriorFlag(bool makeWarriorFlag)
{
    this->makeWarriorFlag = makeWarriorFlag;
}

bool Barracks::getMakeArcherFlag()
{
    return makeArcherFlag;
}

void Barracks::setMakeArcherFlag(bool makeArcherFlag)
{
    this->makeArcherFlag = makeArcherFlag;
}
