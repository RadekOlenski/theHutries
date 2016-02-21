#include <string>
#include <sstream>

#include "hutrie.h"
#include "unit.h"
#include "sound.h"
#include "textures.h"


///////////////////////////CONSTRUCTOR/////////////////////////////////////////////////////////////////////////////////////

Hutrie::Hutrie(sf::RenderWindow* hutrieApplication, std::vector<Unit*> unitsFromGame, std::string pathName)
        : MapObject(hutrieApplication, unitsFromGame, pathName),
          hutrieThread(&Hutrie::moveHutrie, this)
{
    title.text.setString("Hutrie:");

    sprite.setPosition(6 * 64, 7 * 64);
    sprite.setScale(0.64, 0.64);

    transparentTexture.loadFromFile(Textures::carrierEmpty);

    sound.openFromFile(Sound::hutrie);
    sound.setVolume(100);

    busy = false;
    pauseThread = false;

    frameCounter = 0;
    animationCounter = 0;
}

///////////////////////////MOVING TO SPECIFIC MOUSE DIRECTION/////////////////////////////////////////////////////////////////////////////////////

void Hutrie::toDirection(float targetX, float targetY)
{

    while (sprite.getPosition().y < targetY)
    {
        if (pauseThread)
        {
            sf::sleep(sf::seconds(2));
        };
        sprite.move(0, 1);
        animateTextureDown();
        sf::sleep(sf::milliseconds(5));
    };
    animationCounter = 0;

    while (sprite.getPosition().x < targetX)
    {
        if (pauseThread)
        {
            sf::sleep(sf::seconds(2));
        };
        animateTextureRight();
        sprite.move(1, 0);
        sf::sleep(sf::milliseconds(5));
    };
    animationCounter = 0;

    while (sprite.getPosition().y > targetY)
    {
        if (pauseThread)
        {
            sf::sleep(sf::seconds(2));
        };
        animateTextureUp();
        sprite.move(0, -1);
        sf::sleep(sf::milliseconds(5));
    };
    animationCounter = 0;

    while (sprite.getPosition().x > targetX)
    {
        if (pauseThread)
        {
            sf::sleep(sf::seconds(2));
        };
        animateTextureLeft();
        sprite.move(-1, 0);
        sf::sleep(sf::milliseconds(5));
    };
    animationCounter = 0;
}

void Hutrie::updateStatus()
{
    std::ostringstream desc;
    desc << "I'm ready for\n\taction!";
    description.text.setString(desc.str());
}

void Hutrie::changeTexture(std::string path)
{
    currentTexture.loadFromFile(path);
    sprite.setTexture(currentTexture);
}
