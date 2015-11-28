#include "mapobject.h"

MapObject::MapObject (sf::RenderWindow *hutrieApplication, std::vector <Unit*> unitsFromGame, std::string pathName, float scaleX, float scaleY, float positionX, float positionY, float originX, float originY) : description(1024+20,200,30)
{
    this->hutrieApplication = hutrieApplication;
    texture.loadFromFile(pathName);
    sprite.setTexture( texture );
    sprite.setPosition( positionX, positionY );
    sprite.setOrigin(originX,originY);
    sprite.setScale(scaleX,scaleY);
    active = true;
    emphasize = false;

    std::vector <Unit*>::iterator it;
    for(it = unitsFromGame.begin(); it != unitsFromGame.end(); ++it)
    {
        objectUnits.push_back(*it);
    }
}

void MapObject::occupyUnits()
{
    std::vector <Unit*>::iterator it;
    for(it = objectUnits.begin(); it != objectUnits.end(); ++it)
    {
        (*it)->setEmpty(false);
        (*it)->setMapObject(this);
    }
}

void MapObject::emphasizeUnits(bool fillColor)
{
    std::vector <Unit*>::iterator it;
    sf::Color color(0, 255, 0, 30);
    if (!fillColor) color = sf::Color::Transparent;
    for(it = objectUnits.begin(); it != objectUnits.end(); ++it)
    {
        (*it)->field.setFillColor(color);
    }
}

void MapObject::showStatus()
{
    hutrieApplication->draw(description.text);
}
