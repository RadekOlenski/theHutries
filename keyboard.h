//
// Created by radek on 27.12.2015.
//

#ifndef THEHUTRIES_KEYBOARD_H
#define THEHUTRIES_KEYBOARD_H


#include <SFML/Graphics.hpp>


class Keyboard
{
public:

    Keyboard(sf::RenderWindow* hutrieApplication);

    void actionsLoop();

private:

    void switchMode(sf::Event event);

    void switchBuildingType(sf::Event event);

    void closeGame(sf::Event event);

    sf::RenderWindow*hutrieApplication;
    sf::Event event;
};


#endif //THEHUTRIES_KEYBOARD_H
