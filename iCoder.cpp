#include <iostream>
#include <fstream>
#include <limits>
#include "header/UIhandler.h"
#include "header/Filehandler.h"
#include "header/AccountHandler.h"

/** FUNCTION PROTOTYPES **/

void menu_controller(char ch);

/** CONSTANTS **/
const std::string fmenu = "./data/menu.dat";
const extern char ESC;
const extern int width_menu;
const extern std::string txtChar;

int main()
{

    std::ifstream file(fmenu);

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

        flag = menu(file, std::string{"MENU1"}, flag); // display the startup menu

        { // taking character from string
            std::string str = iscan(txtChar);
            (str != "") ? ch = str.at(0) : ch = ESC;
        }

        menu_controller(ch); // start as per user choice

    } while (ch != '6');

    file.close(); // closing the current file

    return 0;
}

void menu_controller(char ch)
{
    switch (ch)
    {
    case '1': // go to log in screen
        login();
        break;
    case '2': // go to create account screen
        create_account();
        break;
    case '3': // login Anonymously
        break;
    case '4': // show saved user details
        if (!display_users())
            std::cout << "No user in database" << std::endl;
        break;
    case '5': // details about the software and the shortcut/hint that can be used in it
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