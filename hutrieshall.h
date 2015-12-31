#ifndef HUTRIESHALL_H
#define HUTRIESHALL_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

#include "building.h"
#include "guibutton.h"
#include "guitext.h"

class HutriesHall : public Building
{
public:

    HutriesHall(sf::RenderWindow *hutrieApplication, std::vector<Unit*> unitsFromGame, std::string pathName);

    void updateStatus();

    void showButtons();

    void deactivateButtons();

    void buttonAction();

    bool getMakeWorkerFlag() { return makeWorkerFlag; };

    bool getMakeCarrierFlag() { return makeCarrierFlag; };

    void setMakeWorkerFlag(bool make) { this->makeWorkerFlag = make; };

    void setMakeCarrierFlag(bool make) { this->makeCarrierFlag = make; };

private:

    GUIButton createWorkerButton;
    GUIText tWorker;
    GUIButton createCarrierButton;
    GUIText tCarrier;
    bool makeWorkerFlag;
    bool makeCarrierFlag;


};

#endif // HUTRIESHALL_H
