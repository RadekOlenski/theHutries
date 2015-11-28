#ifndef MAPOBJECT_H
#define MAPOBJECT_H

#include "unit.h"
#include "guitext.h"

#include <SFML/Graphics.hpp>
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
        std::string introduceYourSelf;
        void emphasizeUnits(bool fillColor = true);
        virtual void showStatus();

        bool isActive() {return active;}
        void setActive(bool active) {this->active = active;}
        bool isEmphasize() {return emphasize;}
        void setEmphasize(bool emphasize) {this->emphasize = emphasize;}
        MapObject (sf::RenderWindow *hutrieApplication, std::vector <Unit*> unitsFromGame, std::string pathName, float scaleX = 1, float scaleY = 1, float positionX = 0, float positionY = 0, float originX = 0, float originY = 0);

    protected:
        std::vector <Unit*> objectUnits;
        bool active;
        bool emphasize;
        virtual void occupyUnits();
};

#endif // MAPOBJECT_H
