#ifndef GOODSBUILDING_H
#define GOODSBUILDING_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "building.h"
#include "guibutton.h"
#include "guitext.h"
#include "goods.h"
#include "worker.h"
#include "gamebalance.h"

class GoodsBuilding : public Building
{
public:

    GoodsBuilding(sf::RenderWindow* hutrieApplication, std::vector<Unit*> unitsFromGame);

    void showButtons();

    void deactivateButtons();

    void buttonAction();

    virtual void createProduct() = 0;

    void checkProduction();

    Goods myProducts;

    void giveProduct(Goods* luggage);

    unsigned int productsCounter();

    void highlightButton();

protected:

    void changeBuildingSprite();

    GUIButton callWorker;
    GUIText assignWorker;
    GUIButton goodsReady;
    GUIText goodReady;
    unsigned int productsCapacity = GameBalance::maxProductsInStore;
    sf::Texture textureWithProduct;
};

#endif // GOODSBUILDING_H
