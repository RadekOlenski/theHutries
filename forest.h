//
// Created by Master on 05.01.2016.
//

#ifndef THEHUTRIES_FOREST_H
#define THEHUTRIES_FOREST_H


#include "environment.h"

class Forest : public Environment
{

public:
    Forest(sf::RenderWindow *hutrieApplication, std::vector<Unit *> &unitsFromGame, std::string pathName);

};


#endif //THEHUTRIES_FOREST_H
