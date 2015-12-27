#include "gameModel.h"

int GameModel::chosenMode = 0;
int GameModel::buildingType = 0;

int GameModel::getBuildingType()
{
    return buildingType;
}

void GameModel::setBuildingType(int buildingType)
{
    GameModel::buildingType = buildingType;
}

void GameModel::setChosenMode(int chosenMode)
{
    GameModel::chosenMode = chosenMode;
}

int GameModel::getChosenMode()
{
    return chosenMode;
}

