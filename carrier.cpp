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
                    this->changeTexture(Textures::carrierEmptyMoveLeft1);
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
                    this->changeTexture(Textures::carrierWoodMoveRight1);
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
                    animationCounter++;
                    break;
                case 7:
                    this->changeTexture(Textures::carrierWoodMoveDown8);
                    animationCounter = 0;
                    break;
                default:
                    break;
            }
        }
        else if(myLuggage.getStone() > 0)
        {
            switch (animationCounter)
            {
                case 0:
                    this->changeTexture(Textures::carrierStoneMoveDown1);
                    animationCounter++;
                    break;
                case 1:
                    this->changeTexture(Textures::carrierStoneMoveDown2);
                    animationCounter++;
                    break;
                case 2:
                    this->changeTexture(Textures::carrierStoneMoveDown3);
                    animationCounter++;
                    break;
                case 3:
                    this->changeTexture(Textures::carrierStoneMoveDown4);
                    animationCounter++;
                    break;
                case 4:
                    this->changeTexture(Textures::carrierStoneMoveDown5);
                    animationCounter++;
                    break;
                case 5:
                    this->changeTexture(Textures::carrierStoneMoveDown6);
                    animationCounter++;
                    break;
                case 6:
                    this->changeTexture(Textures::carrierStoneMoveDown7);
                    animationCounter++;
                    break;
                case 7:
                    this->changeTexture(Textures::carrierStoneMoveDown8);
                    animationCounter = 0;
                    break;
                default:
                    break;
            }
        }
        else if(myLuggage.getFood() > 0)
        {
            switch (animationCounter)
            {
                case 0:
                    this->changeTexture(Textures::carrierFoodMoveDown1);
                    animationCounter++;
                    break;
                case 1:
                    this->changeTexture(Textures::carrierFoodMoveDown2);
                    animationCounter++;
                    break;
                case 2:
                    this->changeTexture(Textures::carrierFoodMoveDown3);
                    animationCounter++;
                    break;
                case 3:
                    this->changeTexture(Textures::carrierFoodMoveDown4);
                    animationCounter++;
                    break;
                case 4:
                    this->changeTexture(Textures::carrierFoodMoveDown5);
                    animationCounter++;
                    break;
                case 5:
                    this->changeTexture(Textures::carrierFoodMoveDown6);
                    animationCounter++;
                    break;
                case 6:
                    this->changeTexture(Textures::carrierFoodMoveDown7);
                    animationCounter++;
                    break;
                case 7:
                    this->changeTexture(Textures::carrierFoodMoveDown8);
                    animationCounter = 0;
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
                    animationCounter++;
                    break;
                case 7:
                    this->changeTexture(Textures::carrierWoodMoveUp8);
                    animationCounter = 0;
                    break;
                default:
                    break;
            }
        }
        else if(myLuggage.getStone() > 0)
        {
            switch (animationCounter)
            {
                case 0:
                    this->changeTexture(Textures::carrierStoneMoveUp1);
                    animationCounter++;
                    break;
                case 1:
                    this->changeTexture(Textures::carrierStoneMoveUp2);
                    animationCounter++;
                    break;
                case 2:
                    this->changeTexture(Textures::carrierStoneMoveUp3);
                    animationCounter++;
                    break;
                case 3:
                    this->changeTexture(Textures::carrierStoneMoveUp4);
                    animationCounter++;
                    break;
                case 4:
                    this->changeTexture(Textures::carrierStoneMoveUp5);
                    animationCounter++;
                    break;
                case 5:
                    this->changeTexture(Textures::carrierStoneMoveUp6);
                    animationCounter++;
                    break;
                case 6:
                    this->changeTexture(Textures::carrierStoneMoveUp7);
                    animationCounter++;
                    break;
                case 7:
                    this->changeTexture(Textures::carrierStoneMoveUp8);
                    animationCounter = 0;
                    break;
                default:
                    break;
            }
        }
        else if(myLuggage.getFood() > 0)
        {
            switch (animationCounter)
            {
                case 0:
                    this->changeTexture(Textures::carrierFoodMoveUp1);
                    animationCounter++;
                    break;
                case 1:
                    this->changeTexture(Textures::carrierFoodMoveUp2);
                    animationCounter++;
                    break;
                case 2:
                    this->changeTexture(Textures::carrierFoodMoveUp3);
                    animationCounter++;
                    break;
                case 3:
                    this->changeTexture(Textures::carrierFoodMoveUp4);
                    animationCounter++;
                    break;
                case 4:
                    this->changeTexture(Textures::carrierFoodMoveUp5);
                    animationCounter++;
                    break;
                case 5:
                    this->changeTexture(Textures::carrierFoodMoveUp6);
                    animationCounter++;
                    break;
                case 6:
                    this->changeTexture(Textures::carrierFoodMoveUp7);
                    animationCounter++;
                    break;
                case 7:
                    this->changeTexture(Textures::carrierFoodMoveUp8);
                    animationCounter = 0;
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
                    animationCounter++;
                    break;
                case 7:
                    this->changeTexture(Textures::carrierWoodMoveRight8);
                    animationCounter =0;
                    break;
                default:
                    break;
            }
        }
        else if(myLuggage.getStone() > 0)
        {
            switch (animationCounter)
            {
                case 0:
                    this->changeTexture(Textures::carrierStoneMoveRight1);
                    animationCounter++;
                    break;
                case 1:
                    this->changeTexture(Textures::carrierStoneMoveRight2);
                    animationCounter++;
                    break;
                case 2:
                    this->changeTexture(Textures::carrierStoneMoveRight3);
                    animationCounter++;
                    break;
                case 3:
                    this->changeTexture(Textures::carrierStoneMoveRight4);
                    animationCounter++;
                    break;
                case 4:
                    this->changeTexture(Textures::carrierStoneMoveRight5);
                    animationCounter++;
                    break;
                case 5:
                    this->changeTexture(Textures::carrierStoneMoveRight6);
                    animationCounter++;
                    break;
                case 6:
                    this->changeTexture(Textures::carrierStoneMoveRight7);
                    animationCounter++;
                    break;
                case 7:
                    this->changeTexture(Textures::carrierStoneMoveRight8);
                    animationCounter = 0;
                    break;
                default:
                    break;
            }
        }
        else if(myLuggage.getFood() > 0)
        {
            switch (animationCounter)
            {
                case 0:
                    this->changeTexture(Textures::carrierFoodMoveRight1);
                    animationCounter++;
                    break;
                case 1:
                    this->changeTexture(Textures::carrierFoodMoveRight2);
                    animationCounter++;
                    break;
                case 2:
                    this->changeTexture(Textures::carrierFoodMoveRight3);
                    animationCounter++;
                    break;
                case 3:
                    this->changeTexture(Textures::carrierFoodMoveRight4);
                    animationCounter++;
                    break;
                case 4:
                    this->changeTexture(Textures::carrierFoodMoveRight5);
                    animationCounter++;
                    break;
                case 5:
                    this->changeTexture(Textures::carrierFoodMoveRight6);
                    animationCounter++;
                    break;
                case 6:
                    this->changeTexture(Textures::carrierFoodMoveRight7);
                    animationCounter++;
                    break;
                case 7:
                    this->changeTexture(Textures::carrierFoodMoveRight8);
                    animationCounter = 0;
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
                    animationCounter++;
                    break;
                case 7:
                    this->changeTexture(Textures::carrierWoodMoveLeft8);
                    animationCounter = 0;
                    break;
                default:
                    break;
            }
        }
        else if(myLuggage.getStone() > 0)
        {
            switch (animationCounter)
            {
                case 0:
                    this->changeTexture(Textures::carrierStoneMoveLeft1);
                    animationCounter++;
                    break;
                case 1:
                    this->changeTexture(Textures::carrierStoneMoveLeft2);
                    animationCounter++;
                    break;
                case 2:
                    this->changeTexture(Textures::carrierStoneMoveLeft3);
                    animationCounter++;
                    break;
                case 3:
                    this->changeTexture(Textures::carrierStoneMoveLeft4);
                    animationCounter++;
                    break;
                case 4:
                    this->changeTexture(Textures::carrierStoneMoveLeft5);
                    animationCounter++;
                    break;
                case 5:
                    this->changeTexture(Textures::carrierStoneMoveLeft6);
                    animationCounter++;
                    break;
                case 6:
                    this->changeTexture(Textures::carrierStoneMoveLeft7);
                    animationCounter++;
                    break;
                case 7:
                    this->changeTexture(Textures::carrierStoneMoveLeft8);
                    animationCounter = 0;
                    break;
                default:
                    break;
            }
        }
        else if(myLuggage.getFood() > 0)
        {
            switch (animationCounter)
            {
                case 0:
                    this->changeTexture(Textures::carrierFoodMoveLeft1);
                    animationCounter++;
                    break;
                case 1:
                    this->changeTexture(Textures::carrierFoodMoveLeft2);
                    animationCounter++;
                    break;
                case 2:
                    this->changeTexture(Textures::carrierFoodMoveLeft3);
                    animationCounter++;
                    break;
                case 3:
                    this->changeTexture(Textures::carrierFoodMoveLeft4);
                    animationCounter++;
                    break;
                case 4:
                    this->changeTexture(Textures::carrierFoodMoveLeft5);
                    animationCounter++;
                    break;
                case 5:
                    this->changeTexture(Textures::carrierFoodMoveLeft6);
                    animationCounter++;
                    break;
                case 6:
                    this->changeTexture(Textures::carrierFoodMoveLeft7);
                    animationCounter++;
                    break;
                case 7:
                    this->changeTexture(Textures::carrierFoodMoveLeft8);
                    animationCounter = 0;
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
