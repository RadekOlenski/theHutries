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

        sf::RenderWindow *hutrieApplication;
        sf::Sprite sprite;
        sf::Texture texture;

        //////////////////// GUI INFO //////////////////////////////////////////

        virtual void updateStatus() = 0;
        virtual void showButtons();
        virtual void deactivateButtons();
        virtual void buttonAction();
        GUIText title;
        GUIText description;
        GUIButton descriptionFrame;

        ////////////////////// FLAGS //////////////////////////////////////////

        void highlightUnits(bool fillColor = true);
        bool isHighlighted() {return highlight;}
        void setHighlight(bool emphasize) { this->highlight = emphasize;}
//        bool isActive() {return active;}
//        void setActive(bool active) {this->active = active;}
        int getUnitIndex (int index);
        void reconnectUnits (std::vector <Unit*> unitsFromGame);
        std::vector <Unit*> getObjectUnits() {return objectUnits;};

        ////////////////////// SOUND /////////////////////////////////////////

        void setSoundVolume (int volume) {sound.setVolume(volume);}
        void soundPlay(bool play = true);

        /////////////////////// CONSTRUCTOR /////////////////////////////////

        MapObject (sf::RenderWindow *hutrieApplication, std::vector <Unit*> unitsFromGame, std::string pathName);
        virtual ~MapObject();

        void updateDescriptionTexture(sf::Texture texture);


    protected:
        std::vector <Unit*> objectUnits;
        sf::Music sound;
//        bool active;
        bool highlight;
        virtual void occupyUnits();
  };

#endif // MAPOBJECT_H
