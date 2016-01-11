#ifndef THEHUTRIES_ROCKS_H
#define THEHUTRIES_ROCKS_H


#include "environment.h"
#include "textures.h"

class Rocks : public Environment
{

public:

    Rocks(sf::RenderWindow* hutrieApplication, const std::vector<Unit*> &unitsFromGame,
          std::string pathName = Textures::rocks);

    void updateStatus();
};


#endif //THEHUTRIES_ROCKS_H
