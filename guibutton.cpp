#include "guibutton.h"

GUIButton::GUIButton(int positionX, int positionY, sf::RenderWindow *hutrieApplication, std::string pathname, int sizeX, int sizeY, bool rect, int rectX, int rectY, int rectSizeX, int rectSizeY)
{
    this->hutrieApplication = hutrieApplication;
    button.setSize(sf::Vector2f(sizeX,sizeY));
    button.setPosition(positionX, positionY);
    button.setOutlineColor(sf::Color::Red);
    //button.setOutlineThickness(3);
    texture.loadFromFile(pathname);
    button.setTexture(&texture);
    if (rect) button.setTextureRect(sf::IntRect(rectX, rectY, rectSizeX, rectSizeY));
}

GUIButton::GUIButton(int positionX, int positionY, sf::RenderWindow *hutrieApplication, int sizeX, int sizeY)
{
    this->hutrieApplication = hutrieApplication;
    button.setSize(sf::Vector2f(sizeX,sizeY));
    button.setPosition(positionX, positionY);
    button.setFillColor(sf::Color::White);
    //button.setOutlineThickness(3);
    //button.setTextureRect(sf::IntRect(50, 50, 150, 150));
}

//void GUIButton::create(int positionX, int positionY , sf::RenderWindow *hutrieApplication, std::string pathname)
//{
//    this->hutrieApplication = hutrieApplication;
//    button.setSize(sf::Vector2f(50,50));
//    button.setPosition(positionX, positionY);
//    button.setOutlineColor(sf::Color::Black);
//    button.setOutlineThickness(3);
//    texture.loadFromFile(pathname);
//    button.setTexture(&texture);
//    //button.setTextureRect(sf::IntRect(0, 0, 100, 100));
//}

bool GUIButton::checkBounds()
{
    if(  button.getPosition().x                       <= sf::Mouse::getPosition(*hutrieApplication).x &&
         button.getPosition().x + button.getSize().x  >= sf::Mouse::getPosition(*hutrieApplication).x &&
         button.getPosition().y                       <= sf::Mouse::getPosition(*hutrieApplication).y &&
         button.getPosition().y + button.getSize().y  >= sf::Mouse::getPosition(*hutrieApplication).y)
         return true;
    else return false;
}

