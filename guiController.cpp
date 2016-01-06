//
// Created by radek on 30.12.2015.
//

#include <sstream>
#include <iostream>
#include "guiController.h"
#include "sound.h"
#include "buildingType.h"
#include "interactionMode.h"

GUIController::GUIController(sf::RenderWindow*hutrieApplication, ModelController*modelController, World*world, GUI*gui)
        : titleText(1024 + 20, 40, 45),
        titleThread(&GUIText::display, &titleText)
{


    this->hutrieApplication = hutrieApplication;
    this->modelController = modelController;
    this->world = world;
    this->gui = gui;
}

void GUIController::handleGUIButtonsActions()
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
    if (world->lastClickedUnit)
    {
        world->lastClickedUnit->getMapObject()->buttonAction();
        return;
    }
}

void GUIController::setBuildingButtonsFlags(bool buttonFlag)
{
    gui->residence.setActive(buttonFlag);
    gui->sawmill.setActive(buttonFlag);
    gui->stonecutter.setActive(buttonFlag);
    gui->goldmine.setActive(buttonFlag);
    gui->barracks.setActive(buttonFlag);
    gui->farm.setActive(buttonFlag);
}

void GUIController::drawApplication()
{
    getView();
    prepareToDisplay();
    displayGUI();
    displayElementsOfGUI();
    drawToApplication(background);
    drawToApplication(titleText.text);

    std::vector<Unit*>::iterator it;
    drawGrid(it);
    drawMapObjects(it);

    drawToApplication(cursor);
    displayApplication();
}

void GUIController::getView()
{
    fixed = hutrieApplication->getView();
    //fixed.zoom(2);
}

void GUIController::displayElementsOfGUI()
{
    if (modelController->getChosenInteractionMode() == InteractionMode::BUILDMODE) gui->displayGUIBuildings();
    if (modelController->getChosenInteractionMode() == InteractionMode::HUTRIEINFO)
        gui->displayGUIHutries(world->hutries.size(), world->carriers.size(), world->workers.size(),
                               world->warriors.size(), world->archers.size());
}

void GUIController::drawGrid(std::vector<Unit*>::iterator it)
{
    for (it = world->units.begin(); it != world->units.end(); ++it)
    {
        drawToApplication((*it)->field);
    }
}

void GUIController::drawMapObjects(std::vector<Unit*>::iterator it)
{
    for (it = world->units.begin(); it != world->units.end(); ++it)     //rysosowanie wszystkich mapobjectow na mapie
        // - druga petla zeby ruszajacy sie Hutrie byli rysowani nad zielona kratka a nie pod
    {
        if (!((*it)->isEmpty()))
        {
            drawToApplication((*it)->getMapObject()->sprite);    //rysuje obiekty (budynki, przyroda) widoczne na mapie
            if ((*it)->hutriesNumber() > 0)
            {
                for (int i = 0; i < (*it)->hutriesNumber(); i++)             //jesli w wektorze jest jakis hutri
                {
                   drawToApplication((*it)->getHutrieIndex(i)->sprite);     //rysuj hutrich z vectora dwellers
                }
            }

            if ((*it)->getMapObject()->isHighlighted()
                && modelController->getChosenInteractionMode() == InteractionMode::INFOMODE)  //jesli tryb info rysuj w prawym gui
            {
                drawToApplication((*it)->getMapObject()->title.text);
                drawToApplication((*it)->getMapObject()->description.text);
                drawToApplication((*it)->getMapObject()->descriptionFrame.button);
                (*it)->getMapObject()->showButtons();
            }
            else (*it)->getMapObject()->deactivateButtons();
        }
    }
}

void GUIController::createBackground()
{
    background.setSize(sf::Vector2f(1024, 640));
    //  backgroundTexture.loadFromFile( "sprites/background/background.jpg" );
    backgroundTexture.loadFromFile("sprites/background/background.jpg");
    background.setTexture(&backgroundTexture);
}

void GUIController::createCursor()
{
    hutrieApplication->setMouseCursorVisible(false);
    cursorTexture.loadFromFile("sprites/cursor.png");
    cursor.setTexture(cursorTexture);
}

void GUIController::prepareToDisplay()
{
    hutrieApplication->clear(sf::Color::Black);        //czyszczenie ekranu dla pierwszego wyswietlenia
    hutrieApplication->setView(fixed);
}

