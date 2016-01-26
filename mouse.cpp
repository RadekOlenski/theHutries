#include <SFML/Window/Mouse.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "mouse.h"
#include "interactionMode.h"
#include "buildingType.h"


Mouse::Mouse(sf::RenderWindow* hutrieApplication, ModelController* modelController,
             GameLogicController* gameLogicController)
{
    MouseLock* mouseLock = new MouseLock();
    this->mouseLock = mouseLock;
    this->hutrieApplication = hutrieApplication;
    this->modelController = modelController;
    this->gameLogicController = gameLogicController;
}

void Mouse::leftClickActions()
{
    if (mouseLock->getIsLocked())
    {
        return;
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        int applicationWidth = modelController->getApplicationWidth();
        int applicationHeight = modelController->getApplicationHeight();

        if( modelController->getChosenInteractionMode() == 0)
            {
                gameLogicController->handleMenuButtonsAction();
                if (!modelController->getReadyForGame()) return;
            }

        if( modelController->getPauseGame())
        {
            gameLogicController->handlePauseButtonsAction();
            return;
        }

        if(modelController->getExitWindow())
        {
            gameLogicController->handleExitButtonsAction();
            return;
        }

        if (sf::Mouse::getPosition(*hutrieApplication).x < applicationWidth &&
            sf::Mouse::getPosition(*hutrieApplication).y > 64 &&
            sf::Mouse::getPosition(*hutrieApplication).y <
            applicationHeight + 64)         //jesli klikniecie w obrebie mapy
        {
            gameLogicController->endHighlightUnit();

            gameLogicController->findSelectedUnit();

            handleClickOnMap();

            return;
        }
        gameLogicController->handleGUIButtonsAction();
        gameLogicController->updateBuildingGrid();                                   //przy kliknieciu sprawdza czy siatka pokazujaca wolne pola powinna byc wyswietlana
    }
}

void Mouse::rightClickActions()
{
    if (mouseLock->getIsLocked())
    {
        return;
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
    {
        modelController->setChosenInteractionMode(InteractionMode::NEUTRALMODE);
    }
}


void Mouse::updateMouseLock()
{
    mouseLock->update();
}

void Mouse::handleClickOnMap()
{
    if (gameLogicController->isUnitEmpty())                                                 //jesli unit jest wolny, bez zadnego mapobjectu
    {
        switch (modelController->getChosenInteractionMode()) //BUTTONS F1,F2,F3 OR GUIBUTTONS
        {
            case InteractionMode::BUILDMODE:   //postawienie budynku                                                                                                                                   //BUILDING zajmuje 4 pola na mapie!
            {
                gameLogicController->handleBuildingCreation();

                break;
            }
//            case InteractionMode::HUTRIEMODE:     //poruszanie Hutrim
//            {
//                gameLogicController->handleHutrieMoving();
//                break;
//            }
            default:
                break;
        };
    }
    else
////////////////////////////EMPHASIZE UNIT WITH MAPOBJECT///////////////////////////////////////////////////////////////////////////////////
    {
        modelController->setChosenInteractionMode(InteractionMode::INFOMODE);
        gameLogicController->updateBuildingGrid();                                   //przy kliknieciu sprawdza czy siatka pokazujaca wolne pola powinna byc wyswietlana
        gameLogicController->highlightUnits();

    }
}

