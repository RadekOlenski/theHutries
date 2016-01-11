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

    float getHorizontalScreenZoom() { return horizontalScreenZoom; };

    void setHorizontalScreenZoom(float horizontalScreenZoom) { this->horizontalScreenZoom = horizontalScreenZoom; };

    float getVerticalScreenZoom() { return verticalScreenZoom; };

    void setVerticalScreenZoom(float verticalScreenZoom) { this->verticalScreenZoom = verticalScreenZoom; };

private:

    int chosenInteractionMode;

    int tempChosenMode;

    int chosenBuildingType;

    int applicationWidth;

    int applicationHeight;

    unsigned int selectedUnitIndex;

    float horizontalScreenZoom;

    float verticalScreenZoom;
};


#endif //THEHUTRIES_GAMEMODEL_H
