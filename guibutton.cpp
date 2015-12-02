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

bool GUIButton::checkBounds()
{
    if(  button.getPosition().x                       <= sf::Mouse::getPosition(*hutrieApplication).x &&
         button.getPosition().x + button.getSize().x  >= sf::Mouse::getPosition(*hutrieApplication).x &&
         button.getPosition().y                       <= sf::Mouse::getPosition(*hutrieApplication).y &&
         button.getPosition().y + button.getSize().y  >= sf::Mouse::getPosition(*hutrieApplication).y)
         return true;
    else return false;
}

