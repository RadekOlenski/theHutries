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

};


#endif //THEHUTRIES_SPRITES_H
