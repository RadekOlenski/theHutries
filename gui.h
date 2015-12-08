#ifndef GUI_H
#define GUI_H

#include <SFML/Graphics.hpp>

#include "guibutton.h"
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

    private:

        //////////////////////////// GENERAL //////////////////////////////////////////////////////

        sf::RenderWindow *hutrieApplication;
        int width;
        int height;

        ////////////////////////////// GRAPHICS ///////////////////////////////////////////////////

        sf::RectangleShape guiFrame;
        sf::Texture texture;
        GUIText barText;

        /////////////////////////////// DOWN BAR //////////////////////////////////////////////////

        GUIButton guiBar;
        GUIButton wood;
        GUIButton stone;
        GUIButton gold;
        GUIButton food;
};

#endif // GUI_H
