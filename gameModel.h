
#ifndef THEHUTRIES_GAMEMODEL_H
#define THEHUTRIES_GAMEMODEL_H

#include <SFML/Graphics.hpp>

class GameModel
{
public:

    int getChosenBuildingType();

    void setChosenBuildingType(int chosenBuildingType);

    void setChosenInteractionMode(int chosenInteractionMode);

    int getChosenInteractionMode();

private:

    int chosenInteractionMode;

    int tempChosenMode;

    int chosenBuildingType;

};


#endif //THEHUTRIES_GAMEMODEL_H
