//
// Created by Master on 08.12.2015.
//

#ifndef THEHUTRIES_GOLDMINE_H
#define THEHUTRIES_GOLDMINE_H

#include <SFML/Graphics.hpp>
#include "goodsbuilding.h"


class Goldmine : public GoodsBuilding
{

public:
    Goldmine(sf::RenderWindow *hutrieApplication, const std::vector<Unit *> &unitsFromGame, const std::string &pathName);
    void createProduct();
    void updateStatus();


};


#endif //THEHUTRIES_GOLDMINE_H
