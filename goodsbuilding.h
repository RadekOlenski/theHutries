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

class GoodsBuilding : public Building
{
public:
    GoodsBuilding(sf::RenderWindow *hutrieApplication, std::vector<Unit *> unitsFromGame, std::string pathName);
        //void updateStatus();
        void showButtons();
        void deactivateButtons();
        void buttonAction();
        virtual void createProduct() = 0;
        void checkProduction();
        Goods myProducts;
        void addWorker(Worker* worker);
        Worker* getWorker();
        int getWorkersSize();
        void giveProduct(Goods *luggage);
protected:

    void changeBuildingSprite();

    //virtual void getGoods();
        std::vector <Worker*> myWorkers;
        GUIButton callWorker;
        GUIText assignWorker;
        GUIButton goodsReady;
        GUIText goodReady;

        sf::Texture textureWithProduct;
        sf::Texture textureNoProduct;
};
#endif // GOODSBUILDING_H
