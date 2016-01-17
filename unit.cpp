#include "unit.h"
#include "unittype.h"

Unit::Unit(sf::Vector2f position, int index) : field(sf::Vector2f(64, 64))
{
    this->index = index;
    field.setPosition(position);
    field.setFillColor(sf::Color::Transparent);
    field.setOutlineThickness(1);
    sf::Color color(0, 255, 0, 70);
    field.setOutlineColor(color);
//    emptiness = true;                                         //NO MAPOBJECT ON ME
    type = UnitType::EMPTY;
    forestChecked = false;
    rocksChecked = false;
    mountainChecked = false;
}

void Unit::addHutrie(Hutrie* hutrie)
{
    dwellers.push_back(hutrie);
}

Hutrie* Unit::getHutrie()
{
    Hutrie* tempHutrie = dwellers.back();
    dwellers.pop_back();
    return tempHutrie;
}

int Unit::hutriesNumber()
{
    return dwellers.size();
}

Hutrie* Unit::getHutrieIndex(int index)
{
    return dwellers.at((unsigned int) index);
}

void Unit::assignType(std::string environmentType)  //przydzielanie typu unitu wokol obiektu environment dla trybu budowania
{
    if (type != UnitType::FULL)
    {
        if (environmentType == "forest" && !forestChecked)      // zapobiega dodaniu dwa razy tego samego typu environment, odzielna flaga wyklucza tez przerozne kombinacje
        {
            type += UnitType::NEARFOREST;
            forestChecked = true;
        }
        else if (environmentType == "rocks" && !rocksChecked)
        {
            type += UnitType::NEARROCKS;
            rocksChecked = true;
        }
        else if (environmentType == "mountains" && !mountainChecked)
        {
             type += UnitType::NEARMOUNTAIN;
             mountainChecked = true;
        }
    }
}


