#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <direct.h>
#include <sys/stat.h>
#include "iCoder.h"

/*** GLOBAL VARIABLES ***/
extern int sleep_time;

/** FUNCTION PROTOTYPES **/

void show_menu();

void show_menu(const std::string &menu_data)
{

    for (auto c : menu_data)
    {
        std::cout << c; // printing all characters one by one in console
        Sleep(sleep_time);
    }
}

#endif