#include "hutrieshall.h"
#include "sound.h"

#include <cstdlib>
#include <sstream>
#include <iostream>

HutriesHall::HutriesHall(sf::RenderWindow *hutrieApplication, World *world, std::vector<Unit*> unitsFromGame, std::string pathName)
        : Building(hutrieApplication, unitsFromGame, pathName),
        createCarrierButton(1024 + 40, 500, hutrieApplication, 150, 45),
        createWorkerButton(1024 + 40, 560, hutrieApplication, 150, 45),
        tCarrier(1024 + 60, 510, 20, "Create Carrier"),
        tWorker(1024 + 70, 570, 20, "Create Worker")
{
    this->world = world;
    title.text.setString("Hutries Hall:");

    sprite.setScale(0.45, 0.5);
    sprite.setOrigin(30, 128);

    sound.openFromFile(Sound::hutrieshall);
    setSoundVolume(100);

    makeWorkerFlag = false;
    makeCarrierFlag = false;

    trainingWorker = false;
    trainingCarrier = false;
}

void HutriesHall::updateStatus()
{
    std::ostringstream desc;
    desc << "Available carriers: " << getAvailableCarriers() << "\nAvailable workers: " << getAvailableWorkers() <<
    "\nAvailable warriors: " << rand() % 20 << "\nAvailable archers: " << rand() % 20;
    description.text.setString(desc.str());
}

void HutriesHall::showButtons()
{
    createWorkerButton.setActive(true);
    createCarrierButton.setActive(true);
    hutrieApplication->draw(createWorkerButton.button);
    hutrieApplication->draw(createCarrierButton.button);
    hutrieApplication->draw(tWorker.text);
    hutrieApplication->draw(tCarrier.text);

}

void HutriesHall::deactivateButtons()
{
    createCarrierButton.setActive(false);
    createWorkerButton.setActive(false);
}

void HutriesHall::buttonAction()
{
    if (createWorkerButton.checkBounds() && createWorkerButton.isActive())
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

unsigned int HutriesHall::getAvailableWorkers()
{
    std::vector<Worker*>::iterator itw;
    unsigned int workersCounter = 0;
    for (itw = world->workers.begin(); itw != world->workers.end(); ++itw)
    {
        if (!((*itw)->isBusy()))
        {
            workersCounter ++;
        }
    }
    return workersCounter;
}

unsigned int HutriesHall::getAvailableCarriers()
{
    std::vector<Carrier*>::iterator itc;
    unsigned int carriersCounter = 0;
    for (itc = world->carriers.begin(); itc != world->carriers.end(); ++itc)
    {
        if (!((*itc)->isBusy()))
        {
            carriersCounter ++;
        }
    }
    return carriersCounter;
}

