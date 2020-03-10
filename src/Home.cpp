#include <iostream>
#include <memory>
#include "../header/Home.hpp"
#include "../header/Constants.hpp"
#include "../header/UIhandler.hpp"
#include "../header/AccountHandler.hpp"
#include "../header/Array.hpp"
#include "../header/Scanner.hpp"
#include "../namespace/header/cod_array.hpp"

void home(const std::string &userID)
{
    int ch{0};
    int flag{1};

    do
    {
        title(); // print the title = iCoder

        if (flag)
        {
            flag = 0;
            emessage("--> Welcome " + userID + "!"); // display the welcome message
        }

        menu(home_data); // display the startup menu

        Scanner sc;
        sc.scanChoice(ch);

        home_controller(ch); // start as per user choice

        if (ch == 7 || (ch == ESC && signedUserID == std::string{"NULL"}))
            return;

    } while (ch != 8); // exit the program when ch == 8

    exit(0);
}

void home_controller(int ch)
{
    switch (ch)
    {
    case 1: // arrays
        Arrays();
        return;

    case 2:              // strings
        print_message(); // default is ~ to be Implemented
        break;

    case 3: // matrices
        print_message();
        break;

    case 4: // sparse matrix
        print_message();
        break;

    case 5: // polynomial representation
        print_message();
        break;

    case 6: // linked list
        print_message();
        break;

    case 7: // sign out
        if (signedUserID != std::string{"NULL"})
            save_active_user(std::string{"NULL"});
        return;

    case 8: // exit the program
        return;

    case ESC:
        return;

    default:
        print_message(std::string{"Invalid choice"});
        break;
    }

    press_key(); // program paused - getch()
}