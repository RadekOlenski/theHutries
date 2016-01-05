#ifndef SAWMILL_H
#define SAWMILL_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

#include "goodsbuilding.h"

class Sawmill : public GoodsBuilding
{
    public:
        Sawmill(sf::RenderWindow *hutrieApplication, std::vector <Unit*> unitsFromGame, std::string pathName);
        void createProduct();
        void updateStatus();

    private:
        std::string goodType;
};

#endif // SAWMILL_H
