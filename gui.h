#ifndef GUI_H
#define GUI_H

#include "guibutton.h"

#include <SFML/Graphics.hpp>
#include "guitext.h"

class GUI
{
public:

    ///////////////////////////////GUI PROPERTIES ///////////////////////////////////////////

    GUI(int mapWidth,int mapHeight, sf::RenderWindow *hutrieApplication, int width = 256);
    //int getHeight() {return height;}
    //int getWidth()  {return width;}

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
    GUIText  tSawmill;
    GUIButton barracks;
    GUIText  tBarracks;
    GUIButton residence;
    GUIText  tResidence;
    GUIButton stonecutter;
    GUIText  tStonecutter;
    GUIButton goldmine;
    GUIText tGoldmine;
    GUIButton farm;
    GUIText tFarm;

    /////////////////////////////// HUTRIES SECTION //////////////////////////////////////////

    GUIButton allHutries;
    GUIButton allCarriers;
    GUIButton allWorkers;
    GUIButton allSoldiers;
    GUIText tHutries;
    GUIText tCarriers;
    GUIText tWorkers;
    GUIText tSoldiers;

    //////////////////////////////// DRAWING FUNCTIONS /////////////////////////////////////////

    void displayGUI();
    void displayGUIBuildings();
    void displayGUIHutries(int hutrieSize, int carrierSize, int workerSize, int soldierSize);

    /////////////////////////////////////ENDING ////////////////////////////////////////////////

    void displayEndingText(bool win);


private:

    //////////////////////////// GENERAL //////////////////////////////////////////////////////

    sf::RenderWindow *hutrieApplication;
    int width;
    int height;

    ////////////////////////////// GRAPHICS ///////////////////////////////////////////////////

    sf::RectangleShape guiFrame;
    sf::Texture texture;

    /////////////////////////////// DOWN BAR //////////////////////////////////////////////////

    GUIButton guiBar;
    GUIButton wood;
    GUIButton stone;
    GUIButton gold;
    GUIButton food;
};

#endif // GUI_H
