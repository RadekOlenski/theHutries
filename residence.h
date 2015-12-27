#ifndef RESIDENCE_H
#define RESIDENCE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

#include "building.h"


class Residence : public Building
{
    public:
        Residence(sf::RenderWindow *hutrieApplication, std::vector <Unit*> unitsFromGame, std::string pathName, int *worldSlots);
        void updateStatus();
    static int getAddedSlotsNumber();
private:
    static const int slotsAddition = 10;
        int slotsLeft;
        int *worldSlots;
};

#endif // RESIDENCE_H
