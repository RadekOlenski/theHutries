#include <sstream>

#include <iostream>
#include "guiController.h"
#include "sound.h"
#include "buildingType.h"
#include "interactionMode.h"
#include "gamebalance.h"
#include "unittype.h"

GUIController::GUIController(sf::RenderWindow* hutrieApplication, ModelController* modelController, World* world, GUI* gui)
        : titleText(1024 + 20, 40, 45),
          bigTitleText(150, 100, 150, "The Hutries"),
          quote(500, 400, 30, ""),
          titleThread(&GUIText::display, &titleText),
          bigTitleThread(&GUIText::animation, &bigTitleText),
          quoteThread(&GUIController::displayIntro, this)
{

    this->hutrieApplication = hutrieApplication;
    this->modelController = modelController;
    this->world = world;
    this->gui = gui;
    visibleGrid = false;
    firstIteration = true;
    introFlag = false;
    displayHutriesHall = false;
    readyForGame = false;
    lockArrows = true;
    chosenHowToText = 0;
    setBuildingsCosts();
}

GUIController::~GUIController()
{
    titleThread.terminate();
    bigTitleThread.terminate();
    quoteThread.terminate();
    /*cursor.~Drawable();
    std::cout<<"1"<<std::endl;
    //fixed.;
    background.~Drawable();
    std::cout<<"2"<<std::endl;
    backgroundTexture.~Texture();
    std::cout<<"3"<<std::endl;
    buildingToCursor.~Drawable();
    std::cout<<"4"<<std::endl;
    buildingToCursorTexture.~Texture();
    std::cout<<"5"<<std::endl;
    cursorTexture.~Texture();
    std::cout<<"6"<<std::endl;
    cursorHammerTexture.~Texture();
    std::cout<<"7"<<std::endl;

    titleText.~GUIText();
    std::cout<<"8"<<std::endl;
    bigTitleText.~GUIText();
    std::cout<<"9"<<std::endl;
    quote.~GUIText();
    std::cout<<"10"<<std::endl;*/

    /*titleThread.~Thread();
    std::cout<<"11"<<std::endl;
    bigTitleThread.~Thread();
    std::cout<<"12"<<std::endl;
    quoteThread.~Thread();
    std::cout<<"13"<<std::endl;*/
}

void GUIController::displayIntro()
{
    gui->startingText.text.setString("");
    quote.animation();
    gui->skipText.text.setString("Press Space to skip");
    quote.text.setColor(sf::Color (0, 0, 0, 0));
    gui->startingText.text.setPosition(200, 300);
    gui->startingText.text.setString(GameBalance::historyString);
    sf::sleep(sf::seconds(5));
    gui->startingText.text.setString(GameBalance::historyString2);
    sf::sleep(sf::seconds(5));
    displayHutriesHall = true;
    gui->startingText.text.setPosition(200, 550);
    gui->startingText.text.setString(GameBalance::historyString3);
    introFlag = false;
    modelController->setReadyForGame(true);
}

void GUIController::drawHutriesHall()
{
    drawToApplication(world->buildings.at(0)->sprite);
}

void GUIController::handleMenuButtonsActions()
{
    if (gui->playButton.checkBounds())
    {
        lockArrows = true;
        gui->nextArrowButton.setActive(false);
        gui->backArrowButton.setActive(false);
        quote.text.setStyle(sf::Text::Italic);
        quote.text.setString(GameBalance::quoteString);
        introFlag = true;
        Sound::click();
        return;
    }
    if (gui->aboutButton.checkBounds())
    {
        lockArrows = true;
        gui->nextArrowButton.setActive(false);
        gui->backArrowButton.setActive(false);
        gui->startingText.text.setString(GameBalance::aboutString);
        Sound::click();
        return;
    }
    if (gui->exitButton.checkBounds())
    {
        lockArrows = true;
        gui->nextArrowButton.setActive(false);
        gui->backArrowButton.setActive(false);
        Sound::click();
        hutrieApplication->close();
    }
    if (gui->howToPlayButton.checkBounds())
    {
        lockArrows = false;
        gui->startingText.text.setCharacterSize(30);
        gui->startingText.text.setString(GameBalance::howToPlayString);
        chosenHowToText = 0;
        gui->nextArrowButton.setActive(true);
        updateHowToText();
        Sound::click();
        return;
    }
    if (gui->nextArrowButton.checkBounds() && gui->nextArrowButton.isActive() )
    {
        chosenHowToText++;
        updateHowToText();

        Sound::click();
    }
    if (gui->backArrowButton.checkBounds() && gui->backArrowButton.isActive() )
    {
        chosenHowToText--;
        updateHowToText();
        Sound::click();
    }
    if (!lockArrows)
    {
        if (chosenHowToText == 2 ) gui->nextArrowButton.setActive(false);
        else gui->nextArrowButton.setActive(true);
        if (chosenHowToText == 0 ) gui->backArrowButton.setActive(false);
        else gui->backArrowButton.setActive(true);
    }
}

