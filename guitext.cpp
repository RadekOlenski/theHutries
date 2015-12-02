#include "guitext.h"

GUIText::GUIText(int positionX, int positionY, int characterSize,  std::string displayedText, sf::Color color)
{
    font.loadFromFile("fonts/prince_valiant.ttf");
    text.setFont(font);
    text.setString(displayedText);
    text.setCharacterSize(characterSize);
    text.setPosition(positionX,positionY);
    text.setColor(color);
}

void GUIText::display()
{
    while(1)
    {
      text.setString("The Hutries");
      sf::sleep(sf::seconds(3));
      text.setString("");
      sf::sleep(sf::seconds(0.5));
    }

}
