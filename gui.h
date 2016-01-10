#ifndef GUI_H
#define GUI_H

#include "guibutton.h"

#include <SFML/Graphics.hpp>
#include "guitext.h"

class GUI
{
public:

    ///////////////////////////////GUI PROPERTIES /////////////////////////////////////////////

    GUI(int mapWidth,int mapHeight, sf::RenderWindow *hutrieApplication, int width = 256);
    //int getHeight() {return height;}
    //int getWidth()  {return width;}


    /////////////////////////////// MENU    ///////////////////////////////////////////////////

    GUIText startingText;
    GUIButton playButton;
    GUIText playText;
    GUIButton howToPlayButton;
    GUIText howToPlayText;
    GUIButton aboutButton;
    GUIText aboutText;
    GUIButton exitButton;
    GUIText exitText;

    ////////////////////////////// BASIC TOOLS ////////////////////////////////////////////////

    GUIButton buildButton;
    GUIButton hutrieButton;
    GUIText errorInfo;
    GUIText messageBox;
    GUIText timeLeft;
    GUIText tgold;
    GUIText twood;
    GUIText tstone;
    GUIText tfood;

    /////////////////////////////// BUILDINGS SECTION //////////////////////////////////////////

    GUIButton sawmill;
    GUIText   tSawmill;
    GUIButton woodSawmill;
    GUIText   twoodSawmill;
    GUIButton stoneSawmill;
    GUIText   tstoneSawmill;
    GUIButton barracks;
    GUIText   tBarracks;
    GUIButton woodBarracks;
    GUIText   twoodBarracks;
    GUIButton stoneBarracks;
    GUIText   tstoneBarracks;
    GUIButton residence;
    GUIText   tResidence;
    GUIButton woodResidence;
    GUIText   twoodResidence;
    GUIButton stoneResidence;
    GUIText   tstoneResidence;
    GUIButton stonecutter;
    GUIText   tStonecutter;
    GUIButton woodStonecutter;
    GUIText   twoodStonecutter;
    GUIButton stoneStonecutter;
    GUIText   tstoneStonecutter;
    GUIButton goldmine;
    GUIText   tGoldmine;
    GUIButton woodGoldmine;
    GUIText   twoodGoldmine;
    GUIButton stoneGoldmine;
    GUIText   tstoneGoldmine;
    GUIButton farm;
    GUIText   tFarm;
    GUIButton woodFarm;
    GUIText   twoodFarm;
    GUIButton stoneFarm;
    GUIText   tstoneFarm;

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

    void displayGUI();
    void displayGUIBuildings();
    void displayMenu();
    void displayGUIHutries(int hutrieSize, int carrierSize, int workerSize, int warriorSize, int archerSize);

    /////////////////////////////////////ENDING ////////////////////////////////////////////////

    void displayEndingText(bool win);

private:

    //////////////////////////// GENERAL //////////////////////////////////////////////////////

    sf::RenderWindow *hutrieApplication;
    int width;
    int height;


    ////////////////////////////// GRAPHICS ///////////////////////////////////////////////////

    sf::RectangleShape guiFrame;
    sf::RectangleShape errorFrame;
    sf::Texture texture;
    void setBuildingsCosts();

    /////////////////////////////// DOWN BAR //////////////////////////////////////////////////

    GUIButton guiBar;
    GUIButton wood;
    GUIButton stone;
    GUIButton gold;
    GUIButton food;
};

#endif // GUI_H
