#include <cstdlib>
#include <iostream>

#include "world.h"
#include "hutrieshall.h"
#include "forest.h"
#include "mountain.h"
#include "rocks.h"

World::World(sf::RenderWindow* hutrieApplication, int applicationWidth, int applicationHeight, int unitRectangleSize)
        : lastClickedUnit(NULL)
{
    this->hutrieApplication = hutrieApplication;
    availableSlots = GameBalance::startingHutrieSlots;;                            //wartosc startowa bez zadnej rezydencji
    availableGoods.setProduct(1, GameBalance::startingWood);                //poczatkowe wartosci surowcow
    availableGoods.setProduct(2, GameBalance::startingStone);
    availableGoods.setProduct(3, GameBalance::startingFood);
    availableGoods.setProduct(4, GameBalance::startingGold);

    /////////////////////////// HOW MANY RECTANGLES IN X AND Y DIRECTION//////////////////////////////////////////////////////

    horizontalUnitsCounter = applicationWidth / unitRectangleSize;
    verticalUnitsCounter = applicationHeight / unitRectangleSize;

    /////////////////////////// CREATING GRID OF UNITS//////////////////////////////////////////////////////

    sf::Vector2f position(0, 64);
    for (int j = 0; j < verticalUnitsCounter; j++)
    {
        for (int i = 0; i < horizontalUnitsCounter; i++)
        {
            units.push_back(new Unit(position, i + (j * horizontalUnitsCounter)));
            position.x += unitRectangleSize;
        }
        position.y += unitRectangleSize;
        position.x = 0;
    }

/*
    for (int i = 0; i < verticalUnitsCounter; i++)             //spis indexow w siatce
    {
        for (int j = 0; j < horizontalUnitsCounter; j++)
        {
            std::cout << j + (i * horizontalUnitsCounter) << " ";
        }
        std::cout << std::endl;
    }
*/
    createHutriesHall();
    createEnvironment();
}

void World::createHutriesHall()
{
    int unitIndex = 70;
    std::vector<Unit*> usedUnits;
    prepareUnits(unitIndex, 3, 3, &usedUnits);
    buildings.push_back(new HutriesHall(hutrieApplication, this, usedUnits));
    buildings.back()->placeOnMap();
}

void World::createEnvironment()
{
    createForest();
    createMountains();
    createRocks();
}

void World::prepareUnits(int unitIndex, int height, int width, std::vector<Unit*>* usedUnits)
{
    std::vector<int> field;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            field.push_back(unitIndex + j + (i * horizontalUnitsCounter));
        }
    }
    std::vector<int>::iterator it;
    for (it = field.begin(); it != field.end(); ++it)
    {
        usedUnits->push_back(units.at((unsigned int) *it));
    }
}

bool World::isFieldEmpty(std::vector<Unit*> &usedUnits)
{
    std::vector<Unit*>::iterator it;
    for (it = usedUnits.begin(); it != usedUnits.end(); ++it)
    {
        if (!((*it)->isEmpty())) return false;
    }
    return true;
}

unsigned int World::findSelectedUnitIndex()
{
    std::vector<Unit*>::iterator it;
    for (it = this->units.begin(); it != this->units.end(); ++it)
    {
        if ((*it)->field.getPosition().x <= sf::Mouse::getPosition(*hutrieApplication).x &&
            ((*it)->field.getPosition().x + (*it)->field.getSize().x) >=
            sf::Mouse::getPosition(*hutrieApplication).x &&
            (*it)->field.getPosition().y <= sf::Mouse::getPosition(*hutrieApplication).y &&
            ((*it)->field.getPosition().y + (*it)->field.getSize().y) >=
            sf::Mouse::getPosition(*hutrieApplication).y)
        {
            return (unsigned int) std::distance(this->units.begin(), it);
        }
    }
    return 0;
}

void World::increaseAvailableSlots(int addedSlotsNumber)
{
    this->availableSlots += addedSlotsNumber;
    std::cout << "dostepne miejsca:" << this->availableSlots << std::endl;
}

void World::createForest()
{
    std::vector<Unit*> usedUnits;
    int unitIndex;
    int trees = 0;
    try
    {
        for (int i = 0; i < 2; i++)
        {
            int d = 0;
            do
            {
                usedUnits.clear();
                unitIndex = (rand() % (horizontalUnitsCounter - 3)) +
                            ((rand() % (verticalUnitsCounter - 1)) * horizontalUnitsCounter);
                prepareUnits(unitIndex, 2, 3, &usedUnits);
                if (d > 1000) throw -1;
                else d++;
            }
            while (!(isFieldEmpty(usedUnits)));
            environment.push_back(new Forest(hutrieApplication, usedUnits, Textures::forest));
            this->forestsIndex.push_back(this->environment.size() - 1);
            trees = i;
            std::cout << "Las nr " << i << ", prob postawienia: " << d << std::endl;
        }
    }
    catch (int d)
    {
        std::cout << "Exception: " << d << ": Not enough space for object" << std::endl;
    }
    std::cout << "Ilosc drzew: " << trees << std::endl;
}

