#ifndef THEHUTRIESAPPLICATION_H
#define THEHUTRIESAPPLICATION_H

#include <string>
#include <SFML/Graphics.hpp>

class TheHutriesApplication
{
public:

    TheHutriesApplication();

    void readSettingsFromFile();

    void adjustResolution();

    void adjustVolume();

    void start();

private:

    sf::RenderWindow hutrieApplication;
    std::string resolution;
    std::string displayMode;
    std::string sfxVolumeString;
    std::string musicVolumeString;
    int musicVolume;
    int sfxVolume;
    float horizontalScreenZoom;
    float verticalScreenZoom;
    const int applicationWidth;
    const int applicationHeight;

    bool fullscreenEnable();

    float getXResolution();

    float getYResolution();

    void setEasy();

    void setNormal();

    void setHard();

    void stringsToNumbers();
};

#endif // THEHUTRIESAPPLICATION_H
