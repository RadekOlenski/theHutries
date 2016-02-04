#include "gamebalance.h"

bool GameBalance::exitFlag = false;
int GameBalance::gameTime = 5 * 60;
unsigned int GameBalance::startingWood = 10;
unsigned int GameBalance::startingStone = 10;
unsigned int GameBalance::startingFood = 10;
unsigned int GameBalance::startingGold = 10;

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

const float GameBalance::barracksConstructionTime = 5;
const float GameBalance::residenceConstructionTime = 5;
const float GameBalance::sawmillConstructionTime = 5;
const float GameBalance::stonecutterHutConstructionTime = 5;
const float GameBalance::farmConstructionTime = 5;
const float GameBalance::goldmineConstructionTime = 5;

//////////////////////////////////  TRAINING TIME    //////////////////////////////////////

const float GameBalance::carrierTrainingTime = 3;
const float GameBalance::workerTrainingTime = 5;
const float GameBalance::archerTrainingTime = 3;
const float GameBalance::warriorTrainingTime = 5;

//////////////////////////////////  MENU STRINGS    ///////////////////////////////////////////

    std::string GameBalance::aboutString ( "Created by: Marcin Jozwik\n              Radoslaw Olenski\n      Year: 2016\n   Version: 1.0.1.0");
    std::string GameBalance::quoteString("\"Now, to disbelieve truth brings death,\nas to believe, life; and again,\nto believe the lie and to disbelieve\nthe truth hutries to destruction.\"\nThe Sacred Writings \nof Clement of Alexandria");
    std::string GameBalance::historyString ("You are Hutron I the Great.\nChief of tribe called Hutries.\nYour peaceful life has been disturbed\nby dragon attack. You village no longer exists.");
    std::string GameBalance::historyString2 ("You escape with a few Hutries.\nBut you're not safe. \nGather your men! \nDragon will be back.");
    std::string GameBalance::historyString3 ("Just enter your castle and prepare to fight!\nTrain as many soldiers as possible!");
    std::string GameBalance::howToPlayString ("Hello there!\n\nThis tutorial will guide you through basic mechanics, description of\nall types of buildings, hutries and resources and usage of them.");
    std::string GameBalance::howToPlayMechanicsString ("Mechanics");
    std::string GameBalance::howToPlayBuildingsString  ("\t\t\t\t\tBuildings:\nHutries Hall:\nA heart of the village. All available\ngoods are stored here. You can also train workers and carriers \nby clicking on the building.\nGoods Buildings:\ncreate goods: wood, stone, food, and gold. You need worker to \nstart production and, when product is ready, carrier to \ntransport it to Hutries Hall. They must be near goods deposit.\nBarracks:\n allows you to create soldiers : warriors and archers.\nResidence:\n creates space for more Hutries in your village.");
    std::string GameBalance::howToPlayHutriesString ("Hutries");
    std::string GameBalance::howToPlayResourcesString  ("Resources");
    std::string GameBalance::loseString("Your troops fought bravely, \nbut they could not withstand attack.\nThe Dragon was too powerful...\nThere is no hope for you.\nThe Hutries Tribe has gone.\nForever...");
    std::string GameBalance::winString ("When the Dragon attacked, you wasn't suprised. \nPerfectly trained troops \nproved that nobody should cross Hutries path.\n It,s a big day in Hutries history. \nA new beginning. ");
