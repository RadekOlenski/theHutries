#include "gamebalance.h"

Goods GameBalance::sawmillCost(3, 3);
Goods GameBalance::stonecutterhutCost(3, 3);
Goods GameBalance::barracksCost(3, 5);
Goods GameBalance::residenceCost(5, 3);
Goods GameBalance::goldmineCost(3, 4);
Goods GameBalance::farmCost(4, 3);
Goods GameBalance::archerCost(0, 0, 0, 3);
Goods GameBalance::warriorCost(0, 0, 0, 5);
Goods GameBalance::workerCost(0, 0, 2, 0);
Goods GameBalance::carrierCost(0, 0, 1, 0);

const double GameBalance::warriorQuotient = 0.8;
const double GameBalance::archerQuotient = 0.5;
const double GameBalance::winResult = 6;

//////////////////////////////////  CONSTRUCTION TIME    //////////////////////////////////////

const float GameBalance::barracksConstructionTime = 2;
const float GameBalance::residenceConstructionTime = 2;
const float GameBalance::sawmillConstructionTime = 2;
const float GameBalance::stonecutterHutConstructionTime = 2;
const float GameBalance::farmConstructionTime = 2;
const float GameBalance::goldmineConstructionTime = 2;

//////////////////////////////////  MENU STRINGS    ///////////////////////////////////////////

    std::string GameBalance::aboutString ( "Created by: Marcin Jozwik\n              Radoslaw Olenski\n      Year: 2015\n   Version: 1.0.0.0\n\n Project for Object Oriented Programming Assignment ");
    std::string GameBalance::quoteString("\"Now, to disbelieve truth brings death,\nas to believe, life; and again,\nto believe the lie and to disbelieve\nthe truth hutries to destruction.\"\nThe Sacred Writings \nof Clement of Alexandria");
    std::string GameBalance::historyString ("You are Hutron the Great.\nChief of tribe called Hutries.\nYour peaceful life has been disturbed\nby dragon attack. You village no longer exists.");
    std::string GameBalance::historyString2 ("You escape with a few Hutries.\nBut you're not safe. \nGather your men! \nDragon will be back.");
    std::string GameBalance::historyString3 ("Just enter your castle and prepare to fight!\nTrain as many soldiers as possible!");
    std::string GameBalance::howToPlayString ("Your main objective is to defend your village from dragon's attack.\nIn order to do it you need to train as many soldiers as possible.\n\nBuild 6 types of buildings, create 4 types of Hutries \nand multiply 4 types of goods.\n\nOnly clever moves will lead you to victory.");
    std::string GameBalance::howToPlayString2 ("To create new building use the Hammer Icon at upper right corner,\nchoose building from the list and empty field on a map. \nIf you have enough goods, building will start.\n\nTo create new workers and carriers use buttons connected with \nHutries Hall. This action requires food.\nIn case of warriors and archers use Barracks and gold.");
    std::string GameBalance::howToPlayString3  ("Buildings: \nGoodsbuildings create goods: wood, stone, food, and gold. You need \nworker to start production and, when product is ready, carrier \nto transport it to Hutries Hall. Building must be near goods deposit.\n\nResidence creates space for more Hutries in your village.\n\nBarracks allows you to create soldiers : warriors and archers. ");
    std::string GameBalance::loseString("Your troops fought bravely, \nbut they could not withstand attack.\nThe Dragon was too powerful...\nThere is no hope for you.\nThe Hutries Tribe has gone.\nForever...");
    std::string GameBalance::winString ("When the Dragon attacked, you wasn't suprised. \nPerfectly trained troops \nproved that nobody should cross Hutries path.\n It,s a big day in Hutries history. \nA new beginning. ");
