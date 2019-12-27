#ifndef ACCOUNTHANDLER_H
#define ACCOUNTHANDLER_H

#include <iostream>
#include <iomanip>
#include <string>
#include <conio.h>
#include "UIhandler.h"
#include "ScreenLoader.h"

/** FUNCTION PROTOTYPES **/

void login();
void load();
//void mainMenu(const std::string &username);

/** CONSTANTS **/
const extern int sleep_time;
const std::string username {"Username: "};
const std::string password {"Password: "};


void login() {
    system("cls");
    
    title();          // display the "iCoder" title

    std::string userID, pass;

    std::cout << std::setfill('-') 
              << std::setw(2) << ""
              << " LOGIN "                             // display menu title
              << std::setw(width_menu - 9) << ""
              << std::endl;

    for(auto c: username) {
        std::cout << c;
        Sleep(sleep_time);
    }

    std::cin >> userID;             // taking username from user

    for(auto c: password) {
        std::cout << c;
        Sleep(sleep_time);
    }

    char c;
    while(c = getch())  {           // taking password from user
        if(c=='\r') break;
        pass += c;
        std::cout << "*";
    }
    std::cout << std::endl
              << std::setw(width_menu) << ""
              << std::setfill(' ') << std::endl;

    load();                         // animate loading screen

    //mainMenu(username);             // calling the main menu screen to show all program list

}

#endif