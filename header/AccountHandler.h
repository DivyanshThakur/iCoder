#ifndef ACCOUNTHANDLER_H
#define ACCOUNTHANDLER_H

#include <iostream>
#include <iomanip>
#include <string>
#include <conio.h>
#include "UIhandler.h"

/** FUNCTION PROTOTYPES **/

void login();

/** CONSTANTS **/
const extern int sleep_time;
const std::string username {"Username: "};
const std::string password {"Password: "};


void login() {
    system("cls");
    
    title();

    std::string userID, pass;

    std::cout << std::setfill('-')
              << std::setw(2) << ""
              << " LOGIN "
              << std::setw(width_menu - 9) << "" << std::setfill(' ')
              << std::endl;

    for(auto c: username) {
        std::cout << c;
        Sleep(sleep_time);
    }

    std::cin >> userID;

    for(auto c: password) {
        std::cout << c;
        Sleep(sleep_time);
    }

    char c;
    while(c = getch())  {
        if(c=='\r') break;
        pass += c;
        std::cout << "*";
    }

}

#endif