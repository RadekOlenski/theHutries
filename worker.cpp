#include "unit.h"
#include "worker.h"

Worker::Worker(sf::RenderWindow* hutrieApplication, std::vector<Unit*> unitsFromGame, std::string pathName)
        : Hutrie(hutrieApplication, unitsFromGame, pathName)
{
    title.text.setString("Worker:");

    upTexture.loadFromFile(Textures::workerUp);
    downTexture.loadFromFile(Textures::workerDown);
    leftTexture.loadFromFile(Textures::workerLeft);
    sprite.setTexture(transTexture);
    productionTime = 0;
    actualProductionTime = 0;
    workingFlag = false;
}

void Worker::moveHutrie()
{
    if(pauseThread)
    {
        sf::sleep(sf::seconds(0.7));
    }
    busy = true;
    productionClock.restart();
    toDirection(objectUnits.at(2)->field.getPosition().x, objectUnits.at(2)->field.getPosition().y);
    sprite.setTexture(transTexture);
    productionClock.restart();
    workingFlag = true;
}

float Worker::getProductionTime()
{
    productionTime = actualProductionTime + productionClock.getElapsedTime().asSeconds();
    return productionTime;
}

void Worker::pauseProduction()
{
    actualProductionTime += productionClock.getElapsedTime().asSeconds();
}

void Worker::resumeProduction()
{
    productionClock.restart();
}

void Worker::resetProductionTime()
{
    productionTime = 0;
    actualProductionTime = 0;
}
