#include <iostream>
#include <fstream>
#include <limits>
#include "header/UIhandler.h"
#include "header/Filehandler.h"
#include "header/AccountHandler.h"

/** FUNCTION PROTOTYPES **/
// this is the iscanner branch bebe

void createFile();
void title();
int menu(std::ifstream &file, std::string this_menu, int flag);
void menu_controller(char ch);
void login();

/** CONSTANTS **/
const std::string fmenu = "./data/menu.txt";
const extern int width_menu;

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

        ch = charscan();

        std::cout << std::endl
                  << std::endl;

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

    default:
        std::cout << "Invalid choice";
        break;
    }
    std::cout << std::endl
              << std::setfill('-')
              << std::setw(width_menu) << ""
              << std::setfill(' ') << std::endl;
    std::cout << "Press Enter to continue";
    std::cin.get();
}