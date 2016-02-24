#include "goodsbuilding.h"
#include "sound.h"
#include <iostream>
#include <sstream>

using namespace std;

GoodsBuilding::GoodsBuilding(sf::RenderWindow* hutrieApplication, std::vector<Unit*> unitsFromGame)
        : Building(hutrieApplication, unitsFromGame),
          callWorker(1024 + 40, 500, hutrieApplication, 180, 45, false),
          goodsReady(1024 + 40, 560, hutrieApplication, 150, 45, false),
          assignWorker(1024 + 50, 500, 30, "Assign worker"),
          goodReady(1024 + 50, 560, 30, "Good ready")
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

void GoodsBuilding::checkProduction()
{
//    std::vector<Worker*>::iterator itw;
    for ( auto itw = myWorkers.begin(); itw != myWorkers.end(); ++itw)
    {
        if ((*itw)->getWorkingFlag() && (*itw)->getProductionTime() > GameBalance::productCraftingTime
            && productsCounter() < productsCapacity)
        {
            createProduct();
            Sound::notification();
            (*itw)->resetProductionTime();
            (*itw)->productionClock.restart();
            this->updateStatus();
        }
    }
    changeBuildingSprite();
}

void GoodsBuilding::changeBuildingSprite()
{
    if (buildingConstructed)
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

void GoodsBuilding::highlightButton()
{
    if(callWorker.checkBounds())
        assignWorker.highlight();
    else assignWorker.endHighlight();

    if(goodsReady.checkBounds())
        goodReady.highlight();
    else goodReady.endHighlight();

    if (bringStoneButton.checkBounds())
        bringStoneText.highlight();
    else bringStoneText.endHighlight();

    if (bringWoodButton.checkBounds())
        bringWoodText.highlight();
    else bringWoodText.endHighlight();

    if (constructButton.checkBounds())
        constructText.highlight();
    else constructText.endHighlight();
}
