#include <iostream>
#include <iomanip>
#include <windows.h>
#include <conio.h>
#include "../header/UIhandler.hpp"

void load()
{

    srand(time(nullptr)); // it will generate unique random numbers each time

    std::string loader{"LOADING..."};

    for (int i{0}; i <= rand() % 20 + (rand() % 15) * 2 + 10; ++i)
    {
        if (i % 10 == 0)
            std::cout << "\r          \r";         // erasing current line
        std::cout << loader.at(i % loader.size()); // display char one by one
        Sleep(150);                                // delay
    }
}

void title()
{ // this display the title at top of screen

    const std::string title{"iCoder"};

    std::cout << std::setw(width_menu) << ""
              << std::setw(width_title) << std::setfill('=') << ""
              << std::setfill(' ') << std::endl
              << std::setw(width_menu + width_title / 2 - title.size() / 2) << ""
              << title << std::endl
              << std::setw(width_menu) << ""
              << std::setw(width_title) << std::setfill('=') << ""
              << std::setfill(' ')
              << std::endl
              << std::endl;
}

bool menu(std::string menu_str, bool flag, const std::string heading)
{ // show the specific menu

    header(heading);

    for (auto c : menu_str)
    {
        std::cout << c;

        if (flag)
            Sleep(sleep_time); // delay
    }

    flag = false;

    border(width_menu); // display the footer '----'

    animater(std::string{"Your Choice : "});

    return flag;
}

void header(const std::string &menu_name)
{

    std::cout << std::setfill('-')
              << std::setw(2) << ""
              << menu_name
              << std::setw(width_menu - (menu_name.size() + 2)) << ""
              << std::setfill(' ')
              << std::endl;
}

void border(int size)
{
    std::cout << std::endl
              << std::setfill('-')
              << std::setw(size) << ""
              << std::setfill(' ')
              << std::endl;
}

void emessage(const std::string &emessage)
{
    animater(emessage, emessage_timer);

    igetch();

    for (unsigned int i{0}; i < emessage.size(); ++i)
    {
        std::cout << "\b \b";
        Sleep(emessage_timer);
    }
}

void igetch()
{
    char c;
    while ((c = getch()))
        if (c == '\r' || c == ' ' || c == '\b' || c == 27)
            return;
}

void animater(const std::string &anime, int speed)
{
    for (auto c : anime)
    {
        std::cout << c;
        Sleep(speed);
    }
}

void print_message(const std::string &message)
{
    std::cout << std::endl
              << std::endl
              << message;
}

void press_key()
{
    border(width_menu); // display the footer
    std::cout << "Press a key to continue";
    getch();
}
