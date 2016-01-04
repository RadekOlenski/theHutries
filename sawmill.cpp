#include "sawmill.h"
#include "sound.h"
#include <sstream>

Sawmill::Sawmill(sf::RenderWindow *hutrieApplication, std::vector<Unit *> unitsFromGame, std::string pathName)
        : GoodsBuilding(hutrieApplication, unitsFromGame, pathName)
{

    title.text.setString("Sawmill:");
    sound.openFromFile(Sound::sawmill);
    goodReady.text.setString("Wood ready");
}

void Sawmill::createProduct()
{
    myProducts.setProduct(1,1);
}

void Sawmill::updateStatus()
{
    std::ostringstream desc;
    desc << "Capacity: " << capacity << " workers\nWorkers: " << myWorkers.size() << "\nCarriers: " <<
    checkHutries() - myWorkers.size() << "\nProducts in store: " << myProducts.getWood();
    description.text.setString(desc.str());
}
