//
// Created by Master on 06.01.2016.
//

#ifndef THEHUTRIES_ROCKS_H
#define THEHUTRIES_ROCKS_H


#include "environment.h"

class Rocks : public Environment
{

public:
    Rocks(sf::RenderWindow *hutrieApplication, const std::vector<Unit *> &unitsFromGame, const std::string &pathName);
    void updateStatus();
};


#endif //THEHUTRIES_ROCKS_H
