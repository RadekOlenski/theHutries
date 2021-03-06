#include <SFML/Graphics/Texture.hpp>
#include "textures.h"

//---------------------------- BASIC ----------------------------//
std::string Textures::background = "sprites/background/background.jpg";
std::string Textures::cursor = "sprites/cursor.png";
std::string Textures::hammerCursor = "sprites/hammercursor.png";

//---------------------------- BUILDINGS ------------------------//

std::string Textures::underConstruction = "sprites/buildings/constructionSite.png";

std::string Textures::sawmillBasic = "sprites/buildings/sawmill.png";
std::string Textures::sawmillWithProduct = "sprites/buildings/sawmillWithLogs.png";

std::string Textures::stonecutterHutBasic = "sprites/buildings/stonecutterHut.png";
std::string Textures::stoncutterHutWithProduct = "sprites/buildings/stonecutterHutWithProduct.png";

std::string Textures::farmBasic = "sprites/buildings/farm.png";
std::string Textures::farmWithProduct = "sprites/buildings/farmWithProduct.png";

std::string Textures::goldmineBasic = "sprites/buildings/goldmine.png";
std::string Textures::goldmineWithProduct = "sprites/buildings/goldmineWithProduct.png";

std::string Textures::barracksBasic = "sprites/buildings/barracks.png";

std::string Textures::residenceBasic = "sprites/buildings/residence.png";

std::string Textures::hutriesHall = "sprites/buildings/castle.png";

std::string Textures::transparent = "sprites/carrier/transparent.png";
//---------------------------- CARRIER EMPTY------------------------//

std::string Textures::carrierEmptyMoveRight1 = "sprites/carrier/empty_move_right_1.png";
std::string Textures::carrierEmptyMoveRight2 = "sprites/carrier/empty_move_right_2.png";
std::string Textures::carrierEmptyMoveRight3 = "sprites/carrier/empty_move_right_3.png";
std::string Textures::carrierEmptyMoveRight4 = "sprites/carrier/empty_move_right_4.png";
std::string Textures::carrierEmptyMoveRight5 = "sprites/carrier/empty_move_right_5.png";
std::string Textures::carrierEmptyMoveRight6 = "sprites/carrier/empty_move_right_6.png";
std::string Textures::carrierEmptyMoveRight7 = "sprites/carrier/empty_move_right_7.png";
std::string Textures::carrierEmptyMoveRight8 = "sprites/carrier/empty_move_right_8.png";

std::string Textures::carrierEmptyMoveLeft1 = "sprites/carrier/empty_move_left_1.png";
std::string Textures::carrierEmptyMoveLeft2 = "sprites/carrier/empty_move_left_2.png";
std::string Textures::carrierEmptyMoveLeft3 = "sprites/carrier/empty_move_left_3.png";
std::string Textures::carrierEmptyMoveLeft4 = "sprites/carrier/empty_move_left_4.png";
std::string Textures::carrierEmptyMoveLeft5 = "sprites/carrier/empty_move_left_5.png";
std::string Textures::carrierEmptyMoveLeft6 = "sprites/carrier/empty_move_left_6.png";
std::string Textures::carrierEmptyMoveLeft7 = "sprites/carrier/empty_move_left_7.png";
std::string Textures::carrierEmptyMoveLeft8 = "sprites/carrier/empty_move_left_8.png";

std::string Textures::carrierEmptyMoveDown1 = "sprites/carrier/empty_move_down_1.png";
std::string Textures::carrierEmptyMoveDown2 = "sprites/carrier/empty_move_down_2.png";
std::string Textures::carrierEmptyMoveDown3 = "sprites/carrier/empty_move_down_3.png";
std::string Textures::carrierEmptyMoveDown4 = "sprites/carrier/empty_move_down_4.png";
std::string Textures::carrierEmptyMoveDown5 = "sprites/carrier/empty_move_down_5.png";
std::string Textures::carrierEmptyMoveDown6 = "sprites/carrier/empty_move_down_6.png";
std::string Textures::carrierEmptyMoveDown7 = "sprites/carrier/empty_move_down_7.png";
std::string Textures::carrierEmptyMoveDown8 = "sprites/carrier/empty_move_down_8.png";

