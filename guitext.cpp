#include "guitext.h"

GUIText::GUIText()
{
    font.loadFromFile("fonts/prince_valiant.ttf");
    text.setFont(font);
    text.setCharacterSize(45);      //60
    text.setStyle(sf::Text::Bold);
    text.setPosition(1024 + 20,40);
    text.setColor(sf::Color::Black);
}

void GUIText::display()
{
    while(1)
    {

      text.setString("The");
      sf::sleep(sf::seconds(2));
      text.setPosition(text.getPosition().x + 88 , text.getPosition().y);  //116
      text.setString("Hutries");
      sf::sleep(sf::seconds(2));
      text.setPosition(text.getPosition().x - 88, text.getPosition().y);   //116
      text.setString("The Hutries");
      sf::sleep(sf::seconds(2));
    }
}
