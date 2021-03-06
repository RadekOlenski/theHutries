#include "mapobject.h"

#include "unit.h"
#include "unittype.h"
#include "gamebalance.h"

MapObject::MapObject(sf::RenderWindow* hutrieApplication, std::vector<Unit*> unitsFromGame, std::string pathName)
        : title(1024 + 40, 170, 30),
          descriptionFrame(1024 + 60, 210, hutrieApplication, pathName, 128, 128),
          description(1024 + 30, 340, 20)
{
    this->hutrieApplication = hutrieApplication;

    texture.loadFromFile(pathName);
    sprite.setTexture(texture);
    sprite.setScale(0.5, 0.5);
    sound.setVolume(GameBalance::sfxVolume);

//    active = true;                                                             //WHILE TRUE OBJECT WIL BE DRAWN ON SCREEN
    highlight = false;                                                         //WHILE FALSE NO GREEN BACKROUND UNDER OBJECT + NO INFO ON GUI

    //////////////CONNECTING MAPOBJECT WITH UNITS UNDER OBJECT//////////////////////////////////////////////////////////

    std::vector<Unit*>::iterator it;
    for (it = unitsFromGame.begin(); it != unitsFromGame.end(); ++it)
    {
        objectUnits.push_back(*it);
    }
}

MapObject::~MapObject()
{

}


void MapObject::reconnectUnits(std::vector<Unit*> unitsFromGame)
{
    objectUnits.clear();
    std::vector<Unit*>::iterator it;
    for (it = unitsFromGame.begin(); it != unitsFromGame.end(); ++it)
    {
        objectUnits.push_back(*it);
    }

}
////////////////SET UNIT CONNECTED WITH MAPOBJECT AS NOT EMPTY/////////////////////////////////////////////////////////////

void MapObject::occupyUnits()
{
    std::vector<Unit*>::iterator it;
    for (it = objectUnits.begin(); it != objectUnits.end(); ++it)
    {
//        (*it)->setEmpty(false);
        (*it)->setType(UnitType::FULL);
        (*it)->setMapObject(this);
    }
}

////////////////ADD/DELETE GREEN FILL COLOR UNDER MAPOBJECT/////////////////////////////////////////////////////////////////////////////////////

void MapObject::highlightUnits(bool fillColor)
{
    std::vector<Unit*>::iterator it;
    sf::Color color(0, 255, 0, 50);
    if (!fillColor) color = sf::Color::Transparent;
    for (it = objectUnits.begin(); it != objectUnits.end(); ++it)
    {
        (*it)->field.setFillColor(color);
    }
}

void MapObject::soundPlay(bool play)
{
    if (play) sound.play();
    else sound.stop();
}

int MapObject::getUnitIndex(int index)
{
    return objectUnits.at((unsigned int) index)->getIndex();
}

void MapObject::showButtons() { }

void MapObject::showConstructionButtons() { }

void MapObject::deactivateButtons() { }

void MapObject::buttonAction() { }

void MapObject::constructionButtonAction() { }

void MapObject::updateDescriptionTexture(sf::Texture texture)
{
    descriptionFrame.setTexture(texture);
}

void MapObject::soundPause()
{
    sound.pause();
}

void MapObject::setVolume()
{
    sound.setVolume(GameBalance::sfxVolume);
}
