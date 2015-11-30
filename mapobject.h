#ifndef MAPOBJECT_H
#define MAPOBJECT_H

#include "unit.h"
#include "guitext.h"

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
        GUIText description;
        //std::string introduceYourSelf;
        void emphasizeUnits(bool fillColor = true);
        virtual void showStatus();
        void soundPlay(bool play = true);

        void setSoundVolume (int volume) {sound.setVolume(volume);}
        bool isActive() {return active;}
        void setActive(bool active) {this->active = active;}
        bool isEmphasize() {return emphasize;}
        void setEmphasize(bool emphasize) {this->emphasize = emphasize;}
        MapObject (sf::RenderWindow *hutrieApplication, std::vector <Unit*> unitsFromGame, std::string pathName, std::string soundPathName, float scaleX = 1, float scaleY = 1, float positionX = 0, float positionY = 0, float originX = 0, float originY = 0);
        //MapObject (sf::RenderWindow *hutrieApplication, std::vector <Unit*> unitsFromGame, std::string pathName,  float scaleX = 1, float scaleY = 1, float positionX = 0, float positionY = 0, float originX = 0, float originY = 0);

    protected:
        std::vector <Unit*> objectUnits;
        sf::Music sound;
        bool active;
        bool emphasize;
        virtual void occupyUnits();
};

#endif // MAPOBJECT_H
