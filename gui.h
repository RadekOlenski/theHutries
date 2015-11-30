#ifndef GUI_H
#define GUI_H

#include <SFML/Graphics.hpp>
#include "guibutton.h"
#include "guitext.h"

class GUI
{
    public:
        GUI(int mapWidth,int mapHeight, sf::RenderWindow *hutrieApplication, int width = 256);
        int getHeight() {return height;}
        int getWidth() {return width;}
        sf::Texture texture;
        sf::RenderWindow *hutrieApplication;
        sf::RectangleShape guiFrame;
        GUIText barText;
        GUIButton guiBar;
        GUIButton buildButton;
        GUIButton hutrieButton;
        GUIButton wood;
        GUIButton stone;
        GUIButton gold;
        GUIButton food;
        GUIButton sawmill;
        GUIButton barracks;
        GUIButton residence;
        GUIButton stonecutter;

        void displayGUI();
        void displayGUIBuildings();

    private:
        int width;
        int height;
};

#endif // GUI_H
