#include "hutrieshall.h"

#include <cstdlib>
#include <sstream>
#include <iostream>

HutriesHall::HutriesHall(sf::RenderWindow *hutrieApplication, std::vector<Unit*> unitsFromGame, std::string pathName)
        : Building(hutrieApplication, unitsFromGame, pathName),
        createCarrierButton(1024 + 40, 500, hutrieApplication, 150, 45),
        createWorker(1024 + 40, 560, hutrieApplication, 150, 45),
        tCarrier(1024 + 60, 510, 20, "Create Carrier"),
        tWorker(1024 + 70, 570, 20, "Create Worker")
{
    title.text.setString("Hutries Hall:");

    sprite.setScale(0.45, 0.5);
    sprite.setOrigin(30, 128);

    sound.openFromFile("audio/castle.wav");
    setSoundVolume(100);

    makeWorkerFlag = false;
    makeCarrierFlag = false;
}

void HutriesHall::updateStatus()
{
    std::ostringstream desc;
    desc << "Available carriers: " << rand() % 20 << "\nAvailable workers: " << rand() % 20 <<
    "\nAvailable warriors: " << rand() % 20 << "\nAvailable archers: " << rand() % 20;
    description.text.setString(desc.str());
}

void HutriesHall::showButtons()
{
    createWorker.setActive(true);
    createCarrierButton.setActive(true);
    hutrieApplication->draw(createWorker.button);
    hutrieApplication->draw(createCarrierButton.button);
    hutrieApplication->draw(tWorker.text);
    hutrieApplication->draw(tCarrier.text);

}

void HutriesHall::deactivateButtons()
{
    createCarrierButton.setActive(false);
    createWorker.setActive(false);
}

void HutriesHall::buttonAction()
{
    if (createWorker.checkBounds() && createWorker.isActive())
    {
        std::cout << "Create Worker!!!!" << std::endl;
        makeWorkerFlag = true;
    }
    if (createCarrierButton.checkBounds() && createCarrierButton.isActive())
    {
        std::cout << "Create Carrier!!!!" << std::endl;
        makeCarrierFlag = true;
    }
}
