#include <iostream>
#include <fstream>
#include <limits>
#include <windows.h>
#include <conio.h>
#include <dir.h>
#include "header/Constants.hpp"
#include "header/UIhandler.hpp"
#include "header/AccountHandler.hpp"
#include "header/Home.hpp"
#include "header/Settings.hpp"
#include "header/Scanner.hpp"

/** FUNCTION PROTOTYPES **/
void main_menu_controller(int ch);
void makeDirectory();
bool isDirectoryExists();
void about();

int main()
{
    if (!isDirectoryExists()) // checking if the directory "data" exists or not
        makeDirectory();      // if it doesn't exists then it will create the directory

    if (check_new_user()) // if there is no current user, it displays below message
    {
        title();                                                                     // display title
        emessage(std::string{" HINT --> Use ESC key to return to previous screen"}); // 1 time message to user
    }

    if (check_active_user()) // checking for current signed user
        home(signedUserID);  // if the user is saved in file it will automatically sign in the active user
    else
        save_active_user(std::string{"NULL"}); // if no current user, NULL is passed

    int ch{0};

    do
    {
        system("cls"); // clear the screen each time

        title(); // print the title = iCoder

        menu(main_menu_data); // display the startup menu

        Scanner sc;
        sc.scanChoice(ch); // scan user's choice

        main_menu_controller(ch); // start as per user choice

    } while (ch != 7); // the program terminates after this line

    return 0;
}

void main_menu_controller(int ch)
{
    switch (ch)
    {
    case 1: // go to log in screen
        login();
        break;

    case 2: // go to create account screen
        create_account();
        break;

    case 3: // login Anonymously
        home(std::string{"User"});
        break;

    case 4: // show saved user details
        display_users();
        press_key(); // getch()
        break;

    case 5: // details about the software
        about();
        break;

    case 6: // Customize the software using settings
        settings();
        break;

    case 7: // exit the program
        break;

    case ESC: //ESC
        break;

    default:
        print_message(std::string{"Invalid choice"});
        press_key(); // getch()
        break;
    }
}

void makeDirectory()
{
    // these code will create a folder in that specific destination
    std::string dirpath{"data"};
    mkdir(dirpath.c_str());
}

bool isDirectoryExists()
{
    // code to check if a Directory exists or not
    DWORD attribs = ::GetFileAttributesA("data");

    if (attribs == INVALID_FILE_ATTRIBUTES)
        return false;

    return (attribs & FILE_ATTRIBUTE_DIRECTORY);
}

void about()
{
    char ch;

    system("cls"); // clear the screen each time

    title(); // print the title = iCoder

    header(std::string{" ABOUT "});

    std::cout << "Developer: " << dev_name << std::endl
              << "Version: " << version_info;

    border(width_menu);

    std::cout << "Source code:" << std::endl
              << scode_url.substr(8);

    border(width_menu);

    std::cout << "Press i to open URL";

    ch = getch();

    if (::tolower(ch) == 'i') // this code will open github source code in default browser
        system(std::string("start " + scode_url).c_str());
    else
        return;
}