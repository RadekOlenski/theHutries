//
// Created by radek on 27.12.2015.
//

#ifndef THEHUTRIES_KEYBOARD_H
#define THEHUTRIES_KEYBOARD_H


#include <SFML/Graphics.hpp>
#include "modelController.h"
#include "sound.h"
//#include "world.h"


class Keyboard
{
public:
//World* world;
    Keyboard(sf::RenderWindow* hutrieApplication, ModelController* modelController/*, World* world*/);

    void actionsLoop();

    void closeGame(sf::Event event);

private:

    void chooseInteractionMode(sf::Event event);

    void chooseBuildingType(sf::Event event);

    sf::RenderWindow* hutrieApplication;
    ModelController* modelController;
    sf::Event event;
};


#endif //THEHUTRIES_KEYBOARD_H
