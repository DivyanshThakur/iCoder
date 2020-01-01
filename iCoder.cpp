#include <iostream>
#include <fstream>
#include <limits>
#include "header/UIhandler.h"
#include "header/Filehandler.h"
#include "header/AccountHandler.h"
#include "header/Settings.h"

/*** GLOBAL VARIABLES ***/
std::string signedUserID;
int sleep_time = 50;
int emessage_timer = 25;

/** FUNCTION PROTOTYPES **/

void main_menu_controller(char ch);

/** CONSTANTS **/
const std::string fmenu = "./data/menu.dat";
const extern char ESC;
const extern int width_menu;
const extern std::string txtChar;

int main()
{
    if (check_new_user())
    {
        title(); // display title
        emessage(std::string{"--> Please see HELP section for hints and shortcuts..."});
    }

    if (check_signed_user())
        home(signedUserID); // if the user is saved in file it will automatically sign in the active user

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
        system("cls"); // clear the screen each time

        title(); // print the title = iCoder

        flag = menu(file, std::string{"MENU1"}, flag); // display the startup menu

        { // taking character from string
            std::string str = iscan(txtChar);
            (str != "") ? ch = str.at(0) : ch = ESC;
        }

        main_menu_controller(ch); // start as per user choice

    } while (ch != '7');

    file.close(); // closing the current file

    return 0;
}

void main_menu_controller(char ch)
{
    switch (ch)
    {
    case '1': // go to log in screen
        login();
        return;
    case '2': // go to create account screen
        create_account();
        return;
    case '3': // login Anonymously
        save_active_user(std::string{"User"});
        home(std::string{"User"});
        return;
    case '4': // show saved user details
        if (!display_users())
            std::cout << "No user in database" << std::endl;
        break;
    case '5': // details about the software and the shortcut/hint that can be used in it
        break;

    case '6': // Customize the software using settings
        settings();
        break;
    case '7': // exit the program
        break;
    case ESC: //ESC
        return;

    default:
        std::cout << std::endl
                  << std::endl
                  << "Invalid choice";
        break;
    }

    press_key(); // getch()
}

/** HINTS **/
/*

Press ESC to go to home and main menu

press esc , enter, backspace, space to continue in animate warning

themes

settings to change speed animation

*/