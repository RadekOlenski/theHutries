#include "mapobject.h"

MapObject::MapObject (sf::RenderWindow *hutrieApplication, Unit *unit, std::string pathName, float positionX, float positionY, float originX, float originY, float scaleX, float scaleY)
{
 this->hutrieApplication = hutrieApplication;
 this->unit = unit;
 texture.loadFromFile(pathName);
 sprite.setTexture( texture );
 sprite.setPosition( positionX, positionY );
 sprite.setOrigin(originX,originY);
 sprite.setScale(scaleX,scaleY);
}
