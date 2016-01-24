#ifndef THEHUTRIES_MOUSE_H
#define THEHUTRIES_MOUSE_H


#include "mouseLock.h"
#include "modelController.h"
#include "gui.h"
#include "gameLogicController.h"
#include "sound.h"

class Mouse
{
public:

    Mouse(sf::RenderWindow* hutrieApplication, ModelController* modelController,
          GameLogicController* gameLogicController);

    void leftClickActions();

    void rightClickActions();

    void updateMouseLock();

private:

    MouseLock* mouseLock;
    sf::RenderWindow* hutrieApplication;
    ModelController* modelController;
    GameLogicController* gameLogicController;

    void handleClickOnMap();
};


#endif //THEHUTRIES_MOUSE_H