void GUIController::drawToApplication(sf::RectangleShape shape)
{
    hutrieApplication->draw(shape);
}

void GUIController::drawToApplication(sf::Sprite sprite)
{
    hutrieApplication->draw(sprite);
}

void GUIController::drawToApplication(sf::Text text)
{
    hutrieApplication->draw(text);
}

void GUIController::displayGUI()
{
    gui->displayGUI();
}

void GUIController::displayApplication()
{
    hutrieApplication->display();
}

void GUIController::setCursorPosition()
{
    cursor.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(*hutrieApplication)));
}

void GUIController::launchTitleThread()
{
    titleThread.launch();
}

void GUIController::displayGameOver(bool win)
{
    GUIText endingStats(300, 280, 40, getEndingStats());
    setCursorPosition();
    prepareToDisplay();
    displayGUI();
    drawToApplication(background);
    drawToApplication(endingStats.text);
    drawToApplication(titleText.text);
    gui->displayEndingText(win);
    drawToApplication(cursor);
    displayApplication();
}

std::string GUIController::getEndingStats()
{
    std::ostringstream stats;
    stats << "You have built " << world->buildings.size() << " buildings." << std::endl
    << "You had " << world->hutries.size() << " hutries including: " << std::endl
    << world->carriers.size() << " carriers" << std::endl
    << world->workers.size() << " workers" << std::endl
    << world->soldiers.size() << " soldiers" << std::endl;
    return stats.str();
}

void GUIController::checkCarrierGoods()
{
    std::ostringstream desc;
    desc << world->availableGoods.getWood();
    gui->twood.text.setString(desc.str());

    std::ostringstream desc1;
    desc1 << world->availableGoods.getStone();
    gui->tstone.text.setString(desc1.str());

    std::ostringstream desc2;
    desc2 << world->availableGoods.getFood();
    gui->tfood.text.setString(desc2.str());

    std::ostringstream desc3;
    desc3 << world->availableGoods.getGold();
    gui->tgold.text.setString(desc3.str());
}

//=================================================================================
//                              ERRORS
//=================================================================================


void GUIController::errorNoCarriers()
{
    Sound::error();
    gui->errorInfo.text.setString("Error: No available carriers! Everyone is busy! Create carrier in HutriesHall or build residence");
}


void GUIController::errorNoSlots()
{
    Sound::error();
    gui->errorInfo.text.setString("Error: No more slots! Build residence!");
}

void GUIController::errorNoWorkers()
{
    Sound::error();
    gui->errorInfo.text.setString(
            "Error: No available workers! Everyone is busy! Create worker in HutriesHall or build residence");
}

void GUIController::errorUnitOccupied()
{
    Sound::error();
    gui->errorInfo.text.setString("Error: Unit not empty. Choose another one");
}


void GUIController::errorOutOfMap()
{
    Sound::error();
    gui->errorInfo.text.setString("Error: Building out of map. Choose another place");
}

void GUIController::errorAlreadyCreatingArcher()
{
    Sound::error();
    gui->errorInfo.text.setString("Error: You are currently creating Archer!");
}

void GUIController::errorAlreadyCreatingWarrior()
{
    Sound::error();
    gui->errorInfo.text.setString("Error: You are currently creating Warrior!");
}

void GUIController::errorAlreadyCreatingWorker()
{
    Sound::error();
    gui->errorInfo.text.setString("Error: You are currently creating Worker!");
}

void GUIController::errorAlreadyCreatingCarrier()
{
    Sound::error();
    gui->errorInfo.text.setString("Error: You are currently creating Carrier!");
}

void GUIController::errorNoProductsToCarry()
{
    Sound::error();
    gui->errorInfo.text.setString("Carrier: No products to carry!");
}

void GUIController::errorNotEnoughGoods()
{
    Sound::error();
    gui->errorInfo.text.setString("Goods: Not enough goods for building!");
}

void GUIController::errorMustBuildNearForest()
{
    Sound::error();
    gui->errorInfo.text.setString("Error: You have to build sawmill near forest!");
}

void GUIController::errorMustBuildNearRocks()
{
    Sound::error();
    gui->errorInfo.text.setString("Error: You have to build stonecutterHut near rocks!");
}

void GUIController::errorMustBuildOnMountain()
{
    Sound::error();
    gui->errorInfo.text.setString("Error: You have to build goldmine on mountain!");
}
