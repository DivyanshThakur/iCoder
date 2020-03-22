#include <iostream>
#include <iomanip>
#include <windows.h>
#include <conio.h>
#include "../header/ExHandler.hpp"
#include "../header/UIhandler.hpp"
#include "../header/Scanner.hpp"

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

    std::cout << std::setw(relativeTitleWidth) << ""
              << std::setw(widthTitle) << std::setfill('=') << ""
              << std::setfill(' ') << std::endl
              << std::setw(relativeTitleWidth + widthTitle / 2 - title.size() / 2) << ""
              << title << std::endl
              << std::setw(relativeTitleWidth) << ""
              << std::setw(widthTitle) << std::setfill('=') << ""
              << std::setfill(' ')
              << std::endl
              << std::endl;
}

void menu(const std::vector<std::string> &vecMenu, const std::string &heading, bool showStatus, const std::string &statsVal, const std::string &statsStr)
{ // show the specific menu

    if (showedOneTime)
        title(); // display title - "iCoder"
    else
        showedOneTime = true;

    if (showHint) // display hint in every screen
        show_hint();

    header(heading, false);

    if (showStatus)
        show_status(statsStr, statsVal);

    for (size_t index{0}; index < vecMenu.size(); ++index)
    {
        std::cout << std::setw(2) << std::right << index + 1 << ". " << vecMenu.at(index);

        if (index < vecMenu.size() - 1)
            std::cout << std::endl;
    }

    print_message(std::string{"Your Choice: "});
}

void show_status(const std::string &statsStr, const std::string &statsVal)
{
    std::cout << statsStr << statsVal;
    border(widthMenu);
}

std::string stats_selector()
{
    std::string str;

    switch (stats)
    {
    case DEFAULT:
        str = "DEFAULT";
        break;
    case EASY:
        str = "TRANSPOSITION";
        break;
    case ADV:
        str = "MOVE-TO-FRONT";
        break;
    }

    return str;
}

void header(const std::string &menuTitle, bool showTitle)
{
    if (showTitle)
        title();

    std::cout << std::setfill('-')
              << std::setw(2) << ""
              << menuTitle
              << std::setw(widthMenu - (menuTitle.size() + 2)) << ""
              << std::setfill(' ')
              << std::endl;
}

void show_hint()
{
    header(std::string{" HINT "}, false);

    std::cout << std::setw(6) << std::left << "'Esc'"
              << "Last Screen" << std::endl
              << std::setw(6) << std::left << "'h'"
              << "Help screen" << std::endl
              << std::setw(6) << std::left << "'d'"
              << "Disable this hint" << std::endl;
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
        Sleep(sleepTime);
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
        Sleep(sleepTime);
    }
}

void print_message(const std::string &message)
{
    border(widthMenu);

    std::cout << message;
}

void press_key(const ReturnTo &rt, const std::string &message)
{
    char ch;

    print_message(message);
    ch = getch();

    if (ch == ESC)
    {
        switch (rt)
        {
        case PRE:
            throw EscPressed();
        case HOME:
            throw ReturnHome();
        case NIL:
            break;
        }
    }
}

bool press_i(const std::string &message)
{
    print_message(std::string{message});

    char ch = getch();

    if (::tolower(ch) == 'i')
        return true;

    return false;
}

void wait_message(const std::string &message)
{
    std::cout << message;
    Sleep(1000);
}

bool confirm_the_change(const std::string &message, const std::string &txtConfirm)
{
    print_message(message);

    border(widthMenu);

    animater(txtConfirm + std::string{" (Y/N): "});

    // scanning character
    Scanner sc;
    char c;
    sc.scan(c);

    return (::tolower(c) == 'y');
}