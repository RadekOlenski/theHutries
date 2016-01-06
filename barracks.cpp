#include "barracks.h"

#include <sstream>
#include <iostream>
#include "sound.h"

Barracks::Barracks(sf::RenderWindow *hutrieApplication, std::vector <Unit*> unitsFromGame, std::string pathName)
        : Building(hutrieApplication,unitsFromGame, pathName),
          createWarriorButton(1024 + 40, 475, hutrieApplication, 150, 45),
          createArcherButton(1024 + 40, 535, hutrieApplication, 150, 45),
          textWarrior(1024 + 60, 485, 20, "Create Warrior"),
          textArcher(1024 + 70, 545, 20, "Create Archer"),
          goldArcher(1024 + 200, 545, hutrieApplication, "sprites/goods/gold.png", 25, 25),
          tgoldArcher(1024 + 230, 545, 20, "3"),
          goldWarrior(1024 + 200, 485, hutrieApplication, "sprites/goods/gold.png", 25, 25),
          tgoldWarrior(1024 + 230, 485, 20, "3")

{
    title.text.setString("Barracks:");
    sound.openFromFile(Sound::barracks);

    makeWarriorFlag = false;
    makeArcherFlag = false;
    trainingWarrior = false;
    trainingArcher = false;
    firstCheck = true;
    leftTrainingTime = 0;

    setSoldiersCosts();
}

void Barracks::updateStatus()
{
    std::ostringstream desc;
    desc << "Training finish in " <<  leftTrainingTime  << " sec.\nWarriors during training: " << trainingWarrior << "\nArchers during training:: " << trainingArcher;
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
    hutrieApplication->draw(goldArcher.button);
    hutrieApplication->draw(goldWarrior.button);
    hutrieApplication->draw(tgoldArcher.text);
    hutrieApplication->draw(tgoldWarrior.text);
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

void Barracks::setSoldiersCosts()
{
    std::ostringstream desc;
    desc << GameBalance::warriorCost.getGold();
    tgoldWarrior.text.setString(desc.str());
    std::ostringstream desc1;
    desc1 << GameBalance::archerCost.getGold();
    tgoldArcher.text.setString(desc1.str());
}

void Barracks::updateClock(int fulltime )
{
    leftTrainingTime = fulltime - trainingClock.getElapsedTime().asSeconds();
    if (leftTrainingTime < 0) leftTrainingTime = 0;
}
