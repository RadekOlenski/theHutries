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

    void moveHutrie();

    float getProductionTime();

    void pauseProduction();

    void resumeProduction();

    void resetProductionTime();

    sf::Clock productionClock;

    bool getWorkingFlag() {return workingFlag;}

    void animateTextureUp();

    void animateTextureDown();

    void animateTextureLeft();

    void animateTextureRight();

private:
    float productionTime;
    float actualProductionTime;
    bool workingFlag;
};

#endif // WORKER_H
