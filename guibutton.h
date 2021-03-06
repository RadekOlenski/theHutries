#ifndef GUIBUTTON_H
#define GUIBUTTON_H

#include <SFML/Graphics.hpp>
#include <string>

class GUIButton
{
public:

    GUIButton(int positionX, int positionY, sf::RenderWindow* hutrieApplication, std::string pathName, int sizeX = 50,
              int sizeY = 50, bool rect = false, int rectX = 0, int rectY = 0, int rectSizeX = 1000,
              int rectSizeY = 50);

    GUIButton(int positionX, int positionY, sf::RenderWindow* hutrieApplication, int sizeX, int sizeY,
              bool visible = true);

    sf::RectangleShape button;

    bool checkBounds();

    bool isActive() { return active; };

    void setActive(bool active) { this->active = active; };;

    void setTexture(sf::Texture texture) { this->texture = texture; };

    sf::Texture getTexture() { return texture; };

    void changeTexture(std::string path);
private:

    sf::RenderWindow* hutrieApplication;
    sf::Texture texture;
    bool active;

};

#endif // GUIBUTTON_H
