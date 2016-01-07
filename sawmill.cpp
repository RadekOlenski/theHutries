#include "sawmill.h"
#include "sound.h"
#include "textures.h"
#include <sstream>

Sawmill::Sawmill(sf::RenderWindow *hutrieApplication, std::vector<Unit *> unitsFromGame)
        : GoodsBuilding(hutrieApplication, unitsFromGame)
{

    title.text.setString("Sawmill:");
    sound.openFromFile(Sound::sawmill);
    goodReady.text.setString("Wood ready");
    textureBasic.loadFromFile(Textures::sawmillBasic);
    textureWithProduct.loadFromFile(Textures::sawmillWithProduct);

    buildingConstructed = false;
    leftConstructionTime = 0;
}

void Sawmill::createProduct()
{
    myProducts.setProduct(1,1);
}

void Sawmill::updateStatus()
{
    if(buildingConstructed)
    {
        std::ostringstream desc;
        desc <<  "Workers: " << myWorkers.size() << "/" << capacity << "\nCarriers: " <<
        checkHutries() - myWorkers.size() << "\nProducts in store: " << myProducts.getWood() << "/" << productsCapacity;
        description.text.setString(desc.str());
    }
    else
    {
        std::ostringstream desc;
        desc << "Construction finish in " <<  leftConstructionTime  << " sec.";
        description.text.setString (desc.str() );
    }
}


void Sawmill::updateConstructionClock(int fulltime)
{
    leftConstructionTime = (unsigned int) (fulltime - constructionTimeClock.getElapsedTime().asSeconds());
    if (leftConstructionTime < 0) leftConstructionTime = 0;
}