std::string Textures::carrierEmptyMoveUp1 = "sprites/carrier/empty_move_up_1.png";
std::string Textures::carrierEmptyMoveUp2 = "sprites/carrier/empty_move_up_2.png";
std::string Textures::carrierEmptyMoveUp3 = "sprites/carrier/empty_move_up_3.png";
std::string Textures::carrierEmptyMoveUp4 = "sprites/carrier/empty_move_up_4.png";
std::string Textures::carrierEmptyMoveUp5 = "sprites/carrier/empty_move_up_5.png";
std::string Textures::carrierEmptyMoveUp6 = "sprites/carrier/empty_move_up_6.png";
std::string Textures::carrierEmptyMoveUp7 = "sprites/carrier/empty_move_up_7.png";

//---------------------------- CARRIER WOOD------------------------//

std::string Textures::carrierWoodMoveRight1 = "sprites/carrier/wood_move_right_1.png";
std::string Textures::carrierWoodMoveRight2 = "sprites/carrier/wood_move_right_2.png";
std::string Textures::carrierWoodMoveRight3 = "sprites/carrier/wood_move_right_3.png";
std::string Textures::carrierWoodMoveRight4 = "sprites/carrier/wood_move_right_4.png";
std::string Textures::carrierWoodMoveRight5 = "sprites/carrier/wood_move_right_5.png";
std::string Textures::carrierWoodMoveRight6 = "sprites/carrier/wood_move_right_6.png";
std::string Textures::carrierWoodMoveRight7 = "sprites/carrier/wood_move_right_7.png";
std::string Textures::carrierWoodMoveRight8 = "sprites/carrier/wood_move_right_8.png";

std::string Textures::carrierWoodMoveLeft1 = "sprites/carrier/wood_move_left_1.png";
std::string Textures::carrierWoodMoveLeft2 = "sprites/carrier/wood_move_left_2.png";
std::string Textures::carrierWoodMoveLeft3 = "sprites/carrier/wood_move_left_3.png";
std::string Textures::carrierWoodMoveLeft4 = "sprites/carrier/wood_move_left_4.png";
std::string Textures::carrierWoodMoveLeft5 = "sprites/carrier/wood_move_left_5.png";
std::string Textures::carrierWoodMoveLeft6 = "sprites/carrier/wood_move_left_6.png";
std::string Textures::carrierWoodMoveLeft7 = "sprites/carrier/wood_move_left_7.png";
std::string Textures::carrierWoodMoveLeft8 = "sprites/carrier/wood_move_left_8.png";

std::string Textures::carrierWoodMoveDown1 = "sprites/carrier/wood_move_down_1.png";
std::string Textures::carrierWoodMoveDown2 = "sprites/carrier/wood_move_down_2.png";
std::string Textures::carrierWoodMoveDown3 = "sprites/carrier/wood_move_down_3.png";
std::string Textures::carrierWoodMoveDown4 = "sprites/carrier/wood_move_down_4.png";
std::string Textures::carrierWoodMoveDown5 = "sprites/carrier/wood_move_down_5.png";
std::string Textures::carrierWoodMoveDown6 = "sprites/carrier/wood_move_down_6.png";
std::string Textures::carrierWoodMoveDown7 = "sprites/carrier/wood_move_down_7.png";
std::string Textures::carrierWoodMoveDown8 = "sprites/carrier/wood_move_down_8.png";

std::string Textures::carrierWoodMoveUp1 = "sprites/carrier/wood_move_up_1.png";
std::string Textures::carrierWoodMoveUp2 = "sprites/carrier/wood_move_up_2.png";
std::string Textures::carrierWoodMoveUp3 = "sprites/carrier/wood_move_up_3.png";
std::string Textures::carrierWoodMoveUp4 = "sprites/carrier/wood_move_up_4.png";
std::string Textures::carrierWoodMoveUp5 = "sprites/carrier/wood_move_up_5.png";
std::string Textures::carrierWoodMoveUp6 = "sprites/carrier/wood_move_up_6.png";
std::string Textures::carrierWoodMoveUp7 = "sprites/carrier/wood_move_up_7.png";
std::string Textures::carrierWoodMoveUp8 = "sprites/carrier/wood_move_up_8.png";

//---------------------------- CARRIER STONE ------------------------//

