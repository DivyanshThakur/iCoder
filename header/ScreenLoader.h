#include <iostream>
#include <ctime>
#include <windows.h>

const extern int sleep_time;

void load() {

    srand(time(0));         // it will generate unique random numbers each time

    std::string loader {"LOADING..."};

    for(int i {0}; i <= rand()%20 + (rand()%10)*2 + 10 ; ++i) {
        if(i%10 == 0) std::cout << "\r          \r";            // erasing current line
        std::cout << loader.at(i%loader.size());                // display char one by one
        Sleep(sleep_time * 2);                                  // delay
    }
    std::cout << std::endl;
}