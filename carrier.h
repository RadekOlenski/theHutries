#ifndef CARRIER_H
#define CARRIER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

#include "hutrie.h"
#include "goods.h"
#include "building.h"
#include "textures.h"

class Building;

class Carrier : public Hutrie
{
public:
    Carrier(sf::RenderWindow* hutrieApplication, std::vector<Unit*> unitsFromGame,
            std::string pathName = Textures::carrierRight);

    void moveHutrie();

    bool haveArrived() { return arrived; };;

    bool haveReturned() { return returned; };

    void setReturned(bool returned) { this->returned = returned; };

    void comeBack();;
    sf::Thread carrierThread;
    Goods myLuggage;

    Building* getBuilding() { return myBuilding; };

    void setBuilding(Building* newBuilding) { myBuilding = newBuilding; };

    void animateTextureDown();

    void animateTextureUp();

    void animateTextureRight();

    void animateTextureLeft();

    //void toDirection(float targetX, float targetY);
private:

    Building* myBuilding;
    bool arrived;
    bool returned;
};

#endif // CARRIER_H
