//
// Created by radek on 29.12.2015.
//

#include "mouse.h"

void Mouse::leftClickActions()
{
/*
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && clickingClock.getElapsedTime().asSeconds() > 0.5)
    {
        if (sf::Mouse::getPosition(hutrieApplication).x <
            applicationWidth)         //jesli klikniecie w obrebie mapy
        {

//////////////////////////////////////////STOP HIGHLIGHT LAST CLICKED UNIT///////////////////////////////////////////////////////////

            guiEndHighlightUnit();

///////////////////////////////////////////////////CHOOSING RIGHT UNIT///////////////////////////////////////////////////////////

            unsigned int unitIndex = 70;

            mouseSelectUnit(unitIndex);

//////////////////////////////////////////////////////////LEFT MOUSE MAP ACTIONS/////////////////////////////////////////////////////////////////////////

            mouseMapActions(unitIndex);

////////////////////////////BUTTONS ACTIONS///////////////////////////////////////////////////////////////////////////////////
        }
        else if (gui.buildButton.checkBounds())
        {
            chosenMode = InteractionMode::BUILDMODE;
            clickSound();
        }
        else if (gui.hutrieButton.checkBounds())
        {
            chosenMode = InteractionMode::HUTRIEINFO;
            clickSound();
        }
        else if (gui.sawmill.checkBounds() && gui.sawmill.isActive())
        {
            buildingType = BuildingType::SAWMILL;
            clickSound();
        }
        else if (gui.stonecutter.checkBounds() && gui.stonecutter.isActive())
        {
            buildingType = BuildingType::STONECUTTERHUT;
            clickSound();
        }
        else if (gui.barracks.checkBounds() && gui.barracks.isActive())
        {
            buildingType = BuildingType::BARRACKS;
            clickSound();
        }
        else if (gui.residence.checkBounds() && gui.residence.isActive())
        {
            buildingType = BuildingType::RESIDENCE;
            clickSound();
        }
        else if (gui.goldmine.checkBounds() && gui.goldmine.isActive())
        {
            buildingType = BuildingType::GOLDMINE;
            clickSound();
        }
        else if (gui.farm.checkBounds() && gui.farm.isActive())
        {
            buildingType = BuildingType::FARM;
            clickSound();
        }
        else if (world.lastClickedUnit) { world.lastClickedUnit->getMapObject()->buttonAction(); }

////////////////////////////RESTART CLOCK WHICH FORBIDS MULTICLICKING///////////////////////////////////////////////////////////////////////////////////

        clickingClock.restart();
    }
    updateClock();
*/
}
