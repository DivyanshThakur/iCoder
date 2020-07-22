#include <iostream>
#include <sstream>
#include <windows.h>
#include "../header/cod_scan.hpp"
#include "../header/cod_limits.hpp"
#include "../../constant/Constants.hpp"
#include "../../constant/enum.hpp"

cod::scan::scan() : isLast{true}, isLimitExceed{false}, isString{false} {}

void cod::scan::print() const
{
    std::cout << ((c == '\r') ? '\n' : c);
}

template <typename T>
void cod::scan::assign(T &data)
{
    if (!(isLast))
    {
        print();
        isLast = true;
    }

    std::stringstream ss{value};

    if (!(ss >> data))
        throw InvalidInputException();
}

int cod::scan::check_char(bool isPassword)
{
    int flag{0};

    // -1 means that user has pressed ESC, stop the scan and return to startup menu
    if (c == Constant::ESC)
    {
        isLast = true;
        throw EscPressed();
    }

    else if (c == ' ')
    {
        if (isString && value.size())
        {
            value.push_back(c);
            std::cout << c;
        }
        else
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

int cod::scan::check_shortcut()
{
    int flag = check_char();

    switch (::tolower(c))
    {
    case 'a':
        flag = 10;
        break;
    case 'c':
        flag = 11;
        break;
    case 'd':
        flag = 12;
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

    return flag;
}

void cod::scan::choice(int &choice)
{
    reset();

    while ((c = getch()) && !(value.size() && c == '\r'))
    {
        switch (check_shortcut())
        {
        case -1: // Esc - last screen
            throw EscPressed();
        case 10: // a - about screen
            throw OpenAbout();
        case 11: // c - code screen
            break;
        case 12: // d - disable hints
            // if (Global::showHint && opnScreen != CUR_SETTINGS)
            //     throw OpenAnimeSetting(9);
            break;
        case 14: // help screen
            throw OpenHelp();
        case 15: // info screen
            break;
        case 16: // changelog screen
            throw OpenChangelog();
        case 17: // home screen
            throw OpenMoreScreen();
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
        isLimitExceed = (value.size() >= static_cast<unsigned int>(Constant::Ui::USERNAME_WIDTH));

        switch (check_char())
        {
        case -1:
            throw EscPressed();

        case 0:
            break;

        case 1:
            Ui::popUp("     Space Not Allowed!");
            break;

        case 2:
            Ui::popUp("     Username exceeds " + std::to_string(Constant::Ui::USERNAME_WIDTH) + " characters!");
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
        isLimitExceed = (value.size() >= static_cast<unsigned int>(Constant::Ui::PASSWORD_WIDTH));

        switch (check_char(true))
        {
        case -1:
            throw EscPressed();

        case 0:
            break;

        case 1:
            Ui::popUp(std::string{"     Space Not Allowed!"});
            break;

        case 2:
            Ui::popUp("     Password exceeds " + std::to_string(Constant::Ui::PASSWORD_WIDTH) + " characters!");
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

/*********************************************** TEMPLATE DECLARATIONS ***********************************************/

template void cod::scan::assign(int &data);
template void cod::scan::assign(size_t &data);
template void cod::scan::assign(long long &data);
template void cod::scan::assign(double &data);
template void cod::scan::assign(char &data);