#include <sstream>
#include "gui.h"
#include "gamebalance.h"
#include "textures.h"

GUI::GUI(int mapWidth, int mapHeight, sf::RenderWindow* hutrieApplication, int width) :

    //------------------------MENU----------------------------------------//

        startingText(160, 320, 40, ""),
        skipText(830, 10, 25, ""),
        playButton(1024 + 60, 200, hutrieApplication, 130, 80, false),
        playText  (1024 + 80, 210, 50, "Play"),
        howToPlayButton(1024 + 60, 350, hutrieApplication, 130, 80, false),
        howToPlayText  (1024 + 80, 360, 50, "Help"),
        aboutButton(1024 + 45, 500, hutrieApplication, 170, 80, false),
        aboutText(1024 + 70, 510, 50, "About"),
        exitButton(mapWidth, mapHeight, hutrieApplication, width, 128, false),
        exitText(1024 + 90, mapHeight + 30, 50, "Exit"),
        nextArrowButton(950, 650, hutrieApplication, Textures::arrow),
        backArrowButton(50 , 650, hutrieApplication, Textures::backArrow),

    //-------------------DIFFICULTY LEVEL-----------------------------//

        easyButton(150, 350, hutrieApplication, Textures::carrierMoveRight1),
        normalButton(400, 350, hutrieApplication, Textures::workerRight),
        hardButton(650, 350, hutrieApplication, Textures::warriorRight),
        easyText (185, 320, 37, ""),
        normalText (435, 320,37, ""),
        hardText (685, 320, 37, ""),

    //-------------------ENDING STATS-----------------------------//

        endingBuildingsStats(150, 280, 36, GameBalance::loseString),
        endingHutriesStats(450, 270, 36, GameBalance::loseString),
        endingProductionStats(750, 280, 36, GameBalance::loseString),
        endingMessage(300, 100, 90, "You Lose!!!"),

    //------------------ EXIT WINDOW ---------------------------------//

        exitFrame(sf::Vector2f(700, 350)),
        exitQuestion(330, 230, 50, "Are you sure you want to quit?"),
        exitYesButton(420, 445, hutrieApplication, 100, 55, false),
        exitYesText(430, 440, 50, "Yes"),
        exitNoButton(743, 445, hutrieApplication, 70, 55, false),
        exitNoText(750, 440, 50, "No"),

        //------------------ PAUSE MENU ---------------------------------//

        pauseFrame(sf::Vector2f(350, 500)),
        resumeText(550, 200, 50, "Resume"),
        resumeButton(545, 205, hutrieApplication, 155, 55, false),
        settingsText(550, 290, 50, "Settings"),
        settingsButton(545, 295, hutrieApplication, 158, 55, false),
        helpText(580, 380, 50, "Help"),
        helpButton(575, 385, hutrieApplication, 100, 55, false),
        mainMenuText(510, 470, 50, "Main Menu"),
        mainMenuButton(505, 478, hutrieApplication, 240, 55, false),
        screenBlackout(sf::Vector2f(1366, 768)),
        capturedScreen(sf::Vector2f(1366, 768)),
        blackoutColor(0, 0, 0, 180),

        //---------------------BASIC GAME GUI-----------------------------------//

        guiFrame(sf::Vector2f(width, mapHeight)),
        errorFrame(sf::Vector2f(width, 128)),
        errorInfo(mapWidth + 20, mapHeight + 10, 20, "Message Box:"),

        buildButton(mapWidth + 60, 100, hutrieApplication, Textures::buildButton),
        hutrieButton(mapWidth + 140, 100, hutrieApplication, Textures::hutrieButton),

    //-------------------------GOODS BAR----------------------------------------------//

        guiBar(0, mapHeight + 98 , hutrieApplication, Textures::guiBar, mapWidth, 30),
        timeLeft(20, mapHeight + 2 + 98, 20, "15:00", sf::Color::White),
        gold(208, mapHeight + 98, hutrieApplication, Textures::gold, 30, 30),
        wood(208 + 192, mapHeight + 98, hutrieApplication, Textures::wood, 30, 30),
        stone(208 + 384, mapHeight + 98, hutrieApplication, Textures::stone, 30, 30),
        food(208 + 576, mapHeight + 98, hutrieApplication, Textures::food, 30, 30),
        tgold(280, mapHeight + 2 + 98, 20, "0", sf::Color::White),
        twood(280 + 192, mapHeight + 2 + 98, 20, "0", sf::Color::White),
        tstone(280 + 384, mapHeight + 2 + 98, 20, "0", sf::Color::White),
        tfood(280 + 576, mapHeight + 2 + 98, 20, "0", sf::Color::White),

    //----------------------BUILDING MODE LIST----------------------------------------//

        sawmill(mapWidth + 30, 170, hutrieApplication, Textures::sawmillBasic, 90, 90),
        tSawmill(mapWidth + 40, 260, 20, "Sawmill"),
        woodSawmill(mapWidth + 35, 290, hutrieApplication, Textures::wood, 25, 25),
        twoodSawmill(mapWidth + 60, 290, 20, "3"),
        stoneSawmill(mapWidth + 80, 290, hutrieApplication, Textures::stone, 25, 25),
        tstoneSawmill(mapWidth + 105, 290, 20, "3"),

        stonecutter(mapWidth + 30 + 120, 170, hutrieApplication, Textures::stonecutterHutBasic, 90, 90),
        tStonecutter(mapWidth + 155, 260, 20, "Stonecutter"),
        woodStonecutter(mapWidth + 35 + 120, 290, hutrieApplication, Textures::wood, 25, 25),
        twoodStonecutter(mapWidth + 60 + 120, 290, 20, "3"),
        stoneStonecutter(mapWidth + 80 + 120, 290, hutrieApplication, Textures::stone, 25, 25),
        tstoneStonecutter(mapWidth + 105 + 120, 290, 20, "3"),

        farm(mapWidth + 30, 330, hutrieApplication, Textures::farmGUI, 90, 90),
        tFarm(mapWidth + 40, 420, 20, "Farm"),
        woodFarm(mapWidth + 35, 290 + 160, hutrieApplication, Textures::wood, 25, 25),
        twoodFarm(mapWidth + 60, 290 + 160, 20, "3"),
        stoneFarm(mapWidth + 80, 290 + 160, hutrieApplication, Textures::stone, 25, 25),
        tstoneFarm(mapWidth + 105, 290 + 160, 20, "3"),

        goldmine(mapWidth + 150, 330, hutrieApplication, Textures::goldmineGUI, 90, 90),
        tGoldmine(mapWidth + 155, 420, 20, "Goldmine"),
        woodGoldmine(mapWidth + 35 + 120, 290 + 160, hutrieApplication, Textures::wood, 25, 25),
        twoodGoldmine(mapWidth + 60 + 120, 290 + 160, 20, "3"),
        stoneGoldmine(mapWidth + 80 + 120, 290 + 160, hutrieApplication, Textures::stone, 25, 25),
        tstoneGoldmine(mapWidth + 105 + 120, 290 + 160, 20, "3"),

        barracks(mapWidth + 30, 480, hutrieApplication, Textures::barracksBasic, 90, 90),
        tBarracks(mapWidth + 40, 565, 20, "Barracks"),
        woodBarracks(mapWidth + 35, 290 + 305, hutrieApplication, Textures::wood, 25, 25),
        twoodBarracks(mapWidth + 60, 290 + 305, 20, "3"),
        stoneBarracks(mapWidth + 80, 290 + 305, hutrieApplication, Textures::stone, 25, 25),
        tstoneBarracks(mapWidth + 105, 290 + 305, 20, "3"),

        residence(mapWidth + 150, 480, hutrieApplication, Textures::residenceBasic, 90, 90),
        tResidence(mapWidth + 160, 565, 20, "Residence"),
        woodResidence(mapWidth + 35 + 120, 290 + 305, hutrieApplication, Textures::wood, 25, 25),
        twoodResidence(mapWidth + 60 + 120, 290 + 305, 20, "3"),
        stoneResidence(mapWidth + 80 + 120, 290 + 305, hutrieApplication, Textures::stone, 25, 25),
        tstoneResidence(mapWidth + 105 + 120, 290 + 305, 20, "3"),

    //------------------------------HUTRIE INFO ------------------------------------------//

        allHutries(mapWidth + 30, 170, hutrieApplication, Textures::allHutries, 96, 96),
        tHutries(mapWidth + 150, 200, 30, "26"),
        allCarriers(mapWidth + 30, 260, hutrieApplication, Textures::carrierRight, 96, 96),
        tCarriers(mapWidth + 150, 290, 30, "12"),
        allWorkers(mapWidth + 30, 350, hutrieApplication, Textures::workerRight, 96, 96),
        tWorkers(mapWidth + 150, 380, 30, "5"),
        allWarriors(mapWidth + 30, 440, hutrieApplication, Textures::warriorRight, 96, 96),
        tWarriors(mapWidth + 150, 470, 30, "2"),
        allArchers(mapWidth + 30, 530, hutrieApplication, Textures::archerRight, 96, 96),
        tArchers(mapWidth + 150, 560, 30, "2")
{

    this->hutrieApplication = hutrieApplication;

    guiFrame.setPosition(mapWidth, 0);
    pauseFrame.setPosition(450, 134);
    texture.loadFromFile(Textures::guiTexture);
    guiFrame.setTexture(&texture);
    pauseFrame.setTexture(&texture);
    exitFrame.setPosition(280, 210);
    exitFrame.setTexture(&texture);

    capturedScreen.setPosition(0, 0);
    screenBlackout.setPosition(0, 0);
    screenBlackout.setFillColor(blackoutColor);

    errorFrame.setPosition(mapWidth, mapHeight);
    texture.loadFromFile(Textures::guiTexture);
    errorFrame.setTexture(&texture);

    buildButton.setActive(true);
    hutrieButton.setActive(true);

    easyButton.button.setSize(sf::Vector2f(200,200));
    normalButton.button.setSize(sf::Vector2f(200,200));
    hardButton.button.setSize(sf::Vector2f(200,200));
}

