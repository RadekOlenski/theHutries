#include "residence.h"
#include "sound.h"
#include <sstream>

Residence::Residence(sf::RenderWindow* hutrieApplication, std::vector<Unit*> unitsFromGame, int* worldSlots)
        : Building(hutrieApplication, unitsFromGame)
{
    this->worldSlots = worldSlots;
    title.text.setString("Residence:");
    textureBasic.loadFromFile(Textures::residenceBasic);
    buildingConstructed = false;
    leftConstructionTime = 0;
    doorIndex = 3;
    capacity = 1;
    constructionTime = GameBalance::residenceConstructionTime;
    requiredForConstructionGoods = GameBalance::residenceCost;
}

void Residence::updateStatus()
{
    if (buildingConstructed)
    {
        std::ostringstream desc;
        desc << "\n\nAvailable space in village: \n\t\t\t" << *worldSlots;
        description.text.setString(desc.str());
    }
    else
    {
        std::ostringstream desc;
        desc << "Construction finish in " << ceil(leftConstructionTime) << " sec.\n\n"
             << "\tWood: " << constructionGoods.getWood() << "/" << GameBalance::residenceCost.getWood()
             << "\n\tStone: " << constructionGoods.getStone() << "/" << GameBalance::residenceCost.getStone();
        description.text.setString(desc.str());
    }
}

void Residence::updateConstructionClock()
{
    leftConstructionTime = (unsigned int) (constructionTime - constructionClock.getElapsedTime().asSeconds());
    if (leftConstructionTime < 0) leftConstructionTime = 0;
}

void Residence::setConstructedBuildingSound()
{
    sound.pause();
    sound.openFromFile(Sound::residence);
    if(isHighlighted())
    {
        sound.play();
    }
}

void Residence::highlightButton()
{
    if (bringStoneButton.checkBounds())
        bringStoneText.highlight();
    else bringStoneText.endHighlight();

    if (bringWoodButton.checkBounds())
        bringWoodText.highlight();
    else bringWoodText.endHighlight();

    if (constructButton.checkBounds())
        constructText.highlight();
    else constructText.endHighlight();
}