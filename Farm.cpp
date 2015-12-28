#include "farm.h"
#include <sstream>

Farm::Farm(sf::RenderWindow *hutrieApplication, const std::vector<Unit *> &unitsFromGame, const std::string &pathName)
        : GoodsBuilding(hutrieApplication, unitsFromGame, pathName)
{
    title.text.setString("Farm:");
    sound.openFromFile("audio/saw.wav"); //TODO znaleźć dźwięk farmy
    sound.setVolume(100);
    goodReady.text.setString("Food ready");

}

void Farm::updateStatus()
{
    std::ostringstream desc;
    desc << "Capacity: " << capacity << " workers\nWorkers: " << hutriesCounter << "\nCarriers: " <<
    checkHutries() - hutriesCounter << "\nProducts in store: " << myProducts.getFood();
    description.text.setString(desc.str());
}

void Farm::createProduct()
{
    myProducts.setProduct(3,1);
}
