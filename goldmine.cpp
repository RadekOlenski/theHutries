#include "goldmine.h"
#include "sound.h"
#include "textures.h"
#include <sstream>

Goldmine::Goldmine(sf::RenderWindow *hutrieApplication, const std::vector<Unit *> &unitsFromGame)
        : GoodsBuilding(hutrieApplication, unitsFromGame)
{
    title.text.setString("Goldmine:");
    sound.openFromFile(Sound::goldmine);
    sound.setVolume(50);
    goodReady.text.setString("Gold ready");
    textureBasic.loadFromFile(Textures::goldmineBasic);
    textureWithProduct.loadFromFile(Textures::goldmineWithProduct);

    buildingConstructed = false;
    leftConstructionTime = 0;
    doorIndex = 3;
}

void Goldmine::updateStatus()
{
    if(buildingConstructed)
    {
        std::ostringstream desc;
        desc <<  "Workers: " << myWorkers.size() << "/" << capacity << "\nCarriers: " <<
        checkHutries() - myWorkers.size() << "\nProducts in store: " << myProducts.getGold() << "/" << productsCapacity;
        description.text.setString(desc.str());
    }
    else
    {
        std::ostringstream desc;
        desc << "Construction finish in " <<  leftConstructionTime  << " sec.";
        description.text.setString (desc.str() );
    }
}

void Goldmine::createProduct()
{
    myProducts.setProduct(4,1);
}

void Goldmine::updateConstructionClock(int fulltime)
{
    leftConstructionTime = (unsigned int) (fulltime - constructionTimeClock.getElapsedTime().asSeconds());
    if (leftConstructionTime < 0) leftConstructionTime = 0;
}
