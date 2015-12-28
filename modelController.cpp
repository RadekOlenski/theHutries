#include <iostream>
#include "gameModel.h"
#include "modelController.h"

void ModelController::initializeGameModel()
{
    GameModel* gameModel = new GameModel();
    this->gameModel = gameModel;
}

void ModelController::setChosenInteractionMode(int chosenInteractionMode)
{
    gameModel->setChosenInteractionMode(chosenInteractionMode);
}

int ModelController::getChosenInteractionMode()
{
    std::cout << "Chosen Mode:" << gameModel->getChosenInteractionMode() << std::endl; //DEBUG
    return gameModel->getChosenInteractionMode();
}

int ModelController::getChosenBuildingType()
{
    std::cout << "Building Type:" << gameModel->getChosenBuildingType() << std::endl; //DEBUG
    return gameModel->getChosenBuildingType();
}

void ModelController::setChosenBuildingType(int chosenBuildingType)
{
    gameModel->setChosenBuildingType(chosenBuildingType);
    getChosenBuildingType();                                                  //DEBUG
}