std::string Textures::carrierStoneMoveRight1 = "sprites/carrier/stone_move_right_1.png";
std::string Textures::carrierStoneMoveRight2 = "sprites/carrier/stone_move_right_2.png";
std::string Textures::carrierStoneMoveRight3 = "sprites/carrier/stone_move_right_3.png";
std::string Textures::carrierStoneMoveRight4 = "sprites/carrier/stone_move_right_4.png";
std::string Textures::carrierStoneMoveRight5 = "sprites/carrier/stone_move_right_5.png";
std::string Textures::carrierStoneMoveRight6 = "sprites/carrier/stone_move_right_6.png";
std::string Textures::carrierStoneMoveRight7 = "sprites/carrier/stone_move_right_7.png";
std::string Textures::carrierStoneMoveRight8 = "sprites/carrier/stone_move_right_8.png";

std::string Textures::carrierStoneMoveLeft1 = "sprites/carrier/stone_move_left_1.png";
std::string Textures::carrierStoneMoveLeft2 = "sprites/carrier/stone_move_left_2.png";
std::string Textures::carrierStoneMoveLeft3 = "sprites/carrier/stone_move_left_3.png";
std::string Textures::carrierStoneMoveLeft4 = "sprites/carrier/stone_move_left_4.png";
std::string Textures::carrierStoneMoveLeft5 = "sprites/carrier/stone_move_left_5.png";
std::string Textures::carrierStoneMoveLeft6 = "sprites/carrier/stone_move_left_6.png";
std::string Textures::carrierStoneMoveLeft7 = "sprites/carrier/stone_move_left_7.png";
std::string Textures::carrierStoneMoveLeft8 = "sprites/carrier/stone_move_left_8.png";

std::string Textures::carrierStoneMoveDown1 = "sprites/carrier/stone_move_down_1.png";
std::string Textures::carrierStoneMoveDown2 = "sprites/carrier/stone_move_down_2.png";
std::string Textures::carrierStoneMoveDown3 = "sprites/carrier/stone_move_down_3.png";
std::string Textures::carrierStoneMoveDown4 = "sprites/carrier/stone_move_down_4.png";
std::string Textures::carrierStoneMoveDown5 = "sprites/carrier/stone_move_down_5.png";
std::string Textures::carrierStoneMoveDown6 = "sprites/carrier/stone_move_down_6.png";
std::string Textures::carrierStoneMoveDown7 = "sprites/carrier/stone_move_down_7.png";
std::string Textures::carrierStoneMoveDown8 = "sprites/carrier/stone_move_down_8.png";

std::string Textures::carrierStoneMoveUp1 = "sprites/carrier/stone_move_up_1.png";
std::string Textures::carrierStoneMoveUp2 = "sprites/carrier/stone_move_up_2.png";
std::string Textures::carrierStoneMoveUp3 = "sprites/carrier/stone_move_up_3.png";
std::string Textures::carrierStoneMoveUp4 = "sprites/carrier/stone_move_up_4.png";
std::string Textures::carrierStoneMoveUp5 = "sprites/carrier/stone_move_up_5.png";
std::string Textures::carrierStoneMoveUp6 = "sprites/carrier/stone_move_up_6.png";
std::string Textures::carrierStoneMoveUp7 = "sprites/carrier/stone_move_up_7.png";
std::string Textures::carrierStoneMoveUp8 = "sprites/carrier/stone_move_up_8.png";

//---------------------------- CARRIER FOOD ------------------------//

std::string Textures::carrierFoodMoveRight1 = "sprites/carrier/food_move_right_1.png";
std::string Textures::carrierFoodMoveRight2 = "sprites/carrier/food_move_right_2.png";
std::string Textures::carrierFoodMoveRight3 = "sprites/carrier/food_move_right_3.png";
std::string Textures::carrierFoodMoveRight4 = "sprites/carrier/food_move_right_4.png";
std::string Textures::carrierFoodMoveRight5 = "sprites/carrier/food_move_right_5.png";
std::string Textures::carrierFoodMoveRight6 = "sprites/carrier/food_move_right_6.png";
std::string Textures::carrierFoodMoveRight7 = "sprites/carrier/food_move_right_7.png";
std::string Textures::carrierFoodMoveRight8 = "sprites/carrier/food_move_right_8.png";

