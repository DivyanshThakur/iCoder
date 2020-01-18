#include <iostream>
#include "../header/Settings.hpp"
#include "../header/Constants.hpp"
#include "../header/UIhandler.hpp"

void settings()
{
    char ch;
    bool flag{true};
    do
    {
        system("cls"); // clear the screen each time

        title(); // print the title = iCoder

        flag = menu(settings_data, flag, std::string{" SETTINGS "}); // display the startup menu for settings screen

        { // taking character from string
            std::string str = iscan(txtChar);
            (str != "") ? ch = str.at(0) : ch = ESC;
        }

        settings_controller(ch); // start as per user choice

        if (ch == ESC || ch == '3') //return when ESC is pressed
            return;

    } while (ch != '4');
    exit(0);
}

void settings_controller(char ch)
{

    switch (ch)
    {
    case '1': // change the animation speed of the menu
        change_menu_speed();
        return;
    case '2': // go to create account screen
        std::cout << "\nTo be implemented" << std::endl;
        break;
    case '3': // go to main menu
        return;

    case '4': // exit the program
        break;

    case ESC: //ESC
        return;

    default:
        std::cout << std::endl
                  << std::endl
                  << "Invalid choice";
        break;
    }

    press_key(); // getch()
}

void change_menu_speed()
{
    std::string str;

    std::cout << "\n\nEnter the speed" << std::endl;
    str = iscan(txtChar);
    if (str == "")
        return;
    std::stringstream ss{str};

    if (!(ss >> sleep_time))
    {
        std::cout << "Enter a valid number" << std::endl;
    }
}