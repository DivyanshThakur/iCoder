#include <iostream>
#include <conio.h>

#include "../header/Scanner.hpp"
#include "../header/Constants.hpp"
#include "../header/UIhandler.hpp"

Scanner::Scanner() : isLimitExceed{false} {}

int Scanner::checkChar(bool isPassword)
{
    int flag{0};

    if (c == ESC)
        flag = -1; // -1 means that user has pressed ESC, stop the scanner and return to startup menu

    else if (c == ' ')
        flag = 1;

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

char Scanner::scanChar()
{
    return '\0';
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
    return value;
}

std::string Scanner::scanPassword()
{
    while ((c = getch()))
    { // taking input from user
        isLimitExceed = (value.size() >= static_cast<unsigned int>(width_password));

        if (c == '\r' && value.size())
            break; // if user presses enter end while loop and save the value

        if (c == ESC) // if user presses esc, it returnss to startup menu
            return std::string{""};

        if (c == '\b' && value.size())
        {                         // cheking backspace and limit it to size of value
            std::cout << "\b \b"; // remove last element from console
            value.pop_back();     // remove last element from pass string
        }
        else
        {
            if (c == ' ')
                emessage(std::string{"     Space Not Allowed!"});
            else if (isLimitExceed)
                emessage("     " + txtPassword + " exceeds " + std::to_string(width_password) + " characters!");
        }

        if (c >= '!' && c <= '~' && !isLimitExceed)
        {
            value.push_back(c); // add element at last of pass string

            std::cout << "*";
        }
    }
    return value; // return char or string based on stype
}

// inline std::string Scanner::scan(const int &size_limit)
// {
//     isLimitExceed = (value.size() >= static_cast<unsigned int>(width_username));
// }

void Scanner::reset()
{
    c = '\0';
    value.clear();
    isLimitExceed = false;
}