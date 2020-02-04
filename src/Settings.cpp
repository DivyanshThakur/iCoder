#include <iostream>
#include <sstream>
#include <windows.h>
#include "../header/Settings.hpp"
#include "../header/Constants.hpp"
#include "../header/UIhandler.hpp"
#include "../header/Scanner.hpp"

void settings()
{
    int ch{0};
    do
    {
        system("cls"); // clear the screen each time

        title(); // print the title = iCoder

        menu(settings_data, std::string{" SETTINGS "}); // display the startup menu for settings screen

        Scanner sc;
        ch = sc.scanInt();

        if (ch == ESC || ch == 3) //return when ESC is pressed
            return;

        settings_controller(ch); // start as per user choice

    } while (ch != 4);
    exit(0);
}

void settings_controller(char ch)
{

    switch (ch)
    {
    case 1: // change the animation speed of the menu
        change_menu_speed();
        return;

    case 2:              // go to create account screen
        print_message(); // print - to be implemented
        break;

    case 4: // exit the program
        break;

    default:
        print_message(std::string{"Invalid choice"});
        break;
    }

    press_key(); // getch()
}

void change_menu_speed()
{
    int speed;
    Scanner sc;

    std::cout << "\n\nEnter the speed" << std::endl;

    speed = sc.scanInt();

    if (speed == -1 || speed == ESC)
        return;

    sleep_time = speed;
}