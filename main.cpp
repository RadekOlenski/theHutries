#include <ctime>
#include <string>
#include "game.h"

bool fullscreenEnable();
int main()
{
    srand((unsigned int) time(0));

/////////////////////////// RESOLUTION DECLARATION ////////////////////////////////////////////////////////////

    const int applicationWidth = 1024;
    const int applicationHeight = 640;

    float x = 1366, y = 768;

    bool fullscreen;
//    std::cout << "Minimal supported resolution is 1366x768. \nChanging to lower on your own risk." << std::endl;
//    do
//    {
//        std::cout << "Type resolution of your screen:" << std::endl << "x: ";
//        std::cin >> x;
//        std::cout << "y: ";
//        std::cin >> y;
//    }
//    while (x <= 0 || y <=0);

    float horizontalScreenZoom = x / 1280;
    float verticalScreenZoom = y / 768;

/////////////////////////// CREATING AND STARTING GAME ////////////////////////////////////////////////////////

    Game game(applicationWidth, applicationHeight, horizontalScreenZoom, verticalScreenZoom, true);// fullscreenEnable());
//    if (game.menu())
//    {
        game.play();
        bool result = game.getResult();
        game.gameOver(result);
//    }
/////////////////////////// ENDING ////////////////////////////////////////////////////////////////////////////
    return 0;
}

bool fullscreenEnable()
{
    std::string answer;
    do
    {
        std::cout << "Fullscreen? [y/n]" << std::endl;
        std::cin >> answer;
    }
    while (answer.find_first_not_of("YyNn") != std::string::npos);
    return (bool) answer.find_first_not_of("yY");
}
