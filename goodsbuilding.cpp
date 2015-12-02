#include "goodsbuilding.h"
#include <sstream>
#include <cstdlib>

GoodsBuilding::GoodsBuilding(sf::RenderWindow *hutrieApplication, std::vector <Unit*> unitsFromGame, std::string pathName, int buildingType) : Building(hutrieApplication,unitsFromGame, pathName, buildingType)
{

}

void GoodsBuilding::showStatus()
{
    std::ostringstream desc;
    desc << "Capacity: " << (rand()%5)+1 << " workers\nWorkers: " << (rand()%5)+1 << "\nProducts in store: " << (rand()%5)+1;
    description.text.setString (desc.str() );
}
