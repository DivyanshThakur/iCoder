#ifndef COD_STRING_HPP
#define COD_STRING_HPP

#include <iostream>
#include "cod_scan.hpp"

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
        char *buff = new char[obj._max_size];
        sc >> buff;

        obj = string(buff);

        delete[] buff;
        return sc;
    }

    char *str;
    size_t _size;
    size_t _max_size;

public:
    static constexpr size_t npos = -1;

    string();                                                 // no-args
    string(const char *s);                                    // paramaterized
    string(const string &rhs);                                // copy
    string(string &&rhs);                                     // move
    string(const std::initializer_list<char> &list);          // initializer list
    string(const string &rhs, size_t pos, size_t len = npos); // substring

    string &operator=(const string &rhs);
    string &operator=(string &&rhs);

    ~string();
};

} // namespace cod

#endif