#include "stonecutter.h"
#include "sound.h"
#include "textures.h"
#include <sstream>

StoneCutter::StoneCutter(sf::RenderWindow *hutrieApplication, std::vector <Unit*> unitsFromGame)
        : GoodsBuilding(hutrieApplication,unitsFromGame)
{
    title.text.setString("Stonecutter Hut:");
    sprite.setScale(0.45,0.45);
    sprite.setOrigin(-10,-30);
    sound.openFromFile(Sound::stonecutter);
    goodReady.text.setString("Stone ready");
    textureBasic.loadFromFile(Textures::stonecutterHutBasic);
    textureWithProduct.loadFromFile(Textures::stoncutterHutWithProduct);

    buildingConstructed = false;
    leftConstructionTime = 0;
    doorIndex = 2;
}

void StoneCutter::updateStatus()
{
    if(buildingConstructed)
    {
        std::ostringstream desc;
        desc <<  "Workers: " << myWorkers.size() << "/" << capacity << "\nCarriers: " <<
        checkHutries() - myWorkers.size() << "\nProducts in store: " << myProducts.getStone() << "/" << productsCapacity;
        description.text.setString(desc.str());
    }
    else
    {
        std::ostringstream desc;
        desc << "Construction finish in " <<  leftConstructionTime  << " sec.";
        description.text.setString (desc.str() );
    }
}

void StoneCutter::createProduct()
{
    myProducts.setProduct(2,1);
}

void StoneCutter::updateConstructionClock(int fulltime)
{
    leftConstructionTime = (unsigned int) (fulltime - constructionTimeClock.getElapsedTime().asSeconds());
    if (leftConstructionTime < 0) leftConstructionTime = 0;
}
