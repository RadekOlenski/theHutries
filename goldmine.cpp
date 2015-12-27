#include "goldmine.h"
#include <sstream>

Goldmine::Goldmine(sf::RenderWindow *hutrieApplication, const std::vector<Unit *> &unitsFromGame, const std::string &pathName)
        : GoodsBuilding(hutrieApplication, unitsFromGame, pathName)
{
    title.text.setString("Goldmine:");
    sound.openFromFile("audio/saw.wav"); //TODO znaleźć dźwięk kopalni
    sound.setVolume(100);
    goodReady.text.setString("Gold ready");

}

void Goldmine::updateStatus()
{
    std::ostringstream desc;
    desc << "Capacity: " << capacity << " workers\nWorkers: " << hutriesCounter << "\nCarriers: " <<
    checkHutries() - hutriesCounter << "\nProducts in store: " << myProducts.getGold();
    description.text.setString(desc.str());
}

void Goldmine::createProduct()
{
    myProducts.setProduct(4,1);
}
