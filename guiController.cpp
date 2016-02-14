#include <sstream>

#include <iostream>
#include "guiController.h"
#include "sound.h"
#include "buildingType.h"
#include "interactionMode.h"
#include "gamebalance.h"
#include "unittype.h"

GUIController::GUIController(sf::RenderWindow* hutrieApplication, ModelController* modelController, World* world,
                             GUI* gui)
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
    animationCounter = 0;
    frameCounter = 0;
    setBuildingsCosts();
}

GUIController::~GUIController()
{
    titleThread.terminate();
    bigTitleThread.terminate();
    quoteThread.terminate();
}

void GUIController::chooseDifficulty()
{
    bigTitleText.text.setString("Difficulty:");
//    gui->startingText.text.setPosition(200, 550);
    gui->startingText.text.setString("");
    gui->easyText.text.setString("CARRIER:\n\n\n\nMax time\nMax goods");
    gui->normalText.text.setString("WORKER:\n\n\n\nNormal time\nNormal goods");
    gui->hardText.text.setString("WARRIOR:\n\n\n\nMin time\nMin goods\nNo gold");
    setDifficultyButtonsFlags(true);
}

void GUIController::hideDifficultyTexts()
{
    bigTitleText.text.setString("The Hutries");
    gui->easyText.text.setString("");
    gui->normalText.text.setString("");
    gui->hardText.text.setString("");
}

void GUIController::displayIntro()
{
    hideDifficultyTexts();
    gui->startingText.text.setString("");
    quote.text.setString(GameBalance::quoteString);
    quote.animation();
    gui->skipText.text.setString("Press Space to skip");
    quote.text.setColor(sf::Color(0, 0, 0, 0));
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
        turnOffHelp();
        quote.text.setStyle(sf::Text::Italic);
        chooseDifficulty();
        Sound::click();
        return;
    }
    if (gui->aboutButton.checkBounds())
    {
        turnOffHelp();
        hideDifficultyTexts();
        setDifficultyButtonsFlags(false);
        gui->startingText.text.setPosition(160, 320);
        gui->startingText.text.setString(GameBalance::aboutString);
        Sound::click();
        return;
    }
    if (gui->exitButton.checkBounds())
    {
        turnOffHelp();
        hideDifficultyTexts();
        setDifficultyButtonsFlags(false);
        Sound::click();
        modelController->setExitWindow(true);
        return;
    }
    if (gui->howToPlayButton.checkBounds())
    {
        lockArrows = false;
        hideDifficultyTexts();
        setDifficultyButtonsFlags(false);
        bigTitleThread.terminate();
        bigTitleText.text.setColor(sf::Color::Transparent);
        chosenHowToText = 1;
        gui->nextArrowButton.setActive(true);
        updateHowToText();
        Sound::click();
        return;
    }
    if (gui->nextArrowButton.checkBounds() && gui->nextArrowButton.isActive())
    {
        chosenHowToText++;
        updateHowToText();

        Sound::click();
    }
    if (gui->backArrowButton.checkBounds() && gui->backArrowButton.isActive())
    {
        chosenHowToText--;
        updateHowToText();
        Sound::click();
    }

    handleDifficultyButtonsActions();
    handleHowToPlayButtonsActions();

    if (!lockArrows)
    {
        if (chosenHowToText == 5) gui->nextArrowButton.setActive(false);
        else gui->nextArrowButton.setActive(true);
        if (chosenHowToText == 1) gui->backArrowButton.setActive(false);
        else gui->backArrowButton.setActive(true);
    }
}

void GUIController::turnOffHelp()
{
    chosenHowToText = 0;
    activateHowToPlayButtons(false);
    setHelpBuildingsFlags(false);
    lockArrows = true;
    gui->nextArrowButton.setActive(false);
    gui->backArrowButton.setActive(false);
    gui->backToHelpButton.setActive(false);
    bigTitleText.text.setColor(sf::Color::Black);
    gui->helpTitleText.text.setString ("");
}

