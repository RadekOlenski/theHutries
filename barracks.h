#ifndef BARRACKS_H
#define BARRACKS_H

#include <SFML/Graphics.hpp>

#include <vector>
#include <string>

#include "building.h"
#include "gamebalance.h"


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

    void setFirstCheckFlag(bool firstCheck) { this->firstCheck = firstCheck; };

    bool getFirstCheckFlag() { return firstCheck; };

    void setSoldiersCosts();

    void updateClock(int fulltime );


private:
    GUIButton createWarriorButton;
    GUIText textWarrior;
    GUIButton createArcherButton;
    GUIText textArcher;
    GUIButton goldArcher;
    GUIText tgoldArcher;
    GUIButton goldWarrior;
    GUIText tgoldWarrior;
    bool makeWarriorFlag;
    bool makeArcherFlag;
    bool trainingWarrior;
    bool trainingArcher;
    bool firstCheck;

    const int warriorTrainingTime = GameBalance::warriorTrainingTime;
    const int archerTrainingTime = GameBalance::archerTrainingTime;

    unsigned int leftTrainingTime;

};

#endif // BARRACKS_H
