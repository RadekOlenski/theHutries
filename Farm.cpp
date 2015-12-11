//
// Created by radek on 11.12.2015.
//

#include "farm.h"

Farm::Farm(sf::RenderWindow *hutrieApplication, const std::vector<Unit *> &unitsFromGame, const std::string &pathName,
           int buildingType) : GoodsBuilding(hutrieApplication, unitsFromGame,
                                             pathName, buildingType)
{
    title.text.setString("Farm:");
    sound.openFromFile("audio/saw.wav"); //TODO znaleźć dźwięk farmy
    sound.setVolume(100);
    goodReady.text.setString("Food ready");

}
