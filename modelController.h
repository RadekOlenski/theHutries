//
// Created by radek on 27.12.2015.
//

#ifndef THEHUTRIES_MODELCONTROLLER_H
#define THEHUTRIES_MODELCONTROLLER_H

#include "gameModel.h"

class ModelController
{
public:
    void setChosenInteractionMode(int chosenInteractionMode);

    int getChosenInteractionMode();

    int getChosenBuildingType();

    void setChosenBuildingType(int chosenBuildingType);

    void initializeGameModel();

private:

    GameModel* gameModel;
};


#endif //THEHUTRIES_MODELCONTROLLER_H
