#include "mapobject.h"

MapObject::MapObject (sf::RenderWindow *hutrieApplication, std::vector <Unit*> unitsFromGame, std::string pathName, std::string soundPathName, float scaleX, float scaleY, float positionX, float positionY, float originX, float originY) : description(1024+20,200,30)
{
    this->hutrieApplication = hutrieApplication;

    texture.loadFromFile(pathName);
    sprite.setTexture( texture );
    sprite.setPosition( positionX, positionY );
    sprite.setOrigin(originX,originY);
    sprite.setScale(scaleX,scaleY);

    buffer.loadFromFile(soundPathName);
    sound.setBuffer(buffer);
    sound.setVolume(30);


    active = true;                                                             //WHILE TRUE OBJECT WIL BE DRAWN ON SCREEN
    emphasize = false;                                                         //WHILE FALSE NO GREEN BACKROUND UNDER OBJECT + NO INFO ON GUI

    //////////////CONNECTING MAPOBJECT WITH UNITS UNDER OBJECT//////////////////////////////////////////////////////////

    std::vector <Unit*>::iterator it;
    for(it = unitsFromGame.begin(); it != unitsFromGame.end(); ++it)
    {
        objectUnits.push_back(*it);
    }
}
////////////////SET UNIT CONNECTED WITH MAPOBJECT AS NOT EMPTY/////////////////////////////////////////////////////////////

void MapObject::occupyUnits()
{
    std::vector <Unit*>::iterator it;
    for(it = objectUnits.begin(); it != objectUnits.end(); ++it)
    {
        (*it)->setEmpty(false);
        (*it)->setMapObject(this);
    }
}

////////////////ADD/DELETE GREEN FILL COLOR UNDER MAPOBJECT/////////////////////////////////////////////////////////////////////////////////////

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

////////////////INFORMATION ABOUT MAPOBJECT DISPLAYED ON GUI/////////////////////////////////////////////////////////////////////////////////////

void MapObject::showStatus()
{
    hutrieApplication->draw(description.text);
}

void MapObject::soundPlay()
{
    sound.play();
}
