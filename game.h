#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "world.h"
#include "guitext.h"
#include "gui.h"

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
        sf::Clock clock;
        sf::Thread titleThread;

        //////////GRAPHICS AND AUDIO//////////////////
        sf::Music music;
        GUI gui;
        GUIText titleText;
        sf::RectangleShape background;
        sf::Texture backgroundTexture;
        sf::Sprite cursor;
        sf::Texture cursorTexture;

        /////////////FUNCTIONS////////////////////////

        void actions();
        void displayAll();

        //////////////////////////////////////////////
};

#endif // GAME_H
