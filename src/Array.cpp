#include <iostream>
#include <sstream>
#include "../header/Array.hpp"
#include "../namespace/header/cod_array.hpp"
#include "../header/Scanner.hpp"
#include "../header/UIhandler.hpp"
#include "../header/Constants.hpp"

void Arrays()
{

    int ch{0};

    do
    {
        system("cls"); // clear the screen each timemenu_controller

        title(); // print the title = iCoder

        menu(get_dataType_data, std::string{" SELECT DATA TYPE "});

        Scanner sc;
        sc.scan(ch);

        if (ch == ESC || ch == 6)
            return;

        if (array_type_selector(ch)) // call the array funtion with user defined data type
            return;

    } while (1); // always true
}

bool array_type_selector(int ch)
{

    switch (ch)
    {
    case 1:
        init_array<int>();
        break;

    case 2:
        init_array<long>();
        break;

    case 3:
        init_array<double>();
        break;

    case 4:
        init_array<char>();
        break;

    case 5:
        init_array<std::string>();
        break;

    default:
        print_message(std::string{"Invalid choice"});
        press_key(); // program paused - getch()
        return false;
    }
    return true;
}

/*** TEMPLATE FUNTIONS ARE CODED BELOW ***/

template <typename T>
void init_array()
{
    cod::array<T> arr;
    Scanner sc;
    int ch{0};

    do
    {
        system("cls"); // clear the screen each timemenu_controller

        title(); // print the title = iCoder

        if (arr.max_size())
            menu(menu_create_size + array_data);
        else
            menu(menu_update_size + array_data);

        arrays_controller<T>(ch);
        sc.scan(ch);

        if (ch == ESC || ch == 6)
            return;
        create_array<T>(arr);

    } while (1); // always true
    // display_array_menu();
}

template <typename T>
void arrays_controller(int ch)
{
    switch (ch)
    {
    case 1:              // arrays
        print_message(); // default is ~ to be Implemented
        // Arrays();
        break;

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

    case 7:
        break;

    case 8: // exit the program
        break;

    case ESC: //ESC
        return;

    default:
        print_message(std::string{"Invalid choice"});
        break;
    }

    press_key(); // program paused - getch()
}

template <typename T>
void create_array(cod::array<T> &arr)
{
    Scanner sc;
    int size;

    std::cout << "\nEnter the size of array: ";

    sc.scan(size);
    arr.set_size(size);
}