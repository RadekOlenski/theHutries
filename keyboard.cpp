//
// Created by radek on 27.12.2015.
//

#include "keyboard.h"
#include "interactionMode.h"
#include "modelController.h"
#include "buildingType.h"

Keyboard::Keyboard(sf::RenderWindow* hutrieApplication)
{
    this->hutrieApplication = hutrieApplication;
}

void Keyboard::actionsLoop()
{
    while (hutrieApplication->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            hutrieApplication->close();

        switchMode(event);

        switchBuildingType(event);

        closeGame(event);
    }
}

void Keyboard::switchMode(sf::Event event)
{
    if (event.type != sf::Event::KeyPressed)
    {
        return;
    }
    switch (event.key.code)
    {
        case sf::Keyboard::F1:
            ModelController::setChosenMode(InteractionMode::HUTRIEINFO);
            break;
        case sf::Keyboard::F2:
            ModelController::setChosenMode(InteractionMode::BUILDMODE);
            break;
        case sf::Keyboard::F3:
            ModelController::setChosenMode(InteractionMode::INFOMODE);
            break;
        case sf::Keyboard::F4:
            ModelController::setChosenMode(InteractionMode::HUTRIEMODE);
            break;
        default:
            break;
    }
    //clickSound();
}

void Keyboard::switchBuildingType(sf::Event event)
{
    if (event.type != sf::Event::KeyPressed)
    {
        return;
    }
    if (ModelController::getChosenMode() == InteractionMode::BUILDMODE)
    {
        switch (event.key.code)
        {
            case sf::Keyboard::Num1:
                ModelController::setBuildingType(BuildingType::SAWMILL);
                break;
            case sf::Keyboard::Num2:
                ModelController::setBuildingType(BuildingType::STONECUTTERHUT);
                break;
            case sf::Keyboard::Num3:
                ModelController::setBuildingType(BuildingType::BARRACKS);
                break;
            case sf::Keyboard::Num4:
                ModelController::setBuildingType(BuildingType::RESIDENCE);
                break;
            case sf::Keyboard::Num5:
                ModelController::setBuildingType(BuildingType::GOLDMINE);
                break;
            case sf::Keyboard::Num6:
                ModelController::setBuildingType(BuildingType::FARM);
                break;
            case sf::Keyboard::Space:
            {
                //std::cout<<world.availableSlots << std::endl;
                /*std::vector<Carrier*>::iterator itc;
                for (itc = world.carriers.begin(); itc != world.carriers.end(); ++itc)
                {
                    std::cout << "Wood: " << (*itc)->myLuggage.getWood() << ", Stone: " <<
                    (*itc)->myLuggage.getStone() << ", Food: " << (*itc)->myLuggage.getFood() << ", Gold: " <<
                    (*itc)->myLuggage.getGold() << std::endl;
                }*/
                break;
            }
            default:
                break;
        }
        //   clickSound();
    }
}

void Keyboard::closeGame(sf::Event event)
{
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        hutrieApplication->close();
}
