#include <iostream>
#include <iomanip>
#include <windows.h>
#include <conio.h>
#include "../header/ExHandler.hpp"
#include "../header/UIhandler.hpp"
#include "../header/Scanner.hpp"
#include "../header/Constants.hpp"

void load()
{

    srand(time(nullptr)); // it will generate unique random numbers each time

    std::string loader{"LOADING..."};
    size_t loadLimit = loader.size();

    for (size_t i{0}; i <= rand() % (2 * loadLimit) + (rand() % loadLimit) * 2 + loadLimit; ++i)
    {
        if (i % loadLimit == 0)
            std::cout << "\r" << std::setw(loadLimit) << " "
                      << "\r";                 // erasing current line
        std::cout << loader.at(i % loadLimit); // display char one by one
        Sleep(150);                            // delay
    }
}

void title()
{
    system("cls"); // clear the screen each time

    const std::string title{"iCoder"}; // this display the title at top of screen

    std::cout << std::setw(console_title_relative_width) << ""
              << std::setw(width_title) << std::setfill('=') << ""
              << std::setfill(' ') << std::endl
              << std::setw(console_title_relative_width + width_title / 2 - title.size() / 2) << ""
              << title << std::endl
              << std::setw(console_title_relative_width) << ""
              << std::setw(width_title) << std::setfill('=') << ""
              << std::setfill(' ')
              << std::endl
              << std::endl;
}

void menu(const std::vector<std::string> &vec_menu, const std::string &heading)
{ // show the specific menu

    header(heading);

    for (size_t index{0}; index < vec_menu.size(); ++index)
    {
        std::cout << std::setw(2) << std::right << index + 1 << ". " << vec_menu.at(index);

        if (index < vec_menu.size() - 1)
            std::cout << std::endl;
    }

    border(width_menu);

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

void wait_message(const std::string &message)
{
    std::cout << message;
    Sleep(1000);
}

void press_esc()
{
    char ch;

    border(width_menu); // display the border
    std::cout << "Press ESC to return";
    ch = getch();

    if (ch == ESC)
        throw EscPressed();
}

bool confirm_the_change(const std::string &message, const std::string &txtConfirm)
{
    print_message(message);

    border(width_menu);

    animater(txtConfirm + std::string{" (Y/N): "});

    // scanning character
    Scanner sc;
    char c;
    sc.scan(c);

    if (c == ESC)
        throw EscPressed();

    return (::tolower(c) == 'y');
}