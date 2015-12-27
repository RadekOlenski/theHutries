#include "goodsbuilding.h"
#include <iostream>

using namespace std;

GoodsBuilding::GoodsBuilding(sf::RenderWindow*hutrieApplication, std::vector<Unit*> unitsFromGame,
    std::string pathName, int buildingType)
        : Building(hutrieApplication, unitsFromGame, pathName, buildingType),
            callWorker(1024 + 40, 500, hutrieApplication, 150, 45),
            goodsReady(1024 + 40, 560, hutrieApplication, 150, 45),
            assignWorker(1024 + 60, 510, 20, "Assign worker"),
            goodReady(1024 + 70, 570, 20, "Good ready")
{
    capacity = 3;
    hutriesCounter = 0;
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

//void GoodsBuilding::getGoods(string goodType)
//{
//    if (goodType == "wood")
//        goodStore.push_back(new Wood());
//    if (goodType == "food")
//        goodStore.push_back(new Food());
//    if (goodType == "gold")
//        goodStore.push_back(new Gold());
//    if (goodType == "stone")
//        goodStore.push_back(new Stone());
//
//
//}
