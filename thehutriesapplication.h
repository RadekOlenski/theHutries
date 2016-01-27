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

        void start();

//        void setDifficulty();

        void info();

    private:

        sf::RenderWindow hutrieApplication;
        std::string resolution;
        std::string displayMode;
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
};

#endif // THEHUTRIESAPPLICATION_H
