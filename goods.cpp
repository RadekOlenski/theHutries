#include "goods.h"

Goods::Goods() : wood(0), food(0), gold (0), stone (0)
{

}

void Goods::addProduct(int choice, int howMany)
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
    };
}
