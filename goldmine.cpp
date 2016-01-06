#include "goldmine.h"
#include "sound.h"
#include <sstream>

Goldmine::Goldmine(sf::RenderWindow *hutrieApplication, const std::vector<Unit *> &unitsFromGame, const std::string &pathName)
        : GoodsBuilding(hutrieApplication, unitsFromGame, pathName)
{
    title.text.setString("Goldmine:");
    sound.openFromFile(Sound::goldmine);
    sound.setVolume(50);
    goodReady.text.setString("Gold ready");
    textureWithProduct.loadFromFile("sprites/buildings/goldmine/goldmineWithProduct2.png");
    textureNoProduct.loadFromFile("sprites/buildings/goldmine/goldmine.png");
}

void Goldmine::updateStatus()
{
    std::ostringstream desc;
    desc <<  "Workers: " << myWorkers.size() << "/" << capacity << "\nCarriers: " <<
    checkHutries() - myWorkers.size() << "\nProducts in store: " << myProducts.getGold() << "/" << productsCapacity;
    description.text.setString(desc.str());
}

void Goldmine::createProduct()
{
    myProducts.setProduct(4,1);
}
