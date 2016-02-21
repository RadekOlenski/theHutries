#ifndef THEHUTRIES_SPRITES_H
#define THEHUTRIES_SPRITES_H


#include <string>
#include <SFML/Graphics/Texture.hpp>

class Textures
{
public:

    //---------------------------- BASIC ----------------------------//
    static std::string background;
    static std::string cursor;
    static std::string hammerCursor;

    //---------------------------- BUILDINGS ------------------------//

    static std::string underConstruction;

    static std::string sawmillBasic;
    static std::string sawmillWithProduct;

    static std::string stonecutterHutBasic;
    static std::string stoncutterHutWithProduct;

    static std::string farmBasic;
    static std::string farmWithProduct;

    static std::string goldmineBasic;
    static std::string goldmineWithProduct;

    static std::string barracksBasic;

    static std::string residenceBasic;

    static std::string hutriesHall;

    //---------------------------- HUTRIES ------------------------//

    static std::string archerDown;
    static std::string archerUp;
    static std::string archerLeft;
    static std::string archerRight;

    static std::string warriorDown;
    static std::string warriorUp;
    static std::string warriorLeft;
    static std::string warriorRight;

    static std::string workerDown;
    static std::string workerUp;
    static std::string workerLeft;
    static std::string workerRight;

    static std::string carrierDown;
    static std::string carrierUp;
    static std::string carrierLeft;
    static std::string carrierRight;
    static std::string carrierEmpty;

    //---------------------------- CARRIER EMPTY ------------------------//

    static std::string carrierEmptyMoveRight1;
    static std::string carrierEmptyMoveRight2;
    static std::string carrierEmptyMoveRight3;
    static std::string carrierEmptyMoveRight4;
    static std::string carrierEmptyMoveRight5;
    static std::string carrierEmptyMoveRight6;
    static std::string carrierEmptyMoveRight7;
    static std::string carrierEmptyMoveRight8;

    static std::string carrierEmptyMoveLeft1;
    static std::string carrierEmptyMoveLeft2;
    static std::string carrierEmptyMoveLeft3;
    static std::string carrierEmptyMoveLeft4;
    static std::string carrierEmptyMoveLeft5;
    static std::string carrierEmptyMoveLeft6;
    static std::string carrierEmptyMoveLeft7;
    static std::string carrierEmptyMoveLeft8;

    static std::string carrierEmptyMoveDown1;
    static std::string carrierEmptyMoveDown2;
    static std::string carrierEmptyMoveDown3;
    static std::string carrierEmptyMoveDown4;
    static std::string carrierEmptyMoveDown5;
    static std::string carrierEmptyMoveDown6;
    static std::string carrierEmptyMoveDown7;
    static std::string carrierEmptyMoveDown8;

    static std::string carrierEmptyMoveUp1;
    static std::string carrierEmptyMoveUp2;
    static std::string carrierEmptyMoveUp3;
    static std::string carrierEmptyMoveUp4;
    static std::string carrierEmptyMoveUp5;
    static std::string carrierEmptyMoveUp6;
    static std::string carrierEmptyMoveUp7;

    //---------------------------- CARRIER WOOD ------------------------//

    static std::string carrierWoodMoveRight1;
    static std::string carrierWoodMoveRight2;
    static std::string carrierWoodMoveRight3;
    static std::string carrierWoodMoveRight4;
    static std::string carrierWoodMoveRight5;
    static std::string carrierWoodMoveRight6;
    static std::string carrierWoodMoveRight7;

    static std::string carrierWoodMoveLeft1;
    static std::string carrierWoodMoveLeft2;
    static std::string carrierWoodMoveLeft3;
    static std::string carrierWoodMoveLeft4;
    static std::string carrierWoodMoveLeft5;
    static std::string carrierWoodMoveLeft6;
    static std::string carrierWoodMoveLeft7;

    static std::string carrierWoodMoveDown1;
    static std::string carrierWoodMoveDown2;
    static std::string carrierWoodMoveDown3;
    static std::string carrierWoodMoveDown4;
    static std::string carrierWoodMoveDown5;
    static std::string carrierWoodMoveDown6;
    static std::string carrierWoodMoveDown7;

    static std::string carrierWoodMoveUp1;
    static std::string carrierWoodMoveUp2;
    static std::string carrierWoodMoveUp3;
    static std::string carrierWoodMoveUp4;
    static std::string carrierWoodMoveUp5;
    static std::string carrierWoodMoveUp6;
    static std::string carrierWoodMoveUp7;

    //---------------------------- WORKER ------------------------//

    static std::string workerMoveRight1;
    static std::string workerMoveRight2;
    static std::string workerMoveRight3;
    static std::string workerMoveRight4;
    static std::string workerMoveRight5;
    static std::string workerMoveRight6;
    static std::string workerMoveRight7;
    static std::string workerMoveRight8;

    static std::string workerMoveUp1;
    static std::string workerMoveUp2;
    static std::string workerMoveUp3;
    static std::string workerMoveUp4;
    static std::string workerMoveUp5;
    static std::string workerMoveUp6;
    static std::string workerMoveUp7;
    static std::string workerMoveUp8;

    static std::string workerMoveLeft1;
    static std::string workerMoveLeft2;
    static std::string workerMoveLeft3;
    static std::string workerMoveLeft4;
    static std::string workerMoveLeft5;
    static std::string workerMoveLeft6;
    static std::string workerMoveLeft7;
    static std::string workerMoveLeft8;
    static std::string workerMoveLeft9;

    static std::string workerMoveDown1;
    static std::string workerMoveDown2;
    static std::string workerMoveDown3;
    static std::string workerMoveDown4;
    static std::string workerMoveDown5;
    static std::string workerMoveDown6;
    static std::string workerMoveDown7;
    static std::string workerMoveDown8;
    static std::string workerMoveDown9;

    //---------------------------- WARRIOR ------------------------//

    static std::string warriorMoveRight1;
    static std::string warriorMoveRight2;
    static std::string warriorMoveRight3;
    static std::string warriorMoveRight4;
    static std::string warriorMoveRight5;
    static std::string warriorMoveRight6;
    static std::string warriorMoveRight7;
    static std::string warriorMoveRight8;
    static std::string warriorMoveRight9;
    static std::string warriorMoveRight10;
    static std::string warriorMoveRight11;

    //---------------------------- GOODS ------------------------//

    static std::string gold;
    static std::string wood;
    static std::string food;
    static std::string stone;

    //---------------------------- ENVIRONMENT ------------------------//

    static std::string forest;
    static std::string rocks;
    static std::string mountain;

    //---------------------------- GUI -------------------------------//

    static std::string buildButton;
    static std::string hutrieButton;
    static std::string guiBar;
    static std::string guiTexture;


    static std::string farmGUI;
    static std::string goldmineGUI;
    static std::string allHutries;

    static std::string arrow;
    static std::string backArrow;

};


#endif //THEHUTRIES_SPRITES_H