void GUIController::handleHowToPlayButtonsActions()
{
    if (gui->backToHelpButton.isActive() && gui->backToHelpButton.checkBounds() )
    {
        chosenHowToText = 1;
        updateHowToText();
        Sound::click();
    }
    if (gui->mechanicsButton.isActive() && gui->mechanicsButton.checkBounds() )
    {
        chosenHowToText = 2;
        updateHowToText();
        Sound::click();
    }
    if (gui->buildingsButton.isActive() && gui->buildingsButton.checkBounds() )
    {
        chosenHowToText = 3;
        updateHowToText();
        Sound::click();
    }
    if (gui->hutriesTypesButton.isActive() && gui->hutriesTypesButton.checkBounds() )
    {
        chosenHowToText = 4;
        updateHowToText();
        Sound::click();
    }
    if (gui->resourcesButton.isActive() && gui->resourcesButton.checkBounds() )
    {
        chosenHowToText = 5;
        updateHowToText();
        Sound::click();
    }
}

void GUIController::activateHowToPlayButtons(bool active)
{
    gui->buildingsButton.setActive(active);
    gui->hutriesTypesButton.setActive(active);
    gui->resourcesButton.setActive(active);
    gui->mechanicsButton.setActive(active);
    gui->backToHelpButton.setActive(!active);
}

void GUIController::handleDifficultyButtonsActions()
{
    if (gui->easyButton.checkBounds() && gui->easyButton.isActive())
    {
        setDifficultyButtonsFlags(false);
        introFlag = true;
        setDifficulty("EASY");
        Sound::click();
        return;
    }
    if (gui->normalButton.checkBounds() && gui->normalButton.isActive())
    {
        setDifficultyButtonsFlags(false);
        introFlag = true;
        setDifficulty("NORMAL");
        Sound::click();
        return;
    }
    if (gui->hardButton.checkBounds() && gui->hardButton.isActive())
    {
        setDifficultyButtonsFlags(false);
        introFlag = true;
        setDifficulty("HARD");
        Sound::click();
        return;
    }
}

void GUIController::handlePauseButtonsActions()
{
    if (gui->resumeButton.checkBounds() && gui->resumeButton.isActive())
    {
        modelController->setPauseGame(false);
        Sound::click();
        return;
    }

    if (gui->mainMenuButton.checkBounds() && gui->mainMenuButton.isActive())
    {
        modelController->setBackToMenu(true);
        Sound::click();
        return;
    }
}

