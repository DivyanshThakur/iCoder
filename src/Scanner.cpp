#include <iostream>
#include <sstream>
#include <conio.h>

#include "../header/Scanner.hpp"
#include "../header/Constants.hpp"
#include "../header/UIhandler.hpp"

Scanner::Scanner() : isLimitExceed{false} {}

bool Scanner::print(const std::string &s) const
{
    (s != "") ? std::cout << s : std::cout << std::endl;
    return true;
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
        choice = -1;
}

bool Scanner::scan(double &choice)
{
    reset();

    while ((c = getch()) && !(value.size() && (c == '\r' || c == ' ')))
    {
        if (checkChar() == -1)
            return false;
    }

    if (c == '\r')
        print();
    else if (c == ' ')
        print(" ");

    std::stringstream ss{value};

    if (!(ss >> choice))
        choice = -1;
    return true;
}

bool Scanner::scan(int &choice)
{
    double value;
    if (!scan(value))
        return false;

    choice = static_cast<int>(value);
    return true;
}

bool Scanner::scan(long long &choice)
{
    double value;
    if (!scan(value))
        return false;

    choice = static_cast<long long>(value);
    return true;
}

bool Scanner::scan(char &choice)
{
    reset();

    while ((c = getch()) && !(value.size() && (c == '\r' || c == ' ')))
    {
        if (checkChar() == -1)
            return false;
    }

    if (c == '\r')
        print();
    else if (c == ' ')
        print(" ");

    choice = value.at(0);
    return true;
}

bool Scanner::scan(std::string &choice)
{
    reset();

    while ((c = getch()) && !(value.size() && (c == '\r' || c == ' ')))
    {
        if (checkChar() == -1)
            return false;
    }

    if (c == '\r')
        print();
    else if (c == ' ')
        print(" ");

    choice = value;
    return true;
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