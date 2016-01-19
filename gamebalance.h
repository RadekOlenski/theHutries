#ifndef GAMEBALANCE_H
#define GAMEBALANCE_H


#include "goods.h"
#include <string>

class GameBalance
{
public:

    //////////////////////////////////  COSTS ////////////////////////////////////////////////////

    static Goods sawmillCost;
    static Goods stonecutterhutCost;
    static Goods barracksCost;
    static Goods residenceCost;
    static Goods goldmineCost;
    static Goods farmCost;

    static Goods archerCost;
    static Goods warriorCost;
    static Goods workerCost;
    static Goods carrierCost;

    //////////////////////////////////  GOODS   ///////////////////////////////////////////////////

    static unsigned int startingWood;
    static unsigned int startingStone;
    static unsigned int startingFood;
    static unsigned int startingGold;

    //////////////////////////////////  BUILDINGS ////////////////////////////////////////////

    const static int startingHutrieSlots = 10;
    const static int hutrieSlotsAddition = 10;

    //////////////////////////////////  GOOODBUILDINGS ////////////////////////////////////////////

    const static int maxProductsInStore = 5;
    const static int maxWorkers = 3;
    const static int productCraftingTime = 15;
    const static int carrierLading = 3;

    //////////////////////////////////  TRAINING    ///////////////////////////////////////////////

    const static int carrierTrainingTime = 1;
    const static int workerTrainingTime = 1;
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

    static int gameTime;

    /////////////////////////////////   FINAL RESULT    ///////////////////////////////////////////

    const static double warriorQuotient;
    const static double archerQuotient;
    const static double winResult;

    static std::string winString;
    static std::string loseString;

    /////////////////////////////////   MENU STRINGS    ///////////////////////////////////////////

    static std::string aboutString;
    static std::string howToPlayString;
    static std::string howToPlayString2;
    static std::string howToPlayString3;
    static std::string historyString;
    static std::string historyString2;
    static std::string historyString3;
    static std::string quoteString;

    ///////////////////////////////////////////////////////////////////////////////////////////////
};

#endif // GAMEBALANCE_H
