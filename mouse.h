//
// Created by radek on 29.12.2015.
//

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

    Mouse(sf::RenderWindow* hutrieApplication, ModelController* modelController, GUI* gui,
          GameLogicController* gameLogicController, sf::Sprite* cursor);

    void leftClickActions();

    void rightClickActions();

    void updateMouseLock();

    void setCursorPosition();
private:

    MouseLock* mouseLock;
    sf::RenderWindow* hutrieApplication;
    ModelController* modelController;
    GUI* gui;
    GameLogicController* gameLogicController;
    sf::Sprite* cursor;

    void handleClickOnMap();
};


#endif //THEHUTRIES_MOUSE_H
