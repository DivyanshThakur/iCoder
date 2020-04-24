#include <iostream>
#include <windows.h>
#include "../header/cod_scan.hpp"
#include "../header/cod_limits.hpp"
#include "../../header/Constants.hpp"

cod::scan::scan() : isLast{true}, isLimitExceed{false}, isString{false} {}

void cod::scan::print(const std::string &s) const
{
    (s != "") ? std::cout << s : std::cout << std::endl;
}

int cod::scan::checkChar(bool isPassword)
{
    int flag{0};

    if (c == Ui::ESC)
        return -1; // -1 means that user has pressed ESC, stop the scan and return to startup menu

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

    if (shortcutStats == DEFAULT) // shortcut checking
    {
        switch (::tolower(c))
        {
        case 'a':
            flag = 10;
            break;
        case 'c':
            flag = 11;
            break;
        case 'd':
            flag = (isquitConditionEnabled) ? 12 : 13;
            break;
        case 'h':
            flag = 14;
            break;
        case 'i':
            flag = 15;
            break;
        case 'l':
            flag = 16;
            break;
        case 'm':
            flag = 17;
            break;
        case 'p':
            flag = 18;
            break;
        case 'q':
            flag = 19;
            break;
        case 's':
            flag = 20;
            break;
        case 'u':
            flag = 21;
            break;
        }
    }
    else if (shortcutStats == EASY)
    {
        // & 0x8000 is used for current pressed state
        if (GetAsyncKeyState(VK_CONTROL) && GetAsyncKeyState(0x41) & 0x8000) // ctrl + a
            flag = 10;
        else if (GetAsyncKeyState(VK_CONTROL) && GetAsyncKeyState(0x43) & 0x8000) // ctrl + c
            flag = 11;
        else if (GetAsyncKeyState(VK_CONTROL) && GetAsyncKeyState(0x44) & 0x8000) // ctrl + d
            flag = (isquitConditionEnabled) ? 12 : 13;
        else if (GetAsyncKeyState(VK_CONTROL) && GetAsyncKeyState(0x48) & 0x8000) // ctrl + h
            flag = 14;
        else if (GetAsyncKeyState(VK_CONTROL) && GetAsyncKeyState(0x49) & 0x8000) // ctrl + i
            flag = 15;
        else if (GetAsyncKeyState(VK_CONTROL) && GetAsyncKeyState(0x4C) & 0x8000) // ctrl + l
            flag = 16;
        else if (GetAsyncKeyState(VK_CONTROL) && GetAsyncKeyState(0x4D) & 0x8000) // ctrl + m
            flag = 17;
        else if (GetAsyncKeyState(VK_CONTROL) && GetAsyncKeyState(0x50) & 0x8000) // ctrl + p
            flag = 18;
        else if (GetAsyncKeyState(VK_CONTROL) && GetAsyncKeyState(0x51) & 0x8000) // ctrl + q
            flag = 19;
        else if (GetAsyncKeyState(VK_CONTROL) && GetAsyncKeyState(0x53) & 0x8000) // ctrl + s
            flag = 20;
        else if (GetAsyncKeyState(VK_CONTROL) && GetAsyncKeyState(0x55) & 0x8000) // ctrl + u
            flag = 21;
    }

    return flag;
}

void cod::scan::choice(int &choice)
{
    reset();

    while ((c = getch()) && !(value.size() && c == '\r'))
    {
        switch (checkChar())
        {
        case -1: // Esc - last screen
            throw EscPressed();
        case 10: // a - about screen
            throw OpenAbout();
        case 11: // c - code screen
            break;
        case 13: // d - disable hints
            if (Global::showHint && opnScreen != CUR_SETTINGS)
                throw OpenAnimeSetting(9);
            break;
        case 14: // help screen
            throw OpenHelp();
        case 15: // info screen
            break;
        case 16: // changelog screen
            throw OpenChangelog();
        case 17: // home screen
            throw OpenHomeScreen();
        case 18: // save changes
            break;
        case 19: // exit the software
            throw Exit();
        case 20: // settings screen
            throw OpenSettings();
        case 21: // updates screen
            throw OpenUpdate();
        default: // do nothing
            break;
        }
    }

    std::stringstream ss{value};

    if (!(ss >> choice))
        choice = cod::limits<int>::min();
}

void cod::scan::is_string(bool isStr)
{
    this->isString = isStr;
}

std::string cod::scan::username()
{
    reset();

    while ((c = getch()) && !(c == '\r' && value.size()))
    {
        isLimitExceed = (value.size() >= static_cast<unsigned int>(Ui::widthUsername));

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
            emessage("     " + Ui::txtUsername + " exceeds " + std::to_string(Ui::widthUsername) + " characters!");
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
        isLimitExceed = (value.size() >= static_cast<unsigned int>(Ui::widthPassword));

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
            emessage("     " + Ui::txtPassword + " exceeds " + std::to_string(Ui::widthPassword) + " characters!");
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