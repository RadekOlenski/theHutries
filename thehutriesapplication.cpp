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
        musicVolume = 100;
        sfxVolume = 80;
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
        std::getline( settingsFile, bin);
        std::getline( settingsFile, musicVolumeString);
        std::getline( settingsFile, bin);
        std::getline( settingsFile, sfxVolumeString);
        settingsFile.close();
    }
}

void TheHutriesApplication::stringsToNumbers()
{
    std::stringstream convertMusic(musicVolumeString);
    if (!(convertMusic >> musicVolume))
        musicVolume = 0;
    std::stringstream convertSFX(sfxVolumeString);
    if (!(convertSFX >> sfxVolume))
        sfxVolume = 0;
}

void TheHutriesApplication::adjustVolume()
{
    stringsToNumbers();
    GameBalance::musicVolume = musicVolume;
    GameBalance::sfxVolume = sfxVolume;
}
