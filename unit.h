#ifndef UNIT_H
#define UNIT_H

#include <SFML/Graphics.hpp>

#include <vector>

#include "mapobject.h"
#include "hutrie.h"

class MapObject;

class Unit
{
public:

    sf::RectangleShape field;

    void setMapObject(MapObject* mapObject) { this->mapObject = mapObject; }

    MapObject* getMapObject() { return this->mapObject; }

    bool isEmpty() { return emptiness; }

    void setEmpty(bool emptiness) { this->emptiness = emptiness; }

    Unit(sf::Vector2f position, int index);

    void addHutrie(Hutrie* hutrie);

    Hutrie* getHutrie();

    int hutriesNumber();

    Hutrie* getHutrieIndex(int index);

    int getIndex() { return index; }

private:

    bool emptiness;
    MapObject* mapObject;
    std::vector<Hutrie*> dwellers;
    int index;

};

#endif // UNIT_H
