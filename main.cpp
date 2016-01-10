#include <ctime>
#include "game.h"

int main()
{
    srand((unsigned int) time(0));

/////////////////////////// RESOLUTION DECLARATION ////////////////////////////////////////////////////////////

    const int applicationWidth = 1024;
    const int applicationHeight = 640;

    float x, y;
    std::cout << "Wpisz swoja rozdzielczosc" << std::endl << "x: ";
    std::cin >> x;
    std::cout << "y: ";
    std::cin >> y;

    float horizontalScreenZoom = x / 1280;
    float verticalScreenZoom = y / 800;

/////////////////////////// CREATING AND STARTING GAME ////////////////////////////////////////////////////////

    Game game(applicationWidth, applicationHeight, horizontalScreenZoom, verticalScreenZoom);
    if (game.menu())
    {
        game.play();
        bool result = game.getResult();
        game.gameOver(result);
    }

/////////////////////////// ENDING ////////////////////////////////////////////////////////////////////////////
    return 0;
}
