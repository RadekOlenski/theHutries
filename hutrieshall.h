#ifndef HUTRIESHALL_H
#define HUTRIESHALL_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

#include "building.h"

class HutriesHall : public Building
{
    public:
        HutriesHall(sf::RenderWindow *hutrieApplication, std::vector <Unit*> unitsFromGame, std::string pathName, int buildingType);
        void showStatus();
    private:
};

#endif // HUTRIESHALL_H