void GUIController::handlePauseButtonsActions()
{
    if(gui->resumeButton.checkBounds() && gui->resumeButton.isActive())
    {
        modelController->setPauseGame(false);
        Sound::click();
        return;
    }

    if(gui->mainMenuButton.checkBounds() && gui->mainMenuButton.isActive())
    {
        modelController->setBackToMenu(true);
        std::cout<<"DUPA";
        Sound::click();
        return;
    }
}

void GUIController::updateHowToText()
{
    switch (chosenHowToText)
    {
    case 0:
      gui->startingText.text.setString(GameBalance::howToPlayString);
      break;
    case 1:
      gui->startingText.text.setString(GameBalance::howToPlayString2);
      break;
    case 2:
      gui->startingText.text.setString(GameBalance::howToPlayString3);
      break;
    }
}

void GUIController::handleGUIButtonsActions()
{
    if (gui->hutrieButton.checkBounds())
    {
        modelController->setChosenInteractionMode(InteractionMode::HUTRIEINFO);
        Sound::click();
        return;
    }

    if (gui->buildButton.checkBounds())
    {
        modelController->setChosenInteractionMode(InteractionMode::BUILDMODE);
        modelController->setChosenBuildingType(BuildingType::HUTRIESHALL);
        Sound::click();
//        return;
    }
    if (gui->sawmill.checkBounds() && gui->sawmill.isActive())
    {
        modelController->setChosenBuildingType(BuildingType::SAWMILL);
        showEmptyUnits(true);
        Sound::click();
//        return;
    }
    if (gui->stonecutter.checkBounds() && gui->stonecutter.isActive())
    {
        modelController->setChosenBuildingType(BuildingType::STONECUTTERHUT);
        showEmptyUnits(true);
        Sound::click();
//        return;
    }
    if (gui->barracks.checkBounds() && gui->barracks.isActive())
    {
        modelController->setChosenBuildingType(BuildingType::BARRACKS);
        showEmptyUnits(true);
        Sound::click();
//        return;
    }
    if (gui->residence.checkBounds() && gui->residence.isActive())
    {
        modelController->setChosenBuildingType(BuildingType::RESIDENCE);
        showEmptyUnits(true);
        Sound::click();
//        return;
    }
    if (gui->goldmine.checkBounds() && gui->goldmine.isActive())
    {
        modelController->setChosenBuildingType(BuildingType::GOLDMINE);
        showEmptyUnits(true);
        Sound::click();
//        return;
    }
    if (gui->farm.checkBounds() && gui->farm.isActive())
    {
        modelController->setChosenBuildingType(BuildingType::FARM);
        showEmptyUnits(true);
        Sound::click();
//        return;
    }

    updateBuildingsHighlight();

    if (world->lastClickedUnit)
    {
        world->lastClickedUnit->getMapObject()->buttonAction();
        return;
    }
}