void GUI::displayMainGUI()
{
    hutrieApplication->draw(guiFrame);
    hutrieApplication->draw(errorFrame);
    hutrieApplication->draw(buildButton.button);
    hutrieApplication->draw(hutrieButton.button);

    hutrieApplication->draw(guiBar.button);
    hutrieApplication->draw(wood.button);
    hutrieApplication->draw(gold.button);
    hutrieApplication->draw(stone.button);
    hutrieApplication->draw(food.button);
    hutrieApplication->draw(tgold.text);
    hutrieApplication->draw(twood.text);
    hutrieApplication->draw(tfood.text);
    hutrieApplication->draw(tstone.text);
    hutrieApplication->draw(errorInfo.text);

}

void GUI::displayBuildingsGUI()
{
    hutrieApplication->draw(sawmill.button);
    hutrieApplication->draw(tSawmill.text);
    hutrieApplication->draw(woodSawmill.button);
    hutrieApplication->draw(twoodSawmill.text);
    hutrieApplication->draw(stoneSawmill.button);
    hutrieApplication->draw(tstoneSawmill.text);
    hutrieApplication->draw(barracks.button);
    hutrieApplication->draw(tBarracks.text);
    hutrieApplication->draw(woodBarracks.button);
    hutrieApplication->draw(twoodBarracks.text);
    hutrieApplication->draw(stoneBarracks.button);
    hutrieApplication->draw(tstoneBarracks.text);
    hutrieApplication->draw(stonecutter.button);
    hutrieApplication->draw(tStonecutter.text);
    hutrieApplication->draw(woodStonecutter.button);
    hutrieApplication->draw(twoodStonecutter.text);
    hutrieApplication->draw(stoneStonecutter.button);
    hutrieApplication->draw(tstoneStonecutter.text);
    hutrieApplication->draw(residence.button);
    hutrieApplication->draw(tResidence.text);
    hutrieApplication->draw(woodResidence.button);
    hutrieApplication->draw(twoodResidence.text);
    hutrieApplication->draw(stoneResidence.button);
    hutrieApplication->draw(tstoneResidence.text);
    hutrieApplication->draw(goldmine.button);
    hutrieApplication->draw(tGoldmine.text);
    hutrieApplication->draw(woodGoldmine.button);
    hutrieApplication->draw(twoodGoldmine.text);
    hutrieApplication->draw(stoneGoldmine.button);
    hutrieApplication->draw(tstoneGoldmine.text);
    hutrieApplication->draw(farm.button);
    hutrieApplication->draw(tFarm.text);
    hutrieApplication->draw(woodFarm.button);
    hutrieApplication->draw(twoodFarm.text);
    hutrieApplication->draw(stoneFarm.button);
    hutrieApplication->draw(tstoneFarm.text);

}