std::string Textures::carrierFoodMoveLeft1 = "sprites/carrier/food_move_left_1.png";
std::string Textures::carrierFoodMoveLeft2 = "sprites/carrier/food_move_left_2.png";
std::string Textures::carrierFoodMoveLeft3 = "sprites/carrier/food_move_left_3.png";
std::string Textures::carrierFoodMoveLeft4 = "sprites/carrier/food_move_left_4.png";
std::string Textures::carrierFoodMoveLeft5 = "sprites/carrier/food_move_left_5.png";
std::string Textures::carrierFoodMoveLeft6 = "sprites/carrier/food_move_left_6.png";
std::string Textures::carrierFoodMoveLeft7 = "sprites/carrier/food_move_left_7.png";
std::string Textures::carrierFoodMoveLeft8 = "sprites/carrier/food_move_left_8.png";

std::string Textures::carrierFoodMoveDown1 = "sprites/carrier/food_move_down_1.png";
std::string Textures::carrierFoodMoveDown2 = "sprites/carrier/food_move_down_2.png";
std::string Textures::carrierFoodMoveDown3 = "sprites/carrier/food_move_down_3.png";
std::string Textures::carrierFoodMoveDown4 = "sprites/carrier/food_move_down_4.png";
std::string Textures::carrierFoodMoveDown5 = "sprites/carrier/food_move_down_5.png";
std::string Textures::carrierFoodMoveDown6 = "sprites/carrier/food_move_down_6.png";
std::string Textures::carrierFoodMoveDown7 = "sprites/carrier/food_move_down_7.png";
std::string Textures::carrierFoodMoveDown8 = "sprites/carrier/food_move_down_8.png";

std::string Textures::carrierFoodMoveUp1 = "sprites/carrier/food_move_up_1.png";
std::string Textures::carrierFoodMoveUp2 = "sprites/carrier/food_move_up_2.png";
std::string Textures::carrierFoodMoveUp3 = "sprites/carrier/food_move_up_3.png";
std::string Textures::carrierFoodMoveUp4 = "sprites/carrier/food_move_up_4.png";
std::string Textures::carrierFoodMoveUp5 = "sprites/carrier/food_move_up_5.png";
std::string Textures::carrierFoodMoveUp6 = "sprites/carrier/food_move_up_6.png";
std::string Textures::carrierFoodMoveUp7 = "sprites/carrier/food_move_up_7.png";
std::string Textures::carrierFoodMoveUp8 = "sprites/carrier/food_move_up_8.png";

//---------------------------- CARRIER GOLD ------------------------//

std::string Textures::carrierGoldMoveRight1 = "sprites/carrier/gold_move_right_1.png";
std::string Textures::carrierGoldMoveRight2 = "sprites/carrier/gold_move_right_2.png";
std::string Textures::carrierGoldMoveRight3 = "sprites/carrier/gold_move_right_3.png";
std::string Textures::carrierGoldMoveRight4 = "sprites/carrier/gold_move_right_4.png";
std::string Textures::carrierGoldMoveRight5 = "sprites/carrier/gold_move_right_5.png";
std::string Textures::carrierGoldMoveRight6 = "sprites/carrier/gold_move_right_6.png";
std::string Textures::carrierGoldMoveRight7 = "sprites/carrier/gold_move_right_7.png";
std::string Textures::carrierGoldMoveRight8 = "sprites/carrier/gold_move_right_8.png";

std::string Textures::carrierGoldMoveLeft1 = "sprites/carrier/gold_move_left_1.png";
std::string Textures::carrierGoldMoveLeft2 = "sprites/carrier/gold_move_left_2.png";
std::string Textures::carrierGoldMoveLeft3 = "sprites/carrier/gold_move_left_3.png";
std::string Textures::carrierGoldMoveLeft4 = "sprites/carrier/gold_move_left_4.png";
std::string Textures::carrierGoldMoveLeft5 = "sprites/carrier/gold_move_left_5.png";
std::string Textures::carrierGoldMoveLeft6 = "sprites/carrier/gold_move_left_6.png";
std::string Textures::carrierGoldMoveLeft7 = "sprites/carrier/gold_move_left_7.png";
std::string Textures::carrierGoldMoveLeft8 = "sprites/carrier/gold_move_left_8.png";

