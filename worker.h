#ifndef WORKER_H
#define WORKER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

#include "hutrie.h"



class Worker : public Hutrie
{
    public:
        Worker(sf::RenderWindow *hutrieApplication, std::vector <Unit*> unitsFromGame, std::string pathName);
        void moveHutrie();
        bool haveArrived () {return arrived;};
        void setArrived (bool arrived) {this->arrived = arrived;};
        sf::Clock productionClock;
    private:
        bool arrived;
};

#endif // WORKER_H
