#ifndef THEHUTRIES_KEYBOARD_H
#define THEHUTRIES_KEYBOARD_H


#include <SFML/Graphics.hpp>
#include "modelController.h"
#include "guiController.h"
#include "sound.h"

class Keyboard
{
public:

    Keyboard(sf::RenderWindow* hutrieApplication, ModelController* modelController, GUIController* guiController);

    void actionsLoop();

    void closeGame(sf::Event event);

    void handleExitWindowActions();
private:

    void confirm(sf::Event event);

    void pauseMenuActions(sf::Event event);

    void chooseInteractionMode(sf::Event event);

    void chooseBuildingType(sf::Event event);

    void otherKeyActions(sf::Event event);

    sf::RenderWindow* hutrieApplication;
    ModelController* modelController;
    GUIController* guiController;
    sf::Event event;
};


#endif //THEHUTRIES_KEYBOARD_H
