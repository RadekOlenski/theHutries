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

    constructionTime = GameBalance::farmConstructionTime;
}

void Farm::createProduct()
{
    myProducts.setProduct(3, 1);
}

void Farm::setConstructedBuildingSound()
{
    sound.pause();
    sound.openFromFile(Sound::farm);
    if (isHighlighted())
    {
        sound.play();
    }
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
        desc << "Construction finish in " << ceil(leftConstructionTime) << " sec.";
        description.text.setString(desc.str());
    }
}
