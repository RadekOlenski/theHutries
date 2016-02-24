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
    animationCounter = 0;
    frameCounter = 0;
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
    else
    {
        textWarrior.endHighlight();
        createWarriorButton.changeTexture(Textures::warriorMoveDown1);
    }

    if (createWarriorButton.checkBounds())
        tGoldWarrior.highlight();
    else tGoldWarrior.endHighlight();

    if (createArcherButton.checkBounds())
        textArcher.highlight();
    else
    {
        textArcher.endHighlight();
        createArcherButton.changeTexture(Textures::archerMoveDown1);
    }

    if (createArcherButton.checkBounds())
        tGoldArcher.highlight();
    else tGoldArcher.endHighlight();

    if (bringStoneButton.checkBounds())
        bringStoneText.highlight();
    else bringStoneText.endHighlight();

    if (bringWoodButton.checkBounds())
        bringWoodText.highlight();
    else bringWoodText.endHighlight();

    if (constructButton.checkBounds())
        constructText.highlight();
    else constructText.endHighlight();

    animateButton();
}


void Barracks::animateButton()
{
    if (frameCounter == 0)
    {
        if (createWarriorButton.checkBounds())
        {
            switch (animationCounter)
            {
                case 0:
                    createWarriorButton.changeTexture(Textures::warriorMoveDown1);
                    animationCounter++;
                    break;
                case 1:
                    createWarriorButton.changeTexture(Textures::warriorMoveDown2);
                    animationCounter++;
                    break;
                case 2:
                    createWarriorButton.changeTexture(Textures::warriorMoveDown3);
                    animationCounter++;
                    break;
                case 3:
                    createWarriorButton.changeTexture(Textures::warriorMoveDown4);
                    animationCounter++;
                    break;
                case 4:
                    createWarriorButton.changeTexture(Textures::warriorMoveDown5);
                    animationCounter++;
                    break;
                case 5:
                    createWarriorButton.changeTexture(Textures::warriorMoveDown6);
                    animationCounter++;
                    break;
                case 6:
                    createWarriorButton.changeTexture(Textures::warriorMoveDown7);
                    animationCounter++;
                    break;
                case 7:
                    createWarriorButton.changeTexture(Textures::warriorMoveDown8);
                    animationCounter++;
                    break;
                case 8:
                    createWarriorButton.changeTexture(Textures::warriorMoveDown9);
                    animationCounter++;
                    break;
                case 9:
                    createWarriorButton.changeTexture(Textures::warriorMoveDown10);
                    animationCounter++;
                    break;
                case 10:
                    createWarriorButton.changeTexture(Textures::warriorMoveDown11);
                    animationCounter++;
                    break;
                case 11:
                    createWarriorButton.changeTexture(Textures::warriorMoveDown12);
                    animationCounter = 0;
                    break;
                default:
                    break;
            }
        }
        else if (createArcherButton.checkBounds())
        {
            switch (animationCounter)
            {
                case 0:
                    createArcherButton.changeTexture(Textures::archerMoveDown1);
                    animationCounter++;
                    break;
                case 1:
                    createArcherButton.changeTexture(Textures::archerMoveDown2);
                    animationCounter++;
                    break;
                case 2:
                    createArcherButton.changeTexture(Textures::archerMoveDown3);
                    animationCounter++;
                    break;
                case 3:
                    createArcherButton.changeTexture(Textures::archerMoveDown4);
                    animationCounter++;
                    break;
                case 4:
                    createArcherButton.changeTexture(Textures::archerMoveDown5);
                    animationCounter++;
                    break;
                case 5:
                    createArcherButton.changeTexture(Textures::archerMoveDown6);
                    animationCounter++;
                    break;
                case 6:
                    createArcherButton.changeTexture(Textures::archerMoveDown7);
                    animationCounter++;
                    break;
                case 7:
                    createArcherButton.changeTexture(Textures::archerMoveDown8);
                    animationCounter = 0;
                    break;
                default:
                    break;
            }
        }
        else animationCounter = 0;
    }
    frameCounter++;
    if(frameCounter > 25)
        frameCounter = 0;
}
