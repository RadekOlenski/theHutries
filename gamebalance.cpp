#include "gamebalance.h"

    Goods GameBalance::sawmillCost(3,3);
    Goods GameBalance::stonecutterhutCost (3,3);
    Goods GameBalance::barracksCost (3,5);
    Goods GameBalance::residenceCost (5,3);
    Goods GameBalance::goldmineCost (3,4);
    Goods GameBalance::farmCost (4,3);
    Goods GameBalance::archerCost (0,0,0,3);
    Goods GameBalance::warriorCost (0,0,0,5);

    const double GameBalance::warriorQuotient = 0.8;
    const double GameBalance::archerQuotient = 0.8;
    const double GameBalance::winResult = 6;
    const double GameBalance::carrierTrainingTime = 0.3;
    const double GameBalance::workerTrainingTime = 0.5;

    double GameBalance::screenZoom = 1.1;

    //////////////////////////////////  CONSTRUCTION TIME    //////////////////////////////////////
    const float GameBalance::barracksConstructionTime = 2;
    const float GameBalance::residenceConstructionTime = 2;
    const float GameBalance::sawmillConstructionTime = 2;
    const float GameBalance::stonecutterHutConstructionTime = 2;
    const float GameBalance::farmConstructionTime = 2;
    const float GameBalance::goldmineConstructionTime = 2;
