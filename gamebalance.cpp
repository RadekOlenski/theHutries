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

    //////////////////////////////////  MENU STRINGS    ///////////////////////////////////////////

    std::string GameBalance::aboutString ( "Created by: Marcin Jozwik\n              Radoslaw Olenski\n      Year: 2015\n   Version: 0.9.9.8\n\n Project for Object Oriented Programming Credit");
    std::string GameBalance::howToPlayString ("Mini tutorial");
    std::string GameBalance::quoteString("Now, to disbelieve truth brings death,\nas to believe, life; and again,\nto believe the lie and to disbelieve\nthe truth hutries to destruction.\"\nThe Sacred Writings \nof Clement of Alexandria");
    std::string GameBalance::historyString ("You are Hutron the Great.\nChief of tribe called Hutries.\nYour peaceful life has been disturbed\nby dragon attack.");
    std::string GameBalance::historyString2 ("You escape with a few Hutries.\nBut you're not safe. \nGather your men! \nDragon will be back.");
    std::string GameBalance::historyString3 ("Just enter your castle and prepare to fight!");
