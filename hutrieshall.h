#ifndef HUTRIESHALL_H
#define HUTRIESHALL_H

#include <SFML/Graphics.hpp>

#include <vector>
#include <string>

#include "building.h"
#include "guibutton.h"
#include "guitext.h"
#include "world.h"

class HutriesHall : public Building
{
public:

    HutriesHall(sf::RenderWindow *hutrieApplication, World *world, std::vector<Unit *> unitsFromGame,
                std::string pathName);

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

    int getWorkerTrainingTime() { return workerTrainingTime; };

    int getCarrierTrainingTime() { return carrierTrainingTime; };

    sf::Clock trainingClock;

private:

    unsigned int getAvailableWorkers();

    unsigned int getAvailableCarriers();

    GUIButton createWorkerButton;
    GUIText tWorker;
    GUIButton createCarrierButton;
    GUIText tCarrier;
    bool makeWorkerFlag;
    bool makeCarrierFlag;
    bool trainingWorker;
    bool trainingCarrier;

    const int workerTrainingTime = 5;
    const int carrierTrainingTime = 3;

    World *world;
};

#endif // HUTRIESHALL_H
