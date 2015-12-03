#include "unit.h"

Unit::Unit(sf::Vector2f position, int index) : field(sf::Vector2f(64, 64))
{
        this->index = index;
        field.setPosition(position);
        field.setFillColor(sf::Color::Transparent);
        field.setOutlineThickness(1);
        sf::Color color(0, 255, 0, 70);
        field.setOutlineColor(color);
        emptiness = true;                                         //NO MAPOBJECT ON ME
}

void Unit::addHutrie(Hutrie* hutrie)
{
    dwellers.push_back(hutrie);
}

int Unit::hutriesNumber()
{
    return dwellers.size();
}

Hutrie* Unit::getHutrie(int index)
{
    return dwellers.at(index);
}


