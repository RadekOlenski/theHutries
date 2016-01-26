#include "modelController.h"
#include "interactionMode.h"
#include "buildingType.h"
#include "keyboard.h"

Keyboard::Keyboard(sf::RenderWindow* hutrieApplication, ModelController* modelController, GUIController* guiController)
{
    this->hutrieApplication = hutrieApplication;
    this->modelController = modelController;
    this->guiController = guiController;
}

void Keyboard::actionsLoop()
{
    while (hutrieApplication->pollEvent(event))
    {
        if(modelController->getPauseGame())
        {
            pauseMenuActions();
            return;
        }

        if (event.type == sf::Event::Closed)
        {
            hutrieApplication->close();
        }

        chooseInteractionMode(event);

        chooseBuildingType(event);

        otherKeyActions(event);

        closeGame(event);
    }
}

void Keyboard::chooseInteractionMode(sf::Event event)
{
    if (event.type != sf::Event::KeyPressed)
    {
        return;
    }
    switch (event.key.code)
    {
        case sf::Keyboard::F1:
            modelController->setChosenInteractionMode(InteractionMode::HUTRIEINFO);
            guiController->showEmptyUnits(false);
            break;
        case sf::Keyboard::F2:
            modelController->setChosenInteractionMode(InteractionMode::BUILDMODE);
            modelController->setChosenBuildingType(BuildingType::HUTRIESHALL);
            guiController->showEmptyUnits(false);
            break;
        case sf::Keyboard::F3:
            modelController->setChosenInteractionMode(InteractionMode::INFOMODE);
            guiController->showEmptyUnits(false);
            break;
//        case sf::Keyboard::F4:
//            modelController->setChosenInteractionMode(InteractionMode::HUTRIEMODE);
//            guiController->showEmptyUnits(false);
//            break;
        default:
            break;
    }
    Sound::click();
}

void Keyboard::chooseBuildingType(sf::Event event)
{
    if (event.type != sf::Event::KeyPressed)
    {

        return;
    }
    if (modelController->getChosenInteractionMode() == InteractionMode::BUILDMODE)
    {
        switch (event.key.code)
        {
            case sf::Keyboard::Num1:
                modelController->setChosenBuildingType(BuildingType::SAWMILL);
                guiController->showEmptyUnits(true);
                break;
            case sf::Keyboard::Num2:
                modelController->setChosenBuildingType(BuildingType::STONECUTTERHUT);
                guiController->showEmptyUnits(true);
                break;
            case sf::Keyboard::Num4:
                modelController->setChosenBuildingType(BuildingType::GOLDMINE);
                guiController->showEmptyUnits(true);
                break;
            case sf::Keyboard::Num3:
                modelController->setChosenBuildingType(BuildingType::FARM);
                guiController->showEmptyUnits(true);
                break;
            case sf::Keyboard::Num5:
                modelController->setChosenBuildingType(BuildingType::BARRACKS);
                guiController->showEmptyUnits(true);
                break;
            case sf::Keyboard::Num6:
                modelController->setChosenBuildingType(BuildingType::RESIDENCE);
                guiController->showEmptyUnits(true);
                break;
            default:
                break;
        }
        guiController->updateBuildingsHighlight();
        Sound::click();
    }
}

void Keyboard::otherKeyActions(sf::Event event)
{
    if (event.type != sf::Event::KeyPressed)
    {
        return;
    }
    switch (event.key.code)
    {
        case sf::Keyboard::G:
            guiController->setVisibleGridFlag(!guiController->getVisibleGridFlag());
            break;
        default:
            break;
    }
}

void Keyboard::closeGame(sf::Event event)
{
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
    {
        //  hutrieApplication->close();
        modelController->setPauseGame(!modelController->getPauseGame());
    }
}

void Keyboard::pauseMenuActions()
{
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
    {
        modelController->setPauseGame(!modelController->getPauseGame());
    }
}
