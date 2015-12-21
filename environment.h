#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

#include "mapobject.h"

class Environment : public MapObject
{
    public:
        Environment(sf::RenderWindow *hutrieApplication, std::vector <Unit*> unitsFromGame, std::string pathName);
        void updateStatus();
    private:
};

#endif // ENVIRONMENT_H
