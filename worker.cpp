#include "worker.h"

Worker::Worker(sf::RenderWindow *hutrieApplication, std::vector <Unit*> unitsFromGame, std::string pathName, bool onBuilding) : Hutrie(hutrieApplication,unitsFromGame,pathName)
{
    title.text.setString("Worker:");

    upTexture.loadFromFile("sprites/worker/up.png");
    downTexture.loadFromFile("sprites/worker/down.png");
    leftTexture.loadFromFile("sprites/worker/left.png");
}
