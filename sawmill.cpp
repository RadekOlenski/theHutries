#include "sawmill.h"
#include <sstream>

Sawmill::Sawmill(sf::RenderWindow *hutrieApplication, std::vector<Unit *> unitsFromGame, std::string pathName,
                 int buildingType) : GoodsBuilding(hutrieApplication, unitsFromGame, pathName, buildingType)
{

    title.text.setString("Sawmill:");
    sound.openFromFile("audio/saw.wav");
    sound.setVolume(100);
    goodReady.text.setString("Wood ready");
}

void Sawmill::createProduct()
{
    myProducts.setProduct(1,1);
}

void Sawmill::updateStatus()
{
    std::ostringstream desc;
    desc << "Capacity: " << capacity << " workers\nWorkers: " << hutriesCounter << "\nCarriers: " <<
    checkHutries() - hutriesCounter << "\nProducts in store: " << myProducts.getWood();
    description.text.setString(desc.str());
}
