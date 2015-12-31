#ifndef BARRACKS_H
#define BARRACKS_H

#include <SFML/Graphics.hpp>

#include <vector>
#include <string>

#include "building.h"


class Barracks : public Building
{
    public:
        Barracks(sf::RenderWindow *hutrieApplication, std::vector <Unit*> unitsFromGame, std::string pathName);
        void updateStatus();

        bool getMakeWarriorFlag();

        void setMakeWarriorFlag(bool makeWarriorFlag);

        bool getMakeArcherFlag();

        void setMakeArcherFlag(bool makeArcherFlag);

        void buttonAction();

        void showButtons();

        void deactivateButtons();

private:
        GUIButton createWarriorButton;
        GUIText textWarrior;
        GUIButton createArcherButton;
        GUIText textArcher;
        bool makeWarriorFlag;
        bool makeArcherFlag;
};

#endif // BARRACKS_H
