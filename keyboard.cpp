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
        if (event.type == sf::Event::Closed)
        {
            hutrieApplication->close();
        }

        chooseInteractionMode(event);

        chooseBuildingType(event);

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
            break;
        case sf::Keyboard::F2:
            modelController->setChosenInteractionMode(InteractionMode::BUILDMODE);
            modelController->setChosenBuildingType(BuildingType::HUTRIESHALL);
            break;
        case sf::Keyboard::F3:
            modelController->setChosenInteractionMode(InteractionMode::INFOMODE);
            break;
//        case sf::Keyboard::F4:
//            modelController->setChosenInteractionMode(InteractionMode::HUTRIEMODE);
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
                break;
            case sf::Keyboard::Num2:
                modelController->setChosenBuildingType(BuildingType::STONECUTTERHUT);
                break;
            case sf::Keyboard::Num4:
                modelController->setChosenBuildingType(BuildingType::GOLDMINE);
                break;
            case sf::Keyboard::Num3:
                modelController->setChosenBuildingType(BuildingType::FARM);
                break;
            case sf::Keyboard::Num5:
                modelController->setChosenBuildingType(BuildingType::BARRACKS);
                break;
            case sf::Keyboard::Num6:
                modelController->setChosenBuildingType(BuildingType::RESIDENCE);
                break;
            default:
                break;
        }
        guiController->updateBuildingsHighlight();
        Sound::click();
    }
}

void Keyboard::closeGame(sf::Event event)
{
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        hutrieApplication->close();
}
