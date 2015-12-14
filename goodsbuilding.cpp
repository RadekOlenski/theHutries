#include "goodsbuilding.h"
#include <sstream>
#include <cstdlib>
#include <iostream>

GoodsBuilding::GoodsBuilding(sf::RenderWindow *hutrieApplication, std::vector <Unit*> unitsFromGame, std::string pathName, int buildingType) : Building(hutrieApplication,unitsFromGame, pathName, buildingType),
                                                                                                                                               callWorker ( 1024 + 40 , 500, hutrieApplication, 150, 45),
                                                                                                                                               goodsReady ( 1024 + 40 , 560, hutrieApplication, 150, 45),
                                                                                                                                               assignWorker(1024 + 60, 510, 20, "Assign worker"),
                                                                                                                                               goodReady(1024 + 70, 570, 20, "Good ready")
{
    capacity = 3;
    hutriesCounter = 0;
}

void GoodsBuilding::showStatus()
{
    std::ostringstream desc;
    desc << "Capacity: " << capacity << " workers\nWorkers: " << hutriesCounter << "\nCarriers: " << checkHutries() - hutriesCounter <<"\nProducts in store: " << (rand()%5)+1;
    description.text.setString (desc.str() );
}

void GoodsBuilding::showButtons()
{
    callWorker.setActive(true);
    goodsReady.setActive(true);
    hutrieApplication->draw(callWorker.button);
    hutrieApplication->draw(goodsReady.button);
    hutrieApplication->draw(assignWorker.text);
    hutrieApplication->draw(goodReady.text);

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

