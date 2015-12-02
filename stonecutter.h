#ifndef STONECUTTER_H
#define STONECUTTER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

#include "goodsbuilding.h"

class StoneCutter : public GoodsBuilding
{
    public:
        StoneCutter(sf::RenderWindow *hutrieApplication, std::vector <Unit*> unitsFromGame, std::string pathName, int buildingType);
    private:
};

#endif // STONECUTTER_H
