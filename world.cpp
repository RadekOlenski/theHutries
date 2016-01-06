#include <cstdlib>
#include <iostream>

#include "world.h"
#include "hutrieshall.h"

World::World(sf::RenderWindow*hutrieApplication, int applicationWidth, int applicationHeight, int unitRectangleSize)
        : lastClickedUnit(NULL)
{
    this->hutrieApplication = hutrieApplication;
    availableSlots = 10;                            //wartosc startowa bez zadnej rezydencji
    availableGoods.setProduct(1,10);                //poczatkowe wartosci surowcow
    availableGoods.setProduct(2,10);
    availableGoods.setProduct(3,10);
    availableGoods.setProduct(4,10);

    /////////////////////////// HOW MANY RECTANGLES IN X AND Y DIRECTION//////////////////////////////////////////////////////

    horizontalUnitsCounter = applicationWidth / unitRectangleSize;
    verticalUnitsCounter = applicationHeight / unitRectangleSize;

    /////////////////////////// CREATING GRID OF UNITS//////////////////////////////////////////////////////

    sf::Vector2f position(0, 0);
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

    //       for (int i = 0; i < verticalUnitsCounter; i++)             spis indexow w siatce
    //       {
    //           for (int j=0; j < horizontalUnitsCounter; j++)
    //           {
    //               std::cout << j + (i*horizontalUnitsCounter) << " ";
    //           }
    //        std::cout << std::endl;
    //       }

    ////////////////////////////// ADDING TOWNHALL ///////////////////////////////////////////////////////////////////////////

    int unitIndex = 70;
    std::vector<Unit*> usedUnits;
    prepareUnits(unitIndex, 3, 3, &usedUnits);
    buildings.push_back(new HutriesHall(hutrieApplication, this, usedUnits, "sprites/buildings/castle.png"));
    buildings.back()->placeOnMap();
    /////////////////////////// ADDING ENVIRONMENT /////////////////////////////////////////////////////////////////

    int trees = 0;
    try
    {
        for (int i = 0; i < 4; i++)
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
            environment.push_back(new Environment(hutrieApplication, usedUnits, "sprites/environment/trees.png"));
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

void World::prepareUnits(int unitIndex, int height, int width, std::vector<Unit*>*usedUnits)
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
}

void World::increaseAvailableSlots(int addedSlotsNumber)
{
    this->availableSlots += addedSlotsNumber;
    std::cout << "dostepne miejsca:" << this->availableSlots << std::endl;

}
