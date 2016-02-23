#include "warrior.h"

Warrior::Warrior(sf::RenderWindow* hutrieApplication, const std::vector<Unit*> &unitsFromGame,
                 const std::vector<Unit*> &unitsForMoving, std::string pathName)
        : Soldier(hutrieApplication, unitsFromGame, unitsForMoving, pathName)
{
};

void Warrior::animateTextureUp()
{
  if (frameCounter == 0)
  {
      switch (animationCounter)
      {
        case 0:
          this->changeTexture(Textures::warriorMoveUp1);
              animationCounter++;
              break;
        case 1:
          this->changeTexture(Textures::warriorMoveUp2);
              animationCounter++;
              break;
        case 2:
          this->changeTexture(Textures::warriorMoveUp3);
              animationCounter++;
              break;
        case 3:
          this->changeTexture(Textures::warriorMoveUp4);
              animationCounter++;
              break;
        case 4:
          this->changeTexture(Textures::warriorMoveUp5);
              animationCounter++;
              break;
        case 5:
          this->changeTexture(Textures::warriorMoveUp6);
              animationCounter++;
              break;
        case 6:
          this->changeTexture(Textures::warriorMoveUp7);
              animationCounter++;
              break;
        case 7:
          this->changeTexture(Textures::warriorMoveUp8);
              animationCounter++;
              break;
        case 8:
          this->changeTexture(Textures::warriorMoveUp9);
              animationCounter++;
              break;
        case 9:
          this->changeTexture(Textures::warriorMoveUp10);
              animationCounter++;
              break;
        case 10:
          this->changeTexture(Textures::warriorMoveUp11);
              animationCounter++;
              break;
        case 11:
          this->changeTexture(Textures::warriorMoveUp12);
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

void Warrior::animateTextureDown()
{
  if (frameCounter == 0)
  {
    switch (animationCounter)
    {
      case 0:
        this->changeTexture(Textures::warriorMoveDown1);
            animationCounter++;
            break;
      case 1:
        this->changeTexture(Textures::warriorMoveDown2);
            animationCounter++;
            break;
      case 2:
        this->changeTexture(Textures::warriorMoveDown3);
            animationCounter++;
            break;
      case 3:
        this->changeTexture(Textures::warriorMoveDown4);
            animationCounter++;
            break;
      case 4:
        this->changeTexture(Textures::warriorMoveDown5);
            animationCounter++;
            break;
      case 5:
        this->changeTexture(Textures::warriorMoveDown6);
            animationCounter++;
            break;
      case 6:
        this->changeTexture(Textures::warriorMoveDown7);
            animationCounter++;
            break;
      case 7:
        this->changeTexture(Textures::warriorMoveDown8);
            animationCounter++;
            break;
      case 8:
        this->changeTexture(Textures::warriorMoveDown9);
            animationCounter++;
            break;
      case 9:
        this->changeTexture(Textures::warriorMoveDown10);
            animationCounter++;
            break;
      case 10:
        this->changeTexture(Textures::warriorMoveDown11);
            animationCounter++;
            break;
      case 11:
        this->changeTexture(Textures::warriorMoveDown12);
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

void Warrior::animateTextureLeft()
{
  if (frameCounter == 0)
  {
    switch (animationCounter)
    {
      case 0:
        this->changeTexture(Textures::warriorMoveLeft1);
            animationCounter++;
            break;
      case 1:
        this->changeTexture(Textures::warriorMoveLeft2);
            animationCounter++;
            break;
      case 2:
        this->changeTexture(Textures::warriorMoveLeft3);
            animationCounter++;
            break;
      case 3:
        this->changeTexture(Textures::warriorMoveLeft4);
            animationCounter++;
            break;
      case 4:
        this->changeTexture(Textures::warriorMoveLeft5);
            animationCounter++;
            break;
      case 5:
        this->changeTexture(Textures::warriorMoveLeft6);
            animationCounter++;
            break;
      case 6:
        this->changeTexture(Textures::warriorMoveLeft7);
            animationCounter++;
            break;
      case 7:
        this->changeTexture(Textures::warriorMoveLeft8);
            animationCounter++;
            break;
      case 8:
        this->changeTexture(Textures::warriorMoveLeft9);
            animationCounter++;
            break;
      case 9:
        this->changeTexture(Textures::warriorMoveLeft10);
            animationCounter++;
            break;
      case 10:
        this->changeTexture(Textures::warriorMoveLeft11);
            animationCounter++;
            break;
      case 11:
        this->changeTexture(Textures::warriorMoveLeft12);
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

void Warrior::animateTextureRight()
{
  if (frameCounter == 0)
  {
    switch (animationCounter)
    {
      case 0:
        this->changeTexture(Textures::warriorMoveRight1);
            animationCounter++;
            break;
      case 1:
        this->changeTexture(Textures::warriorMoveRight2);
            animationCounter++;
            break;
      case 2:
        this->changeTexture(Textures::warriorMoveRight3);
            animationCounter++;
            break;
      case 3:
        this->changeTexture(Textures::warriorMoveRight4);
            animationCounter++;
            break;
      case 4:
        this->changeTexture(Textures::warriorMoveRight5);
            animationCounter++;
            break;
      case 5:
        this->changeTexture(Textures::warriorMoveRight6);
            animationCounter++;
            break;
      case 6:
        this->changeTexture(Textures::warriorMoveRight7);
            animationCounter++;
            break;
      case 7:
        this->changeTexture(Textures::warriorMoveRight8);
            animationCounter++;
            break;
      case 8:
        this->changeTexture(Textures::warriorMoveRight9);
            animationCounter++;
            break;
      case 9:
        this->changeTexture(Textures::warriorMoveRight10);
            animationCounter++;
            break;
      case 10:
        this->changeTexture(Textures::warriorMoveRight11);
            animationCounter++;
            break;
      case 11:
        this->changeTexture(Textures::warriorMoveRight12);
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
