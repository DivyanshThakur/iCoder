#ifndef UIHANDLER_H
#define UIHANDLER_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>
#include <string>
#include <conio.h>

/** FUNCTION PROTOTYPES **/

void title();
int menu(std::ifstream &file, std::string this_menu, int flag);
std::string iscan(const std::string &stype);
void header(const std::string &menu_name);
void footer();

/** CONSTANTS **/
const int sleep_time = 50;
const int width_menu = 25;
const int width_title = 30;
const char ESC = 27;
const std::string txtPassword{"Password"};
const std::string txtChar{"Char"};
const std::string txtString{"String"};

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
                //if(flag)
                // Sleep(sleep_time);          // delay
            }
        }
    }

    flag = 0;
    file.clear();
    file.seekg(0, std::ios::beg);

    footer(); // display the footer '----'
    std::cout << "Your Choice : ";

    return flag;
}

std::string iscan(const std::string &stype)
{
    std::string value;

    char c;

    while (c = getch())
    { // taking input from user
        if (c == '\r' && value.size())
            break; // if user presses enter end while loop and save the value

        if (c == ESC) // if user presses esc, it returnss to startup menu
            return std::string{""};

        if (c == '\b' && value.size())
        {                         // cheking backspace and limit it to size of value
            std::cout << "\b \b"; // remove last element from console
            value.pop_back();     // remove last element from pass string
        }
        else if (c >= '!' && c <= '~')
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
void footer()
{
    std::cout << std::endl
              << std::setfill('-')
              << std::setw(width_menu) << ""
              << std::setfill(' ') << std::endl;
}

#endif