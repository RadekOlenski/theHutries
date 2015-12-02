#ifndef MAPOBJECT_H
#define MAPOBJECT_H

#include "unit.h"
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

        virtual void showStatus() = 0;
        GUIText title;
        GUIText description;
        GUIButton descriptionFrame;

        ////////////////////// FLAGS //////////////////////////////////////////

        void emphasizeUnits(bool fillColor = true);
        bool isEmphasize() {return emphasize;}
        void setEmphasize(bool emphasize) {this->emphasize = emphasize;}
        bool isActive() {return active;}
        void setActive(bool active) {this->active = active;}

        ////////////////////// SOUND /////////////////////////////////////////

        void setSoundVolume (int volume) {sound.setVolume(volume);}
        void soundPlay(bool play = true);

        /////////////////////// CONSTRUCTOR /////////////////////////////////

        MapObject (sf::RenderWindow *hutrieApplication, std::vector <Unit*> unitsFromGame,std::string pathName);


    protected:
        std::vector <Unit*> objectUnits;
        sf::Music sound;
        bool active;
        bool emphasize;
        virtual void occupyUnits();
  };

#endif // MAPOBJECT_H
