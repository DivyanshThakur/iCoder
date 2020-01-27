#include <iostream>
#include <conio.h>

#include "../header/Scanner.hpp"
#include "../header/Constants.hpp"
#include "../header/UIhandler.hpp"

Scanner::Scanner() : isLimitExceed{false} {}

char Scanner::scanChar()
{
}
std::string Scanner::scanUsername()
{
    while ((c = getch()))
    {
        isLimitExceed = (value.size() >= static_cast<unsigned int>(width_username));

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
                emessage("     " + txtUsername + " exceeds " + std::to_string(width_username) + " characters!");
        }

        if (c >= '!' && c <= '~' && !isLimitExceed)
        {
            value.push_back(c); // add element at last of pass string

            std::cout << c;
        }
    }
    return value; // return char or string based on stype
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
    c = NULL;
    value.clear();
    isLimitExceed = false;
}