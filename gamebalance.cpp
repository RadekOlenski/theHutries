#include "gamebalance.h"

int GameBalance::musicVolume = 100;
int GameBalance::sfxVolume = 100;
int GameBalance::tempMusicVolume = 0;
int GameBalance::tempSFXVolume = 0;
int GameBalance::tempResSlots = 0;


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

const float GameBalance::carrierTrainingTime = 1;//3;
const float GameBalance::workerTrainingTime = 2;//5;
const float GameBalance::archerTrainingTime = 3;
const float GameBalance::warriorTrainingTime = 5;

//////////////////////////////////  MENU STRINGS    ///////////////////////////////////////////

    std::string GameBalance::aboutString ( "Created by: Marcin Jozwik\n              Radoslaw Olenski\n      Year: 2016\n   Version: 1.1.1.0");
    std::string GameBalance::quoteString("\"Now, to disbelieve truth brings death,\nas to believe, life; and again,\nto believe the lie and to disbelieve\nthe truth hutries to destruction.\"\nThe Sacred Writings \nof Clement of Alexandria");
    std::string GameBalance::historyString ("You are Hutron I the Great.\nChief of tribe called Hutries.\nYour peaceful life has been disturbed\nby dragon attack. You village no longer exists.");
    std::string GameBalance::historyString2 ("You escape with a few Hutries.\nBut you're not safe. \nGather your men! \nDragon will be back.");
    std::string GameBalance::historyString3 ("Just enter your castle and prepare to fight!\nTrain as many soldiers as possible!");

    std::string GameBalance::howToPlayString ("Hello there!\n\nThis tutorial will guide you through basic mechanics, description of\nall types of buildings, hutries and resources and usage of them.\n\n\n\n\n\n\n\n\n\t\t\tNeed more info? Check out a manual in PDF!");
    std::string GameBalance::howToPlayMechanicsString ("You start game with some resources and 10 places in a Residence to train Hutries. \nTo construct a new building enter Build Mode and choose an appropriate building \nfrom a list. Then find an available place on a map and create a Construction Site. \nNow you have to send Carriers with resources necessary to construction. The last \nstep is to send a Worker, who will construct the building and stay in it to produce \ngoods. Be careful! To create the worker, you need available slots in the Residence! \nA small hint: build Sawmill and Stonecutter Hut first and you will be able to \nproduce resources necessary to construct next buildings. Your main goal is to train \nenough soldiers to defeat the Dragon. To do that you need Gold from a Goldmine. \nYour battle will soon begin but not only against the Dragon but also against \nlimited time!");
    std::string GameBalance::howToPlayBuildingsString  ("Click on a building to see more information.");
    std::string GameBalance::howToPlayHutriesHallString  ("A heart of the village. \nAll available goods are stored here. \nYou can also train workers and carriers \nby clicking on the building.\nAll of them are waiting for your orders \nhere.");
    std::string GameBalance::howToPlayBarracksString  ("To win the game you need to train \nas many archers and warriors as possible. \nBarracks allow you to do that.\nOne worker is required.\nTo start training click on the building\nand choose appropriate unit in buildings \nmenu on the right. You need gold \nand space in residence to do that.");
    std::string GameBalance::howToPlayResidenceString  ("You can train limited number of \nHutries in your village. Residence \nallows you to expand it. \nYou start with 10 Hutries and \nevery built residence gives 10 extra places.\nThese places can be occupied by any Hutrie:\ncarrier, worker, soldier or archer.");
    std::string GameBalance::howToPlaySawmillString  ("Creates wood for buildings' construction. \nYou can build it only nearby forest.\nUp to three workers can work here at \nthe same time. More workers = more wood.\nWhen production is over, you need carrier \nto transport goods to Hutries Hall.\nThen wood is ready to use.");
    std::string GameBalance::howToPlayStonecutterHutString  ("Creates stone for buildings' construction.\nYou can build it only nearby rocks.\nUp to three workers can work here at \nthe same time. More workers = more stones.\nWhen production is over, you need carrier \nto transport goods to Hutries Hall.\nThen stones is ready to use.");
    std::string GameBalance::howToPlayFarmString  ("Creates food for workers and carriers. \nUp to three workers can work here at \nthe same time. More workers = more food.\nWhen production is over, you need carrier \nto transport goods to Hutries Hall.\nThen food can be used in carriers\nand workers training.");
    std::string GameBalance::howToPlayGoldmineString  ("Creates gold for soldiers' training.\nYou can build it only nearby mountains.\nUp to three workers can work here at \nthe same time. More workers = more gold.\nWhen production is over, you need carrier \nto transport goods to Hutries Hall.\nThen gold can be spent on soldiers training.");
    std::string GameBalance::howToPlayHutriesString ("Hutries are members of your tribe. They are ready to serve you as long \nas residence is provided to them. There are 4 professions to choose from:\n\n\t\tCarrier - transports goods between Hutries Hall and other buildings.\n\n\t\tWorker - constructs buildings and produces goods.\n\n\t\tWarrior - stronger and more expensive unit in fight against the dragon.\n\n\t\tArcher - weaker but cheaper than warrior. Doesnt't like dragons.");
    std::string GameBalance::howToPlayResourcesString  ("   Necessary for:\t\t\t\t\tCreated in:\n\n\t  Soldiers\t\t\t\t\t\tGoldmine\n\n\n\t  Buildings\t\t\t\tSawmill, Stonecutter Hut\n\n\nCarriers & Workers\t\t\t\t\tFarm");

    std::string GameBalance::loseString("Your troops fought bravely, \nbut they could not withstand the attack.\nThe Dragon was too powerful...\nThere is no hope for you.\nThe Hutries Tribe has gone.\nForever...");
    std::string GameBalance::winString ("When the Dragon attacked, you wasn't surprised. \nMeticulously trained troops \nproved that nobody should cross Hutries path.\n It's a big day in Hutries history. \nA new beginning. ");