void GUIController::updateHowToText()
{
    switch (chosenHowToText)
    {
        case 1:
            gui->helpTitleText.text.setString ("");
            gui->helpTitleText.text.setPosition(400, 50);
            gui->startingText.text.setPosition(120, 130);
            gui->startingText.text.setCharacterSize(30);
            gui->startingText.text.setString(GameBalance::howToPlayString);
            activateHowToPlayButtons(true);
            setHelpBuildingsFlags(false);
            break;
        case 2:
            gui->helpTitleText.text.setString ("Mechanics:");
            gui->helpTitleText.text.setPosition(400, 50);
            gui->startingText.text.setPosition(120, 130);
            gui->startingText.text.setString(GameBalance::howToPlayMechanicsString);
            activateHowToPlayButtons(false);
            setHelpBuildingsFlags(false);
            break;
        case 3:
            gui->helpTitleText.text.setString ("Buildings:");
            gui->helpTitleText.text.setPosition(400, 50);
            gui->startingText.text.setPosition(250, 110);
            gui->startingText.text.setString(GameBalance::howToPlayBuildingsString);
            activateHowToPlayButtons(false);
            setHelpBuildingsFlags(true);
            break;
        case 4:
            gui->helpTitleText.text.setString ("Hutries:");
            gui->helpTitleText.text.setPosition(400, 50);
            gui->startingText.text.setPosition(120, 130);
            gui->startingText.text.setString(GameBalance::howToPlayHutriesString);
            activateHowToPlayButtons(false);
            setHelpBuildingsFlags(false);
            break;
        case 5:
            gui->helpTitleText.text.setString ("Resources:");
            gui->helpTitleText.text.setPosition(130, 45);
            gui->startingText.text.setPosition(350, 130);
            gui->startingText.text.setString(GameBalance::howToPlayResourcesString);
            activateHowToPlayButtons(false);
            setHelpBuildingsFlags(false);
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

    if (world->lastClickedUnit && modelController->getChosenInteractionMode() == InteractionMode::INFOMODE)
    {
        world->lastClickedUnit->getMapObject()->buttonAction();
        world->lastClickedUnit->getMapObject()->constructionButtonAction();
        return;
    }
}

void GUIController::handleExitButtonsActions()
{
    if (gui->exitYesButton.checkBounds() && gui->exitYesButton.isActive())
    {
        GameBalance::exitFlag = true;
        modelController->setExitWindow(false);
        return;
    }
    if (gui->exitNoButton.checkBounds() && gui->exitNoButton.isActive())
    {
        GameBalance::exitFlag = false;
        modelController->setExitWindow(false);
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

    switch (modelController->getChosenBuildingType())
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
        gui->timeLeft.text.setCharacterSize(100);
        gui->timeLeft.text.setColor(sf::Color::Black);
        gui->timeLeft.text.setPosition(30, 590);
    }
    else
    {
        gui->timeLeft.text.setCharacterSize(20);
        gui->timeLeft.text.setColor(sf::Color::White);
        gui->timeLeft.text.setPosition(20, 640 + 2 + 98);
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

void GUIController::setDifficultyButtonsFlags(bool buttonFlag)
{
    gui->easyButton.setActive(buttonFlag);
    gui->normalButton.setActive(buttonFlag);
    gui->hardButton.setActive(buttonFlag);
}

void GUIController::setPauseButtonsFlags(bool buttonFlag)
{
    gui->resumeButton.setActive(buttonFlag);
    gui->settingsButton.setActive(buttonFlag);
    gui->helpButton.setActive(buttonFlag);
    gui->mainMenuButton.setActive(buttonFlag);
}

void GUIController::setHelpBuildingsFlags (bool buttonFlag)
{
    gui->helpHutriesHall.setActive(buttonFlag);
    gui->helpBarracks.setActive(buttonFlag);
    gui->helpResidence.setActive(buttonFlag);
    gui->helpSawmill.setActive(buttonFlag);
    gui->helpStonecutter.setActive(buttonFlag);
    gui->helpFarm.setActive(buttonFlag);
    gui->helpGoldmine.setActive(buttonFlag);
}

void GUIController::setExitButtonsFlags(bool buttonFlag)
{
    gui->exitYesButton.setActive(buttonFlag);
    gui->exitNoButton.setActive(buttonFlag);
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
    if (modelController->getChosenInteractionMode() == 2 &&
        modelController->getChosenBuildingType() != BuildingType::HUTRIESHALL)
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
        fixed.setViewport(sf::FloatRect(0, 0, modelController->getHorizontalScreenZoom(),
                                        modelController->getVerticalScreenZoom()));
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

void GUIController::setGridOutlineColor(bool outlineColorFlag)
{
    sf::Color color(0, 255, 0, 60);
    if (!outlineColorFlag) color = sf::Color::Transparent;
   // std::vector<Unit*>::iterator it;
    for (auto it = world->units.begin(); it != world->units.end(); ++it)
    {
        (*it)->field.setOutlineColor(color);
    }
}


void GUIController::drawGrid(std::vector<Unit*>::iterator it)
{
    if (visibleGrid or (modelController->getChosenInteractionMode() == InteractionMode::BUILDMODE
                        && modelController->getChosenBuildingType() != BuildingType::HUTRIESHALL))
    {
        for (it = world->units.begin(); it != world->units.end(); ++it)
        {
            if ((*it)->getType() == UnitType::FULL && (*it)->getMapObject()->isHighlighted())
                continue;
            else
                drawToApplication((*it)->field);
        }
    }
    for (it = world->units.begin(); it != world->units.end(); ++it)
    {
        if ((*it)->getType() == UnitType::FULL && (*it)->getMapObject()->isHighlighted())
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
                (*it)->getMapObject()->showConstructionButtons();
                if (!modelController->getPauseGame())
                {
                    (*it)->getMapObject()->highlightButton();
                }

            }
            else (*it)->getMapObject()->deactivateButtons();
        }
    }
}

void GUIController::createBackground()
{
    background.setSize(sf::Vector2f(1024, 640 + 128));
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
    sf::Color color(0, 150, 0, 150);
    buildingToCursor.setColor(color);
    buildingToCursor.setScale(0.4, 0.4);
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

void GUIController::attachBuildingToCursor(sf::Vector2f worldPos)
{
    if (modelController->getChosenInteractionMode() == InteractionMode::BUILDMODE)
    {
        switch (modelController->getChosenBuildingType())
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

void GUIController::terminateQuoteThread()
{
    quoteThread.terminate();
}

void GUIController::setEndingText(bool win, bool next)
{
    if (next)
    {
        gui->setEndingMessageString(finalScore);
    }
    else if (win)
    {
        gui->setEndingMessageString("You Win!!!");
    }
    else
    {
        gui->setEndingMessageString("You Lose!!!");
    }

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
        setEndingText(win, next);
        gui->endingBuildingsStats.text.setString(GameBalance::winString);
    }
    setCursorPosition();
    prepareToDisplay();
    displayGUI();
    drawToApplication(background);
    drawToApplication(gui->endingBuildingsStats.text);
    if (next)
    {
        setEndingText(win, next);
        gui->endingBuildingsStats.text.setPosition(110, 280);
        drawToApplication(gui->endingHutriesStats.text);
        drawToApplication(gui->endingProductionStats.text);
        next = false;
    }
    drawToApplication(titleText.text);
    gui->displayEndingText();
    drawToApplication(cursor);
    displayApplication();
}

void GUIController::displayHowToPlay()
{
   drawToApplication( gui->helpTitleText.text );

   if  (gui->backToHelpButton.isActive())
   {
       drawToApplication( gui->backToHelpButton.button );
       drawToApplication (gui->backToHelpText.text);
   }
   if  (chosenHowToText == 1)
   {
       drawToApplication( gui->mechanicsButton.button );
       drawToApplication (gui->mechanicsText.text);
       drawToApplication( gui->buildingsButton.button );
       drawToApplication (gui->buildingsText.text);
       drawToApplication( gui->resourcesButton.button );
       drawToApplication (gui->resourcesText.text);
       drawToApplication( gui->hutriesTypesButton.button );
       drawToApplication (gui->hutriesTypesText.text);
       return;
   }
   if  (chosenHowToText == 3)
   {
       drawToApplication( gui->helpSawmill.button );
       drawToApplication( gui->helpStonecutter.button );
       drawToApplication( gui->helpFarm.button );
       drawToApplication( gui->helpGoldmine.button );
       drawToApplication( gui->helpBarracks.button );
       drawToApplication( gui->helpResidence.button );
       drawToApplication( gui->helpHutriesHall.button );
       drawToApplication( gui->helpHutriesHallText.text );
       drawToApplication( gui->helpBarracksText.text );
       drawToApplication( gui->helpResidenceText.text );
       drawToApplication( gui->helpSawmillText.text );
       drawToApplication( gui->helpStonecutterText.text );
       drawToApplication( gui->helpFarmText.text );
       drawToApplication( gui->helpGoldmineText.text );
       return;
   }
   if   (chosenHowToText == 5)
   {
       drawToApplication( gui->helpGold.button);
       drawToApplication( gui->helpWood.button);
       drawToApplication( gui->helpStone.button);
       drawToApplication( gui->helpFood.button);
   }


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
    if (howToPlayFlag) displayHowToPlay();
    if (displayHutriesHall) drawHutriesHall();
    if (!introFlag) drawToApplication(cursor);
    displayApplication();
}

void GUIController::displayPauseMenu()
{
    setCursorPosition();
    getView();
    gui->displayPauseMenu();
    cursor.setTexture(cursorTexture);
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

void GUIController::displayExitWindow()
{
    hutrieApplication->clear();
    drawToApplication(background);
    gui->displayMenu();
    drawToApplication(titleText.text);
    drawToApplication(quote.text);
    drawToApplication(bigTitleText.text);
    setCursorPosition();
    getView();
    gui->displayExitWindow();
    drawToApplication(cursor);
    displayApplication();
}

std::string GUIController::getEndingBuildingsStats()
{
    std::ostringstream stats;
    stats << "Buildings:" << std::endl
          << "General: " << world->buildings.size() << std::endl
          << "Hutrie Hall: 1" << std::endl
          << "Goods Buildings: " << world->goodsBuildingIndex.size() << std::endl
          << "Barracks: "  << world->barracksIndex.size() << std::endl
          << "Residence: " <<  ( world->hutries.size() + world->availableSlots - GameBalance::startingHutrieSlots) / GameBalance::hutrieSlotsAddition << std::endl
          << "\n\t\t\t\t\t\t\t\t\t\t\t\tPress ESC to exit";
    return stats.str();
}

std::string GUIController::getEndingHutriesStats()
{
    std::ostringstream stats;
    stats << "Hutries:" << std::endl
    << "General: " << world->hutries.size() << std::endl
    << "Carriers: " << world->carriers.size() << std::endl
    << "Workers: " << world->workers.size() << std::endl
    << "Warriors: " << world->warriors.size() << std::endl
    << "Archers: " << world->archers.size();
    return stats.str();
}

std::string GUIController::getEndingProductionStats()
{
    std::ostringstream stats;
    stats << "Production:" << std::endl
    << "General: " << world->generalGoods.getWood() + world->generalGoods.getStone() + world->generalGoods.getFood() +
                      world->generalGoods.getGold() << std::endl
    << "Wood: " << world->generalGoods.getWood() << std::endl
    << "Stone: " << world->generalGoods.getStone() << std::endl
    << "Food: " << world->generalGoods.getFood() << std::endl
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
    if (!mark)
    {
        emptyColor = sf::Color::Transparent;
        fullColor = sf::Color::Transparent;
    }
    if (modelController->getChosenBuildingType() == BuildingType::SAWMILL)
    {
        for (it = world->units.begin(); it != world->units.end(); ++it)
        {
            if ((*it)->getType() == UnitType::NEARFOREST ||
                (*it)->getType() == UnitType::NEARFOREST + UnitType::NEARMOUNTAIN ||
                (*it)->getType() == UnitType::NEARFOREST + UnitType::NEARROCKS ||
                (*it)->getType() == UnitType::NEARFOREST + UnitType::NEARROCKS + UnitType::NEARMOUNTAIN)
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
                (*it)->getType() == UnitType::NEARROCKS + UnitType::NEARFOREST + UnitType::NEARMOUNTAIN)
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
                (*it)->getType() == UnitType::NEARMOUNTAIN + UnitType::NEARFOREST + UnitType::NEARROCKS)
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

void GUIController::updateClock(int time)
{
    std::ostringstream newTime;
    newTime << time / 60 << ":" << time % 60;
    gui->timeLeft.text.setString(newTime.str());
}

void GUIController::highlightTargetButton()
{
    if (modelController->getChosenInteractionMode() == InteractionMode::BUILDMODE
        && !modelController->getPauseGame())
    {
        if (gui->sawmill.checkBounds())
            gui->tSawmill.highlight();
        else gui->tSawmill.endHighlight();

        if (gui->sawmill.checkBounds())
            gui->tstoneSawmill.highlight();
        else gui->tstoneSawmill.endHighlight();

        if (gui->sawmill.checkBounds())
            gui->twoodSawmill.highlight();
        else gui->twoodSawmill.endHighlight();

        if (gui->stonecutter.checkBounds())
            gui->tStonecutter.highlight();
        else gui->tStonecutter.endHighlight();

        if (gui->stonecutter.checkBounds())
            gui->tstoneStonecutter.highlight();
        else gui->tstoneStonecutter.endHighlight();

        if (gui->stonecutter.checkBounds())
            gui->twoodStonecutter.highlight();
        else gui->twoodStonecutter.endHighlight();

        if (gui->goldmine.checkBounds())
            gui->tGoldmine.highlight();
        else gui->tGoldmine.endHighlight();

        if (gui->goldmine.checkBounds())
            gui->tstoneGoldmine.highlight();
        else gui->tstoneGoldmine.endHighlight();

        if (gui->goldmine.checkBounds())
            gui->twoodGoldmine.highlight();
        else gui->twoodGoldmine.endHighlight();

        if (gui->residence.checkBounds())
            gui->tResidence.highlight();
        else gui->tResidence.endHighlight();

        if (gui->residence.checkBounds())
            gui->tstoneResidence.highlight();
        else gui->tstoneResidence.endHighlight();

        if (gui->residence.checkBounds())
            gui->twoodResidence.highlight();
        else gui->twoodResidence.endHighlight();

        if (gui->farm.checkBounds())
            gui->tFarm.highlight();
        else gui->tFarm.endHighlight();

        if (gui->farm.checkBounds())
            gui->tstoneFarm.highlight();
        else gui->tstoneFarm.endHighlight();

        if (gui->farm.checkBounds())
            gui->twoodFarm.highlight();
        else gui->twoodFarm.endHighlight();

        if (gui->barracks.checkBounds())
            gui->tBarracks.highlight();
        else gui->tBarracks.endHighlight();

        if (gui->barracks.checkBounds())
            gui->tstoneBarracks.highlight();
        else gui->tstoneBarracks.endHighlight();

        if (gui->barracks.checkBounds())
            gui->twoodBarracks.highlight();
        else gui->twoodBarracks.endHighlight();
    }

    if (modelController->getChosenInteractionMode() == InteractionMode::MENUMODE)
    {
        if (howToPlayFlag)
        {
            if (gui->backArrowButton.checkBounds())
                gui->backArrowButton.button.setFillColor(sf::Color(0,0,0,200));
            else gui->backArrowButton.button.setFillColor(sf::Color::White);

            if (gui->nextArrowButton.checkBounds())
                gui->nextArrowButton.button.setFillColor(sf::Color(0,0,0,200));
            else gui->nextArrowButton.button.setFillColor(sf::Color::White);

            if (gui->mechanicsButton.checkBounds())
                gui->mechanicsText.highlight();
            else gui->mechanicsText.endHighlight();

            if (gui->buildingsButton.checkBounds())
                gui->buildingsText.highlight();
            else gui->buildingsText.endHighlight();

            if (gui->hutriesTypesButton.checkBounds())
                gui->hutriesTypesText.highlight();
            else gui->hutriesTypesText.endHighlight();

            if (gui->resourcesButton.checkBounds())
                gui->resourcesText.highlight();
            else gui->resourcesText.endHighlight();

            if (gui->backToHelpButton.checkBounds())
                gui->backToHelpText.highlight();
            else gui->backToHelpText.endHighlight();

            if (chosenHowToText == 3)
            {
                if (gui->helpHutriesHall.checkBounds())
                    gui->helpHutriesHallText.highlight();
                else gui->helpHutriesHallText.endHighlight();

                if (gui->helpBarracks.checkBounds())
                    gui->helpBarracksText.highlight();
                else gui->helpBarracksText.endHighlight();

                if (gui->helpResidence.checkBounds())
                    gui->helpResidenceText.highlight();
                else gui->helpResidenceText.endHighlight();

                if (gui->helpSawmill.checkBounds())
                    gui->helpSawmillText.highlight();
                else gui->helpSawmillText.endHighlight();

                if (gui->helpStonecutter.checkBounds())
                    gui->helpStonecutterText.highlight();
                else gui->helpStonecutterText.endHighlight();

                if (gui->helpFarm.checkBounds())
                    gui->helpFarmText.highlight();
                else gui->helpFarmText.endHighlight();

                 if (gui->helpGoldmine.checkBounds())
                    gui->helpGoldmineText.highlight();
                else gui->helpGoldmineText.endHighlight();

            }
        }

        if (gui->playButton.checkBounds())
            gui->playText.highlight();
        else gui->playText.endHighlight();

        if (gui->howToPlayButton.checkBounds())
            gui->howToPlayText.highlight();
        else gui->howToPlayText.endHighlight();

        if (gui->aboutButton.checkBounds())
            gui->aboutText.highlight();
        else gui->aboutText.endHighlight();

        if (gui->exitButton.checkBounds())
            gui->exitText.highlight();
        else gui->exitText.endHighlight();

        if (gui->easyButton.checkBounds())
            gui->easyText.highlight();
        else
        {
            gui->easyText.endHighlight();
            gui->easyButton.changeTexture(Textures::carrierEmptyMoveRight1);
        }

        if (gui->normalButton.checkBounds())
            gui->normalText.highlight();
        else
        {
            gui->normalText.endHighlight();
            gui->normalButton.changeTexture(Textures::workerMoveRight1);
        }

        if (gui->hardButton.checkBounds())
            gui->hardText.highlight();
        else
        {
            gui->hardText.endHighlight();
            gui->hardButton.changeTexture(Textures::warriorMoveRight1);
        }

        changeDifficultyButtonSprite();
    }

    if (modelController->getExitWindow())
    {
        if (gui->exitNoButton.checkBounds())
            gui->exitNoText.highlight();
        else gui->exitNoText.endHighlight();

        if (gui->exitYesButton.checkBounds())
            gui->exitYesText.highlight();
        else gui->exitYesText.endHighlight();
    }

    if (modelController->getPauseGame())
    {
        if (gui->resumeButton.checkBounds())
            gui->resumeText.highlight();
        else gui->resumeText.endHighlight();

        if (gui->settingsButton.checkBounds())
            gui->settingsText.highlight();
        else gui->settingsText.endHighlight();

        if (gui->helpButton.checkBounds())
            gui->helpText.highlight();
        else gui->helpText.endHighlight();

        if (gui->mainMenuButton.checkBounds())
            gui->mainMenuText.highlight();
        else gui->mainMenuText.endHighlight();
    }
}

//////////////////////////////////  DIFFICULTY  /////////////////////////////////////////////////

void GUIController::setHard()
{
    GameBalance::gameTime = 5 * 60;
    GameBalance::startingFood = 10;
    GameBalance::startingWood = 10;
    GameBalance::startingStone = 10;
    GameBalance::startingGold = 0;
}

void GUIController::setNormal()
{
    GameBalance::gameTime = 10 * 60;
    GameBalance::startingFood = 15;
    GameBalance::startingWood = 15;
    GameBalance::startingStone = 15;
    GameBalance::startingGold = 15;
}

void GUIController::setEasy()
{
    GameBalance::gameTime = 15 * 60;
    GameBalance::startingFood = 20;
    GameBalance::startingWood = 20;
    GameBalance::startingStone = 20;
    GameBalance::startingGold = 20;
}

void GUIController::setDifficulty(std::string difficult)
{
    if (difficult == "EASY")
    {
        setEasy();
    }
    else if (difficult == "NORMAL")
    {
        setNormal();
    }
    else if (difficult == "HARD")
    {
        setHard();
    }
    world->setStartingGoods();
    updateGoodsNumber();
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
            "Error: \nNo available carriers!\nCreate carrier in HutriesHall");
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
            "Error: \nNo available workers! \nCreate worker in HutriesHall");
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

void GUIController::errorOverflowHutriesHallQueue()
{
    Sound::error();
    errorsVisiblityClock.restart();
    gui->errorInfo.text.setString("Error: \n        Too much Hutries \n        during training!");
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

void GUIController::errorTooMuchGoods()
{
    Sound::error();
    errorsVisiblityClock.restart();
    gui->errorInfo.text.setString("Error: \n        Too much goods!");
}

void GUIController::changeDifficultyButtonSprite()
{
    if (frameCounter == 0)
    {
        if (gui->easyButton.checkBounds())
        {
            switch (animationCounter)
            {
                case 0:
                    gui->easyButton.changeTexture(Textures::carrierEmptyMoveRight1);
                    animationCounter++;
                    break;
                case 1:
                    gui->easyButton.changeTexture(Textures::carrierEmptyMoveRight2);
                    animationCounter++;
                    break;
                case 2:
                    gui->easyButton.changeTexture(Textures::carrierEmptyMoveRight3);
                    animationCounter++;
                    break;
                case 3:
                    gui->easyButton.changeTexture(Textures::carrierEmptyMoveRight4);
                    animationCounter++;
                    break;
                case 4:
                    gui->easyButton.changeTexture(Textures::carrierEmptyMoveRight5);
                    animationCounter++;
                    break;
                case 5:
                    gui->easyButton.changeTexture(Textures::carrierEmptyMoveRight6);
                    animationCounter++;
                    break;
                case 6:
                    gui->easyButton.changeTexture(Textures::carrierEmptyMoveRight7);
                    animationCounter++;
                    break;
                case 7:
                    gui->easyButton.changeTexture(Textures::carrierEmptyMoveRight8);
                    animationCounter = 0;
                    break;
                default:
                    break;
            }
        }

        else if (gui->normalButton.checkBounds())
        {
            switch (animationCounter)
            {
                case 0:
                    gui->normalButton.changeTexture(Textures::workerMoveRight1);
                    animationCounter++;
                    break;
                case 1:
                    gui->normalButton.changeTexture(Textures::workerMoveRight2);
                    animationCounter++;
                    break;
                case 2:
                    gui->normalButton.changeTexture(Textures::workerMoveRight3);
                    animationCounter++;
                    break;
                case 3:
                    gui->normalButton.changeTexture(Textures::workerMoveRight4);
                    animationCounter++;
                    break;
                case 4:
                    gui->normalButton.changeTexture(Textures::workerMoveRight5);
                    animationCounter++;
                    break;
                case 5:
                    gui->normalButton.changeTexture(Textures::workerMoveRight6);
                    animationCounter++;
                    break;
                case 6:
                    gui->normalButton.changeTexture(Textures::workerMoveRight7);
                    animationCounter++;
                    break;
                case 7:
                    gui->normalButton.changeTexture(Textures::workerMoveRight8);
                    animationCounter = 0;
                    break;
                default:
                    break;
            }
        }

        else if (gui->hardButton.checkBounds())
        {
            switch (animationCounter)
            {
                case 0:
                    gui->hardButton.changeTexture(Textures::warriorMoveRight1);
                    animationCounter++;
                    break;
                case 1:
                    gui->hardButton.changeTexture(Textures::warriorMoveRight2);
                    animationCounter++;
                    break;
                case 2:
                    gui->hardButton.changeTexture(Textures::warriorMoveRight3);
                    animationCounter++;
                    break;
                case 3:
                    gui->hardButton.changeTexture(Textures::warriorMoveRight4);
                    animationCounter++;
                    break;
                case 4:
                    gui->hardButton.changeTexture(Textures::warriorMoveRight5);
                    animationCounter++;
                    break;
                case 5:
                    gui->hardButton.changeTexture(Textures::warriorMoveRight6);
                    animationCounter++;
                    break;
                case 6:
                    gui->hardButton.changeTexture(Textures::warriorMoveRight7);
                    animationCounter++;
                    break;
                case 7:
                    gui->hardButton.changeTexture(Textures::warriorMoveRight8);
                    animationCounter++;
                    break;
                case 8:
                    gui->hardButton.changeTexture(Textures::warriorMoveRight9);
                    animationCounter++;
                    break;
                case 9:
                    gui->hardButton.changeTexture(Textures::warriorMoveRight10);
                    animationCounter++;
                    break;
                case 10:
                    gui->hardButton.changeTexture(Textures::warriorMoveRight11);
                    animationCounter = 0;
                    break;
                default:
                    break;
            }
        }

        else animationCounter = 0;
    }
    frameCounter++;
    if(frameCounter > 3)
        frameCounter = 0;
}
