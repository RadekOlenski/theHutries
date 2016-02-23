#include "barracks.h"

#include <sstream>
#include <iostream>
#include "sound.h"


Barracks::Barracks(sf::RenderWindow* hutrieApplication, std::vector<Unit*> unitsFromGame)
        : Building(hutrieApplication, unitsFromGame),

          trainHutries(1024 + 65, 440, 25, "Train Hutries:"),

          createArcherButton(1024 + 140, 470, hutrieApplication, Textures::archerMoveDown1, 90, 90),
          textArcher(1024 + 160, 555, 20, "Archer"),
          goldArcher(1024 + 170, 585, hutrieApplication, Textures::gold, 25, 25),
          tGoldArcher(1024 + 195, 585, 20, "3"),

          createWarriorButton(1024 + 30, 470, hutrieApplication, Textures::warriorMoveDown1, 90, 90),
          textWarrior(1024 + 50, 555, 20, "Warrior"),
          goldWarrior(1024 + 60, 585, hutrieApplication, Textures::gold, 25, 25),
          tGoldWarrior(1024 + 85, 585, 20, "3")
{
    title.text.setString("Barracks:");
    textureBasic.loadFromFile(Textures::barracksBasic);

    makeWarriorFlag = false;
    makeArcherFlag = false;
    trainingWarrior = false;
    trainingArcher = false;
    firstCheck = true;
    buildingConstructed = false;
    enoughGoodsForCreation = false;
    leftTrainingTime = 0;
    leftConstructionTime = 0;
    constructionTime = GameBalance::barracksConstructionTime;
    warriorTrainingTime = GameBalance::warriorTrainingTime;
    archerTrainingTime = GameBalance::archerTrainingTime;
    setSoldiersCosts();
    requiredForConstructionGoods = GameBalance::barracksCost;
    doorIndex = 3;
    capacity = 1;
}

void Barracks::updateStatus()
{
    if (buildingConstructed)
    {
        std::ostringstream desc;
        desc << "Training finish in " << ceil(leftTrainingTime)
        << " sec.\nWarriors during training: " << trainingWarrior
        << "\nArchers during training:: " << trainingArcher;
        description.text.setString(desc.str());
    }
    else
    {
        std::ostringstream desc;
        desc << "Construction finish in " << ceil(leftConstructionTime) << " sec.\n\n"
             << "\tWood: " << constructionGoods.getWood() << "/" << GameBalance::barracksCost.getWood()
             << "\n\tStone: " << constructionGoods.getStone() << "/" << GameBalance::barracksCost.getStone();
        description.text.setString(desc.str());
    }
}

void Barracks::showButtons()
{
    if (buildingConstructed)
    {
        createWarriorButton.setActive(true);
        createArcherButton.setActive(true);
        hutrieApplication->draw(trainHutries.text);
        hutrieApplication->draw(createWarriorButton.button);
        hutrieApplication->draw(createArcherButton.button);
        hutrieApplication->draw(textWarrior.text);
        hutrieApplication->draw(textArcher.text);
        hutrieApplication->draw(goldArcher.button);
        hutrieApplication->draw(goldWarrior.button);
        hutrieApplication->draw(tGoldArcher.text);
        hutrieApplication->draw(tGoldWarrior.text);
    }
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
        Sound::purchaseSound();
    }
    if (createArcherButton.checkBounds() && createArcherButton.isActive())
    {
        std::cout << "Create Archer!!!!" << std::endl;
        makeArcherFlag = true;
        Sound::purchaseSound();
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
    tGoldWarrior.text.setString(desc.str());
    std::ostringstream desc1;
    desc1 << GameBalance::archerCost.getGold();
    tGoldArcher.text.setString(desc1.str());
}

void Barracks::setConstructedBuildingSound()
{
    sound.pause();
    sound.openFromFile(Sound::barracks);
    if(isHighlighted())
    {
        sound.play();
    }
}

void Barracks::highlightButton()
{
    if (createWarriorButton.checkBounds())
        textWarrior.highlight();
    else textWarrior.endHighlight();

    if (createWarriorButton.checkBounds())
        tGoldWarrior.highlight();
    else tGoldWarrior.endHighlight();

    if (createArcherButton.checkBounds())
        textArcher.highlight();
    else textArcher.endHighlight();

    if (createArcherButton.checkBounds())
        tGoldArcher.highlight();
    else tGoldArcher.endHighlight();
}
