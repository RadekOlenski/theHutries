#include "unit.h"
#include "carrier.h"
#include "gamebalance.h"


Carrier::Carrier(sf::RenderWindow* hutrieApplication, std::vector<Unit*> unitsFromGame, std::string pathName)
        : Hutrie(hutrieApplication, unitsFromGame, pathName), carrierThread(&Carrier::comeBack, this)
{
    arrived = false;
    sprite.setTexture(transparentTexture);
}

void Carrier::moveHutrie()
{
    if (pauseThread)
    {
        sf::sleep(sf::seconds(0.7));
    }
    busy = true;
    unsigned int door = (unsigned int) myBuilding->getDoorIndex();
    toDirection(objectUnits.at(door)->field.getPosition().x, objectUnits.at(door)->field.getPosition().y);
    sprite.setTexture(transparentTexture);
    sf::sleep(sf::seconds(GameBalance::carrierLoading));
    arrived = true;
}

void Carrier::comeBack()
{
    if (pauseThread)
    {
        sf::sleep(sf::seconds(0.7));
    }
    arrived = false;
    toDirection(6 * 64, 7 * 64);
    busy = false;
    returned = true;
    sprite.setTexture(transparentTexture);
}

void Carrier::animateTextureDown()
{
    if (frameCounter == 0)
    {
        if(myLuggage.isEmpty())
        {
            switch (animationCounter)
            {
                case 0:
                    this->changeTexture(Textures::carrierEmptyMoveDown1);
                    animationCounter++;
                    break;
                case 1:
                    this->changeTexture(Textures::carrierEmptyMoveDown2);
                    animationCounter++;
                    break;
                case 2:
                    this->changeTexture(Textures::carrierEmptyMoveDown3);
                    animationCounter++;
                    break;
                case 3:
                    this->changeTexture(Textures::carrierEmptyMoveDown4);
                    animationCounter++;
                    break;
                case 4:
                    this->changeTexture(Textures::carrierEmptyMoveDown5);
                    animationCounter++;
                    break;
                case 5:
                    this->changeTexture(Textures::carrierEmptyMoveDown6);
                    animationCounter++;
                    break;
                case 6:
                    this->changeTexture(Textures::carrierEmptyMoveDown7);
                    animationCounter++;
                    break;
                case 7:
                    this->changeTexture(Textures::carrierEmptyMoveDown8);
                    animationCounter = 0;
                    break;
                default:
                    break;
            }
        }
        else if(myLuggage.getWood() > 0)
        {
            switch (animationCounter)
            {
                case 0:
                    this->changeTexture(Textures::carrierWoodMoveDown1);
                    animationCounter++;
                    break;
                case 1:
                    this->changeTexture(Textures::carrierWoodMoveDown2);
                    animationCounter++;
                    break;
                case 2:
                    this->changeTexture(Textures::carrierWoodMoveDown3);
                    animationCounter++;
                    break;
                case 3:
                    this->changeTexture(Textures::carrierWoodMoveDown4);
                    animationCounter++;
                    break;
                case 4:
                    this->changeTexture(Textures::carrierWoodMoveDown5);
                    animationCounter++;
                    break;
                case 5:
                    this->changeTexture(Textures::carrierWoodMoveDown6);
                    animationCounter++;
                    break;
                case 6:
                    this->changeTexture(Textures::carrierWoodMoveDown7);
                    animationCounter =0;
                    break;
                default:
                    break;
            }
        }
    }

    frameCounter++;
    if (frameCounter > 5)
        frameCounter = 0;
}

void Carrier::animateTextureUp()
{
    if (frameCounter == 0)
    {
        if(myLuggage.isEmpty())
        {
            switch (animationCounter)
            {
                case 0:
                    this->changeTexture(Textures::carrierEmptyMoveUp1);
                    animationCounter++;
                    break;
                case 1:
                    this->changeTexture(Textures::carrierEmptyMoveUp2);
                    animationCounter++;
                    break;
                case 2:
                    this->changeTexture(Textures::carrierEmptyMoveUp3);
                    animationCounter++;
                    break;
                case 3:
                    this->changeTexture(Textures::carrierEmptyMoveUp4);
                    animationCounter++;
                    break;
                case 4:
                    this->changeTexture(Textures::carrierEmptyMoveUp5);
                    animationCounter++;
                    break;
                case 5:
                    this->changeTexture(Textures::carrierEmptyMoveUp6);
                    animationCounter++;
                    break;
                case 6:
                    this->changeTexture(Textures::carrierEmptyMoveUp7);
                    animationCounter = 0;
                    break;
                default:
                    break;
            }
        }
        else if(myLuggage.getWood() > 0)
        {
            switch (animationCounter)
            {
                case 0:
                    this->changeTexture(Textures::carrierWoodMoveUp1);
                    animationCounter++;
                    break;
                case 1:
                    this->changeTexture(Textures::carrierWoodMoveUp2);
                    animationCounter++;
                    break;
                case 2:
                    this->changeTexture(Textures::carrierWoodMoveUp3);
                    animationCounter++;
                    break;
                case 3:
                    this->changeTexture(Textures::carrierWoodMoveUp4);
                    animationCounter++;
                    break;
                case 4:
                    this->changeTexture(Textures::carrierWoodMoveUp5);
                    animationCounter++;
                    break;
                case 5:
                    this->changeTexture(Textures::carrierWoodMoveUp6);
                    animationCounter++;
                    break;
                case 6:
                    this->changeTexture(Textures::carrierWoodMoveUp7);
                    animationCounter =0;
                    break;
                default:
                    break;
            }
        }
    }

    frameCounter++;
    if (frameCounter > 5)
        frameCounter = 0;
}

