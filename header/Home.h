#ifndef HOME_H
#define HOME_H

#include <iostream>
#include <string>
#include "UIhandler.h"
#include "AccountHandler.h"

/*** GLOBAL VARIABLES ***/
extern std::string signedUserID;
extern int sleep_time;

/** FUNCTION PROTOTYPES **/
void home(const std::string &userID);
void home_controller(char ch);
void extern save_active_user(const std::string &userID); // defined in AccountHandler.h

/** CONSTANTS **/
const extern std::string menu2_data;
const extern std::string fsetting;

void home(const std::string &userID)
{
    char ch{};
    int flag{1};

    do
    {
        system("cls"); // clear the screen each timemenu_controller

        title(); // print the title = iCoder

        if (flag)
            emessage("--> Welcome " + userID + "!"); // display the welcome message

        flag = menu(menu2_data, flag); // display the startup menu

        { // taking character from string
            std::string str = iscan(txtChar);
            (str != "") ? ch = str.at(0) : ch = ESC;
        }

        home_controller(ch); // start as per user choice

        if (ch == '4')
            return;

    } while (ch != '6');

    exit(0);
}

void home_controller(char ch)
{
    switch (ch)
    {
    case '1':
        break;
    case '2':
        break;
    case '3':
        break;
    case '4': // sign out
        if (signedUserID != std::string{"NULL"})
            save_active_user(std::string{"NULL"});
        return;
    case '5':
        break;

    case '6': // exit the program
        break;
    case ESC: //ESC
        return;

    default:
        std::cout << std::endl
                  << std::endl
                  << "Invalid choice";
        break;
    }

    press_key(); // program paused - getch()
}

#endif