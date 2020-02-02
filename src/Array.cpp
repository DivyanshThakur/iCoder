#include <iostream>
#include <sstream>
#include "../header/Array.hpp"
#include "../namespace/header/cod_array.hpp"
#include "../header/Scanner.hpp"
#include "../header/UIhandler.hpp"

void Arrays()
{
    int ch{0};

    do
    {
        system("cls"); // clear the screen each timemenu_controller

        title(); // print the title = iCoder

        menu(home_data); // display the startup menu

        Scanner sc;
        ch = sc.scanChoice();

        arrays_controller(ch); // start as per user choice

        if (ch == 7)
            return;

    } while (ch != 8); // exit the program when ch == 8

    exit(0);
}

void arrays_controller(int ch)
{
    // switch (ch)
    // {
    // case 1: // arrays
    //     Arrays();
    //     break;

    // case 2:              // strings
    //     print_message(); // default is ~ to be Implemented
    //     break;

    // case 3: // matrices
    //     print_message();

    //     break;

    // case 4: // sparse matrix
    //     print_message();

    //     break;

    // case 5: // polynomial representation
    //     print_message();
    //     break;

    // case 6: // linked list
    //     print_message();
    //     break;

    // case 7: break;

    // case 8: // exit the program
    //     break;

    // case ESC: //ESC
    //     return;

    // default:
    //     print_message(std::string{"Invalid choice"});
    //     break;
    // }

    // press_key(); // program paused - getch()
}
