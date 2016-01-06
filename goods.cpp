#include "goods.h"

Goods::Goods() : wood(0), food(0), gold (0), stone (0)
{

}

Goods::Goods(unsigned int wood, unsigned int food, unsigned int gold, unsigned int stone) : wood(wood), food(food), gold (gold), stone (stone)
{

}

void Goods::setProduct(unsigned int choice, int howMany)
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

Goods & Goods::operator +( Goods & goods )
{
     this->wood += goods.wood;
     this->stone += goods.stone;
     this->food += goods.food;
     this->gold += goods.gold;
     return *this;
}

bool Goods::isEmpty()
{
    return ( (wood == 0 && stone == 0 && food == 0 && gold == 0) ? true : false );
}

unsigned int Goods::whichProduct()
{
    if  (wood) return 1;
    else if (stone) return 2;
    else if (gold)  return 4;
    else if (food)  return 3;
    else return 0;
}
