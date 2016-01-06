#ifndef GAMEBALANCE_H
#define GAMEBALANCE_H


#include "goods.h"

class GameBalance
{
    public:

    //////////////////////////////////  COSTS ////////////////////////////////////////////////////

    static  Goods sawmillCost;
    static  Goods stonecutterhutCost;
    static  Goods barracksCost;
    static  Goods residenceCost;
    static  Goods goldmineCost;
    static  Goods farmCost;

    static  Goods archerCost;
    static  Goods warriorCost;

    //////////////////////////////////  GOODS   ///////////////////////////////////////////////////

    const static unsigned int startingWood = 10;
    const static unsigned int startingStone = 10;
    const static unsigned int startingFood = 10;
    const static unsigned int startingGold = 100;

    //////////////////////////////////  GOOODBUILDINGS ////////////////////////////////////////////

    const static int maxProductsInStore = 5;
    const static int maxWorkers = 3;
    const static int productCraftingTime = 15;

    //////////////////////////////////  TRAINING    ///////////////////////////////////////////////

    const static int carrierTrainingTime = 0.3;
    const static int workerTrainingTime = 0.5;
    const static int archerTrainingTime = 3;
    const static int warriorTrainingTime = 5;

    //////////////////////////////////  CLOCKS    /////////////////////////////////////////////////

    const static int gameTime = 2 * 60;

    ///////////////////////////////////////////////////////////////////////////////////////////////
};

#endif // GAMEBALANCE_H