std::string Textures::carrierGoldMoveDown1 = "sprites/carrier/gold_move_down_1.png";
std::string Textures::carrierGoldMoveDown2 = "sprites/carrier/gold_move_down_2.png";
std::string Textures::carrierGoldMoveDown3 = "sprites/carrier/gold_move_down_3.png";
std::string Textures::carrierGoldMoveDown4 = "sprites/carrier/gold_move_down_4.png";
std::string Textures::carrierGoldMoveDown5 = "sprites/carrier/gold_move_down_5.png";
std::string Textures::carrierGoldMoveDown6 = "sprites/carrier/gold_move_down_6.png";
std::string Textures::carrierGoldMoveDown7 = "sprites/carrier/gold_move_down_7.png";
std::string Textures::carrierGoldMoveDown8 = "sprites/carrier/gold_move_down_8.png";

std::string Textures::carrierGoldMoveUp1 = "sprites/carrier/gold_move_up_1.png";
std::string Textures::carrierGoldMoveUp2 = "sprites/carrier/gold_move_up_2.png";
std::string Textures::carrierGoldMoveUp3 = "sprites/carrier/gold_move_up_3.png";
std::string Textures::carrierGoldMoveUp4 = "sprites/carrier/gold_move_up_4.png";
std::string Textures::carrierGoldMoveUp5 = "sprites/carrier/gold_move_up_5.png";
std::string Textures::carrierGoldMoveUp6 = "sprites/carrier/gold_move_up_6.png";
std::string Textures::carrierGoldMoveUp7 = "sprites/carrier/gold_move_up_7.png";
std::string Textures::carrierGoldMoveUp8 = "sprites/carrier/gold_move_up_8.png";

//---------------------------- WORKER ------------------------//

std::string Textures::workerMoveRight1 = "sprites/worker/move_right_1.png";
std::string Textures::workerMoveRight2 = "sprites/worker/move_right_2.png";
std::string Textures::workerMoveRight3 = "sprites/worker/move_right_3.png";
std::string Textures::workerMoveRight4 = "sprites/worker/move_right_4.png";
std::string Textures::workerMoveRight5 = "sprites/worker/move_right_5.png";
std::string Textures::workerMoveRight6 = "sprites/worker/move_right_6.png";
std::string Textures::workerMoveRight7 = "sprites/worker/move_right_7.png";
std::string Textures::workerMoveRight8 = "sprites/worker/move_right_8.png";

std::string Textures::workerMoveUp1 = "sprites/worker/move_up_1.png";
std::string Textures::workerMoveUp2 = "sprites/worker/move_up_2.png";
std::string Textures::workerMoveUp3 = "sprites/worker/move_up_3.png";
std::string Textures::workerMoveUp4 = "sprites/worker/move_up_4.png";
std::string Textures::workerMoveUp5 = "sprites/worker/move_up_5.png";
std::string Textures::workerMoveUp6 = "sprites/worker/move_up_6.png";
std::string Textures::workerMoveUp7 = "sprites/worker/move_up_7.png";
std::string Textures::workerMoveUp8 = "sprites/worker/move_up_8.png";

std::string Textures::workerMoveLeft1 = "sprites/worker/move_left_1.png";
std::string Textures::workerMoveLeft2 = "sprites/worker/move_left_2.png";
std::string Textures::workerMoveLeft3 = "sprites/worker/move_left_3.png";
std::string Textures::workerMoveLeft4 = "sprites/worker/move_left_4.png";
std::string Textures::workerMoveLeft5 = "sprites/worker/move_left_5.png";
std::string Textures::workerMoveLeft6 = "sprites/worker/move_left_6.png";
std::string Textures::workerMoveLeft7 = "sprites/worker/move_left_7.png";
std::string Textures::workerMoveLeft8 = "sprites/worker/move_left_8.png";
std::string Textures::workerMoveLeft9 = "sprites/worker/move_left_8.png";

std::string Textures::workerMoveDown1 = "sprites/worker/move_down_1.png";
std::string Textures::workerMoveDown2 = "sprites/worker/move_down_2.png";
std::string Textures::workerMoveDown3 = "sprites/worker/move_down_3.png";
std::string Textures::workerMoveDown4 = "sprites/worker/move_down_4.png";
std::string Textures::workerMoveDown5 = "sprites/worker/move_down_5.png";
std::string Textures::workerMoveDown6 = "sprites/worker/move_down_6.png";
std::string Textures::workerMoveDown7 = "sprites/worker/move_down_7.png";
std::string Textures::workerMoveDown8 = "sprites/worker/move_down_8.png";
std::string Textures::workerMoveDown9 = "sprites/worker/move_down_8.png";

