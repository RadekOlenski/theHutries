#ifndef WORKER_H
#define WORKER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

#include "hutrie.h"


class Worker : public Hutrie
{
    public:
        Worker(sf::RenderWindow *hutrieApplication, std::vector <Unit*> unitsFromGame, std::string pathName, bool onBuilding = true);
    protected:
    private:
};

#endif // WORKER_H
