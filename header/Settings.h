#ifndef SETTINGS_H
#define SETTINGS_H

#include <iostream>
#include <sstream>
#include <windows.h>
#include "UIhandler.h"

/*** GLOBAL VARIABLES ***/
int sleep_time = 50;
int emessage_timer = 25;

/** CONSTANTS **/
const extern std::string txtChar;

void settings()
{
    std::string str;
    std::cout << "\n\nEnter the speed" << std::endl;
    str = iscan(txtChar);
    if (str == "")
        return;

    std::stringstream ss(str);

    if (!(ss >> sleep_time))
    {
        std::cout << "Enter a valid number" << std::endl;
    }
}

#endif