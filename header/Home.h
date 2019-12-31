#include <iostream>
#include <string>
#include "UIhandler.h"

/** FUNCTION PROTOTYPES **/
void home(const std::string &userID);
void home_controller(char ch);

/** CONSTANTS **/
const extern std::string fmenu;

void home(const std::string &userID)
{

    std::ifstream file{fmenu};

    if (!file)
    {                 // validating opening of file
        createFile(); // if error occur it creates a fresh file in specific folder
        file.open(fmenu);
    }

    char ch{};
    int flag{1};

    do
    {
        system("cls"); // clear the screen each timemenu_controller

        title(); // print the title = iCoder

        if (flag)
            emessage("-- Welcome " + userID + "!"); // display the welcome message

        flag = menu(file, std::string{"MENU2"}, flag); // display the startup menu

        { // taking character from string
            std::string str = iscan(txtChar);
            (str != "") ? ch = str.at(0) : ch = ESC;
        }

        home_controller(ch); // start as per user choice

    } while (ch != '6');

    file.close(); // closing the current file

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
    case '4':
        break;
    case '5':
        break;

    case '6': // exit the program
        break;
    case ESC: //ESC
        break;

    default:
        std::cout << std::endl
                  << std::endl
                  << "Invalid choice";
        break;
    }

    border(width_menu); // display the footer

    std::cout << "Press a key to continue";
    getch();
}