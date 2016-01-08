#include "unit.h"
#include "worker.h"
#include "textures.h"


Worker::Worker(sf::RenderWindow *hutrieApplication, std::vector <Unit*> unitsFromGame, std::string pathName) : Hutrie(hutrieApplication,unitsFromGame,pathName)
{
    title.text.setString("Worker:");

    upTexture.loadFromFile(Textures::workerUp);
    downTexture.loadFromFile(Textures::workerDown);
    leftTexture.loadFromFile(Textures::workerLeft);
    sprite.setTexture( transTexture );
}

void Worker::moveHutrie()
{
    productionClock.restart();
    toDirection(objectUnits.at(2)->field.getPosition().x, objectUnits.at(2)->field.getPosition().y );
    sprite.setTexture( transTexture );
    arrived = true;
    productionClock.restart();
}
