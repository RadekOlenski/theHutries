#include "gameModel.h"


int GameModel::getChosenBuildingType()
{
    return chosenBuildingType;
}

void GameModel::setChosenBuildingType(int chosenBuildingType)
{
    GameModel::chosenBuildingType = chosenBuildingType;
}

void GameModel::setChosenInteractionMode(int chosenInteractionMode)
{
    GameModel::chosenInteractionMode = chosenInteractionMode;
}

int GameModel::getChosenInteractionMode()
{
    return chosenInteractionMode;
}

