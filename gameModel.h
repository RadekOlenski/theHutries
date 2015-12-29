
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

    int getApplicationWidth();

    void setApplicationWidth(int applicationWidth);

    int getApplicationHeight();

    void setApplicationHeight(int applicationHeight);

    unsigned int getSelectedUnitIndex();

    void setSelectedUnitIndex(unsigned int selectedUnitIndex);

    int getTempChosenMode();

    void setTempChosenMode(int tempChosenMode);

private:

    int chosenInteractionMode;

    int tempChosenMode;

    int chosenBuildingType;

    int applicationWidth;

    int applicationHeight;

    unsigned int selectedUnitIndex;
};


#endif //THEHUTRIES_GAMEMODEL_H
