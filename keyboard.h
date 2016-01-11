#ifndef THEHUTRIES_KEYBOARD_H
#define THEHUTRIES_KEYBOARD_H


#include <SFML/Graphics.hpp>
#include "modelController.h"
#include "sound.h"

class Keyboard
{
public:

    Keyboard(sf::RenderWindow* hutrieApplication, ModelController* modelController);

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
