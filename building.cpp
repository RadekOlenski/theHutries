#include "building.h"
#include <cstdlib>

Building::Building(sf::RenderWindow *hutrieApplication, Unit *unit0, Unit *unit1, Unit *unit2, Unit *unit3) : MapObject(hutrieApplication, unit0, "sprites/buildings/sawmill.png",0.5,0.5)
{
    buildingField.resize(4);
    buildingField.at(0) = unit0;
    buildingField.at(1) = unit1;
    buildingField.at(2) = unit2;
    buildingField.at(3) = unit3;
    switch(rand()%4)
    {
        case 0: texture.loadFromFile("sprites/buildings/sawmill.png"); break;
        case 1: texture.loadFromFile("sprites/buildings/barracks.png"); break;
        case 2: texture.loadFromFile("sprites/buildings/stone.png"); break;
        case 3: texture.loadFromFile("sprites/buildings/residence.png"); break;
    }

}

void Building::placeOnMap()
{
    //sprite.setPosition(sf::Mouse::getPosition(*hutrieApplication).x,sf::Mouse::getPosition(*hutrieApplication).y);
    //sprite.setPosition (static_cast <sf::Vector2f> (sf::Mouse::getPosition(*hutrieApplication)) );
    sprite.setPosition (unit->field.getPosition());
    std::vector <Unit*>::iterator it;
    for(it = buildingField.begin(); it != buildingField.end(); ++it)
    {
        (*it)->setEmpty(false);
    }
}
