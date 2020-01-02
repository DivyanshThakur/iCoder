#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <direct.h>
#include <sys/stat.h>

/*** GLOBAL VARIABLES ***/
extern int sleep_time;

/** FUNCTION PROTOTYPES **/

void show_menu();

/** CONSTANTS **/
const std::string menu1_data{"1. Log In\n2. Create Account\n3. Try (Anonymous)\n4. Users\n5. About\n6. Settings\n7. Exit"};
const std::string menu2_data{"1. Array\n2. Recursion\n3. Linked List\n4. Main Menu (Sign Out)\n5. Exit"};

void show_menu(const std::string &menu_data)
{

    for (auto c : menu_data)
    {
        std::cout << c; // printing all characters one by one in console
        Sleep(sleep_time);
    }
}

#endif