#ifndef MAPOBJECT_H
#define MAPOBJECT_H

//#include "unit.h"
#include "guitext.h"

#include "guibutton.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <vector>

class Unit;

class MapObject
{
public:

    sf::RenderWindow* hutrieApplication;
    sf::Sprite sprite;
    sf::Texture texture;

    //////////////////// GUI INFO //////////////////////////////////////////

    virtual void updateStatus() = 0;

    virtual void showButtons();

    virtual void deactivateButtons();

    virtual void buttonAction();

    virtual void constructionButtonAction();

    virtual void showConstructionButtons();

    GUIText title;
    GUIText description;
    GUIButton descriptionFrame;

    ////////////////////// FLAGS //////////////////////////////////////////

    void highlightUnits(bool fillColor = true);

    bool isHighlighted() { return highlight; }

    void setHighlight(bool emphasize) { this->highlight = emphasize; }

    int getUnitIndex(int index);

    void reconnectUnits(std::vector<Unit*> unitsFromGame);

    std::vector<Unit*> getObjectUnits() { return objectUnits; };

    ////////////////////// SOUND /////////////////////////////////////////

    void setSoundVolume(int volume) { sound.setVolume(volume); }

    void soundPlay(bool play = true);

    void soundPause();

    /////////////////////// CONSTRUCTOR /////////////////////////////////

    MapObject(sf::RenderWindow* hutrieApplication, std::vector<Unit*> unitsFromGame, std::string pathName);

    virtual ~MapObject();

    void updateDescriptionTexture(sf::Texture texture);

    virtual void highlightButton() {};

    void setVolume();

protected:

    std::vector<Unit*> objectUnits;
    sf::Music sound;
    bool highlight;

//    virtual void occupyUnits();
    void occupyUnits();
};

#endif // MAPOBJECT_H
