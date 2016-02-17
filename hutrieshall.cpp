#include "hutrieshall.h"
#include "sound.h"

#include <sstream>
#include <iostream>

HutriesHall::HutriesHall(sf::RenderWindow* hutrieApplication, World* world, std::vector<Unit*> unitsFromGame,
                         std::string pathName)
        : Building(hutrieApplication, unitsFromGame, pathName),
        //createCarrierButton(1024 + 40, 500, hutrieApplication, 150, 45),
        //createWorkerButton(1024 + 40, 560, hutrieApplication, 150, 45),

          trainHutries(1024 + 65, 490, 25, "Train Hutries:"),
          createWorkerButton(1024 + 30, 520, hutrieApplication, Textures::workerDown, 90, 90),
          tWorker(1024 + 40, 605, 20, "Worker"),

          createCarrierButton(1024 + 140, 520, hutrieApplication, Textures::carrierDown, 90, 90),
          tCarrier(1024 + 150, 605, 20, "Carrier"),

          foodWorker(1024 + 95, 605, hutrieApplication, Textures::food, 25, 25),
          tfoodWorker(1024 + 120, 605, 20, "3"),
          foodCarrier(1024 + 205, 605, hutrieApplication, Textures::food, 25, 25),
          tfoodCarrier(1024 + 230, 605, 20, "3")
{
    this->world = world;
    title.text.setString("Hutries Hall:");

    sprite.setScale(0.45, 0.5);
    sprite.setOrigin(30, 128);

    sound.openFromFile(Sound::hutrieshall);
    setSoundVolume(50);

    makeWorkerFlag = false;
    makeCarrierFlag = false;

    trainingWorker = 0;
    trainingCarrier = 0;

    buildingConstructed = true;

    firstCheck = true;
    enoughGoodsForCreation = false;
    leftTrainingTime = 0;
    doorIndex = 6;
    frameCounter = 0;
    animationCounter = 0;
    workerTrainingTime = GameBalance::workerTrainingTime;
    carrierTrainingTime = GameBalance::carrierTrainingTime;
    getHutriesCosts();

    deactivateConstructionButtons();
    constructButton.setActive(false);
}

void HutriesHall::updateStatus()
{
    std::ostringstream desc;
    desc << "Training finish in " << ceil(leftTrainingTime)
    << " sec.\nWorkers during training: " << trainingWorker
    << "\nCarriers during training: " << trainingCarrier
    << "\nAvailable Workers: " << getAvailableWorkers()
    << "\nAvailable Carriers: " << getAvailableCarriers();
    description.text.setString(desc.str());
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
    hutrieApplication->draw(foodWorker.button);
    hutrieApplication->draw(foodCarrier.button);
    hutrieApplication->draw(tfoodWorker.text);
    hutrieApplication->draw(tfoodCarrier.text);
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
        Sound::purchaseSound();
    }
    if (createCarrierButton.checkBounds() && createCarrierButton.isActive())
    {
        std::cout << "Create Carrier!!!!" << std::endl;
        makeCarrierFlag = true;
        Sound::purchaseSound();
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
            workersCounter++;
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
            carriersCounter++;
        }
    }
    return carriersCounter;
}

void HutriesHall::getHutriesCosts()
{
    std::ostringstream desc;
    desc << GameBalance::workerCost.getFood();
    tfoodWorker.text.setString(desc.str());
    std::ostringstream desc1;
    desc1 << GameBalance::carrierCost.getFood();
    tfoodCarrier.text.setString(desc1.str());
}

void HutriesHall::highlightButton()
{
    if (createWorkerButton.checkBounds())
        tWorker.highlight();
    else
    {
        tWorker.endHighlight();
        createWorkerButton.changeTexture(Textures::workerMoveDown1);
    }

    if (createWorkerButton.checkBounds())
        tfoodWorker.highlight();
    else tfoodWorker.endHighlight();

    if (createCarrierButton.checkBounds())
        tCarrier.highlight();
    else
    {
        tCarrier.endHighlight();
        createCarrierButton.changeTexture(Textures::carrierEmptyMoveDown1);
    }

    if (createCarrierButton.checkBounds())
        tfoodCarrier.highlight();
    else tfoodCarrier.endHighlight();

    animateButton();
}

void HutriesHall::animateButton()
{
    if (frameCounter == 0)
    {
        if (createCarrierButton.checkBounds())
        {
            switch (animationCounter)
            {
                case 0:
                    createCarrierButton.changeTexture(Textures::carrierEmptyMoveDown1);
                    animationCounter++;
                    break;
                case 1:
                    createCarrierButton.changeTexture(Textures::carrierEmptyMoveDown2);
                    animationCounter++;
                    break;
                case 2:
                    createCarrierButton.changeTexture(Textures::carrierEmptyMoveDown3);
                    animationCounter++;
                    break;
                case 3:
                    createCarrierButton.changeTexture(Textures::carrierEmptyMoveDown4);
                    animationCounter++;
                    break;
                case 4:
                    createCarrierButton.changeTexture(Textures::carrierEmptyMoveDown5);
                    animationCounter++;
                    break;
                case 5:
                    createCarrierButton.changeTexture(Textures::carrierEmptyMoveDown6);
                    animationCounter++;
                    break;
                case 6:
                    createCarrierButton.changeTexture(Textures::carrierEmptyMoveDown7);
                    animationCounter++;
                    break;
                case 7:
                    createCarrierButton.changeTexture(Textures::carrierEmptyMoveDown8);
                    animationCounter = 0;
                    break;
                default:
                    break;
            }
        }
        else if (createWorkerButton.checkBounds())
        {
            switch (animationCounter)
            {
                case 0:
                    createWorkerButton.changeTexture(Textures::workerMoveDown1);
                    animationCounter++;
                    break;
                case 1:
                    createWorkerButton.changeTexture(Textures::workerMoveDown2);
                    animationCounter++;
                    break;
                case 2:
                    createWorkerButton.changeTexture(Textures::workerMoveDown3);
                    animationCounter++;
                    break;
                case 3:
                    createWorkerButton.changeTexture(Textures::workerMoveDown4);
                    animationCounter++;
                    break;
                case 4:
                    createWorkerButton.changeTexture(Textures::workerMoveDown5);
                    animationCounter++;
                    break;
                case 5:
                    createWorkerButton.changeTexture(Textures::workerMoveDown6);
                    animationCounter++;
                    break;
                case 6:
                    createWorkerButton.changeTexture(Textures::workerMoveDown7);
                    animationCounter++;
                    break;
                case 7:
                    createWorkerButton.changeTexture(Textures::workerMoveDown8);
                    animationCounter = 0;
                    break;
                default:
                    break;
            }
        }
        else animationCounter = 0;
    }
    frameCounter++;
    if(frameCounter > 25)
        frameCounter = 0;
}
