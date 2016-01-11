#ifndef GUITEXT_H
#define GUITEXT_H

#include <SFML/Graphics.hpp>


class GUIText
{
public:

    GUIText(int positionX, int positionY, int characterSize, std::string displayedText = "",
            sf::Color color = sf::Color::Black);

    sf::Text text;
    sf::Font font;

    void display();

    void animation();
};

#endif // GUITEXT_H
