#include "guitext.h"
#include <cstdlib>

GUIText::GUIText()
{
    font.loadFromFile("fonts/prince_valiant.ttf");
    text.setFont(font);
    text.setCharacterSize(45);      //60
    text.setStyle(sf::Text::Bold);
    text.setPosition(1024 + 20,40);
    text.setColor(sf::Color::Black);
}

GUIText::GUIText(int positionX, int positionY, int characterSize, sf::Color color)
{
    font.loadFromFile("fonts/prince_valiant.ttf");
    text.setFont(font);
    text.setCharacterSize(characterSize);
    text.setPosition(positionX,positionY);
    text.setColor(color);
}

void GUIText::display()
{
//    while(1)
//    {
//      text.setString("The");
//      sf::sleep(sf::seconds(2));
//      text.setPosition(text.getPosition().x + 88 , text.getPosition().y);  //116
//      text.setString("Hutries");
//      sf::sleep(sf::seconds(2));
//      text.setPosition(text.getPosition().x - 88, text.getPosition().y);   //116
//      text.setString("The Hutries");
//      sf::sleep(sf::seconds(2));
//    }
    while(1)
    {
      text.setString("The Hutries");
      sf::sleep(sf::seconds(3));
      //int r = rand () % 256;
//      sf::Color color(r,r,r,r);
//      text.setColor(color);
      text.setString("");
      sf::sleep(sf::seconds(0.5));
    }

}
