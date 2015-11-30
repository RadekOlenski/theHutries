#include "unit.h"

Unit::Unit(sf::Vector2f position) : field(sf::Vector2f(64, 64))
{
        field.setPosition(position);
        field.setFillColor(sf::Color::Transparent);
        field.setOutlineThickness(1);
        sf::Color color(0, 255, 0, 70);
        field.setOutlineColor(color);
        emptiness = true;                                         //NO MAPOBJECT ON ME
}
