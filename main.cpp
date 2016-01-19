#include <ctime>
#include <string>
#include <windows.h>
#include "game.h"

bool fullscreenEnable();
void setDifficulty();

int main()
{
    HWND hWnd = GetConsoleWindow();
    SetConsoleTitle("The Hutries");

    srand((unsigned int) time(0));

/////////////////////////// RESOLUTION DECLARATION ////////////////////////////////////////////////////////////

    const int applicationWidth = 1024;
    const int applicationHeight = 640;
    bool fullscreen;
    float x = 1366, y = 768;
    std::cout << "Minimal supported resolution is 1366x768. \nChanging to lower on your own risk." << std::endl;
    do
    {
        std::cout << "Type resolution of your screen:" << std::endl << "x: ";
        std::cin >> x;
        std::cout << "y: ";
        std::cin >> y;
    }
    while (x <= 0 || y <= 0);
    setDifficulty();

    float horizontalScreenZoom = x / 1280;
    float verticalScreenZoom = y / 768;
/////////////////////////// CREATING AND STARTING GAME ////////////////////////////////////////////////////////

    Game game(applicationWidth, applicationHeight, horizontalScreenZoom, verticalScreenZoom,
              false);// fullscreenEnable());
    ShowWindow(hWnd, SW_HIDE);

    if (game.menu())
    {
        game.play();
        bool result = game.getResult();
        game.gameOver(result);
    }

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

void setDifficulty()
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
    switch(difficult)
    {
        case 1:
            GameBalance::gameTime = 15 * 60;
            break;
        case 2:
            GameBalance::gameTime = 10 * 60;
            break;
        case 3:
            GameBalance::gameTime = 5 * 60;
            break;
        default:
            break;
    }
}
