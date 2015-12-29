//
// Created by radek on 29.12.2015.
//

#include "mouseLock.h"
#include <SFML/Graphics.hpp>

using namespace sf;

MouseLock::MouseLock()
{
    MouseLock::isLocked = false;
    MouseLock::hasLeftBeenPressed = false;
    MouseLock::hasRightBeenPressed = false;
}

bool MouseLock::getIsLocked()
{
    return MouseLock::isLocked;
}

void MouseLock::update()
{
    bool isCurrentlyPressed = Mouse::isButtonPressed(Mouse::Left);
    if (MouseLock::hasLeftBeenPressed && isCurrentlyPressed)
    {
        isLocked = true;
    }
    if (MouseLock::hasLeftBeenPressed && !isCurrentlyPressed)
    {
        // has been released
        isLocked = false;
    }
    
    MouseLock::hasLeftBeenPressed = isCurrentlyPressed;
}
