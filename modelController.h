//
// Created by radek on 27.12.2015.
//

#ifndef THEHUTRIES_MODELCONTROLLER_H
#define THEHUTRIES_MODELCONTROLLER_H

#include "gameModel.h"

class ModelController
{
public:
    static void setChosenMode(int chosenMode);

    static int getChosenMode();

    static int getBuildingType();

    static void setBuildingType(int buildingType);

};


#endif //THEHUTRIES_MODELCONTROLLER_H
