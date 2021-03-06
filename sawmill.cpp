#include "sawmill.h"
#include "sound.h"
#include <sstream>

Sawmill::Sawmill(sf::RenderWindow* hutrieApplication, std::vector<Unit*> unitsFromGame)
        : GoodsBuilding(hutrieApplication, unitsFromGame)
{

    title.text.setString("Sawmill:");
    goodReady.text.setString("Wood ready");
    textureBasic.loadFromFile(Textures::sawmillBasic);
    textureWithProduct.loadFromFile(Textures::sawmillWithProduct);

    buildingConstructed = false;
    leftConstructionTime = 0;
    doorIndex = 2;
    constructionTime = GameBalance::sawmillConstructionTime;
    requiredForConstructionGoods = GameBalance::sawmillCost;
}

void Sawmill::createProduct()
{
    myProducts.setProduct(1, 1);
}

void Sawmill::setConstructedBuildingSound()
{
    sound.pause();
    sound.openFromFile(Sound::sawmill);
    if(isHighlighted())
    {
        sound.play();
    }
}

void Sawmill::updateStatus()
{
    if (buildingConstructed)
    {
        std::ostringstream desc;
        desc << "Workers: " << myWorkers.size() << "/" << capacity << "\nCarriers: " <<
        myCarriers.size() << "\nProducts in store: " << myProducts.getWood() << "/" << productsCapacity;
        description.text.setString(desc.str());
    }
    else
    {
        std::ostringstream desc;
        desc << "Construction finish in " << ceil(leftConstructionTime) << " sec.\n\n"
             << "\tWood: " << constructionGoods.getWood() << "/" << GameBalance::sawmillCost.getWood()
             << "\n\tStone: " << constructionGoods.getStone() << "/" << GameBalance::sawmillCost.getStone();
        description.text.setString(desc.str());
    }
}
