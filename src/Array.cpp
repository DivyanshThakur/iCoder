#include <iostream>
#include <sstream>
#include "../header/Array.hpp"
#include "../namespace/header/cod_array.hpp"
#include "../header/Scanner.hpp"
#include "../header/UIhandler.hpp"
#include "../header/Constants.hpp"

void Arrays()
{
    cod::array<int> int_arr;
    cod::array<long> long_arr;
    cod::array<double> double_arr;
    cod::array<char> char_arr;
    cod::array<std::string> str_arr;

    int ch{0};

    system("cls"); // clear the screen each timemenu_controller

    title(); // print the title = iCoder
    switch (get_dataType())
    {
    case 1:
        int_call();
        break;

    case 2:
        long_call();
        break;

    case 3:
        double_call();
        break;

    case 4:
        char_call();
        break;

    case 5:
        str_call();
        break;

    case ESC:
        return;

    default:
        print_message(std::string{"Invalid choice"});
        break;
    }

    do
    {
        system("cls"); // clear the screen each timemenu_controller

        title(); // print the title = iCoder

        menu(home_data); // display the startup menu

        Scanner sc;
        ch = sc.scanNum();

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

void int_call()
{
}
void long_call()
{
}

void double_call()
{
}
void char_call()
{
}
void str_call()
{
}