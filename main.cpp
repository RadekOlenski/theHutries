#include <ctime>
#include "game.h"

int main()
{
    srand((unsigned int) time(0));

/////////////////////////// RESOLUTION DECLARATION ////////////////////////////////////////////////////////////

    const int applicationWidth = 1024;
    const int applicationHeight = 640;

/////////////////////////// CREATING AND STARTING GAME ////////////////////////////////////////////////////////

    Game game(applicationWidth, applicationHeight);
    if (game.menu())
    {
        game.play();
        bool result = game.getResult();
        game.gameOver(result);
    }

/////////////////////////// ENDING ////////////////////////////////////////////////////////////////////////////
    return 0;
}
