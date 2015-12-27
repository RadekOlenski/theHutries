#include "goods.h"

Goods::Goods() : wood(0), food(0), gold (0), stone (0)
{

}

Goods::Goods(int wood, int food, int gold, int stone) : wood(wood), food(food), gold (gold), stone ()
{

}

void Goods::setProduct(int choice, int howMany)
{
    switch(choice)
    {
        case 1:
            wood += howMany;
            break;
        case 2:
            stone += howMany;
            break;
        case 3:
            food += howMany;

            break;
        case 4:
            gold += howMany;
            break;
        case 5:
            wood = 0;
            stone = 0;
            food = 0;
            gold = 0;
            break;
    };
}

Goods Goods::operator +( const Goods & goods )
{
    return Goods( this->wood + goods.wood,
                  this->stone + goods.stone,
                  this->food + goods.food,
                  this->gold + goods.gold );
}

bool Goods::isEmpty()
{
    return ( (wood == 0 && stone == 0 && food == 0 && gold == 0) ? true : false );
}
