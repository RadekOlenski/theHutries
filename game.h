#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "world.h"
#include "guitext.h"
#include "gui.h"
#include "hutrieshall.h"

class Game
{
    public:
        Game(int applicationWidth = 1024, int applicationHeight = 640);
        void play();
    private:

        /////////////////WINDOW////////////////////////

        int applicationWidth;
        int applicationHeight;
        sf::RenderWindow hutrieApplication;
        sf::View fixed;

        ////////////////LOGIC//////////////////////////

        World world;
        int chosenMode;
        int tempChosenMode;
        int buildingType;
        bool buttonFlag;
        sf::Clock deadline;
        sf::Clock clock;
        sf::Thread titleThread;
        void deliverGoods (Hutrie * hutrie);
        HutriesHall *pHall;

        //////////GRAPHICS AND AUDIO//////////////////
        sf::Music music;
        GUI gui;
        GUIText titleText;
        sf::RectangleShape background;
        sf::Texture backgroundTexture;
        sf::Sprite cursor;
        sf::Texture cursorTexture;

        sf::Sound sound;
        sf::SoundBuffer buffer;
        void error();
        void ting();

        /////////////FUNCTIONS////////////////////////

        void actions();
        void displayAll();

        //////////////////////////////////////////////
};

#endif // GAME_H
