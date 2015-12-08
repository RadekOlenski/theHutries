#include "stonecutter.h"

StoneCutter::StoneCutter(sf::RenderWindow *hutrieApplication, std::vector <Unit*> unitsFromGame, std::string pathName, int buildingType) : GoodsBuilding(hutrieApplication,unitsFromGame, pathName, buildingType)
{
    title.text.setString("Stonecutter Hut:");
    sprite.setScale(0.45,0.45);
    sprite.setOrigin(-10,-30);
    sound.openFromFile("audio/rock.wav");
    goodReady.text.setString("Stone ready");
}
