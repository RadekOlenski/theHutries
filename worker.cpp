#include "unit.h"
#include "worker.h"


Worker::Worker(sf::RenderWindow *hutrieApplication, std::vector <Unit*> unitsFromGame, std::string pathName) : Hutrie(hutrieApplication,unitsFromGame,pathName)
{
    title.text.setString("Worker:");

    upTexture.loadFromFile("sprites/worker/up.png");
    downTexture.loadFromFile("sprites/worker/down.png");
    leftTexture.loadFromFile("sprites/worker/left.png");
}

void Worker::moveHutrie()
{
    toDirection(objectUnits.at(0)->field.getPosition().x, objectUnits.at(0)->field.getPosition().y );
    sprite.setTexture( transTexture );
    arrived = true;
}
