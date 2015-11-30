#ifndef GUIBUTTON_H
#define GUIBUTTON_H

#include <SFML/Graphics.hpp>
#include <string>

class GUIButton
{
    public:
        GUIButton();
        GUIButton(int positionX, int positionY,sf::RenderWindow *hutrieApplication, std::string pathname, int sizeX = 50, int sizeY = 50, bool rect = false, int rectX = 0, int rectY = 0, int rectSizeX = 1000, int rectSizeY = 50 );
        GUIButton(int positionX, int positionY,sf::RenderWindow *hutrieApplication, int sizeX = 50, int sizeY = 50);
        sf::RectangleShape button;
        //void create(int positionX, int positionY, sf::RenderWindow *hutrieApplication, std::string pathname);
        bool checkBounds();
    private:
        sf::RenderWindow *hutrieApplication;
        sf::Texture texture;

};

#endif // GUIBUTTON_H
