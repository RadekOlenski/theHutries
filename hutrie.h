#ifndef HUTRIE_H
#define HUTRIE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

#include "mapobject.h"
//#include "unit.h"

//class MapObject;
class Unit;

class Hutrie : public MapObject
{

public:

    sf::Thread hutrieThread;

    Hutrie(sf::RenderWindow* hutrieApplication, std::vector<Unit*> unitsFromGame, std::string pathName);

    virtual void moveHutrie() = 0;

    void updateStatus();

    bool isBusy() { return busy; }

    void setBusy(bool busy) { this->busy = busy; }

    void setPauseThread(bool pauseThread) {this->pauseThread = pauseThread; };

    virtual void animateTextureDown() {};

    virtual void animateTextureUp() {};

    virtual void animateTextureRight() {};

    virtual void animateTextureLeft() {};

    void changeTexture(std::string path);

protected:
    sf::Texture upTexture;
    sf::Texture downTexture;
    sf::Texture leftTexture;
    sf::Texture transTexture;

    void toDirection(float targetX, float targetY);

    bool busy;
    bool pauseThread;

    int frameCounter;
    int animationCounter;
};

#endif // HUTRIE_H
