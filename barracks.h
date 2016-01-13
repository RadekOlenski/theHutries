#ifndef BARRACKS_H
#define BARRACKS_H

#include <SFML/Graphics.hpp>

#include <vector>
#include <string>

#include "building.h"
#include "gamebalance.h"
#include "textures.h"


class Barracks : public Building
{
public:
    Barracks(sf::RenderWindow* hutrieApplication, std::vector<Unit*> unitsFromGame);

    void updateStatus();

    bool getMakeWarriorFlag();

    void setMakeWarriorFlag(bool makeWarriorFlag);

    bool getMakeArcherFlag();

    void setMakeArcherFlag(bool makeArcherFlag);

    void buttonAction();

    void showButtons();

    void deactivateButtons();

    int getWarriorTrainingTime() { return warriorTrainingTime; };

    int getArcherTrainingTime() { return archerTrainingTime; };

    void setTrainingWarriorFlag(bool trainingWarrior) { this->trainingWarrior = trainingWarrior; };

    bool getTrainingWarriorFlag() { return trainingWarrior; };

    void setTrainingArcherFlag(bool trainingArcher) { this->trainingArcher = trainingArcher; };

    bool getTrainingArcherFlag() { return trainingArcher; };

    void setFirstCheckFlag(bool firstCheck) { this->firstCheck = firstCheck; };

    bool getFirstCheckFlag() { return firstCheck; };

    void setSoldiersCosts();

    void updateTrainingClock(int fullTime);

    void updateConstructionClock(int fullTime);

    float getElapsedConstructionTime() { return constructionTimeClock.getElapsedTime().asSeconds(); };

    bool getBuildingConstructedFlag() { return buildingConstructed; };

    void setBuildingConstructedFlag(bool buildingConstructed) { this->buildingConstructed = buildingConstructed; };

    void setEnoughGoodsForCreation(bool enoughGoodsForCreation) { this->enoughGoodsForCreation = enoughGoodsForCreation; };

    bool getEnoughGoodsForCreation() { return enoughGoodsForCreation; };

    float getConstructionTime() { return constructionTime; };

    sf::Clock trainingClock;

    void setConstructedBuildingSound();

private:

    GUIButton createWarriorButton;
    GUIText textWarrior;
    GUIButton createArcherButton;
    GUIText textArcher;
    GUIButton goldArcher;
    GUIText tGoldArcher;
    GUIButton goldWarrior;
    GUIText tGoldWarrior;
    GUIText trainHutries;
    bool makeWarriorFlag;
    bool makeArcherFlag;
    bool trainingWarrior;
    bool trainingArcher;
    bool firstCheck;
    bool buildingConstructed;
    bool enoughGoodsForCreation;

    const int warriorTrainingTime = GameBalance::warriorTrainingTime;
    const int archerTrainingTime = GameBalance::archerTrainingTime;

    unsigned int leftTrainingTime;
    unsigned int leftConstructionTime;

    const float constructionTime = GameBalance::barracksConstructionTime;
    sf::Clock constructionTimeClock;
};

#endif // BARRACKS_H
