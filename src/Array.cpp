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
        init_array<long long>();
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

    update_size<T>(arr);

    do
    {
        system("cls"); // clear the screen each timemenu_controller

        title(); // print the title = iCoder

        if (arr.max_size())
            menu(menu_update_size + array_data);
        else
            menu(menu_create_size + array_data);

        sc.scan(ch);

        if (ch == ESC || ch == 5)
            return;

        arrays_controller<T>(arr, ch);

    } while (ch != 6); // exit at ch==6
    exit(0);
}

template <typename T>
void arrays_controller(cod::array<T> &arr, int ch)
{
    switch (ch)
    {
    case 1: // add or update size of array
        update_size<T>(arr);
        break;

    case 2:
        print_message(); // default is ~ to be Implemented
        press_key();     // program paused - getch()
        break;

    case 3:
        print_message();
        press_key(); // program paused - getch()
        break;

    case 4:
        print_message();
        press_key(); // program paused - getch()
        break;

    case 6: // exit the program
        break;

    default:
        print_message(std::string{"Invalid choice"});
        press_key(); // program paused - getch()
        break;
    }
}

template <typename T>
void update_size(cod::array<T> &arr)
{
    Scanner sc;
    int size;

    system("cls"); // clear the screen each timemenu_controller

    title(); // print the title = iCoder

    header(std::string{" ARRAY SIZE "});

    animater(std::string{"Enter size: "});

    sc.scan(size);
    arr.set_size(size);

    std::cout << "Enter the values:" << std::endl;

    sc >> arr;
    std::cout << arr;

    igetch();
}