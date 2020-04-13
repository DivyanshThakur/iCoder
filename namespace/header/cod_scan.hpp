#ifndef COD_SCAN_HPP
#define COD_SCAN_HPP

#include <string>
#include <sstream>
#include <conio.h>
#include "../../header/ExHandler.hpp"
#include "../../header/UIhandler.hpp"

namespace cod
{
class scan
{
    friend scan &operator>>(scan &sc, const bool &last)
    {
        sc.isLast = last;
        return sc;
    }

    friend scan &operator>>(scan &sc, char &data)
    {
        sc.reset();

        while ((sc.c = getch()) && !(sc.value.size() && (sc.c == '\r' || sc.c == ' ')))
        {
            if (sc.value.size() > 0)
                sc.isLimitExceed = true;
            else
                sc.isLimitExceed = false;

            switch (sc.checkChar())
            {
            case -1:
                throw EscPressed();
                break;

            case 12: // display quit message
                isquitConditionEnabled = false;
                if (showQuit)
                    throw OpenAnimeSetting(8); // quit message
                break;
            }
        }

        if (!(sc.isLast))
        {
            if (sc.c == '\r')
                sc.print();
            else if (sc.c == ' ')
                sc.print(" ");

            sc.isLast = true;
        }

        std::stringstream ss{sc.value};

        if (!(ss >> data))
            throw InvalidInputException();

        return sc;
    }

    template <typename T>
    friend scan &operator>>(scan &sc, T &data)
    {
        sc.reset();

        while ((sc.c = getch()) && !(sc.value.size() && (sc.c == '\r' || sc.c == ' ')))
        {
            if (sc.checkChar() == -1)
                throw EscPressed();
        }

        if (!(sc.isLast))
        {
            if (sc.c == '\r')
                sc.print();
            else if (sc.c == ' ')
                sc.print(" ");

            sc.isLast = true;
        }

        std::stringstream ss{sc.value};

        if (!(ss >> data))
            throw InvalidInputException();

        return sc;
    }

private:
    char c;
    bool isLast;
    std::string value;
    bool isLimitExceed;

    int checkChar(bool isPassword = false);
    void print(const std::string &s = "") const;

public:
    scan(); // type of string - username, pass, char

    void choice(int &choice);

    std::string username();
    std::string password();

    void reset(); // reset the values of scan class
};
} // namespace cod

#endif