void GUI::displayHutriesGUI(int hutrieSize, int carrierSize, int workerSize, int warriorSize, int archerSize)
{
    std::ostringstream desc;
    desc << hutrieSize;
    tHutries.text.setString(desc.str());
    std::ostringstream desc1;
    desc1 << carrierSize;
    tCarriers.text.setString(desc1.str());
    std::ostringstream desc2;
    desc2 << workerSize;
    tWorkers.text.setString(desc2.str());
    std::ostringstream desc3;
    desc3 << warriorSize;
    tWarriors.text.setString(desc3.str());
    std::ostringstream desc4;
    desc4 << archerSize;
    tArchers.text.setString(desc4.str());


    hutrieApplication->draw(allHutries.button);
    hutrieApplication->draw(allCarriers.button);
    hutrieApplication->draw(allWorkers.button);
    hutrieApplication->draw(allWarriors.button);
    hutrieApplication->draw(allArchers.button);
    hutrieApplication->draw(tHutries.text);
    hutrieApplication->draw(tWorkers.text);
    hutrieApplication->draw(tCarriers.text);
    hutrieApplication->draw(tWarriors.text);
    hutrieApplication->draw(tArchers.text);

}

void GUI::setEndingMessageString(std::string text)
{
    endingMessage.text.setString(text);
}

