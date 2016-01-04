#ifndef BARRACKS_H
#define BARRACKS_H

#include <SFML/Graphics.hpp>

#include <vector>
#include <string>

#include "building.h"


class Barracks : public Building
{
public:
    Barracks(sf::RenderWindow *hutrieApplication, std::vector<Unit *> unitsFromGame, std::string pathName);

    void updateStatus();

    bool getMakeWarriorFlag();

    void setMakeWarriorFlag(bool makeWarriorFlag);

    bool getMakeArcherFlag();

    void setMakeArcherFlag(bool makeArcherFlag);

    void buttonAction();

    void showButtons();

    void deactivateButtons();

    sf::Clock trainingClock;

    int getWarriorTrainingTime() { return warriorTrainingTime; };

    int getArcherTrainingTime() { return archerTrainingTime; };

    void setTrainingWarriorFlag(bool trainingWarrior) { this->trainingWarrior = trainingWarrior; };

    bool getTrainingWarriorFlag() { return trainingWarrior; };

    void setTrainingArcherFlag(bool trainingArcher) { this->trainingArcher = trainingArcher; };

    bool getTrainingArcherFlag() { return trainingArcher; };

private:
    GUIButton createWarriorButton;
    GUIText textWarrior;
    GUIButton createArcherButton;
    GUIText textArcher;
    bool makeWarriorFlag;
    bool makeArcherFlag;
    bool trainingWarrior;
    bool trainingArcher;

    const int warriorTrainingTime = 5;
    const int archerTrainingTime = 3;
};

#endif // BARRACKS_H
