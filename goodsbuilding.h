#ifndef GOODSBUILDING_H
#define GOODSBUILDING_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "building.h"
#include "guibutton.h"
#include "guitext.h"
#include "goods.h"

class GoodsBuilding : public Building
{
public:
    GoodsBuilding(sf::RenderWindow *hutrieApplication, std::vector<Unit *> unitsFromGame, std::string pathName,
                  int buildingType);
        //void showStatus();
        void showButtons();
        void deactivateButtons();
        void buttonAction();
        virtual void createProduct() = 0;
        Goods myProducts;
protected:
        //virtual void getGoods();
        GUIButton callWorker;
        GUIText assignWorker;
        GUIButton goodsReady;
        GUIText goodReady;
};
#endif // GOODSBUILDING_H
