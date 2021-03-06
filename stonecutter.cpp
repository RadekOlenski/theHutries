#include "stonecutter.h"
#include "sound.h"
#include <sstream>

StoneCutter::StoneCutter(sf::RenderWindow* hutrieApplication, std::vector<Unit*> unitsFromGame)
        : GoodsBuilding(hutrieApplication, unitsFromGame)
{
    title.text.setString("Stonecutter Hut:");
    sprite.setScale(0.45, 0.45);
    sprite.setOrigin(-10, -30);
    goodReady.text.setString("Stone ready");
    textureBasic.loadFromFile(Textures::stonecutterHutBasic);
    textureWithProduct.loadFromFile(Textures::stoncutterHutWithProduct);

    buildingConstructed = false;
    leftConstructionTime = 0;
    doorIndex = 2;
    constructionTime = GameBalance::stonecutterHutConstructionTime;
        requiredForConstructionGoods = GameBalance::stonecutterhutCost;
}

void StoneCutter::createProduct()
{
    myProducts.setProduct(2, 1);
}

void StoneCutter::setConstructedBuildingSound()
{
    sound.pause();
    sound.openFromFile(Sound::stonecutter);
    if(isHighlighted())
    {
        sound.play();
    }
}

void StoneCutter::updateStatus()
{
    if (buildingConstructed)
    {
        std::ostringstream desc;
        desc << "Workers: " << myWorkers.size() << "/" << capacity << "\nCarriers: " <<
        myCarriers.size() << "\nProducts in store: " << myProducts.getStone() << "/" << productsCapacity;
        description.text.setString(desc.str());
    }
    else
    {
        std::ostringstream desc;
        desc << "Construction finish in " << ceil(leftConstructionTime) << " sec.\n\n"
             << "\tWood: " << constructionGoods.getWood() << "/" << GameBalance::stonecutterhutCost.getWood()
             << "\n\tStone: " << constructionGoods.getStone() << "/" << GameBalance::stonecutterhutCost.getStone();
        description.text.setString(desc.str());
    }
}
