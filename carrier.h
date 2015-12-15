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
        sf::Thread carrierThread;
    private:
        bool arrived;
        Goods myLuggage;

};

#endif // CARRIER_H
