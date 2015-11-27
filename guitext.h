#ifndef GUITEXT_H
#define GUITEXT_H

#include <SFML/Graphics.hpp>


class GUIText
{
public:
    GUIText();
    sf:: Text text;
    sf::Font font;
    void display();
};

#endif // GUITEXT_H
