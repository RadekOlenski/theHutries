#ifndef GUITEXT_H
#define GUITEXT_H

#include <SFML/Graphics.hpp>


class GUIText
{
public:
    GUIText();
    GUIText(int positionX, int positionY, int characterSize, sf::Color color = sf::Color::Black);
    sf:: Text text;
    sf::Font font;
    void display();
};

#endif // GUITEXT_H