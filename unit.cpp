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

void Unit::assignType(std::string environmentType)
{
    if (type == UnitType::EMPTY)
    {
        if (environmentType == "forest")
        {
            type = UnitType::NEARFOREST;
        }
        else if (environmentType == "rocks")
        {
            type = UnitType::NEARROCKS;
        }
        else if (environmentType == "mountains")
        {
            type = UnitType::NEARMOUNTAIN;
        }
    }
    else if (type != UnitType::FULL)
    {
        if (environmentType == "forest")
        {
            if (type != UnitType::NEARFOREST) type += UnitType::NEARFOREST;
        }
        else if (environmentType == "rocks")
        {
            if (type != UnitType::NEARROCKS)type += UnitType::NEARROCKS;
        }
        else if (environmentType == "mountains")
        {
             if (type != UnitType::NEARMOUNTAIN) type += UnitType::NEARMOUNTAIN;
        }
    }
}


