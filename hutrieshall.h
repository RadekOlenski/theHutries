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

    bool getTrainingWorkerFlag() { return trainingWorker; };

    bool getTrainingCarrierFlag() { return trainingCarrier; };

    void setTrainingCarrierFlag(bool trainingCarrier) { this->trainingCarrier = trainingCarrier; };

    void setTrainingWorkerFlag(bool trainingWorker) { this->trainingWorker = trainingWorker; };

    float getWorkerTrainingTime() { return workerTrainingTime; };

    float getCarrierTrainingTime() { return carrierTrainingTime; };

    void getHutriesCosts();

    void setFirstCheckFlag(bool firstCheck) { this->firstCheck = firstCheck; };

    bool getFirstCheckFlag() { return firstCheck; };

    void setEnoughGoodsForCreation(bool enoughGoodsForCreation) { this->enoughGoodsForCreation = enoughGoodsForCreation; };

    bool getEnoughGoodsForCreation() { return enoughGoodsForCreation; };

private:

    unsigned int getAvailableWorkers();

    unsigned int getAvailableCarriers();

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
    bool trainingWorker;
    bool trainingCarrier;
    bool enoughGoodsForCreation;

    World* world;
};

#endif // HUTRIESHALL_H
