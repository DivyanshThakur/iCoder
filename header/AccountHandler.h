#ifndef ACCOUNTHANDLER_H
#define ACCOUNTHANDLER_H

#include <iostream>
#include <iomanip>
#include <string>
#include <conio.h>
#include "UIhandler.h"
#include "ScreenLoader.h"

/** FUNCTION PROTOTYPES **/

void login();
std::string iscan();
std::string passwordscan();
void load();
//void mainMenu(const std::string &username);

/** CONSTANTS **/
const extern int sleep_time;
const std::string username{"Username: "};
const std::string password{"Password: "};

void login()
{
    system("cls");

    title(); // display the "iCoder" title

    std::string userID, pass;

    std::cout << std::setfill('-')
              << std::setw(2) << ""
              << " LOGIN " // display menu title
              << std::setw(width_menu - 9) << ""
              << std::endl
              << std::endl;

    for (auto c : username)
    {
        std::cout << c;
        Sleep(sleep_time);
    }

    userID = iscan(); // taking username from user
    if (userID == "")
        return;

    for (auto c : password)
    {
        std::cout << c;
        Sleep(sleep_time);
    }

    pass = passwordscan(); // scanning password
    if (pass == "")
        return;

    std::cout << std::endl
              << std::setw(width_menu) << ""
              << std::setfill(' ') << std::endl;

    load(); // animate loading screen

    //mainMenu(username);             // calling the main menu screen to show all program list
}

#endif