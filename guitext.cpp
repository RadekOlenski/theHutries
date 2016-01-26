#include "guitext.h"

GUIText::GUIText(int positionX, int positionY, int characterSize, std::string displayedText, sf::Color color)
    : highlightColor(90, 47, 8)
{
    font.loadFromFile("fonts/prince_valiant.ttf");
    text.setFont(font);
    text.setString(displayedText);
    text.setCharacterSize((unsigned int) characterSize);
    text.setPosition(positionX, positionY);
    text.setColor(color);

}

void GUIText::display()
{
    while (1)
    {
        text.setString("The Hutries");
        sf::sleep(sf::seconds(3));
        text.setString("");
        sf::sleep(sf::seconds(0.5));
    }

}

void GUIText::animation()
{
    sf::Color basicColor(0, 0, 0, 0);
    text.setColor(basicColor);
    for (int i = 0; i < 255; i++)
    {
        basicColor.a = (sf::Uint8) i;
        text.setColor(basicColor);
        sf::sleep(sf::milliseconds(30));
    }
    sf::sleep(sf::seconds(8));

}

void GUIText::highlight()
{
    text.setColor(highlightColor);
}

void GUIText::endHighlight()
{
    text.setColor(sf::Color::Black);
}
