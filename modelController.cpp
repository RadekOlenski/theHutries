#include <iostream>
#include "gameModel.h"
#include "modelController.h"

void ModelController::setChosenMode(int chosenMode)
{
    GameModel::setChosenMode(chosenMode);
}

int ModelController::getChosenMode()
{
    std::cout<<"Chosen Mode:"<<GameModel::getChosenMode()<<std::endl; //DEBUG
    return GameModel::getChosenMode();
}

int ModelController::getBuildingType()
{
    std::cout<<"Building Type:"<<GameModel::getBuildingType()<<std::endl; //DEBUG
    return GameModel::getBuildingType();
}

void ModelController::setBuildingType(int buildingType)
{
    GameModel::setBuildingType(buildingType);
    getBuildingType();                                                  //DEBUG
}
