#include "sawmill.h"

Sawmill::Sawmill(sf::RenderWindow *hutrieApplication, std::vector<Unit *> unitsFromGame, std::string pathName,
                 int buildingType) : GoodsBuilding(hutrieApplication, unitsFromGame, pathName, buildingType)
{
    title.text.setString("Sawmill:");
    sound.openFromFile("audio/saw.wav");
    sound.setVolume(100);
    goodReady.text.setString("Wood ready");
}