void GUI::displayEndingText()
{
        hutrieApplication->draw(endingMessage.text);
}

void GUI::displayMenu()
{
    hutrieApplication->draw(guiFrame);
    hutrieApplication->draw(errorFrame);
    hutrieApplication->draw(guiBar.button);

    hutrieApplication->draw(startingText.text);
    hutrieApplication->draw(skipText.text);
    hutrieApplication->draw(playButton.button);
    hutrieApplication->draw(playText.text);
    hutrieApplication->draw(howToPlayButton.button);
    hutrieApplication->draw(howToPlayText.text);
    hutrieApplication->draw(aboutButton.button);
    hutrieApplication->draw(aboutText.text);
    hutrieApplication->draw(exitButton.button);
    hutrieApplication->draw(exitText.text);
    hutrieApplication->draw(easyText.text);
    hutrieApplication->draw(normalText.text);
    hutrieApplication->draw(hardText.text);
    if (backArrowButton.isActive()) hutrieApplication->draw(backArrowButton.button);
    if (nextArrowButton.isActive())hutrieApplication->draw(nextArrowButton.button);
    if (easyButton.isActive())hutrieApplication->draw(easyButton.button);
    if (normalButton.isActive())hutrieApplication->draw(normalButton.button);
    if (hardButton.isActive())hutrieApplication->draw(hardButton.button);
}

void GUI::displayPauseMenu()
{
    hutrieApplication->draw(screenBlackout);
    hutrieApplication->draw(pauseFrame);
    hutrieApplication->draw(resumeText.text);
    hutrieApplication->draw(resumeButton.button);
    hutrieApplication->draw(settingsText.text);
    hutrieApplication->draw(settingsButton.button);
    hutrieApplication->draw(helpText.text);
    hutrieApplication->draw(helpButton.button);
    hutrieApplication->draw(mainMenuText.text);
    hutrieApplication->draw(mainMenuButton.button);
}

void GUI::displayExitWindow()
{
    hutrieApplication->draw(screenBlackout);
    hutrieApplication->draw(exitFrame);
    hutrieApplication->draw(exitQuestion.text);
    hutrieApplication->draw(exitYesButton.button);
    hutrieApplication->draw(exitYesText.text);
    hutrieApplication->draw(exitNoButton.button);
    hutrieApplication->draw(exitNoText.text);
}
