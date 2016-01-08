#include "hutrieshall.h"
#include "sound.h"

#include <cstdlib>
#include <sstream>
#include <iostream>

HutriesHall::HutriesHall(sf::RenderWindow *hutrieApplication, World *world, std::vector<Unit*> unitsFromGame, std::string pathName)
        : Building(hutrieApplication, unitsFromGame, pathName),
        //createCarrierButton(1024 + 40, 500, hutrieApplication, 150, 45),
        //createWorkerButton(1024 + 40, 560, hutrieApplication, 150, 45),

          trainHutries(1024 + 65, 490, 25, "Train Hutries:"),
          createWorkerButton(1024 + 30, 520, hutrieApplication, Textures::workerDown, 90, 90),
          tWorker(1024 + 50, 605, 20, "Worker"),

          createCarrierButton(1024 + 140, 520, hutrieApplication, Textures::carrierDown, 90, 90),
          tCarrier(1024 + 160, 605, 20, "Carrier")

          //tCarrier(1024 + 60, 510, 20, "Create Carrier"),
      //  tWorker(1024 + 70, 570, 20, "Create Worker")
{
    this->world = world;
    title.text.setString("Hutries Hall:");

    sprite.setScale(0.45, 0.5);
    sprite.setOrigin(30, 128);

    sound.openFromFile(Sound::hutrieshall);
    setSoundVolume(50);

    makeWorkerFlag = false;
    makeCarrierFlag = false;

    trainingWorker = false;
    trainingCarrier = false;

    leftTrainingTime = 0;
    doorIndex = 6;
}

void HutriesHall::updateStatus()
{
    std::ostringstream desc;
    desc << "Training finish in " <<  leftTrainingTime
    << " sec.\nWorkers during training: " << trainingWorker
    << "\nCarriers during training: " << trainingCarrier
    << "\nAvailable Workers: " << getAvailableWorkers()
    << "\nAvailable Carriers: " << getAvailableCarriers();
    description.text.setString (desc.str() );
}

void HutriesHall::showButtons()
{
    createWorkerButton.setActive(true);
    createCarrierButton.setActive(true);
    hutrieApplication->draw(trainHutries.text);
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
        Sound::click();
    }
    if (createCarrierButton.checkBounds() && createCarrierButton.isActive())
    {
        std::cout << "Create Carrier!!!!" << std::endl;
        makeCarrierFlag = true;
        Sound::click();
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

void HutriesHall::updateClock(int trainingTime)
{
    leftTrainingTime = trainingTime - trainingClock.getElapsedTime().asSeconds();
    if (leftTrainingTime < 0) leftTrainingTime = 0;
}
