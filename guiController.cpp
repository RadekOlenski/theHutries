#include <sstream>
#include <iostream>
#include "guiController.h"
#include "sound.h"
#include "buildingType.h"
#include "interactionMode.h"
#include "gamebalance.h"

GUIController::GUIController(sf::RenderWindow*hutrieApplication, ModelController*modelController, World*world, GUI*gui)
        : titleText(1024 + 20, 40, 45),
          bigTitleText (150, 100, 150, "The Hutries"),
          quote(500, 400, 30, ""),
          titleThread(&GUIText::display, &titleText),
          bigTitleThread(&GUIText::animation, &bigTitleText),
          quoteThread(&GUIController::displayIntro, this)
{


    this->hutrieApplication = hutrieApplication;
    this->modelController = modelController;
    this->world = world;
    this->gui = gui;
    firstIteration = true;
    introFlag = false;
    displayHutriesHall = false;
}

void GUIController::displayIntro()
{
    gui->startingText.text.setString("");
    quote.animation();
    quote.text.setColor(sf::Color (0,0,0,0));
    gui->startingText.text.setPosition(200,300);
    gui->startingText.text.setString(GameBalance::historyString);
    sf::sleep(sf::seconds(5));
    gui->startingText.text.setString(GameBalance::historyString2);
    sf::sleep(sf::seconds(5));
    world->createHutriesHall();
    displayHutriesHall = true;
    gui->startingText.text.setPosition(200,550);
    gui->startingText.text.setString(GameBalance::historyString3);
    introFlag = false;
}

void GUIController::drawHutriesHall()
{
    drawToApplication(world->buildings.at(0)->sprite);
}

void GUIController::handleMenuButtonsActions()
{
    if (gui->playButton.checkBounds())
    {
        quote.text.setStyle(sf::Text::Italic);
        quote.text.setString(GameBalance::quoteString);
        introFlag = true;
        Sound::click();
        return;
    }
    if (gui->aboutButton.checkBounds())
    {
        gui->startingText.text.setString(GameBalance::aboutString);
        Sound::click();
        return;
    }
    if (gui->howToPlayButton.checkBounds())
    {
        gui->startingText.text.setString(GameBalance::howToPlayString);
        Sound::click();
        return;
    }
     if (gui->exitButton.checkBounds())
    {
        Sound::click();
        hutrieApplication->close();
    }
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

void GUIController::setMenuButtonsFlags (bool buttonFlag)
{
    gui->playButton.setActive(buttonFlag);
    gui->howToPlayButton.setActive(buttonFlag);
    gui->aboutButton.setActive(buttonFlag);
    gui->exitButton.setActive(buttonFlag);
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
    if (firstIteration)
    {
        fixed.zoom(GameBalance::screenZoom);
        firstIteration = false;
    }

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
    background.setSize(sf::Vector2f(1024, 640 + 128));
    //  backgroundTexture.loadFromFile( "sprites/background/background.jpg" );
    backgroundTexture.loadFromFile(Textures::background);
    background.setTexture(&backgroundTexture);
}

void GUIController::createCursor()
{
    hutrieApplication->setMouseCursorVisible(false);
    cursorTexture.loadFromFile(Textures::cursor);
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

void GUIController::launchBigTitleThread()
{
    bigTitleThread.launch();
}

void GUIController::launchQuoteThread()
{
    quoteThread.launch();
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

void GUIController::displayMenu()
{
    setCursorPosition();
    getView();
    prepareToDisplay();
    drawToApplication(background);
    gui->displayMenu();
    drawToApplication(titleText.text);
    drawToApplication(quote.text);
    drawToApplication(bigTitleText.text);
    if (displayHutriesHall) drawHutriesHall();
    if (!introFlag) drawToApplication(cursor);
    displayApplication();
}

std::string GUIController::getEndingStats()
{
    std::ostringstream stats;
    stats << "You have built " << world->buildings.size() << " buildings." << std::endl
    << "You had " << world->hutries.size() << " hutries including: " << std::endl
    << world->carriers.size() << " carriers" << std::endl
    << world->workers.size() << " workers" << std::endl
    << world->warriors.size() << " warriors" << std::endl
    << world->archers.size() << " archers" << std::endl;
    return stats.str();
}

void GUIController::updateGoodsNumber()
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
    gui->errorInfo.text.setString("Error: No available carriers!\nEveryone is busy! \nCreate carrier in HutriesHall \nor build residence");
}


void GUIController::errorNoSlots()
{
    Sound::error();
    gui->errorInfo.text.setString("Error: \n        No more slots! \n       Build residence!");
}

void GUIController::errorNoWorkers()
{
    Sound::error();
    gui->errorInfo.text.setString(
            "Error: No available workers! \nEveryone is busy! \nCreate worker in HutriesHall\nor build residence");
}

void GUIController::errorUnitOccupied()
{
    Sound::error();
    gui->errorInfo.text.setString("Error: \n        Unit not empty.\n        Choose another one");
}


void GUIController::errorOutOfMap()
{
    Sound::error();
    gui->errorInfo.text.setString("Error: \n        Building out of map.\n        Choose another place");
}

void GUIController::errorAlreadyCreatingArcher()
{
    Sound::error();
    gui->errorInfo.text.setString("Error: \n        You are currently \n        creating Archer!");
}

void GUIController::errorAlreadyCreatingWarrior()
{
    Sound::error();
    gui->errorInfo.text.setString("Error: \n        You are currently \n        creating Warrior!");
}

void GUIController::errorAlreadyCreatingWorker()
{
    Sound::error();
    gui->errorInfo.text.setString("Error: \n        You are currently \n        creating Worker!");
}

void GUIController::errorAlreadyCreatingCarrier()
{
    Sound::error();
    gui->errorInfo.text.setString("Error: \n        You are currently \n        creating Carrier!");
}

void GUIController::errorNoProductsToCarry()
{
    Sound::error();
    gui->errorInfo.text.setString("Carrier: No products to carry!");
}

void GUIController::errorNotEnoughGoods()
{
    Sound::error();
    gui->errorInfo.text.setString("Goods: \n        Not enough goods \n        for building!");
}

void GUIController::errorMustBuildNearForest()
{
    Sound::error();
    gui->errorInfo.text.setString("Error: \n        You have to build \n        sawmill near forest!");
}

void GUIController::errorMustBuildNearRocks()
{
    Sound::error();
    gui->errorInfo.text.setString("Error: \n        You have to build \n       Stonecutter Hut\n       near rocks!");
}

void GUIController::errorMustBuildOnMountain()
{
    Sound::error();
    gui->errorInfo.text.setString("Error: \n        You have to build \n       goldmine on mountain!");
}
