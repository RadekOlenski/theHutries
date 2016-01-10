#ifndef THEHUTRIES_MOUSELOCK_H
#define THEHUTRIES_MOUSELOCK_H


class MouseLock
{
public:


    MouseLock();

    bool getIsLocked();

    void update();

private:
    bool isLocked;
    bool hasLeftBeenPressed;
    bool hasRightBeenPressed;
};


#endif //THEHUTRIES_MOUSELOCK_H
