#ifndef GUI_H
#define GUI_H

#include "guibutton.h"

#include <SFML/Graphics.hpp>
#include "guitext.h"

class GUI
{
public:

    GUI(int mapWidth, int mapHeight, sf::RenderWindow* hutrieApplication, int width = 256);

    /////////////////////////////// MENU    ///////////////////////////////////////////////////

    GUIText startingText;
    GUIText skipText;
    GUIButton playButton;
    GUIText playText;
    GUIButton howToPlayButton;
    GUIText howToPlayText;
    GUIButton aboutButton;
    GUIText aboutText;
    GUIButton exitButton;
    GUIText exitText;
    GUIButton nextArrowButton;
    GUIButton backArrowButton;

    GUIText endingBuildingsStats;
    GUIText endingHutriesStats;
    GUIText endingProductionStats;

    GUIButton easyButton;
    GUIButton normalButton;
    GUIButton hardButton;

    GUIText easyText;
    GUIText normalText;
    GUIText hardText;

    //////////////////////////////////////HOW TO PLAY////////////////////////////////////////////

    GUIText helpTitleText;

    GUIButton mechanicsButton;
    GUIButton buildingsButton;
    GUIButton hutriesTypesButton;
    GUIButton resourcesButton;
    GUIText mechanicsText;
    GUIText buildingsText;
    GUIText hutriesTypesText;
    GUIText resourcesText;

    GUIButton helpSawmill;
    GUIButton helpStonecutter;
    GUIButton helpFarm;
    GUIButton helpGoldmine;
    GUIButton helpBarracks;
    GUIButton helpResidence;
    GUIButton helpHutriesHall;
    GUIText helpHutriesHallText;
    GUIText helpBarracksText;
    GUIText helpResidenceText;
    GUIText helpSawmillText;
    GUIText helpStonecutterText;
    GUIText helpFarmText;
    GUIText helpGoldmineText;

    GUIButton helpBuildingDescription;
    GUIButton helpHutriesHallDescription;

    GUIButton helpGold;
    GUIButton helpWood;
    GUIButton helpStone;
    GUIButton helpFood;
    sf::RectangleShape verticalLine;
    sf::RectangleShape verticalLine2;
    sf::RectangleShape horizontalLine;
    sf::RectangleShape horizontalLine2;
    sf::RectangleShape horizontalLine3;

    /////////////////////////////// PAUSE MENU ///////////////////////////////////////////////////

    GUIText resumeText;
    GUIButton resumeButton;
    GUIText musicText;
    GUIButton musicButton;
    GUIText sfxText;
    GUIButton sfxButton;
    GUIText mainMenuText;
    GUIButton mainMenuButton;
    GUIButton backToHelpButton;
    GUIText backToHelpText;

    /////////////////////////////// EXIT WINDOW ///////////////////////////////////////////////////

    GUIText exitQuestion;
    GUIText exitYesText;
    GUIButton exitYesButton;
    GUIText exitNoText;
    GUIButton exitNoButton;

    ////////////////////////////// BASIC TOOLS ////////////////////////////////////////////////

    GUIButton buildButton;
    GUIButton hutrieButton;
    GUIText errorInfo;
    GUIText timeLeft;
    GUIText tgold;
    GUIText twood;
    GUIText tstone;
    GUIText tfood;

    /////////////////////////////// BUILDINGS SECTION //////////////////////////////////////////

    GUIButton sawmill;
    GUIText tSawmill;
    GUIButton woodSawmill;
    GUIText twoodSawmill;
    GUIButton stoneSawmill;
    GUIText tstoneSawmill;
    GUIButton barracks;
    GUIText tBarracks;
    GUIButton woodBarracks;
    GUIText twoodBarracks;
    GUIButton stoneBarracks;
    GUIText tstoneBarracks;
    GUIButton residence;
    GUIText tResidence;
    GUIButton woodResidence;
    GUIText twoodResidence;
    GUIButton stoneResidence;
    GUIText tstoneResidence;
    GUIButton stonecutter;
    GUIText tStonecutter;
    GUIButton woodStonecutter;
    GUIText twoodStonecutter;
    GUIButton stoneStonecutter;
    GUIText tstoneStonecutter;
    GUIButton goldmine;
    GUIText tGoldmine;
    GUIButton woodGoldmine;
    GUIText twoodGoldmine;
    GUIButton stoneGoldmine;
    GUIText tstoneGoldmine;
    GUIButton farm;
    GUIText tFarm;
    GUIButton woodFarm;
    GUIText twoodFarm;
    GUIButton stoneFarm;
    GUIText tstoneFarm;

    /////////////////////////////// HUTRIES SECTION //////////////////////////////////////////

    GUIButton allHutries;
    GUIButton allCarriers;
    GUIButton allWorkers;
    GUIButton allWarriors;
    GUIButton allArchers;
    GUIText tHutries;
    GUIText tCarriers;
    GUIText tWorkers;
    GUIText tWarriors;
    GUIText tArchers;

    //////////////////////////////// DRAWING FUNCTIONS /////////////////////////////////////////

    void displayMainGUI();

    void displayBuildingsGUI();

    void displayHutriesGUI(int hutrieSize, int carrierSize, int workerSize, int warriorSize, int archerSize);

    void displayMenu();

    void displayPauseMenu();

    void displayExitWindow();

    /////////////////////////////////////ENDING ////////////////////////////////////////////////

    void displayEndingText();

    void setEndingMessageString(std::string text);

    GUIText endingMessage;

    sf::RectangleShape capturedScreen;

private:
    //////////////////////////// GENERAL //////////////////////////////////////////////////////

    sf::RenderWindow* hutrieApplication;

    ////////////////////////////// GRAPHICS ///////////////////////////////////////////////////
    sf::RectangleShape exitFrame;
    sf::RectangleShape guiFrame;
    sf::RectangleShape pauseFrame;
    sf::RectangleShape errorFrame;
    sf::Texture texture;
    sf::RectangleShape screenBlackout;
    sf::Color blackoutColor;

    /////////////////////////////// DOWN BAR //////////////////////////////////////////////////

    GUIButton guiBar;
    GUIButton wood;
    GUIButton stone;
    GUIButton gold;
    GUIButton food;
};

#endif // GUI_H
