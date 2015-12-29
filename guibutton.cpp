#include "guibutton.h"

GUIButton::GUIButton(int positionX, int positionY, sf::RenderWindow *hutrieApplication, std::string pathName, int sizeX, int sizeY, bool rect, int rectX, int rectY, int rectSizeX, int rectSizeY)
{
    this->hutrieApplication = hutrieApplication;
    button.setSize(sf::Vector2f(sizeX,sizeY));
    button.setPosition(positionX, positionY);
    texture.loadFromFile(pathName);
    button.setTexture(&texture);
    active = false;
    if (rect) button.setTextureRect(sf::IntRect(rectX, rectY, rectSizeX, rectSizeY));
}

GUIButton::GUIButton(int positionX, int positionY, sf::RenderWindow *hutrieApplication, int sizeX, int sizeY)
{
    this->hutrieApplication = hutrieApplication;
    button.setSize(sf::Vector2f(sizeX,sizeY));
    button.setPosition(positionX, positionY);
    button.setFillColor(sf::Color::Yellow);
}


bool GUIButton::checkBounds()
{
    sf::Vector2f buttonPosition = button.getPosition();
    sf::Vector2f buttonSize = button.getSize();
    sf::Vector2i mousePosition = sf::Mouse::getPosition(*hutrieApplication);

    bool result = active
        && buttonPosition.x <= mousePosition.x
        && buttonPosition.x + buttonSize.x >= mousePosition.x
        && buttonPosition.y <= mousePosition.y
        && buttonPosition.y + buttonSize.y >= mousePosition.y;
    return result;
}

