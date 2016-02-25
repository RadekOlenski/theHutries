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

        if( modelController->getChosenInteractionMode() == InteractionMode::MENUMODE)
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

        gameLogicController->endHighlightUnit();                            //zeby po kliknieciu gdzie indziej nie zostawala niepotrzebna ramka

        if (sf::Mouse::getPosition(*hutrieApplication).x < applicationWidth &&
            sf::Mouse::getPosition(*hutrieApplication).y > 64 &&
            sf::Mouse::getPosition(*hutrieApplication).y <
            applicationHeight + 64)         //jesli klikniecie w obrebie mapy
        {

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
        gameLogicController->updateBuildingGrid();
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
        if ( modelController->getChosenInteractionMode() == InteractionMode::BUILDMODE )
        {
                gameLogicController->handleBuildingCreation();
        }
    }
    else if ( modelController->getChosenInteractionMode() != InteractionMode::BUILDMODE || ( modelController->getChosenInteractionMode() == InteractionMode::BUILDMODE && modelController->getChosenBuildingType() == BuildingType::HUTRIESHALL) )
////////////////////////////EMPHASIZE UNIT WITH MAPOBJECT///////////////////////////////////////////////////////////////////////////////////
    {
        modelController->setChosenInteractionMode(InteractionMode::INFOMODE);
        gameLogicController->updateBuildingGrid();                                   //przy kliknieciu sprawdza czy siatka pokazujaca wolne pola powinna byc wyswietlana
        gameLogicController->highlightUnits();

    }
}

