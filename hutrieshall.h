#ifndef HUTRIESHALL_H
#define HUTRIESHALL_H

#include <SFML/Graphics.hpp>

#include <vector>
#include <string>

#include "building.h"
#include "guibutton.h"
#include "guitext.h"
#include "world.h"
#include "gamebalance.h"
#include "textures.h"

class HutriesHall : public Building
{
public:

    HutriesHall(sf::RenderWindow* hutrieApplication, World* world, std::vector<Unit*> unitsFromGame,
                std::string pathName = Textures::hutriesHall);

    void updateStatus();

    void showButtons();

    void deactivateButtons();

    void buttonAction();

    bool getMakeWorkerFlag() { return makeWorkerFlag; };

    bool getMakeCarrierFlag() { return makeCarrierFlag; };

    void setMakeWorkerFlag(bool make) { this->makeWorkerFlag = make; };

    void setMakeCarrierFlag(bool make) { this->makeCarrierFlag = make; };

    unsigned int getTrainingWorkerCounter() { return trainingWorker; };

    unsigned int getTrainingCarrierCounter() { return trainingCarrier; };

    void decreaseTrainingCarrierCounter( ) { this->trainingCarrier--; };

    void decreaseTrainingWorkerCounter( ) { this->trainingWorker--; };

    void increaseTrainingCarrierCounter( ) { this->trainingCarrier++; };

    void increaseTrainingWorkerCounter( ) { this->trainingWorker++; };

    float getWorkerTrainingTime() { return workerTrainingTime; };

    float getCarrierTrainingTime() { return carrierTrainingTime; };

    void getHutriesCosts();

    void setFirstCheckFlag(bool firstCheck) { this->firstCheck = firstCheck; };

    bool getFirstCheckFlag() { return firstCheck; };

    void setEnoughGoodsForCreation(bool enoughGoodsForCreation) { this->enoughGoodsForCreation = enoughGoodsForCreation; };

    bool getEnoughGoodsForCreation() { return enoughGoodsForCreation; };

    void highlightButton();

    void animateButton();

private:

    unsigned int getAvailableWorkers();

    unsigned int getAvailableCarriers();

    int animationCounter;

    int frameCounter;

    GUIButton createWorkerButton;
    GUIText tWorker;
    GUIButton createCarrierButton;
    GUIText tCarrier;
    GUIText trainHutries;
    GUIButton foodWorker;
    GUIText tfoodWorker;
    GUIButton foodCarrier;
    GUIText tfoodCarrier;
    bool firstCheck;
    bool makeWorkerFlag;
    bool makeCarrierFlag;
    unsigned int trainingWorker;
    unsigned int trainingCarrier;
    bool enoughGoodsForCreation;

    World* world;
};

#endif // HUTRIESHALL_H
