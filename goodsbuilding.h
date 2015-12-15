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
        Goods myProducts;};

#endif // GOODSBUILDING_H
