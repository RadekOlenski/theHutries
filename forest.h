#ifndef THEHUTRIES_FOREST_H
#define THEHUTRIES_FOREST_H


#include "environment.h"
#include "textures.h"

class Forest : public Environment
{

public:
    Forest(sf::RenderWindow* hutrieApplication, std::vector<Unit*> &unitsFromGame,
           std::string pathName = Textures::forest);

    void updateStatus();

};


#endif //THEHUTRIES_FOREST_H
