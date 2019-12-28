#include <iostream>
#include <fstream>
#include <limits>
#include "header/UIhandler.h"
#include "header/Filehandler.h"
#include "header/AccountHandler.h"

/** FUNCTION PROTOTYPES **/

void createFile();
void title();
int menu(std::ifstream &file, std::string this_menu, int flag);
void menu_controller(char ch);
void login();

std::string iscan(const std::string &stype);

/** CONSTANTS **/
const std::string fmenu = "./data/menu.txt";
const extern char ESC;
const extern int width_menu;
const extern std::string txtPassword;
const extern std::string txtString;
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
        {                                              // taking character from string
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
    std::cout << std::endl
              << std::setfill('-')
              << std::setw(width_menu) << ""
              << std::setfill(' ') << std::endl;
    std::cout << "Press Enter to continue";
    std::cin.get();
}