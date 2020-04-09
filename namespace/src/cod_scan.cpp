#include <iostream>
#include "../header/cod_scan.hpp"
#include "../header/cod_limits.hpp"
#include "../../header/Constants.hpp"

cod::scan::scan() : isLast{true}, isLimitExceed{false} {}

void cod::scan::print(const std::string &s) const
{
    (s != "") ? std::cout << s : std::cout << std::endl;
}

int cod::scan::checkChar(bool isPassword)
{
    int flag{0};

    if (c == ESC)
        flag = -1; // -1 means that user has pressed ESC, stop the scan and return to startup menu

    else if (c == ' ')
    {
        flag = 1;
    }
    else if (c == '\b' && value.size())
    {                         // cheking backspace and limit it to size of value
        std::cout << "\b \b"; // remove last element from console
        value.pop_back();     // remove last element from pass string
    }

    else if (isLimitExceed)
        flag = 2;

    else if (c >= '!' && c <= '~')
    {
        flag = 3;

        value.push_back(c); // add element at last of pass string

        std::cout << (isPassword ? '*' : c);
    }

    // shortcut checking
    c = ::tolower(c);

    // switch(::tolower(c)){
    //     case 'q':
    //     break;
    // }

    if (c == 'q')
        flag = 11;
    else if (c == 's')
        flag = 12;
    else if (c == 'a')
        flag = 13;
    else if (c == 'h')
        flag = 14;
    else if (c == 'u')
        flag = 15;
    else if (c == 'l')
        flag = 16;
    else if (c == 'd')
        flag = 17;

    return flag;
}

void cod::scan::choice(int &choice)
{
    reset();

    while ((c = getch()) && !(value.size() && c == '\r'))
    {
        switch (checkChar())
        {
        case -1:
            throw EscPressed();
        case 11:
            throw Exit();
        case 12:
            throw OpenSettings();
        case 13:
            throw OpenAbout();
        case 14:
            throw OpenHelp();
        case 15:
            throw OpenUpdate();
        case 16:
            throw OpenChangelog();
        case 17:
            throw OpenHintSetting();
        default: // do nothing
            break;
        }
    }

    std::stringstream ss{value};

    if (!(ss >> choice))
        choice = cod::limits<int>::min();
}

std::string cod::scan::username()
{
    reset();

    while ((c = getch()) && !(c == '\r' && value.size()))
    {
        isLimitExceed = (value.size() >= static_cast<unsigned int>(widthUsername));

        switch (checkChar())
        {
        case -1:
            throw EscPressed();

        case 0:
            break;

        case 1:
            emessage(std::string{"     Space Not Allowed!"});
            break;

        case 2:
            emessage("     " + txtUsername + " exceeds " + std::to_string(widthUsername) + " characters!");
            break;
        }
    }

    if (c == '\r')
        print();

    return value;
}

std::string cod::scan::password()
{
    reset();

    while ((c = getch()) && !(c == '\r' && value.size()))
    {
        isLimitExceed = (value.size() >= static_cast<unsigned int>(widthPassword));

        switch (checkChar(true))
        {
        case -1:
            throw EscPressed();

        case 0:
            break;

        case 1:
            emessage(std::string{"     Space Not Allowed!"});
            break;

        case 2:
            emessage("     " + txtPassword + " exceeds " + std::to_string(widthPassword) + " characters!");
            break;
        }
    }
    return value;
}

void cod::scan::reset()
{
    value.clear();
    isLimitExceed = false;
}