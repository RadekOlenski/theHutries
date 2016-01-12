#include <string>
#include <sstream>

#include "hutrie.h"
#include "unit.h"
#include "sound.h"
#include "textures.h"


///////////////////////////CONSTRUCTOR/////////////////////////////////////////////////////////////////////////////////////

Hutrie::Hutrie(sf::RenderWindow* hutrieApplication, std::vector<Unit*> unitsFromGame, std::string pathName)
        : MapObject(hutrieApplication, unitsFromGame, pathName), hutrieThread(&Hutrie::moveHutrie, this)
{
    title.text.setString("Hutrie:");

    sprite.setPosition(6 * 64, 7 * 64);
    sprite.setScale(0.64, 0.64);

    transTexture.loadFromFile(Textures::carrierEmpty);

    sound.openFromFile(Sound::hutrie);
    sound.setVolume(100);

    busy = false;
}

///////////////////////////MOVING TO SPECIFIC MOUSE DIRECTION/////////////////////////////////////////////////////////////////////////////////////

void Hutrie::toDirection(float targetX, float targetY)
{

    while (sprite.getPosition().y < targetY)
    {
        sprite.move(0, 1);
        sprite.setTexture(downTexture);
        sf::sleep(sf::milliseconds(5));
    };

    while (sprite.getPosition().x < targetX)
    {
        sprite.setTexture(texture);
        sprite.move(1, 0);
        sf::sleep(sf::milliseconds(5));
    };

    while (sprite.getPosition().y > targetY)
    {
        sprite.setTexture(upTexture);
        sprite.move(0, -1);
        sf::sleep(sf::milliseconds(5));
    };

    while (sprite.getPosition().x > targetX)
    {
        sprite.setTexture(leftTexture);
        sprite.move(-1, 0);
        sf::sleep(sf::milliseconds(5));
    };
}

void Hutrie::updateStatus()
{
    std::ostringstream desc;
    desc << "I'm ready for\n\taction!";
    description.text.setString(desc.str());
}


