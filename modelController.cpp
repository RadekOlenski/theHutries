#include "gameModel.h"
#include "modelController.h"

ModelController::ModelController()
{
    GameModel* gameModel = new GameModel();
    this->gameModel = gameModel;
    setReadyForGame(false);
}

void ModelController::setChosenInteractionMode(int chosenInteractionMode)
{
    gameModel->setChosenInteractionMode(chosenInteractionMode);
}

int ModelController::getChosenInteractionMode()
{
    return gameModel->getChosenInteractionMode();
}

int ModelController::getChosenBuildingType()
{
    return gameModel->getChosenBuildingType();
}

void ModelController::setChosenBuildingType(int chosenBuildingType)
{
    gameModel->setChosenBuildingType(chosenBuildingType);
    getChosenBuildingType();
}

int ModelController::getApplicationWidth()
{
    return gameModel->getApplicationWidth();
}

void ModelController::setApplicationWidth(int applicationWidth)
{
    gameModel->setApplicationWidth(applicationWidth);
}

int ModelController::getApplicationHeight()
{
    return gameModel->getApplicationHeight();
}

void ModelController::setApplicationHeight(int applicationHeight)
{
    gameModel->setApplicationHeight(applicationHeight);
}

unsigned int ModelController::getSelectedUnitIndex()
{
    return gameModel->getSelectedUnitIndex();
}

void ModelController::setSelectedUnitIndex(unsigned int selectedUnitIndex)
{
    gameModel->setSelectedUnitIndex(selectedUnitIndex);
}

int ModelController::getTempChosenMode()
{
    return gameModel->getTempChosenMode();
}

void ModelController::setTempChosenMode(int tempChosenMode)
{
    gameModel->setTempChosenMode(tempChosenMode);
}
