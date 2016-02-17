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
    if (pauseThread)
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

void Worker::animateTextureDown()
{
    if (frameCounter == 0)
    {
        switch (animationCounter)
        {
            case 0:
                this->changeTexture(Textures::workerMoveDown1);
                animationCounter++;
                break;
            case 1:
                this->changeTexture(Textures::workerMoveDown2);
                animationCounter++;
                break;
            case 2:
                this->changeTexture(Textures::workerMoveDown3);
                animationCounter++;
                break;
            case 3:
                this->changeTexture(Textures::workerMoveDown4);
                animationCounter++;
                break;
            case 4:
                this->changeTexture(Textures::workerMoveDown5);
                animationCounter++;
                break;
            case 5:
                this->changeTexture(Textures::workerMoveDown6);
                animationCounter++;
                break;
            case 6:
                this->changeTexture(Textures::workerMoveDown7);
                animationCounter++;
                break;
            case 7:
                this->changeTexture(Textures::workerMoveDown8);
                animationCounter++;
                break;
            case 8:
                this->changeTexture(Textures::workerMoveDown9);
                animationCounter = 0;
                break;
            default:
                break;
        }
    }

    frameCounter++;
    if (frameCounter > 5)
        frameCounter = 0;
}

void Worker::animateTextureUp()
{
    if (frameCounter == 0)
    {
        switch (animationCounter)
        {
            case 0:
                this->changeTexture(Textures::workerMoveUp1);
                animationCounter++;
                break;
            case 1:
                this->changeTexture(Textures::workerMoveUp2);
                animationCounter++;
                break;
            case 2:
                this->changeTexture(Textures::workerMoveUp3);
                animationCounter++;
                break;
            case 3:
                this->changeTexture(Textures::workerMoveUp4);
                animationCounter++;
                break;
            case 4:
                this->changeTexture(Textures::workerMoveUp5);
                animationCounter++;
                break;
            case 5:
                this->changeTexture(Textures::workerMoveUp6);
                animationCounter++;
                break;
            case 6:
                this->changeTexture(Textures::workerMoveUp7);
                animationCounter++;
                break;
            case 7:
                this->changeTexture(Textures::workerMoveUp8);
                animationCounter = 0;
                break;
            default:
                break;
        }
    }

    frameCounter++;
    if (frameCounter > 5)
        frameCounter = 0;
}

void Worker::animateTextureRight()
{
    if (frameCounter == 0)
    {
        switch (animationCounter)
        {
            case 0:
                this->changeTexture(Textures::workerMoveRight1);
                animationCounter++;
                break;
            case 1:
                this->changeTexture(Textures::workerMoveRight2);
                animationCounter++;
                break;
            case 2:
                this->changeTexture(Textures::workerMoveRight3);
                animationCounter++;
                break;
            case 3:
                this->changeTexture(Textures::workerMoveRight4);
                animationCounter++;
                break;
            case 4:
                this->changeTexture(Textures::workerMoveRight5);
                animationCounter++;
                break;
            case 5:
                this->changeTexture(Textures::workerMoveRight6);
                animationCounter++;
                break;
            case 6:
                this->changeTexture(Textures::workerMoveRight7);
                animationCounter++;
                break;
            case 7:
                this->changeTexture(Textures::workerMoveRight8);
                animationCounter = 0;
                break;
            default:
                break;
        }
    }

    frameCounter++;
    if (frameCounter > 5)
        frameCounter = 0;
}

void Worker::animateTextureLeft()
{
    if (frameCounter == 0)
    {
        switch (animationCounter)
        {
            case 0:
                this->changeTexture(Textures::workerMoveLeft1);
                animationCounter++;
                break;
            case 1:
                this->changeTexture(Textures::workerMoveLeft2);
                animationCounter++;
                break;
            case 2:
                this->changeTexture(Textures::workerMoveLeft3);
                animationCounter++;
                break;
            case 3:
                this->changeTexture(Textures::workerMoveLeft4);
                animationCounter++;
                break;
            case 4:
                this->changeTexture(Textures::workerMoveLeft5);
                animationCounter++;
                break;
            case 5:
                this->changeTexture(Textures::workerMoveLeft6);
                animationCounter++;
                break;
            case 6:
                this->changeTexture(Textures::workerMoveLeft7);
                animationCounter++;
                break;
            case 7:
                this->changeTexture(Textures::workerMoveLeft8);
                animationCounter++;
                break;
            case 8:
                this->changeTexture(Textures::workerMoveLeft9);
                animationCounter = 0;
                break;
            default:
                break;
        }
    }

    frameCounter++;
    if (frameCounter > 5)
        frameCounter = 0;
}