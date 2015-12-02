#ifndef RESIDENCE_H
#define RESIDENCE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

#include "building.h"


class Residence : public Building
{
    public:
        Residence(sf::RenderWindow *hutrieApplication, std::vector <Unit*> unitsFromGame, std::string pathName, int buildingType);
        void showStatus();
    private:
        const int slotsAddition;
        int slotsLeft;
};

#endif // RESIDENCE_H
