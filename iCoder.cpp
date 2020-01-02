#include <iostream>
#include <fstream>
#include <limits>
#include "header/AccountHandler.h"
#include "header/UIhandler.h"
#include "header/Menuhandler.h"
#include "header/Settings.h"

/*** GLOBAL VARIABLES ***/
std::string signedUserID;
extern int sleep_time;
extern int emessage_timer;

/** FUNCTION PROTOTYPES **/
void main_menu_controller(char ch);
void makeDirectory();
bool isDirectoryExists();

/** CONSTANTS **/
const extern char ESC;
const extern std::string txtChar;
const extern std::string menu1_data;

int main()
{
    if (!isDirectoryExists())
        makeDirectory();

    if (check_new_user())
    {
        title(); // display title
        emessage(std::string{"--> See HELP for hints and shortcuts..."});
    }

    if (check_signed_user())
        home(signedUserID); // if the user is saved in file it will automatically sign in the active user

    char ch{};
    int flag{1};

    do
    {
        system("cls"); // clear the screen each time

        title(); // print the title = iCoder

        flag = menu(menu1_data, flag); // display the startup menu

        { // taking character from string
            std::string str = iscan(txtChar);
            (str != "") ? ch = str.at(0) : ch = ESC;
        }

        main_menu_controller(ch); // start as per user choice

    } while (ch != '7');

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

void makeDirectory()
{
    // these code will create a folder in that specific destination
    std::string dirpath{"data"};
    mkdir(dirpath.c_str());
}

bool isDirectoryExists()
{
    DWORD attribs = ::GetFileAttributesA("data");

    if (attribs == INVALID_FILE_ATTRIBUTES)
        return false;

    return (attribs & FILE_ATTRIBUTE_DIRECTORY);
}

/** HINTS **/
/*

Press ESC to go to home and main menu

press esc , enter, backspace, space to continue in animate warning

themes

settings to change speed animation

*/