#ifndef UIHANDLER_H
#define UIHANDLER_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>
#include <string>

/** FUNCTION PROTOTYPES **/

void title();
int menu(std::ifstream &file, std::string this_menu, int flag);

/** CONSTANTS **/
const int sleep_time = 50;
const int width_menu = 20;
const int width_title = 30;


void title() {          // this display the title at top of screen

        const std::string title {"iCoder"};

        std::cout << std::setw(width_menu) << ""
                  << std::setw(width_title) << std::setfill('=') << ""
                  << std::setfill(' ') << std::endl
                  << std::setw(width_menu + width_title/2 - title.size()/2) << ""
                  << title << std::endl
                  << std::setw(width_menu) << ""
                  << std::setw(width_title) << std::setfill('=') << ""
                  << std::setfill(' ')
                  << std::endl << std::endl;
}


int menu(std::ifstream &file, std::string this_menu, int flag) {        // show the specific menu

    char c;
    std::string fmenu;
    
    std::cout << std::setfill('-')
              << std::setw(2) << ""
              << " MENU "
              << std::setw(width_menu - 8) << ""
              << std::endl;
    while(file >> fmenu) {

        if(fmenu == this_menu) {
            
            while(file.get(c) && c!='~') {
                std::cout << c;
                if(flag)
                Sleep(sleep_time);          // delay
            }
        }
    }
    
    flag = 0;
    file.clear();
    file.seekg(0, std::ios::beg);

    std::cout << std::endl
              << std::setw(width_menu) << ""
              << std::setfill(' ') << std::endl
              << "Your Choice : ";
              
    return flag;
}

#endif