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

int GameModel::getApplicationWidth()
{
    return GameModel::applicationWidth;
}

void GameModel::setApplicationWidth(int applicationWidth)
{
    GameModel::applicationWidth = applicationWidth;
}

int GameModel::getApplicationHeight()
{
    return GameModel::applicationHeight;
}

void GameModel::setApplicationHeight(int applicationHeight)
{
    GameModel::applicationHeight = applicationHeight;
}

unsigned int GameModel::getSelectedUnitIndex()
{
    return selectedUnitIndex;
}

void GameModel::setSelectedUnitIndex(unsigned int unitIndex)
{
    GameModel::selectedUnitIndex = unitIndex;
}

int GameModel::getTempChosenMode()
{
    return tempChosenMode;
}

void GameModel::setTempChosenMode(int tempChosenMode)
{
    GameModel::tempChosenMode = tempChosenMode;
}