//---------------------------- WARRIOR ------------------------//

std::string Textures::warriorMoveRight1 = "sprites/warrior/move_right_1.png";
std::string Textures::warriorMoveRight2 = "sprites/warrior/move_right_2.png";
std::string Textures::warriorMoveRight3 = "sprites/warrior/move_right_3.png";
std::string Textures::warriorMoveRight4 = "sprites/warrior/move_right_4.png";
std::string Textures::warriorMoveRight5 = "sprites/warrior/move_right_5.png";
std::string Textures::warriorMoveRight6 = "sprites/warrior/move_right_6.png";
std::string Textures::warriorMoveRight7 = "sprites/warrior/move_right_7.png";
std::string Textures::warriorMoveRight8 = "sprites/warrior/move_right_8.png";
std::string Textures::warriorMoveRight9 = "sprites/warrior/move_right_9.png";
std::string Textures::warriorMoveRight10 = "sprites/warrior/move_right_10.png";
std::string Textures::warriorMoveRight11 = "sprites/warrior/move_right_11.png";
std::string Textures::warriorMoveRight12 = "sprites/warrior/move_right_12.png";

std::string Textures::warriorMoveLeft1 = "sprites/warrior/move_left_1.png";
std::string Textures::warriorMoveLeft2 = "sprites/warrior/move_left_2.png";
std::string Textures::warriorMoveLeft3 = "sprites/warrior/move_left_3.png";
std::string Textures::warriorMoveLeft4 = "sprites/warrior/move_left_4.png";
std::string Textures::warriorMoveLeft5 = "sprites/warrior/move_left_5.png";
std::string Textures::warriorMoveLeft6 = "sprites/warrior/move_left_6.png";
std::string Textures::warriorMoveLeft7 = "sprites/warrior/move_left_7.png";
std::string Textures::warriorMoveLeft8 = "sprites/warrior/move_left_8.png";
std::string Textures::warriorMoveLeft9 = "sprites/warrior/move_left_9.png";
std::string Textures::warriorMoveLeft10 = "sprites/warrior/move_left_10.png";
std::string Textures::warriorMoveLeft11 = "sprites/warrior/move_left_11.png";
std::string Textures::warriorMoveLeft12 = "sprites/warrior/move_left_12.png";

std::string Textures::warriorMoveDown1 = "sprites/warrior/move_down_1.png";
std::string Textures::warriorMoveDown2 = "sprites/warrior/move_down_2.png";
std::string Textures::warriorMoveDown3 = "sprites/warrior/move_down_3.png";
std::string Textures::warriorMoveDown4 = "sprites/warrior/move_down_4.png";
std::string Textures::warriorMoveDown5 = "sprites/warrior/move_down_5.png";
std::string Textures::warriorMoveDown6 = "sprites/warrior/move_down_6.png";
std::string Textures::warriorMoveDown7 = "sprites/warrior/move_down_7.png";
std::string Textures::warriorMoveDown8 = "sprites/warrior/move_down_8.png";
std::string Textures::warriorMoveDown9 = "sprites/warrior/move_down_9.png";
std::string Textures::warriorMoveDown10 = "sprites/warrior/move_down_10.png";
std::string Textures::warriorMoveDown11 = "sprites/warrior/move_down_11.png";
std::string Textures::warriorMoveDown12 = "sprites/warrior/move_down_12.png";

std::string Textures::warriorMoveUp1 = "sprites/warrior/move_up_1.png";
std::string Textures::warriorMoveUp2 = "sprites/warrior/move_up_2.png";
std::string Textures::warriorMoveUp3 = "sprites/warrior/move_up_3.png";
std::string Textures::warriorMoveUp4 = "sprites/warrior/move_up_4.png";
std::string Textures::warriorMoveUp5 = "sprites/warrior/move_up_5.png";
std::string Textures::warriorMoveUp6 = "sprites/warrior/move_up_6.png";
std::string Textures::warriorMoveUp7 = "sprites/warrior/move_up_7.png";
std::string Textures::warriorMoveUp8 = "sprites/warrior/move_up_8.png";
std::string Textures::warriorMoveUp9 = "sprites/warrior/move_up_9.png";
std::string Textures::warriorMoveUp10 = "sprites/warrior/move_up_10.png";
std::string Textures::warriorMoveUp11 = "sprites/warrior/move_up_11.png";
std::string Textures::warriorMoveUp12 = "sprites/warrior/move_up_12.png";

