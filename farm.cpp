#include "farm.h"
#include "sound.h"
#include <sstream>

Farm::Farm(sf::RenderWindow* hutrieApplication, const std::vector<Unit*> &unitsFromGame)
        : GoodsBuilding(hutrieApplication, unitsFromGame)
{
    title.text.setString("Farm:");
    goodReady.text.setString("Food ready");

    textureBasic.loadFromFile(Textures::farmBasic);
    textureWithProduct.loadFromFile(Textures::farmWithProduct);

    buildingConstructed = false;
    leftConstructionTime = 0;
    doorIndex = 3;
}

void Farm::updateStatus()
{
    if (buildingConstructed)
    {
        std::ostringstream desc;
        desc << "Workers: " << myWorkers.size() << "/" << capacity << "\nCarriers: " <<
        myCarriers.size() << "\nProducts in store: " << myProducts.getFood() << "/" << productsCapacity;
        description.text.setString(desc.str());
    }
    else
    {
        std::ostringstream desc;
        desc << "Construction finish in " << leftConstructionTime << " sec.";
        description.text.setString(desc.str());
    }
}

void Farm::createProduct()
{
    myProducts.setProduct(3, 1);
}

void Farm::updateConstructionClock(int fullTime)
{
    leftConstructionTime = (unsigned int) (fullTime - constructionTimeClock.getElapsedTime().asSeconds());
    if (leftConstructionTime < 0) leftConstructionTime = 0;
}

void Farm::setConstructedBuildingSound()
{
    sound.pause();
    sound.openFromFile(Sound::farm);
    if(isHighlighted())
    {
        sound.play();
    }
}
