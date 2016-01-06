#include "farm.h"
#include "sound.h"
#include <sstream>

Farm::Farm(sf::RenderWindow *hutrieApplication, const std::vector<Unit *> &unitsFromGame, const std::string &pathName)
        : GoodsBuilding(hutrieApplication, unitsFromGame, pathName)
{
    title.text.setString("Farm:");
    sound.openFromFile(Sound::farm); //TODO znaleźć dźwięk farmy
    sound.setVolume(50);
    goodReady.text.setString("Food ready");
    textureWithProduct.loadFromFile("sprites/buildings/farmWithProduct.png");
    textureNoProduct.loadFromFile("sprites/buildings/farm.png");
}

void Farm::updateStatus()
{
    std::ostringstream desc;
    desc <<  "Workers: " << myWorkers.size() << "/" << capacity << "\nCarriers: " <<
    checkHutries() - myWorkers.size() << "\nProducts in store: " << myProducts.getFood() << "/" << productsCapacity;
    description.text.setString(desc.str());
}

void Farm::createProduct()
{
    myProducts.setProduct(3,1);
}
