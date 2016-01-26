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

    sf::Color highlightColor;

    void display();

    void animation();

    void highlight();

    void endHighlight();
};

#endif // GUITEXT_H
