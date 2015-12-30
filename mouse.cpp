#include <SFML/Window/Mouse.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>
#include "mouse.h"
#include "mouseLock.h"
#include "modelController.h"
#include "interactionMode.h"
#include "buildingType.h"
#include "gameLogicController.h"
#include "sound.h"


Mouse::Mouse(sf::RenderWindow*hutrieApplication, ModelController*modelController, GUI*gui,
             GameLogicController*gameLogicController, sf::Sprite*cursor)
{
    MouseLock*mouseLock = new MouseLock();
    this->mouseLock = mouseLock;
    this->hutrieApplication = hutrieApplication;
    this->modelController = modelController;
    this->gui = gui;
    this->gameLogicController = gameLogicController;
    this->cursor = cursor;
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
        if (sf::Mouse::getPosition(*hutrieApplication).x < applicationWidth)         //jesli klikniecie w obrebie mapy
        {
            gameLogicController->endHighlightUnit();

            gameLogicController->findSelectedUnit();

            handleClickOnMap();
            return;
        }
        guiButtonsActions();
        /*if (world.lastClickedUnit) {
            world.lastClickedUnit->getMapObject()->buttonAction();
            return;
}
*/
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
        //sf::Vector2f distance = gui.guiFrame.getPosition() - static_cast<sf::Vector2f>(sf::Mouse::getPosition(hutrieApplication));
        //std::cout << distance.x << "," << distance.y << std::endl;
        //fixed.setCenter(static_cast<sf::Vector2f>(sf::Mouse::getPosition(hutrieApplication)));
        //gui.guiFrame.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(hutrieApplication))+distance);
    }
}

void Mouse::guiButtonsActions()
{
    if (gui->buildButton.checkBounds())
    {
        modelController->setChosenInteractionMode(InteractionMode::BUILDMODE);
        Sound::click();
        return;
    }
    if (gui->hutrieButton.checkBounds())
    {
        modelController->setChosenInteractionMode(InteractionMode::HUTRIEINFO);
        Sound::click();
        return;
    }
    if (gui->sawmill.checkBounds() && gui->sawmill.isActive())
    {
        modelController->setChosenBuildingType(BuildingType::SAWMILL);
        Sound::click();
        return;
    }
    if (gui->stonecutter.checkBounds() && gui->stonecutter.isActive())
    {
        modelController->setChosenBuildingType(BuildingType::STONECUTTERHUT);
        Sound::click();
        return;
    }
    if (gui->barracks.checkBounds() && gui->barracks.isActive())
    {
        modelController->setChosenBuildingType(BuildingType::BARRACKS);
        Sound::click();
        return;
    }
    if (gui->residence.checkBounds() && gui->residence.isActive())
    {
        modelController->setChosenBuildingType(BuildingType::RESIDENCE);
        Sound::click();
        return;
    }
    if (gui->goldmine.checkBounds() && gui->goldmine.isActive())
    {
        modelController->setChosenBuildingType(BuildingType::GOLDMINE);
        Sound::click();
        return;
    }
    if (gui->farm.checkBounds() && gui->farm.isActive())
    {
        modelController->setChosenBuildingType(BuildingType::FARM);
        Sound::click();
        return;
    }
}

void Mouse::updateMouseLock()
{
    mouseLock->update();
}

void Mouse::handleClickOnMap()
{
/*
    if (chosenInteractionMode == 1 && !(world.units.at( unitIndex )->isEmpty()))    //poruszanie Hutrim do budynku
    {
        std::vector <Unit*> usedUnits;
        usedUnits.push_back(world.units.at(unitIndex));
        world.hutries.push_back(new Worker(&hutrieApplication, usedUnits,"sprites/worker/right.png" ));
        world.hutries.back()->hutrieThread.launch();                         //tworzy watek w ktorym porusza sie Hutrie
        world.units.at(unitIndex)->addHutrie(world.hutries.back());
    }
*/

    if (gameLogicController->isUnitEmpty())                                                 //jesli unit jest wolny, bez zadnego mapobjectu
    {
        switch (modelController->getChosenInteractionMode()) //BUTTONS F1,F2,F3 OR GUIBUTTONS
        {
            case InteractionMode::BUILDMODE:   //postawienie budynku                                                                                                                                   //BUILDING zajmuje 4 pola na mapie!
            {
                gameLogicController->handleBuildingCreation();
                break;
            }
            case InteractionMode::HUTRIEMODE:     //poruszanie Hutrim
            {
                gameLogicController->handleHutrieMoving();
                break;
            }
            default:
                break;
        };
    }
    else
////////////////////////////EMPHASIZE UNIT WITH MAPOBJECT///////////////////////////////////////////////////////////////////////////////////
    {
        gameLogicController->highlightUnits();
    }
}

void Mouse::setCursorPosition()
{
    cursor->setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(*hutrieApplication)));
}
