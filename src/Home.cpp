#include <iostream>
#include <memory>
#include "../header/Home.hpp"
#include "../header/Constants.hpp"
#include "../header/UIhandler.hpp"
#include "../header/AccountHandler.hpp"
#include "../header/Array.hpp"

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

        flag = menu(home_data, flag); // display the startup menu

        { // taking character from string
            std::string str = iscan(txtChar);
            (str != "") ? ch = str.at(0) : ch = ESC;
        }

        home_controller(ch); // start as per user choice

        if (ch == '7')
            return;

    } while (ch != '8'); // exit the program when ch == 8

    exit(0);
}

void home_controller(char ch)
{
    switch (ch)
    {
    case '1':            // arrays
        print_message(); // default is ~ to be Implemented
        break;

    case '2': // strings
        print_message();
        break;

    case '3': // matrices
        print_message();

        break;

    case '4': // sparse matrix
        print_message();

        break;

    case '5': // polynomial representation
        print_message();
        break;

    case '6': // linked list
        print_message();
        break;

    case '7': // sign out
        if (signedUserID != std::string{"NULL"})
            save_active_user(std::string{"NULL"});
        return;

    case '8': // exit the program
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