void Carrier::animateTextureRight()
{
    if (frameCounter == 0)
    {
        if(myLuggage.isEmpty())
        {
            switch (animationCounter)
            {
                case 0:
                    this->changeTexture(Textures::carrierEmptyMoveRight1);
                    animationCounter++;
                    break;
                case 1:
                    this->changeTexture(Textures::carrierEmptyMoveRight2);
                    animationCounter++;
                    break;
                case 2:
                    this->changeTexture(Textures::carrierEmptyMoveRight3);
                    animationCounter++;
                    break;
                case 3:
                    this->changeTexture(Textures::carrierEmptyMoveRight4);
                    animationCounter++;
                    break;
                case 4:
                    this->changeTexture(Textures::carrierEmptyMoveRight5);
                    animationCounter++;
                    break;
                case 5:
                    this->changeTexture(Textures::carrierEmptyMoveRight6);
                    animationCounter++;
                    break;
                case 6:
                    this->changeTexture(Textures::carrierEmptyMoveRight7);
                    animationCounter++;
                    break;
                case 7:
                    this->changeTexture(Textures::carrierEmptyMoveRight8);
                    animationCounter = 0;
                    break;
                default:
                    break;
            }
        }
        else if(myLuggage.getWood() > 0)
        {
            switch (animationCounter)
            {
                case 0:
                    this->changeTexture(Textures::carrierWoodMoveRight1);
                    animationCounter++;
                    break;
                case 1:
                    this->changeTexture(Textures::carrierWoodMoveRight2);
                    animationCounter++;
                    break;
                case 2:
                    this->changeTexture(Textures::carrierWoodMoveRight3);
                    animationCounter++;
                    break;
                case 3:
                    this->changeTexture(Textures::carrierWoodMoveRight4);
                    animationCounter++;
                    break;
                case 4:
                    this->changeTexture(Textures::carrierWoodMoveRight5);
                    animationCounter++;
                    break;
                case 5:
                    this->changeTexture(Textures::carrierWoodMoveRight6);
                    animationCounter++;
                    break;
                case 6:
                    this->changeTexture(Textures::carrierWoodMoveRight7);
                    animationCounter =0;
                    break;
                default:
                    break;
            }
        }
        else this->changeTexture(Textures::carrierRight);
    }

    frameCounter++;
    if (frameCounter > 5)
        frameCounter = 0;
}

void Carrier::animateTextureLeft()
{
    if (frameCounter == 0)
    {
        if(myLuggage.isEmpty())
        {
            switch (animationCounter)
            {
                case 0:
                    this->changeTexture(Textures::carrierEmptyMoveLeft1);
                    animationCounter++;
                    break;
                case 1:
                    this->changeTexture(Textures::carrierEmptyMoveLeft2);
                    animationCounter++;
                    break;
                case 2:
                    this->changeTexture(Textures::carrierEmptyMoveLeft3);
                    animationCounter++;
                    break;
                case 3:
                    this->changeTexture(Textures::carrierEmptyMoveLeft4);
                    animationCounter++;
                    break;
                case 4:
                    this->changeTexture(Textures::carrierEmptyMoveLeft5);
                    animationCounter++;
                    break;
                case 5:
                    this->changeTexture(Textures::carrierEmptyMoveLeft6);
                    animationCounter++;
                    break;
                case 6:
                    this->changeTexture(Textures::carrierEmptyMoveLeft7);
                    animationCounter++;
                    break;
                case 7:
                    this->changeTexture(Textures::carrierEmptyMoveLeft8);
                    animationCounter = 0;
                    break;
                default:
                    break;
            }
        }
        else if(myLuggage.getWood() > 0)
        {
            switch (animationCounter)
            {
                case 0:
                    this->changeTexture(Textures::carrierWoodMoveLeft1);
                    animationCounter++;
                    break;
                case 1:
                    this->changeTexture(Textures::carrierWoodMoveLeft2);
                    animationCounter++;
                    break;
                case 2:
                    this->changeTexture(Textures::carrierWoodMoveLeft3);
                    animationCounter++;
                    break;
                case 3:
                    this->changeTexture(Textures::carrierWoodMoveLeft4);
                    animationCounter++;
                    break;
                case 4:
                    this->changeTexture(Textures::carrierWoodMoveLeft5);
                    animationCounter++;
                    break;
                case 5:
                    this->changeTexture(Textures::carrierWoodMoveLeft6);
                    animationCounter++;
                    break;
                case 6:
                    this->changeTexture(Textures::carrierWoodMoveLeft7);
                    animationCounter =0;
                    break;
                default:
                    break;
            }
        }
    }

    frameCounter++;
    if (frameCounter > 5)
        frameCounter = 0;
}
