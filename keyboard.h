//
// Created by radek on 27.12.2015.
//

#ifndef THEHUTRIES_KEYBOARD_H
#define THEHUTRIES_KEYBOARD_H


#include <SFML/Graphics.hpp>
#include "modelController.h"


class Keyboard
{
public:

    Keyboard(sf::RenderWindow* hutrieApplication, ModelController* modelController);

    void actionsLoop();

private:

    void chooseInteractionMode(sf::Event event);

    void chooseBuildingType(sf::Event event);

    void closeGame(sf::Event event);

    sf::RenderWindow* hutrieApplication;
    ModelController* modelController;
    sf::Event event;
};


#endif //THEHUTRIES_KEYBOARD_H
