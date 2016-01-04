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

    HutriesHall(sf::RenderWindow *hutrieApplication, World *world, std::vector<Unit*> unitsFromGame, std::string pathName);

    void updateStatus();

    void showButtons();

    void deactivateButtons();

    void buttonAction();

    bool getMakeWorkerFlag() { return makeWorkerFlag; };

    bool getMakeCarrierFlag() { return makeCarrierFlag; };

    void setMakeWorkerFlag(bool make) { this->makeWorkerFlag = make; };

    void setMakeCarrierFlag(bool make) { this->makeCarrierFlag = make; };

private:

    unsigned int getAvailableWorkers();
    unsigned int getAvailableCarriers();
    GUIButton createWorkerButton;
    GUIText tWorker;
    GUIButton createCarrierButton;
    GUIText tCarrier;
    bool makeWorkerFlag;
    bool makeCarrierFlag;
    World *world;


};

#endif // HUTRIESHALL_H
