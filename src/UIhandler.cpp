#include <iostream>
#include <iomanip>
#include <windows.h>
#include <conio.h>
#include "../header/UIhandler.hpp"
#include "../header/Scanner.hpp"
#include "../header/Constants.hpp"

void mod(int &x)
{
    x = 0 - x;
}

void load()
{

    srand(time(nullptr)); // it will generate unique random numbers each time

    std::string loader{"LOADING..."};

    for (int i{0}; i <= rand() % 20 + (rand() % 10) * 2 + 10; ++i)
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

void menu(std::string menu_str, const std::string heading)
{ // show the specific menu

    header(heading);

    std::cout << menu_str;

    border(width_menu); // display the footer '----'

    std::cout << "Your Choice: ";
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

void emessage(const std::string &message)
{
    animater(message);

    igetch();

    for (size_t i{0}; i < message.size(); ++i)
    {
        std::cout << "\b \b";
        Sleep(sleep_time);
    }
}

void igetch()
{
    char c;
    while ((c = getch()))
        if (c == '\r' || c == ' ' || c == '\b' || c == 27)
            return;
}

void animater(const std::string &anime)
{
    for (const auto &c : anime)
    {
        std::cout << c;
        Sleep(sleep_time);
    }
}

void print_message(const std::string &message)
{
    border(width_menu);

    std::cout << message;
}

void press_key()
{
    border(width_menu); // display the footer
    std::cout << "Press a key to continue";
    getch();
}

bool press_esc()
{
    char ch;

    border(width_menu); // display the border
    std::cout << "Press ESC to return";
    ch = getch();

    return (ch == ESC);
}

bool confirm_the_change(const std::string &message)
{
    print_message(message);

    border(width_menu);

    animater(std::string{"Do you want to proceed? (Y/N): "});

    // scanning character
    Scanner sc;
    char c;
    sc.scan(c);

    if (c == ESC)
        return false;

    return (::tolower(c) == 'y');
}