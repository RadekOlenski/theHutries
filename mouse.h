//
// Created by radek on 29.12.2015.
//

#ifndef THEHUTRIES_MOUSE_H
#define THEHUTRIES_MOUSE_H


#include "mouseLock.h"
#include "modelController.h"
#include "gui.h"
#include "gameLogicController.h"

class Mouse
{
public:

    Mouse(sf::RenderWindow* hutrieApplication, ModelController* modelController, GUI* gui,
          GameLogicController* gameLogicController);

    void leftClickActions();

    void updateMouseLock();

private:

    MouseLock* mouseLock;
    sf::RenderWindow* hutrieApplication;
    ModelController* modelController;
    GUI* gui;
    GameLogicController* gameLogicController;

    void guiButtonsActions();

    void handleClickOnMap();
};


#endif //THEHUTRIES_MOUSE_H