void GUIController::updateBuildingsHighlight()
{
    gui->sawmill.button.setFillColor(sf::Color::White);
    gui->stonecutter.button.setFillColor(sf::Color::White);
    gui->goldmine.button.setFillColor(sf::Color::White);
    gui->farm.button.setFillColor(sf::Color::White);
    gui->barracks.button.setFillColor(sf::Color::White);
    gui->residence.button.setFillColor(sf::Color::White);

    switch(modelController->getChosenBuildingType())
    {
    case 1:
        gui->sawmill.button.setFillColor(sf::Color::Green);
        break;
    case 2:
        gui->stonecutter.button.setFillColor(sf::Color::Green);
        break;
    case 3:
        gui->goldmine.button.setFillColor(sf::Color::Green);
        break;
    case 4:
        gui->farm.button.setFillColor(sf::Color::Green);
        break;
    case 5:
        gui->barracks.button.setFillColor(sf::Color::Green);
        break;
    case 6:
        gui->residence.button.setFillColor(sf::Color::Green);
        break;
    }
}
void GUIController::highlightClock(bool highlight)
{
    if (highlight)
    {
        gui->timeLeft.text.setCharacterSize(600);
        gui->timeLeft.text.setColor(sf::Color::Black);
        gui->timeLeft.text.setPosition(30,30);
    }
    else
    {
        gui->timeLeft.text.setCharacterSize(20);
        gui->timeLeft.text.setColor(sf::Color::White);
        gui->timeLeft.text.setPosition(20,640 + 2 + 98);
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

void GUIController::setMenuButtonsFlags(bool buttonFlag)
{
    gui->playButton.setActive(buttonFlag);
    gui->howToPlayButton.setActive(buttonFlag);
    gui->aboutButton.setActive(buttonFlag);
    gui->exitButton.setActive(buttonFlag);
}

void GUIController::setPauseButtonsFlags(bool buttonFlag)
{
    gui->resumeButton.setActive(buttonFlag);
    gui->settingsButton.setActive(buttonFlag);
    gui->helpButton.setActive(buttonFlag);
    gui->mainMenuButton.setActive(buttonFlag);
}

void GUIController::drawApplication()
{
    getView();
    prepareToDisplay();
    drawToApplication(background);
    displayGUI();
    displayElementsOfGUI();
    drawToApplication(titleText.text);

    std::vector<Unit*>::iterator it;
    drawGrid(it);
    drawMapObjects(it);
    drawToApplication(gui->timeLeft.text);
        setCursorSprite();
    drawToApplication(buildingToCursor);
        drawToApplication(cursor);
    displayApplication();
}

void GUIController::setCursorSprite()
{
    if (modelController->getChosenInteractionMode() == 2 && modelController->getChosenBuildingType() != BuildingType::HUTRIESHALL)
    {
        cursor.setTexture(cursorHammerTexture);
    }
    else
    {
       cursor.setTexture(cursorTexture);
    }
}

void GUIController::getView()
{
    fixed = hutrieApplication->getView();
    if (firstIteration)
    {
        //fixed.zoom(1.08);
        fixed.setViewport(sf::FloatRect(0, 0, modelController->getHorizontalScreenZoom(), modelController->getVerticalScreenZoom()));
        firstIteration = false;
    }
}

void GUIController::displayElementsOfGUI()
{
    if (modelController->getChosenInteractionMode() == InteractionMode::BUILDMODE) gui->displayBuildingsGUI();
    if (modelController->getChosenInteractionMode() == InteractionMode::HUTRIEINFO)
        gui->displayHutriesGUI(world->hutries.size(), world->carriers.size(), world->workers.size(),
                               world->warriors.size(), world->archers.size());
}

void GUIController::drawGrid(std::vector<Unit*>::iterator it)
{
    if(visibleGrid or (modelController->getChosenInteractionMode() == InteractionMode::BUILDMODE
                       && modelController->getChosenBuildingType() != BuildingType::HUTRIESHALL))
    {
        for (it = world->units.begin(); it != world->units.end(); ++it)
        {
            if((*it)->getType() == UnitType::FULL && (*it)->getMapObject()->isHighlighted())
                continue;
            else
                drawToApplication((*it)->field);
        }
    }
    for (it = world->units.begin(); it != world->units.end(); ++it)
    {
        if((*it)->getType() == UnitType::FULL && (*it)->getMapObject()->isHighlighted())
            drawToApplication((*it)->field);
    }
}

void GUIController::drawMapObjects(std::vector<Unit*>::iterator it)
{
    for (it = world->units.begin(); it != world->units.end(); ++it)     //rysosowanie wszystkich mapobjectow na mapie
        // - druga petla zeby ruszajacy sie Hutrie byli rysowani nad zielona kratka a nie pod
    {
        if ((*it)->getType() == UnitType::FULL)
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
                && modelController->getChosenInteractionMode() ==
                   InteractionMode::INFOMODE)  //jesli tryb info rysuj w prawym gui
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
    cursorHammerTexture.loadFromFile(Textures::hammerCursor);
    cursor.setTexture(cursorTexture);
    buildingToCursorTexture.loadFromFile(Textures::sawmillBasic);
    buildingToCursor.setTexture(buildingToCursorTexture);
    sf::Color color (0,150,0,150);
    buildingToCursor.setColor(color);
    buildingToCursor.setScale(0.4,0.4);
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
    gui->displayMainGUI();
}

void GUIController::displayApplication()
{
    hutrieApplication->display();
}

void GUIController::setCursorPosition()
{
    sf::Vector2i pixelPos = sf::Mouse::getPosition(*hutrieApplication);
    pixelPos.x = (int) (pixelPos.x * modelController->getHorizontalScreenZoom());
    pixelPos.y = (int) (pixelPos.y * modelController->getVerticalScreenZoom());
    sf::Vector2f worldPos = hutrieApplication->mapPixelToCoords(pixelPos);
    cursor.setPosition(worldPos);
    attachBuildingToCursor(worldPos);
}

void GUIController::attachBuildingToCursor (sf::Vector2f worldPos)
{
    if (modelController->getChosenInteractionMode() == InteractionMode::BUILDMODE)
    {
        switch(modelController->getChosenBuildingType())
        {
        case BuildingType::SAWMILL:
            buildingToCursorTexture.loadFromFile(Textures::sawmillBasic);
            break;
        case BuildingType::STONECUTTERHUT:
            buildingToCursorTexture.loadFromFile(Textures::stonecutterHutBasic);
            break;
        case BuildingType::FARM:
            buildingToCursorTexture.loadFromFile(Textures::farmBasic);
            break;
        case BuildingType::GOLDMINE:
            buildingToCursorTexture.loadFromFile(Textures::goldmineBasic);
            break;
        case BuildingType::BARRACKS:
            buildingToCursorTexture.loadFromFile(Textures::barracksBasic);
            break;
        case BuildingType::RESIDENCE:
            buildingToCursorTexture.loadFromFile(Textures::residenceBasic);
            break;
        default:
            buildingToCursorTexture.loadFromFile(Textures::carrierEmpty);
            break;
        };
    }
    else
    {
        buildingToCursorTexture.loadFromFile(Textures::carrierEmpty);
    }
    buildingToCursor.setPosition(worldPos);
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

void GUIController::displayGameOver(bool win, bool next)
{
    if (next)
    {
       gui->endingBuildingsStats.text.setString(getEndingBuildingsStats());
       gui->endingHutriesStats.text.setString(getEndingHutriesStats());
       gui->endingProductionStats.text.setString(getEndingProductionStats());
    }
    else if (win)
    {
        gui->endingBuildingsStats.text.setString(GameBalance::winString);
    }
    setCursorPosition();
    prepareToDisplay();
    displayGUI();
    drawToApplication(background);
    drawToApplication(gui->endingBuildingsStats.text);
    if (next)
    {
        gui->endingBuildingsStats.text.setPosition(110,280);
        drawToApplication(gui->endingHutriesStats.text);
        drawToApplication(gui->endingProductionStats.text);
        next = false;
    }
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

void GUIController::displayPauseMenu()
{
    setCursorPosition();
    getView();
    setCursorSprite();
    gui->displayPauseMenu();
    createCursor();
    drawToApplication(cursor);
    displayApplication();
}

void GUIController::captureScreen()
{
    hutrieApplication->clear();
    drawToApplication(background);
    displayGUI();
    displayElementsOfGUI();
    drawToApplication(titleText.text);

    std::vector<Unit*>::iterator it;
    drawGrid(it);
    drawMapObjects(it);
    drawToApplication(gui->timeLeft.text);
}

std::string GUIController::getEndingBuildingsStats()
{
    std::ostringstream stats;
    stats << "Buildings:" << std::endl
          << "General: " << world->buildings.size() << std::endl
          << "Goods Buildings: " << world->goodsBuildingIndex.size() << std::endl
          << "Barracks: "  << world->barracksIndex.size() << std::endl
          << "Residence: " <<  ( world->hutries.size() + world->availableSlots - GameBalance::startingHutrieSlots) / GameBalance::hutrieSlotsAddition << std::endl
          << "\n\n\t\t\t\t\t\t\t\t\t\t\t\tPress ESC to exit";
    return stats.str();
}

std::string GUIController::getEndingHutriesStats()
{
    std::ostringstream stats;
    stats << "Hutries:"   << std::endl
          << "General: "  << world->hutries.size()  << std::endl
          << "Carriers: " << world->carriers.size() << std::endl
          << "Workers: "  << world->workers.size()  << std::endl
          << "Warriors: " << world->warriors.size() << std::endl
          << "Archers: "  << world->archers.size();
    return stats.str();
}

std::string GUIController::getEndingProductionStats()
{
    std::ostringstream stats;
    stats << "Production:" << std::endl
          << "General: " << world->generalGoods.getWood() + world->generalGoods.getStone() + world->generalGoods.getFood() + world->generalGoods.getGold() << std::endl
          << "Wood: " << world->generalGoods.getWood()<< std::endl
          << "Stone: " << world->generalGoods.getStone()<< std::endl
          << "Food: " << world->generalGoods.getFood()<< std::endl
          << "Gold: " << world->generalGoods.getGold();
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

void GUIController::setBuildingsCosts()
{
    std::ostringstream desc;
    desc << GameBalance::sawmillCost.getWood();
    gui->twoodSawmill.text.setString(desc.str());
    std::ostringstream desc1;
    desc1 << GameBalance::sawmillCost.getStone();
    gui->tstoneSawmill.text.setString(desc1.str());

    std::ostringstream desc2;
    desc2 << GameBalance::stonecutterhutCost.getWood();
    gui->twoodStonecutter.text.setString(desc2.str());
    std::ostringstream desc3;
    desc3 << GameBalance::stonecutterhutCost.getStone();
    gui->twoodStonecutter.text.setString(desc3.str());

    std::ostringstream desc4;
    desc4 << GameBalance::farmCost.getWood();
    gui->twoodFarm.text.setString(desc4.str());
    std::ostringstream desc5;
    desc5 << GameBalance::farmCost.getStone();
    gui->tstoneFarm.text.setString(desc5.str());

    std::ostringstream desc6;
    desc6 << GameBalance::goldmineCost.getWood();
    gui->twoodGoldmine.text.setString(desc6.str());
    std::ostringstream desc7;
    desc7 << GameBalance::goldmineCost.getStone();
    gui->tstoneGoldmine.text.setString(desc7.str());

    std::ostringstream desc8;
    desc8 << GameBalance::residenceCost.getWood();
    gui->twoodResidence.text.setString(desc8.str());
    std::ostringstream desc9;
    desc9 << GameBalance::residenceCost.getStone();
    gui->tstoneResidence.text.setString(desc9.str());

    std::ostringstream desc10;
    desc10 << GameBalance::barracksCost.getWood();
    gui->twoodBarracks.text.setString(desc10.str());
    std::ostringstream desc11;
    desc11 << GameBalance::barracksCost.getStone();
    gui->tstoneBarracks.text.setString(desc11.str());
}

void GUIController::showEmptyUnits(bool mark)
{
    std::vector<Unit*>::iterator it;
    sf::Color emptyColor(0, 255, 0, 30);
    sf::Color fullColor(255, 0, 0, 50);
    sf::Color forestColor(sf::Color::Black);
    if (!mark)
    {
        emptyColor = sf::Color::Transparent;
        fullColor = sf::Color::Transparent;
        forestColor = sf::Color::Transparent;
    }
    if (modelController->getChosenBuildingType() == BuildingType::SAWMILL)
    {
         for (it = world->units.begin(); it != world->units.end(); ++it)
        {
            if ((*it)->getType() == UnitType::NEARFOREST ||
                (*it)->getType() == UnitType::NEARFOREST + UnitType::NEARMOUNTAIN ||
                (*it)->getType() == UnitType::NEARFOREST + UnitType::NEARROCKS ||
                (*it)->getType() == UnitType::NEARFOREST + UnitType::NEARROCKS + UnitType::NEARMOUNTAIN )
            {
                (*it)->field.setFillColor(emptyColor);
            }
            else
            {
                (*it)->field.setFillColor(fullColor);
            }
        }
    }
    else if (modelController->getChosenBuildingType() == BuildingType::STONECUTTERHUT)
    {
         for (it = world->units.begin(); it != world->units.end(); ++it)
        {
            if ((*it)->getType() == UnitType::NEARROCKS ||
                (*it)->getType() == UnitType::NEARROCKS + UnitType::NEARMOUNTAIN ||
                (*it)->getType() == UnitType::NEARROCKS + UnitType::NEARFOREST ||
                (*it)->getType() == UnitType::NEARROCKS + UnitType::NEARFOREST + UnitType::NEARMOUNTAIN )
            {
                (*it)->field.setFillColor(emptyColor);
            }
            else
            {
                (*it)->field.setFillColor(fullColor);
            }
        }
    }
    else if (modelController->getChosenBuildingType() == BuildingType::GOLDMINE)
    {
         for (it = world->units.begin(); it != world->units.end(); ++it)
        {
            if ((*it)->getType() == UnitType::NEARMOUNTAIN ||
                (*it)->getType() == UnitType::NEARMOUNTAIN + UnitType::NEARROCKS ||
                (*it)->getType() == UnitType::NEARMOUNTAIN + UnitType::NEARFOREST ||
                (*it)->getType() == UnitType::NEARMOUNTAIN + UnitType::NEARFOREST + UnitType::NEARROCKS )
            {
                (*it)->field.setFillColor(emptyColor);
            }
            else
            {
                (*it)->field.setFillColor(fullColor);
            }
        }
    }
    else
    {
        for (it = world->units.begin(); it != world->units.end(); ++it)
    {
        if ((*it)->getType() != UnitType::FULL)
        {
            (*it)->field.setFillColor(emptyColor);
        }
        else
        {
             (*it)->field.setFillColor(fullColor);
        }
    }
    }
}

void GUIController::resetDrawsCounter()
{
    gui->resetDrawsCounter();
}


void GUIController::updateClock(int time)
{
    std::ostringstream newTime;
    newTime << time / 60 << ":" << time % 60;
    gui->timeLeft.text.setString(newTime.str());
}

//=================================================================================
//                              ERRORS
//=================================================================================

void GUIController::handleErrorsVisiblity()
{
    if (errorsVisiblityClock.getElapsedTime().asSeconds() > 4)
    {
        gui->errorInfo.text.setString("Message Box:");
    }
}

void GUIController::errorNoCarriers()
{
    Sound::error();
    errorsVisiblityClock.restart();
    gui->errorInfo.text.setString(
            "Error: No available carriers!\nEveryone is busy! \nCreate carrier in HutriesHall \nor build residence");
}

void GUIController::errorNoSlots()
{
    Sound::error();
    errorsVisiblityClock.restart();
    gui->errorInfo.text.setString("Error: \n        No more slots! \n       Build residence!");
}

void GUIController::errorNoWorkers()
{
    Sound::error();
    errorsVisiblityClock.restart();
    gui->errorInfo.text.setString(
            "Error: No available workers! \nEveryone is busy! \nCreate worker in HutriesHall\nor build residence");
}


void GUIController::errorUnitOccupied()
{
    Sound::error();
    errorsVisiblityClock.restart();
    gui->errorInfo.text.setString("Error: \n        Unit not empty.\n        Choose another one");
}

void GUIController::errorOutOfMap()
{
    Sound::error();
    errorsVisiblityClock.restart();
    gui->errorInfo.text.setString("Error: \n        Building out of map.\n        Choose another place");
}

void GUIController::errorAlreadyCreatingArcher()
{
    Sound::error();
    errorsVisiblityClock.restart();
    gui->errorInfo.text.setString("Error: \n        You are currently \n        creating Archer!");
}

void GUIController::errorAlreadyCreatingWarrior()
{
    Sound::error();
    errorsVisiblityClock.restart();
    gui->errorInfo.text.setString("Error: \n        You are currently \n        creating Warrior!");
}

void GUIController::errorAlreadyCreatingWorker()
{
    Sound::error();
    errorsVisiblityClock.restart();
    gui->errorInfo.text.setString("Error: \n        You are currently \n        creating Worker!");
}

void GUIController::errorAlreadyCreatingCarrier()
{
    Sound::error();
    errorsVisiblityClock.restart();
    gui->errorInfo.text.setString("Error: \n        You are currently \n        creating Carrier!");
}

void GUIController::errorNoProductsToCarry()
{
    Sound::error();
    errorsVisiblityClock.restart();
    gui->errorInfo.text.setString("Carrier: No products to carry!");
}

void GUIController::errorNotEnoughGoods()
{
    Sound::error();
    errorsVisiblityClock.restart();
    gui->errorInfo.text.setString("Goods: \n        Not enough goods \n        for building!");
}

void GUIController::errorMustBuildNearForest()
{
    Sound::error();
    errorsVisiblityClock.restart();
    gui->errorInfo.text.setString("Error: \n        You have to build \n        sawmill near forest!");
}

void GUIController::errorMustBuildNearRocks()
{
    Sound::error();
    errorsVisiblityClock.restart();
    gui->errorInfo.text.setString("Error: \n        You have to build \n       Stonecutter Hut\n       near rocks!");
}

void GUIController::errorMustBuildOnMountain()
{
    Sound::error();
    errorsVisiblityClock.restart();
    gui->errorInfo.text.setString("Error: \n        You have to build \n       goldmine on mountain!");
}

void GUIController::errorToMuchWorkers()
{
    Sound::error();
    errorsVisiblityClock.restart();
    gui->errorInfo.text.setString("Error: \n        Too much workers!");
}

