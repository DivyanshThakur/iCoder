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
std::string iscan();

/** CONSTANTS **/
const int sleep_time = 50;
const int width_menu = 25;
const int width_title = 30;

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

    std::cout << std::setfill('-')
              << std::setw(2) << ""
              << " MENU "
              << std::setw(width_menu - 8) << ""
              << std::endl;
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

    std::cout << std::endl
              << std::setw(width_menu) << ""
              << std::setfill(' ') << std::endl
              << "Your Choice : ";

    return flag;
}

std::string iscan()
{
    std::string value;

    char c;

    while (c = getch())
    { // taking input from user
        if (c == '\r' && value.size())
            break; // if user presses enter end while loop and save the value

        if (c == 27) // if user presses esc, it returnss to startup menu
            return std::string{""};

        if (c == '\b' && value.size())
        {                         // cheking backspace and limit it to size of value
            std::cout << "\b \b"; // remove last element from console
            value.pop_back();     // remove last element from pass string
        }
        else if (c >= '!' && c <= '~')
        {
            value.push_back(c); // add element at last of pass string
            std::cout << c;     // display 'c' to console by replacing password
        }
    }
    return value;
}

std::string passwordscan()
{

    std::string value;

    char c;
    while (c = getch())
    { // taking password from user
        if (c == '\r' && value.size())
            break; // if user press enter end while loop and save password

        if (c == 27) // if user presses esc, it returnss to startup menu
            return std::string{""};

        if (c == '\b' && value.size())
        {                         // cheking backspace and limit it to size of password
            std::cout << "\b \b"; // remove last element from console
            value.pop_back();     // remove last element from pass string
        }
        else if (c >= '!' && c <= '~' && c != '<' && c != '>')
        {                       // checking valid password
            value.push_back(c); // add element at last of pass string
            std::cout << "*";   // display '*' to console by replacing password
        }
    }
    return value;
}

char charscan()
{
    std::string value;

    char c;

    while (c = getch())
    { // taking password from user
        if (c == '\r' && value.size())
            break; // if user press enter end while loop and save password

        if (c == 27) // if user presses esc, it returnss to startup menu
            return '\0';

        if (c == '\b' && value.size())
        {                         // cheking backspace and limit it to size of password
            std::cout << "\b \b"; // remove last element from console
            value.pop_back();     // remove last element from pass string
        }
        else if (c >= '!' && c <= '~')
        {                       // checking valid password
            value.push_back(c); // add element at last of pass string
            std::cout << c;     // display '*' to console by replacing password
        }
    }
    return value.at(0);
}

#endif