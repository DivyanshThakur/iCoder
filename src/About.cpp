#include <iostream>
#include "../header/About.hpp"
#include "../header/UIhandler.hpp"
#include "../header/Scanner.hpp"
#include "../header/Constants.hpp"

void about()
{
    int ch{0};
    do
    {
        system(std::string("start https://www.").c_str());
        system("cls"); // clear the screen each time

        title(); // print the title = iCoder

        menu(settings_data, std::string{" SETTINGS "}); // display the startup menu for settings screen

        Scanner sc;
        sc.scanChoice(ch);

        if (ch == ESC || ch == 2) //return when ESC is pressed
            return;

        // settings_controller(ch); // start as per user choice

    } while (ch != 3);
    exit(0);
}