//
// Created by radek on 11.12.2015.
//

#ifndef THEHUTRIES_FARM_H
#define THEHUTRIES_FARM_H

#include "SFML/graphics.hpp"
#include "goodsbuilding.h"

class Farm : public GoodsBuilding
{

    public:
        Farm(sf::RenderWindow *hutrieApplication, const std::vector<Unit *> &unitsFromGame, const std::string &pathName,
                 int buildingType);
    void createProduct();
    void showStatus();
};

#endif //THEHUTRIES_FARM_H
