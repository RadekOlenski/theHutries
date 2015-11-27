#include "gui.h"

GUI::GUI(int mapWidth,int mapHeight, int width) :  guiFrame(sf::Vector2f(width,mapHeight))
{
    this->width = width;
    height = mapHeight;
    //this->hutrieApplication = hutrieApplication;
    guiFrame.setPosition( mapWidth , 0);
    //guiFrame.setOrigin( -mapWidth , 0);
    //guiFrame.setFillColor(sf::Color::White);
    //guiFrame.setOutlineThickness(1);
    //guiFrame.setOutlineColor(sf::Color::Blue);
    texture.loadFromFile("sprites/background/pergamino.jpg");
    guiFrame.setTexture(&texture);
}
