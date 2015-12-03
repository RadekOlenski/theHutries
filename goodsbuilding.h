#ifndef GOODSBUILDING_H
#define GOODSBUILDING_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

#include "building.h"
#include "guibutton.h"

class GoodsBuilding : public Building
{
    public:
        GoodsBuilding(sf::RenderWindow *hutrieApplication, std::vector <Unit*> unitsFromGame, std::string pathName, int buildingType);
        void showStatus();
        void showButtons();
        void deactivateButtons();
        void buttonAction();
    protected:
        //virtual void getGoods();
        GUIButton callWorker;
        GUIButton goodsReady;

};

#endif // GOODSBUILDING_H
