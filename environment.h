#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "mapobject.h"
#include <SFML/Graphics.hpp>

class Environment : public MapObject
{
    public:
        Environment(sf::RenderWindow *hutrieApplication, std::vector <Unit*> unitsFromGame);
        void showStatus();
    private:
};

#endif // ENVIRONMENT_H
