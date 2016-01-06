#include "stonecutter.h"
#include "sound.h"
#include <sstream>

StoneCutter::StoneCutter(sf::RenderWindow *hutrieApplication, std::vector <Unit*> unitsFromGame, std::string pathName)
        : GoodsBuilding(hutrieApplication,unitsFromGame, pathName)
{
    title.text.setString("Stonecutter Hut:");
    sprite.setScale(0.45,0.45);
    sprite.setOrigin(-10,-30);
    sound.openFromFile(Sound::stonecutter);
    goodReady.text.setString("Stone ready");
    textureWithProduct.loadFromFile("sprites/buildings/stonecutterHutWithProduct.png");
    textureNoProduct.loadFromFile("sprites/buildings/stonecutterHut.png");
}

void StoneCutter::updateStatus()
{
    std::ostringstream desc;
    desc <<  "Workers: " << myWorkers.size() << "/" << capacity << "\nCarriers: " <<
    checkHutries() - myWorkers.size() << "\nProducts in store: " << myProducts.getStone() << "/" << productsCapacity;
    description.text.setString(desc.str());
}

void StoneCutter::createProduct()
{
    myProducts.setProduct(2,1);
}
