//
// Created by Master on 06.01.2016.
//

#ifndef THEHUTRIES_MOUNTAINS_H
#define THEHUTRIES_MOUNTAINS_H


#include "environment.h"

class Mountain : public Environment
{

public:
    Mountain(sf::RenderWindow *hutrieApplication, const std::vector<Unit *> &unitsFromGame,
              const std::string &pathName);
    void updateStatus();
};


#endif //THEHUTRIES_MOUNTAINS_H
