#ifndef GOODSBUILDING_H
#define GOODSBUILDING_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

#include "building.h"

class GoodsBuilding : public Building
{
    public:
        GoodsBuilding(sf::RenderWindow *hutrieApplication, std::vector <Unit*> unitsFromGame, std::string pathName, int buildingType);
        void showStatus();
    protected:
        //virtual void getGoods();
};

#endif // GOODSBUILDING_H
