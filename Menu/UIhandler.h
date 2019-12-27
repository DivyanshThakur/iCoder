#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>

/** CONSTANTS **/
const int width_menu = 20;
const int width_title = 30;


void title(const std::string &title) {

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


int menu(std::ifstream &file, int flag) {

    char c;
    
    std::cout << std::setfill('-')
              << std::setw(2) << ""
              << " MENU "
              << std::setw(width_menu - 8) << ""
              << std::endl;

    while(file.get(c)) {
        std::cout << c;
        if(flag)
        Sleep(50);
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