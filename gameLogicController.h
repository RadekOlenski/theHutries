#ifndef THEHUTRIES_GAMELOGICCONTROLLER_H
#define THEHUTRIES_GAMELOGICCONTROLLER_H

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include "world.h"
#include "modelController.h"

class GameLogicController
{

public:

    GameLogicController(World*world, sf::RenderWindow* hutrieApplication, ModelController* modelController);

    void createBuilding(std::vector<Unit*> usedUnits);

private:
    World* world;
    sf::RenderWindow* hutrieApplication;
    ModelController* modelController;

};


#endif //THEHUTRIES_GAMELOGICCONTROLLER_H
