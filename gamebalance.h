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
    const static unsigned int startingGold = 10;

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

    //////////////////////////////////  CONSTRUCTION TIME    //////////////////////////////////////

    const static float barracksConstructionTime;
    const static float residenceConstructionTime;
    const static float sawmillConstructionTime;
    const static float stonecutterHutConstructionTime;
    const static float farmConstructionTime;
    const static float goldmineConstructionTime;

    //////////////////////////////////  CLOCKS    /////////////////////////////////////////////////

    const static int gameTime = 2 * 60;

    /////////////////////////////////   FINAL RESULT    ///////////////////////////////////////////

    const static double warriorQuotient;
    const static double archerQuotient;
    const static double winResult;

    ///////////////////////////////////////////////////////////////////////////////////////////////
};

#endif // GAMEBALANCE_H
