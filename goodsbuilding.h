#ifndef GOODSBUILDING_H
#define GOODSBUILDING_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "world.h"
#include "building.h"
#include "guibutton.h"
#include "guitext.h"
#include "goods.h"

class GoodsBuilding : public Building
{
public:
    GoodsBuilding(sf::RenderWindow *hutrieApplication, std::vector<Unit *> unitsFromGame, std::string pathName,
                  int buildingType);

    void showStatus();

    void showButtons();

    void deactivateButtons();

    void buttonAction();

    virtual void getGoods(std::string goodType);

protected:
    //virtual void getGoods();
    GUIButton callWorker;
    GUIText assignWorker;
    GUIButton goodsReady;
    GUIText goodReady;
private:
    std::vector<Goods *> goodStore;
};

#endif // GOODSBUILDING_H
