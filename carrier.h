#ifndef CARRIER_H
#define CARRIER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

#include "hutrie.h"
#include "goods.h"


class Carrier : public Hutrie
{
    public:
        Carrier(sf::RenderWindow *hutrieApplication, std::vector <Unit*> unitsFromGame, std::string pathName, bool onBuilding = true);
        void moveHutrie();
        bool haveArrived () {return arrived;};
        void setArrived (bool arrived) {this->arrived = arrived;};
        void comeBack();
        Goods getMyLuggage() {return myLuggage;};
        sf::Thread carrierThread;
        Goods myLuggage;
    private:
        bool arrived;

};

#endif // CARRIER_H
