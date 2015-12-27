//
// Created by radek on 27.12.2015.
//

#ifndef THEHUTRIES_GAMEMODEL_H
#define THEHUTRIES_GAMEMODEL_H

#include <SFML/Graphics.hpp>

class GameModel
{
public:

    static int getBuildingType();

    static void setBuildingType(int buildingType);

    static void setChosenMode(int chosenMode);

    static int getChosenMode();

private:

    static int chosenMode;

    int tempChosenMode;

    static int buildingType;
};


#endif //THEHUTRIES_GAMEMODEL_H
