#include "thehutriesapplication.h"
#include <fstream>
#include "game.h"
#include "gamebalance.h"

TheHutriesApplication::TheHutriesApplication() : applicationWidth (1024),
                                                 applicationHeight (640)
{

}

void TheHutriesApplication::start()
{
     hutrieApplication.create(sf::VideoMode::getDesktopMode(), "The Hutries", sf::Style::Fullscreen);
     while (!GameBalance::exitFlag)
     {
        Game game(&hutrieApplication, applicationWidth, applicationHeight, horizontalScreenZoom, verticalScreenZoom, fullscreenEnable());
        game.menu();
        if (GameBalance::exitFlag)
        {
            hutrieApplication.close();
            break;
        }
        game.play();
     }
}

void TheHutriesApplication::adjustResolution()
{
    horizontalScreenZoom = getXResolution() / 1280;
    verticalScreenZoom   = getYResolution() / 768;
}

bool TheHutriesApplication::fullscreenEnable()
{
     return (bool) !displayMode.compare("fullscreen");
}

float TheHutriesApplication::getXResolution()
{
    float x;
    std::istringstream issX(resolution.substr(0,4));
    issX >> x;
    return x;
}

float TheHutriesApplication::getYResolution()
{
    float y;
    std::istringstream issY(resolution.substr(7));
    issY >> y;
    return y;
}

void TheHutriesApplication::readSettingsFromFile()
{
    std::ifstream settingsFile;
    settingsFile.open ("config/settings.txt", std::ios_base :: in);
    if(settingsFile.good() == false)
    {
        std::cout << "File doesn't exist! Failed to open settings file" << std::endl;
        std::cout << "Default settings: ON" << std::endl;
        resolution = "1360 x 768";
        displayMode = "fullscreen";
    }
    else
    {
        std::string bin;
        std::getline( settingsFile, bin);
        std::getline( settingsFile, bin);
        std::getline( settingsFile, resolution);
        std::getline( settingsFile, bin);
        std::getline( settingsFile, bin);
        std::getline( settingsFile, displayMode);
        std::getline( settingsFile, displayMode);
        settingsFile.close();
    }
}

void TheHutriesApplication::setHard()
{
    GameBalance::gameTime = 5 * 60;
    GameBalance::startingFood = 10;
    GameBalance::startingWood = 10;
    GameBalance::startingStone = 10;
    GameBalance::startingGold = 0;
}

void TheHutriesApplication::setNormal()
{
    GameBalance::gameTime = 10 * 60;
    GameBalance::startingFood = 15;
    GameBalance::startingWood = 15;
    GameBalance::startingStone = 15;
    GameBalance::startingGold = 15;
}

void TheHutriesApplication::setEasy()
{
    GameBalance::gameTime = 15 * 60;
    GameBalance::startingFood = 20;
    GameBalance::startingWood = 20;
    GameBalance::startingStone = 20;
    GameBalance::startingGold = 20;
}

void TheHutriesApplication::setDifficulty()
{
    int difficult;
    std::cout << "Choose difficulty level." << std::endl;
    do
    {
        std::cout << "1 - Hutrie Carrier (easy): " << std::endl;
        std::cout << "2 - Hutrie Worker (normal): " << std::endl;
        std::cout << "3 - Hutrie Warrior (hard): " << std::endl;
        std::cin >> difficult;
    }
    while (difficult <= 0);
    switch (difficult)
    {
        case 1:
            setEasy();
            break;
        case 2:
            setNormal();
            break;
        case 3:
            setHard();
            break;
        default:
            break;
    }
}

void TheHutriesApplication::info()
{
    std::cout << "Resolution string: " << resolution << std::endl;
    std::cout << "Display Mode string: " << displayMode << std::endl;
    std::cout << "X: " << getXResolution() << std::endl;
    std::cout << "Y: " << getYResolution() << std::endl;
    std::cout << "HorizontalScreenZoom: " << horizontalScreenZoom << std::endl;
    std::cout << "VerticalScreenZoom: " << verticalScreenZoom << std::endl;
}
