#include "farm.h"
#include "sound.h"
#include <sstream>

Farm::Farm(sf::RenderWindow *hutrieApplication, const std::vector<Unit *> &unitsFromGame, const std::string &pathName)
        : GoodsBuilding(hutrieApplication, unitsFromGame, pathName)
{
    title.text.setString("Farm:");
    sound.openFromFile(Sound::farm); //TODO znaleźć dźwięk farmy
    goodReady.text.setString("Food ready");

}

void Farm::updateStatus()
{
    std::ostringstream desc;
    desc << "Capacity: " << capacity << " workers\nWorkers: " << myWorkers.size() << "\nCarriers: " <<
    checkHutries() - myWorkers.size() << "\nProducts in store: " << myProducts.getFood();
    description.text.setString(desc.str());
}

void Farm::createProduct()
{
    myProducts.setProduct(3,1);
}