void World::createMountains()
{
    std::vector<Unit*> usedUnits;
    int unitIndex;
    try
    {
        for (int i = 0; i < 2; i++)
        {
            int d = 0;
            do
            {
                usedUnits.clear();
                unitIndex = (rand() % (horizontalUnitsCounter - 3)) +
                            ((rand() % (verticalUnitsCounter - 1)) * horizontalUnitsCounter);
                prepareUnits(unitIndex, 2, 2, &usedUnits);
                if (d > 1000) throw -1;
                else d++;
            }
            while (!(isFieldEmpty(usedUnits)));
            environment.push_back(new Mountain(hutrieApplication, usedUnits, Textures::mountain));
            this->mountainsIndex.push_back(this->environment.size() - 1);
            std::cout << "Gory nr " << i << ", prob postawienia: " << d << std::endl;
        }
    }
    catch (int d)
    {
        std::cout << "Exception: " << d << ": Not enough space for object" << std::endl;
    }
}

void World::createRocks()
{
    std::vector<Unit*> usedUnits;
    int unitIndex;
    try
    {
        for (int i = 0; i < 2; i++)
        {
            int d = 0;
            do
            {
                usedUnits.clear();
                unitIndex = (rand() % (horizontalUnitsCounter - 3)) +
                            ((rand() % (verticalUnitsCounter - 1)) * horizontalUnitsCounter);
                prepareUnits(unitIndex, 2, 3, &usedUnits);
                if (d > 1000) throw -1;
                else d++;
            }
            while (!(isFieldEmpty(usedUnits)));
            environment.push_back(new Rocks(hutrieApplication, usedUnits, Textures::rocks));
            this->rocksIndex.push_back(this->environment.size() - 1);
            std::cout << "Skaly nr " << i << ", prob postawienia: " << d << std::endl;
        }
    }
    catch (int d)
    {
        std::cout << "Exception: " << d << ": Not enough space for object" << std::endl;
    }
}

World::~World()
{

    std::vector<Hutrie*>::iterator ithutries;
    for (ithutries = hutries.begin(); ithutries != hutries.end(); ++ithutries)
    {
        (*ithutries)->hutrieThread.terminate();
    }
    std::cout << "Koniec Hutrie Threads" << std::endl;

    std::vector<Carrier*>::iterator itcarriers;
    for (itcarriers = carriers.begin(); itcarriers != carriers.end(); ++itcarriers) {
    delete (*itcarriers);
    }
    std::cout << "Koniec Carriers" << std::endl;

//    std::vector<Soldier*>::iterator itsoldiers;
//    for (itsoldiers = soldiers.begin(); itsoldiers != soldiers.end(); ++itsoldiers) {
//    delete (*itsoldiers);
//    }
//    std::cout << "Koniec Soldiers" << std::endl;

    std::vector<Warrior*>::iterator itwarriors;
    for (itwarriors = warriors.begin(); itwarriors != warriors.end(); ++itwarriors) {
    delete (*itwarriors);
    }
    std::cout << "Koniec Warriors" << std::endl;

    std::vector<Archer*>::iterator itarchers;
    for (itarchers = archers.begin(); itarchers != archers.end(); ++itarchers) {
    delete (*itarchers);
    }
    std::cout << "Koniec Archers" << std::endl;

    std::vector<Worker*>::iterator itworkers;
    for (itworkers = workers.begin(); itworkers != workers.end(); ++itworkers) {
    delete (*itworkers);
    }
    std::cout << "Koniec Workers" << std::endl;
//
//

//    for (ithutries = hutries.begin(); ithutries != hutries.end(); ++ithutries)
//    {
//        delete (*ithutries);
//    }
//    std::cout << "Koniec Hutrie" << std::endl;
    soldiers.clear();
    std::cout << "Koniec Soldiers" << std::endl;
    hutries.clear();
    std::cout << "Koniec Hutrie" << std::endl;

    std::vector<Building*>::iterator itbuildings;
    for (itbuildings = buildings.begin(); itbuildings != buildings.end(); ++itbuildings)
    {
        delete (*itbuildings);
    }
    std::cout << "Koniec Building" << std::endl;

    std::vector<Environment*>::iterator itenvironment;
    for (itenvironment = environment.begin(); itenvironment != environment.end(); ++itenvironment)
    {
        delete (*itenvironment);
    }
    std::cout << "Koniec Enviroment" << std::endl;

     std::vector<Unit*>::iterator itunits;
    for (itunits = units.begin(); itunits != units.end(); ++itunits) {
    delete (*itunits);
    }
    std::cout << "Koniec Unit" << std::endl;

    barracksIndex.clear();
    goodsBuildingIndex.clear();
    forestsIndex.clear();
    rocksIndex.clear();
    mountainsIndex.clear();
}
