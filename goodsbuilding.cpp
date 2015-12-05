#include "goodsbuilding.h"
#include <sstream>
#include <cstdlib>
#include <iostream>

GoodsBuilding::GoodsBuilding(sf::RenderWindow *hutrieApplication, std::vector <Unit*> unitsFromGame, std::string pathName, int buildingType) : Building(hutrieApplication,unitsFromGame, pathName, buildingType),
                                                                                                                                               callWorker ( 1024 + 40 , 500, hutrieApplication, 90, 45),
                                                                                                                                               goodsReady ( 1024 + 40 , 560, hutrieApplication, 90, 45)
{
    capacity = 3;
}

void GoodsBuilding::showStatus()
{
    std::ostringstream desc;
    desc << "Capacity: " << capacity << " workers\nWorkers: " << hutriesCounter << "\nCarriers: " << checkHutries() - hutriesCounter << "\nProducts in store: " << (rand()%5)+1;
    description.text.setString (desc.str() );
}

void GoodsBuilding::showButtons()
{
    callWorker.setActive(true);
    goodsReady.setActive(true);
    hutrieApplication->draw(callWorker.button);
    hutrieApplication->draw(goodsReady.button);
}

void GoodsBuilding::deactivateButtons()
{
    callWorker.setActive(false);
    goodsReady.setActive(false);
}

void GoodsBuilding::buttonAction()
{
    if (callWorker.checkBounds() && callWorker.isActive())
    {
        std::cout << "I need worker!!!!";
        needWorker = true;
    }
    if (goodsReady.checkBounds() && goodsReady.isActive())
    {
        std::cout << "I need carrier!!!!";
        needCarrier = true;
    }
}

