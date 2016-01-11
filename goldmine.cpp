#include "goldmine.h"
#include "sound.h"
#include <sstream>

Goldmine::Goldmine(sf::RenderWindow* hutrieApplication, const std::vector<Unit*> &unitsFromGame)
        : GoodsBuilding(hutrieApplication, unitsFromGame)
{
    title.text.setString("Goldmine:");
    goodReady.text.setString("Gold ready");
    textureBasic.loadFromFile(Textures::goldmineBasic);
    textureWithProduct.loadFromFile(Textures::goldmineWithProduct);

    buildingConstructed = false;
    leftConstructionTime = 0;
    doorIndex = 3;
}

void Goldmine::updateStatus()
{
    if (buildingConstructed)
    {
        std::ostringstream desc;
        desc << "Workers: " << myWorkers.size() << "/" << capacity << "\nCarriers: " <<
        myCarriers.size() << "\nProducts in store: " << myProducts.getGold() << "/" << productsCapacity;
        description.text.setString(desc.str());
    }
    else
    {
        std::ostringstream desc;
        desc << "Construction finish in " << leftConstructionTime << " sec.";
        description.text.setString(desc.str());
    }
}

void Goldmine::createProduct()
{
    myProducts.setProduct(4, 1);
}

void Goldmine::updateConstructionClock(int fullTime)
{
    leftConstructionTime = (unsigned int) (fullTime - constructionTimeClock.getElapsedTime().asSeconds());
    if (leftConstructionTime < 0) leftConstructionTime = 0;
}

void Goldmine::setConstructedBuildingSound()
{
    sound.pause();
    sound.openFromFile(Sound::goldmine);
    sound.play();
}

