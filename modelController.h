#ifndef THEHUTRIES_MODELCONTROLLER_H
#define THEHUTRIES_MODELCONTROLLER_H

#include "gameModel.h"

class ModelController
{
public:
    ModelController();

    void setChosenInteractionMode(int chosenInteractionMode);

    int getChosenInteractionMode();

    int getChosenBuildingType();

    void setChosenBuildingType(int chosenBuildingType);

    int getApplicationWidth();

    void setApplicationWidth(int applicationWidth);

    int getApplicationHeight();

    void setApplicationHeight(int applicationHeight);

    unsigned int getSelectedUnitIndex();

    void setSelectedUnitIndex(unsigned int selectedUnitIndex);

    int getTempChosenMode();

    void setTempChosenMode(int tempChosenMode);

private:

    GameModel*gameModel;
};


#endif //THEHUTRIES_MODELCONTROLLER_H
