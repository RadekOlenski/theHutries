#ifndef GUI_H
#define GUI_H

#include <SFML/Graphics.hpp>

class GUI
{
    public:
        GUI(int mapWidth,int mapHeight, int width = 256);//sf::RenderWindow *hutrieApplication);
        int getHeight() {return height;}
        int getWidth() {return width;}
        sf::Texture texture;
        //sf::RenderWindow *hutrieApplication;
        sf::RectangleShape guiFrame;

    private:
        int width;
        int height;
};

#endif // GUI_H
