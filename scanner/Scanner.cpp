#include "Scanner.hpp"
#include <sstream>
#include <conio.h>

char Scanner::c;
std::string Scanner::value;

int checkKey(){
    
}

void Scanner::choice(int &choice)
{
    // reset();

    while ((c = getch()) && !(value.size() && c == '\r'))
    {
        switch (checkKey())
        {
        case -1: // Esc - last screen
            throw EscPressed();
        case 10: // a - about screen
            throw StartAbout();
        case 11: // c - code screen
            break;
        case 12: // d - disable hints
            // if (Global::showHint && opnScreen != CUR_SETTINGS)
            //     throw OpenAnimeSetting(9);
            break;
        case 14: // help screen
            throw StartHelp();
        case 15: // info screen
            break;
        case 16: // changelog screen
            throw StartChangelog();
        case 17: // home screen
            throw StartMore();
        case 18: // save changes
            break;
        case 19: // exit the software
            throw Exit();
        case 20: // settings screen
            throw StartSettings();
        case 21: // updates screen
            throw StartUpdate();
        default: // do nothing
            break;
        }
    }

    std::stringstream ss{value};

    if (!(ss >> choice))
        choice = cod::limits<int>::min();
}