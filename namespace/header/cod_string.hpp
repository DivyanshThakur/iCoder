#ifndef COD_STRING_HPP
#define COD_STRING_HPP

#include <iostream>
#include "cod_scan.hpp"
#include "cod_limits.hpp"

namespace cod
{
class string
{
    friend std::ostream &operator<<(std::ostream &os, const string &obj)
    {
        os << obj.str;
        return os;
    }

    friend cod::scan &operator>>(cod::scan &sc, string &obj)
    {
        char *buff = new char[10000];
        sc >> buff;

        obj = string(buff);

        delete[] buff;
        return sc;
    }

    char *str;

public:
    string();
    string(const char *s);
    string(const string &source);
    string(string &&source);

    string &operator=(const string &s);
    string &operator=(string &&s);

    ~string();
};

} // namespace cod

#endif