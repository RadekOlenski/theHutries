#ifndef GAMEBALANCE_H
#define GAMEBALANCE_H


#include "goods.h"
#include <string>

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
    static  Goods workerCost;
    static  Goods carrierCost;

    //////////////////////////////////  GOODS   ///////////////////////////////////////////////////

    const static unsigned int startingWood = 100;
    const static unsigned int startingStone = 100;
    const static unsigned int startingFood = 100;
    const static unsigned int startingGold = 100;

    //////////////////////////////////  BUILDINGS ////////////////////////////////////////////

    const static int startingHutrieSlots = 10;
	
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

    const static int gameTime = 5 * 60;

    /////////////////////////////////   FINAL RESULT    ///////////////////////////////////////////

    const static double warriorQuotient;
    const static double archerQuotient;
    const static double winResult;

    /////////////////////////////////   MENU STRINGS    ///////////////////////////////////////////

    static std::string aboutString;
    static std::string howToPlayString;
    static std::string historyString;
    static std::string historyString2;
    static std::string historyString3;
    static std::string quoteString;

    ///////////////////////////////////////////////////////////////////////////////////////////////
};

#endif // GAMEBALANCE_H
