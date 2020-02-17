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

    return flag;
}

void Scanner::scanChoice(int &choice)
{
    reset();

    while ((c = getch()) && !(value.size() && c == '\r'))
    {
        if (checkChar() == -1)
        {
            choice = ESC;
            return;
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
        isLimitExceed = (value.size() >= static_cast<unsigned int>(width_username));

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
            emessage("     " + txtUsername + " exceeds " + std::to_string(width_username) + " characters!");
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
        isLimitExceed = (value.size() >= static_cast<unsigned int>(width_password));

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
            emessage("     " + txtPassword + " exceeds " + std::to_string(width_password) + " characters!");
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
            else
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