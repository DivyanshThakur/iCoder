#include <iostream>
#include <sstream>
#include <conio.h>
#include "../header/Scanner.hpp"
#include "../header/Constants.hpp"
#include "../header/UIhandler.hpp"
#include "../header/ExHandler.hpp"
#include "../namespace/header/cod_limits.hpp"

Scanner::Scanner() : isLimitExceed{false} {}

void Scanner::print(const std::string &s) const
{
    (s != "") ? std::cout << s : std::cout << std::endl;
}

int Scanner::checkChar(bool isPassword)
{
    int flag{0};

    if (c == ESC)
        flag = -1; // -1 means that user has pressed ESC, stop the scanner and return to startup menu

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
    else if (c == 't')
        flag = 18;

    return flag;
}

void Scanner::scanChoice(int &choice)
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
        case 18:
            throw OpenLsearchSetting();
        default: // do nothing
            break;
        }
    }

    std::stringstream ss{value};

    if (!(ss >> choice))
        choice = cod::limits<int>::min();
}

std::string Scanner::scanUsername()
{
    reset();

    while ((c = getch()) && !(c == '\r' && value.size()))
    {
        isLimitExceed = (value.size() >= static_cast<unsigned int>(widthUsername));

        switch (checkChar())
        {
        case -1:
            return std::string{""};

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

std::string Scanner::scanPassword()
{
    reset();

    while ((c = getch()) && !(c == '\r' && value.size()))
    {
        isLimitExceed = (value.size() >= static_cast<unsigned int>(widthPassword));

        switch (checkChar(true))
        {
        case -1:
            return std::string{""};

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

void Scanner::reset()
{
    c = '\0';
    value.clear();
    isLimitExceed = false;
}

/** TEMPLATE FUNCTIONS **/

template <typename T>
void Scanner::scan(T &data, bool isLast)
{
    reset();
    int count{0};

    while ((c = getch()) && !(value.size() && c == '\r'))
    {
        if (c == ' ')
        {
            if (isLast)
                ++count;
            else if (value.size()) // will break only when the string has minimum 1 element
                break;

            if (count == 5)
                emessage(std::string{"     Press Enter to submit data"});
        }

        if (checkChar() == -1)
            throw EscPressed();
    }

    if (!isLast)
    {
        if (c == '\r')
            print();
        else if (c == ' ')
            print(" ");
    }

    std::stringstream ss{value};

    if (!(ss >> data))
        throw InvalidInputException();
}

template void Scanner::scan<int>(int &choice, bool isLast);
template void Scanner::scan<size_t>(size_t &choice, bool isLast);
template void Scanner::scan<long long>(long long &choice, bool isLast);
template void Scanner::scan<double>(double &choice, bool isLast);
template void Scanner::scan<char>(char &choice, bool isLast);
template void Scanner::scan<std::string>(std::string &choice, bool isLast);