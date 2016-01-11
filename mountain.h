#ifndef THEHUTRIES_MOUNTAINS_H
#define THEHUTRIES_MOUNTAINS_H


#include "environment.h"
#include "textures.h"

class Mountain : public Environment
{

public:

    Mountain(sf::RenderWindow* hutrieApplication, const std::vector<Unit*> &unitsFromGame,
             std::string pathName = Textures::mountain);

    void updateStatus();
};


#endif //THEHUTRIES_MOUNTAINS_H
