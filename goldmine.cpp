//
// Created by Master on 08.12.2015.
//

#include "goldmine.h"

Goldmine::Goldmine(sf::RenderWindow *hutrieApplication, const std::vector<Unit *> &unitsFromGame,
                   const std::string &pathName, int buildingType) : GoodsBuilding(hutrieApplication, unitsFromGame,
                                                                                  pathName, buildingType)
{
    title.text.setString("Goldmine:");
    sound.openFromFile("audio/saw.wav"); //TODO znaleźć dźwięk kopalni
    sound.setVolume(100);
    goodReady.text.setString("Gold ready");

}

