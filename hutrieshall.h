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

        HutriesHall(sf::RenderWindow *hutrieApplication, std::vector <Unit*> unitsFromGame, std::string pathName, int buildingType = 0);
        void updateStatus();
        void showButtons();
        void deactivateButtons();
        void buttonAction();

        bool getMakeWorker() {return makeWorker;};
        bool getMakeCarrier() {return makeCarrier;};
        void setMakeWorker(bool make) {this->makeWorker = make;};
        void setMakeCarrier(bool make) {this->makeCarrier = make;};
    private:

        GUIButton createWorker;
        GUIText tWorker;
        GUIButton createCarrier;
        GUIText tCarrier;
        bool makeWorker;
        bool makeCarrier;

};

#endif // HUTRIESHALL_H