//---------------------------- ARCHER ------------------------//

std::string Textures::archerMoveRight1 = "sprites/archer/move_right_1.png";
std::string Textures::archerMoveRight2 = "sprites/archer/move_right_2.png";
std::string Textures::archerMoveRight3 = "sprites/archer/move_right_3.png";
std::string Textures::archerMoveRight4 = "sprites/archer/move_right_4.png";
std::string Textures::archerMoveRight5 = "sprites/archer/move_right_5.png";
std::string Textures::archerMoveRight6 = "sprites/archer/move_right_6.png";
std::string Textures::archerMoveRight7 = "sprites/archer/move_right_7.png";
std::string Textures::archerMoveRight8 = "sprites/archer/move_right_8.png";

std::string Textures::archerMoveLeft1 = "sprites/archer/move_left_1.png";
std::string Textures::archerMoveLeft2 = "sprites/archer/move_left_2.png";
std::string Textures::archerMoveLeft3 = "sprites/archer/move_left_3.png";
std::string Textures::archerMoveLeft4 = "sprites/archer/move_left_4.png";
std::string Textures::archerMoveLeft5 = "sprites/archer/move_left_5.png";
std::string Textures::archerMoveLeft6 = "sprites/archer/move_left_6.png";
std::string Textures::archerMoveLeft7 = "sprites/archer/move_left_7.png";
std::string Textures::archerMoveLeft8 = "sprites/archer/move_left_8.png";

std::string Textures::archerMoveDown1 = "sprites/archer/move_down_1.png";
std::string Textures::archerMoveDown2 = "sprites/archer/move_down_2.png";
std::string Textures::archerMoveDown3 = "sprites/archer/move_down_3.png";
std::string Textures::archerMoveDown4 = "sprites/archer/move_down_4.png";
std::string Textures::archerMoveDown5 = "sprites/archer/move_down_5.png";
std::string Textures::archerMoveDown6 = "sprites/archer/move_down_6.png";
std::string Textures::archerMoveDown7 = "sprites/archer/move_down_7.png";
std::string Textures::archerMoveDown8 = "sprites/archer/move_down_8.png";

std::string Textures::archerMoveUp1 = "sprites/archer/move_up_1.png";
std::string Textures::archerMoveUp2 = "sprites/archer/move_up_2.png";
std::string Textures::archerMoveUp3 = "sprites/archer/move_up_3.png";
std::string Textures::archerMoveUp4 = "sprites/archer/move_up_4.png";
std::string Textures::archerMoveUp5 = "sprites/archer/move_up_5.png";
std::string Textures::archerMoveUp6 = "sprites/archer/move_up_6.png";
std::string Textures::archerMoveUp7 = "sprites/archer/move_up_7.png";
std::string Textures::archerMoveUp8 = "sprites/archer/move_up_8.png";

//---------------------------- GOODS ------------------------//

std::string Textures::gold = "sprites/goods/gold.png";
std::string Textures::wood = "sprites/goods/wood.png";
std::string Textures::food = "sprites/goods/food.png";
std::string Textures::stone = "sprites/goods/stone.png";

//---------------------------- ENVIRONMENT ------------------------//

std::string Textures::forest = "sprites/environment/trees.png";
std::string Textures::rocks = "sprites/environment/rocks.png";
std::string Textures::mountain = "sprites/environment/mountain.png";

//---------------------------- GUI -------------------------------//

std::string Textures::buildButton = "sprites/buttons/hammer.png";
std::string Textures::hutrieButton = "sprites/buttons/hutrie.png";
std::string Textures::guiBar = "sprites/buttons/goodsBar2.png";
std::string Textures::guiTexture = "sprites/background/pergamino.jpg";

std::string Textures::farmGUI = "sprites/buildings/farmGUI.png";
std::string Textures::goldmineGUI = "sprites/buildings/goldmineGUI.png";
std::string Textures::allHutries = "sprites/all.png";

std::string Textures::arrow = "sprites/arrow.png";
std::string Textures::backArrow = "sprites/backarrow.png";



