#include <iostream>
#include <fstream>
#include <windows.h>
#include <iomanip>
#include <limits>

/** FUNCTION PROTOTYPES **/

void title(const std::string &title);
void menu(std::ifstream &file);
void menu_controller(char ch);

/** CONSTANTS **/
const int width_menu = 20;
const int width_title = 30;

int main() {

    std::ifstream file;
    file.open("./menu/menu1.txt");
    if(!file) {             // validating opening of file
        std::cerr << "Error Opening file." << std::endl;
        std::cin.get();
        return 1;
    }

    char ch {};

    do {
    system("cls");          // clear the screen each timemenu_controller

    title("iCoder");        // print the title = iCoder

    menu(file);             // display the startup menu

    std::cin >> ch;
    menu_controller(ch);    // start as per user choice
    
    } while(ch != '5');

    file.close();           // closing the current file

    return 0;
}

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

void menu(std::ifstream &file) {

    char c;
    static int flag = 1;
    

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
}

void menu_controller(char ch) {
    switch(ch) {
        case '1':             // go to log in screen
                std::cout << "log in" << std::endl;
                break;

        case '5':
                break;
        
        default:
                std::cout << "\nInvalid choice" << std::endl;
                break;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Press Enter to continue";
    std::cin.get();
}