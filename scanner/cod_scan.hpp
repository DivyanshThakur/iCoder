#ifndef COD_SCAN_HPP
#define COD_SCAN_HPP

#include <iostream>
#include <conio.h>
#include "../../main/header/Ui.hpp"

namespace cod
{
    class scan
    {
        template <typename T>
        void assign(T &data);

        friend scan &operator>>(scan &sc, bool last)
        {
            sc.isLast = last;
            return sc;
        }

        friend scan &operator>>(scan &sc, char &data)
        {
            sc.reset();

            while ((sc.c = getch()) && !(sc.value.size() && (sc.c == '\r' || sc.c == ' ')))
            {
                sc.isLimitExceed = (sc.value.size() > 0);
                sc.check_char();
            }

            sc.assign(data);

            return sc;
        }

        friend scan &operator>>(scan &sc, std::string &data)
        {
            sc.reset();

            while ((sc.c = getch()) && !(sc.value.size() && sc.c == '\r'))
            {
                switch (sc.check_char())
                {
                case 1:
                    if (sc.value.size())
                        goto after_space;
                }
            }

        after_space: // if the user press space and its not a empty string it will reach here breaking the while loop

            if (!(sc.isLast))
            {
                sc.print();
                sc.isLast = true;
            }

            data = sc.value;

            return sc;
        }

        friend scan &operator>>(scan &sc, size_t &data)
        {
            sc.reset();
            int count{0};

            while ((sc.c = getch()) && !(sc.value.size() && sc.c == '\r'))
            {
                if (sc.c == ' ')
                {
                    if (sc.isLast)
                        ++count;
                    else if (sc.value.size()) // will break only when the string has minimum 1 element
                        break;

                    if (count == 3)
                        Ui::popUp(std::string{"     Press Enter to submit data"});
                }

                sc.check_char();
            }

            sc.assign(data);

            return sc;
        }

        template <typename T>
        friend scan &operator>>(scan &sc, T &data) // int, long, double
        {
            sc.reset();

            while ((sc.c = getch()) && !(sc.value.size() && sc.c == '\r'))
            {
                if (sc.c == ' ')
                {
                    if (sc.value.size()) // will break only when the string has minimum 1 element
                        break;
                }

                sc.check_char();
            }

            sc.assign(data);

            return sc;
        }

    private:
        char c;
        bool isLast;
        std::string value;
        bool isLimitExceed;
        bool isString;

        int check_char(bool isPassword = false);
        int check_shortcut();
        void print() const;

    public:
        scan(); // type of string - username, pass, char

        // void choice(int &choice);

        void is_string(bool isStr);

        // std::string username();
        // std::string password();

        void reset(); // reset the values of scan class
    };                // namespace cod
} // namespace cod

#endif