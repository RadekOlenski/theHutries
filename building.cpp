#include "building.h"

Building::Building(sf::RenderWindow *hutrieApplication, Unit *unit) : MapObject(hutrieApplication, unit, "sprites/buildings/sawmill.png",0,0,0,0,0.5,0.5)
{
}

void Building::placeOnMap()
{
    //sprite.setPosition(sf::Mouse::getPosition(*hutrieApplication).x,sf::Mouse::getPosition(*hutrieApplication).y);
    //sprite.setPosition (static_cast <sf::Vector2f> (sf::Mouse::getPosition(*hutrieApplication)) );
    sprite.setPosition (unit->field.getPosition());
    unit->setEmpty(false);
}
