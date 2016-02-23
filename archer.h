#ifndef THEHUTRIES_ARCHER_H
#define THEHUTRIES_ARCHER_H

#include "soldier.h"
#include "textures.h"

class Archer : public Soldier
{
public:
    Archer(sf::RenderWindow* hutrieApplication, const std::vector<Unit*> &unitsFromGame,
           const std::vector<Unit*> &unitsForMoving, std::string pathName = Textures::archerMoveRight1);

    void animateTextureUp();
    void animateTextureDown();
    void animateTextureLeft();
    void animateTextureRight();

};


#endif //THEHUTRIES_ARCHER_H
