#include "goodsbuilding.h"
#include "sound.h"
#include <iostream>

using namespace std;

GoodsBuilding::GoodsBuilding(sf::RenderWindow* hutrieApplication, std::vector<Unit*> unitsFromGame)
        : Building(hutrieApplication, unitsFromGame),
          callWorker(1024 + 40, 500, hutrieApplication, 150, 45),
          goodsReady(1024 + 40, 560, hutrieApplication, 150, 45),
          assignWorker(1024 + 60, 510, 20, "Assign worker"),
          goodReady(1024 + 70, 570, 20, "Good ready")
{
    capacity = GameBalance::maxWorkers;
}

void GoodsBuilding::showButtons()
{
    if (buildingConstructed)
    {
        callWorker.setActive(true);
        goodsReady.setActive(true);
        hutrieApplication->draw(callWorker.button);
        hutrieApplication->draw(goodsReady.button);
        hutrieApplication->draw(assignWorker.text);
        hutrieApplication->draw(goodReady.text);
    }

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

void GoodsBuilding::addWorker(Worker* worker)
{
    myWorkers.push_back(worker);
}

Worker* GoodsBuilding::getWorker()
{
    Worker* tempWorker = myWorkers.back();
    myWorkers.pop_back();
    return tempWorker;
}

int GoodsBuilding::getWorkersSize()
{
    return myWorkers.size();
}

void GoodsBuilding::checkProduction()
{
    std::vector<Worker*>::iterator itw;
    for (itw = myWorkers.begin(); itw != myWorkers.end(); ++itw)
    {
        if ((*itw)->productionClock.getElapsedTime().asSeconds() > GameBalance::productCraftingTime &&
            productsCounter() < productsCapacity)
        {
            createProduct();
            Sound::notification();
            (*itw)->productionClock.restart();
            this->updateStatus();
        }
    }
    changeBuildingSprite();
}

void GoodsBuilding::changeBuildingSprite()
{
    if (myProducts.getWood() > 0
        || myProducts.getFood() > 0
        || myProducts.getGold() > 0
        || myProducts.getStone() > 0)
    {
        sprite.setTexture(textureWithProduct);
    }
    else sprite.setTexture(textureBasic);
}

void GoodsBuilding::giveProduct(Goods* luggage)
{
    luggage->setProduct(myProducts.whichProduct(), 1);
    myProducts.setProduct(myProducts.whichProduct(), -1);
}

unsigned int GoodsBuilding::productsCounter()
{
    switch (myProducts.whichProduct())
    {
        case 1:
            return (unsigned int) myProducts.getWood();
        case 2:
            return (unsigned int) myProducts.getStone();
        case 3:
            return (unsigned int) myProducts.getFood();
        case 4:
            return (unsigned int) myProducts.getGold();
        case 0:
            return 0;
        default:
            return 0;
    };
}

