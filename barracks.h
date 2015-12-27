#ifndef BARRACKS_H
#define BARRACKS_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

#include "building.h"


class Barracks : public Building
{
    public:
        Barracks(sf::RenderWindow *hutrieApplication, std::vector <Unit*> unitsFromGame, std::string pathName);
        void updateStatus();
    private:

};

#endif // BARRACKS_H
