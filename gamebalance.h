#ifndef GAMEBALANCE_H
#define GAMEBALANCE_H


#include "goods.h"

class GameBalance
{
    public:

    static double screenZoom;

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
    const static int carrierLading = 3;

    //////////////////////////////////  TRAINING    ///////////////////////////////////////////////

    const static double carrierTrainingTime;
    const static double workerTrainingTime;
    const static int archerTrainingTime = 3;
    const static int warriorTrainingTime = 5;

    //////////////////////////////////  CLOCKS    /////////////////////////////////////////////////

    const static int gameTime = 2 * 60;

    /////////////////////////////////   FINAL RESULT    ///////////////////////////////////////////

    const static double warriorQuotient;
    const static double archerQuotient;
    const static double winResult;

    ///////////////////////////////////////////////////////////////////////////////////////////////
};

#endif // GAMEBALANCE_H
