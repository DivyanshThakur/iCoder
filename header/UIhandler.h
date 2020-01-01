#ifndef UIHANDLER_H
#define UIHANDLER_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>
#include <string>
#include <conio.h>

/*** GLOBAL VARIABLES ***/
extern int sleep_time;

/** CONSTANTS **/

const int emessage_timer = 25;
const int width_menu = 25;
const int width_title = 30;
const int width_index = 5;
const extern int width_username = 20;
const extern int width_password = 10;
const char ESC = 27;
const std::string txtPassword{"Password"};
const std::string txtUsername{"Username"};
const std::string txtChar{"Char"};
const std::string txtString{"String"};

/** FUNCTION PROTOTYPES **/

void title();
int menu(std::ifstream &file, std::string this_menu, int flag);
std::string iscan(const std::string &stype, bool isMultiple = false);
void header(const std::string &menu_name);
void border(int size);
void emessage(const std::string &emessage);
void animater(const std::string &anime, int speed = sleep_time);
void igetch();
void press_key();

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

int menu(std::ifstream &file, std::string this_menu, int flag)
{ // show the specific menu

    char c;
    std::string fmenu;

    header(std::string{" MENU "});

    while (file >> fmenu)
    {

        if (fmenu == this_menu)
        {

            while (file.get(c) && c != '~')
            {
                std::cout << c;
                if (flag)
                    Sleep(sleep_time); // delay
            }
        }
    }

    flag = 0;
    file.clear();
    file.seekg(0, std::ios::beg);

    border(width_menu); // display the footer '----'

    animater(std::string{"Your Choice : "});

    return flag;
}

std::string iscan(const std::string &stype, bool isMultiple)
{
    std::string value;
    bool isUserExceeded, isPassExceeded;

    char c;

    while (c = getch())
    { // taking input from user

        isUserExceeded = (stype == txtUsername && value.size() >= width_username);
        isPassExceeded = (stype == txtPassword && value.size() >= width_password);

        if (c == '\r' && value.size())
            break; // if user presses enter end while loop and save the value

        if (isMultiple && c == ' ' && value.size())
        {
            std::cout << " ";
            break;
        }

        if (c == ESC) // if user presses esc, it returnss to startup menu
            return std::string{""};

        if (c == '\b' && value.size())
        {                         // cheking backspace and limit it to size of value
            std::cout << "\b \b"; // remove last element from console
            value.pop_back();     // remove last element from pass string
        }
        else if (stype == txtUsername || stype == txtPassword)
        {
            if (c == ' ')
                emessage(std::string{"     Space Not Allowed!"});
            else if (isUserExceeded)
                emessage("     " + txtUsername + " exceeds " + std::to_string(width_username) + " characters!");
            else if (isPassExceeded)
                emessage("     " + txtPassword + " exceeds " + std::to_string(width_password) + " characters!");
        }

        if (c >= '!' && c <= '~' && !(isUserExceeded || isPassExceeded))
        {
            value.push_back(c); // add element at last of pass string

            // checking valid password and display that spcific output
            (stype == std::string{txtPassword}) ? std::cout << "*" : std::cout << c;
        }
    }
    return value; // return char or string based on stype
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

    for (auto i{0}; i < emessage.size(); ++i)
    {
        std::cout << "\b \b";
        Sleep(emessage_timer);
    }
}

void igetch()
{
    char c;
    while (c = getch())
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

void press_key()
{
    border(width_menu); // display the footer
    std::cout << "Press a key to continue";
    getch();
}

#endif