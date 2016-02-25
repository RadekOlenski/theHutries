#include <windows.h>
#include <ctime>

#include "thehutriesapplication.h"

int main()
{
//    HWND hWnd = GetConsoleWindow();
    SetConsoleTitle("The Hutries");

    srand((unsigned int) time(0));

    TheHutriesApplication hutriesApp;

    hutriesApp.readSettingsFromFile();

    hutriesApp.adjustResolution();

    hutriesApp.adjustVolume();

    //ShowWindow(hWnd, SW_HIDE);

    hutriesApp.start();

    return 0;
}


