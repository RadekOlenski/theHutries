#include "archer.h"

Archer::Archer(sf::RenderWindow* hutrieApplication, const std::vector<Unit*> &unitsFromGame,
               const std::vector<Unit*> &unitsForMoving, std::string pathName)
        : Soldier(hutrieApplication, unitsFromGame, unitsForMoving, pathName)
{

}

void Archer::animateTextureUp()
{
    if (frameCounter == 0)
    {
        switch (animationCounter)
        {
            case 0:
                this->changeTexture(Textures::archerMoveUp1);
                animationCounter++;
                break;
            case 1:
                this->changeTexture(Textures::archerMoveUp2);
                animationCounter++;
                break;
            case 2:
                this->changeTexture(Textures::archerMoveUp3);
                animationCounter++;
                break;
            case 3:
                this->changeTexture(Textures::archerMoveUp4);
                animationCounter++;
                break;
            case 4:
                this->changeTexture(Textures::archerMoveUp5);
                animationCounter++;
                break;
            case 5:
                this->changeTexture(Textures::archerMoveUp6);
                animationCounter++;
                break;
            case 6:
                this->changeTexture(Textures::archerMoveUp7);
                animationCounter++;
                break;
            case 7:
                this->changeTexture(Textures::archerMoveUp8);
                animationCounter = 0;
                break;
            default:
                break;
        }
    }
    frameCounter++;
    if(frameCounter > 10)
        frameCounter = 0;
}

void Archer::animateTextureDown()
{
    if (frameCounter == 0)
    {
        switch (animationCounter)
        {
            case 0:
                this->changeTexture(Textures::archerMoveDown1);
                animationCounter++;
                break;
            case 1:
                this->changeTexture(Textures::archerMoveDown2);
                animationCounter++;
                break;
            case 2:
                this->changeTexture(Textures::archerMoveDown3);
                animationCounter++;
                break;
            case 3:
                this->changeTexture(Textures::archerMoveDown4);
                animationCounter++;
                break;
            case 4:
                this->changeTexture(Textures::archerMoveDown5);
                animationCounter++;
                break;
            case 5:
                this->changeTexture(Textures::archerMoveDown6);
                animationCounter++;
                break;
            case 6:
                this->changeTexture(Textures::archerMoveDown7);
                animationCounter++;
                break;
            case 7:
                this->changeTexture(Textures::archerMoveDown8);
                animationCounter = 0;
                break;
            default:
                break;
        }
    }
    frameCounter++;
    if(frameCounter > 10)
        frameCounter = 0;
}

void Archer::animateTextureLeft()
{
    if (frameCounter == 0)
    {
        switch (animationCounter)
        {
            case 0:
                this->changeTexture(Textures::archerMoveLeft1);
                animationCounter++;
                break;
            case 1:
                this->changeTexture(Textures::archerMoveLeft2);
                animationCounter++;
                break;
            case 2:
                this->changeTexture(Textures::archerMoveLeft3);
                animationCounter++;
                break;
            case 3:
                this->changeTexture(Textures::archerMoveLeft4);
                animationCounter++;
                break;
            case 4:
                this->changeTexture(Textures::archerMoveLeft5);
                animationCounter++;
                break;
            case 5:
                this->changeTexture(Textures::archerMoveLeft6);
                animationCounter++;
                break;
            case 6:
                this->changeTexture(Textures::archerMoveLeft7);
                animationCounter++;
                break;
            case 7:
                this->changeTexture(Textures::archerMoveLeft8);
                animationCounter = 0;
                break;
            default:
                break;
        }
    }
    frameCounter++;
    if(frameCounter > 10)
        frameCounter = 0;
}

void Archer::animateTextureRight()
{
    if (frameCounter == 0)
    {
        switch (animationCounter)
        {
            case 0:
                this->changeTexture(Textures::archerMoveRight1);
                animationCounter++;
                break;
            case 1:
                this->changeTexture(Textures::archerMoveRight2);
                animationCounter++;
                break;
            case 2:
                this->changeTexture(Textures::archerMoveRight3);
                animationCounter++;
                break;
            case 3:
                this->changeTexture(Textures::archerMoveRight4);
                animationCounter++;
                break;
            case 4:
                this->changeTexture(Textures::archerMoveRight5);
                animationCounter++;
                break;
            case 5:
                this->changeTexture(Textures::archerMoveRight6);
                animationCounter++;
                break;
            case 6:
                this->changeTexture(Textures::archerMoveRight7);
                animationCounter++;
                break;
            case 7:
                this->changeTexture(Textures::archerMoveRight8);
                animationCounter = 0;
                break;
            default:
                break;
        }
    }
    frameCounter++;
    if(frameCounter > 10)
        frameCounter = 0;
}
