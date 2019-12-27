#include <iostream>
#include <fstream>
#include <limits>
#include "header/UIhandler.h"

/** FUNCTION PROTOTYPES **/

void title(const std::string &title);
int menu(std::ifstream &file,std::string this_menu, int flag);
void menu_controller(char ch);


int main() {

    std::ifstream file;
    file.open("./data/menu.txt");
    if(!file) {                // validating opening of file
        std::cerr << "Error Opening file." << std::endl;
        std::cin.get();
        return 1;
    }

    char ch {};
    int flag {1};

    do {
    system("cls");              // clear the screen each timemenu_controller

    title("iCoder");            // print the title = iCoder

    flag = menu(file, std::string {"MENU1"}, flag);    // display the startup menu

    std::cin >> ch;
    std::cout << std::endl;

    menu_controller(ch);        // start as per user choice
    
    } while(ch != '5');

    file.close();               // closing the current file

    return 0;
}


void menu_controller(char ch) {
    switch(ch) {
        case '1':               // go to log in screen
                std::cout << "log in" << std::endl;
                break;

        case '5':
                break;
        
        default:
                std::cout << "Invalid choice" << std::endl;
                break;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Press Enter to continue";
    std::cin.get();
}