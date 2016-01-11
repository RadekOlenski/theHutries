#ifndef WORKER_H
#define WORKER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

#include "hutrie.h"
#include "textures.h"


class Worker : public Hutrie
{
public:

    Worker(sf::RenderWindow* hutrieApplication, std::vector<Unit*> unitsFromGame,
           std::string pathName = Textures::workerRight);

    void moveHutrie();;;
    sf::Clock productionClock;
};

#endif // WORKER_H
