#ifndef COD_STRING_HPP
#define COD_STRING_HPP

#include <iostream>

namespace cod
{
class string
{
    friend std::ostream &operator<<(std::ostream &os, const string &source)
    {
        os << source.str;
        return os;
    }

    char *str;

public:
    string();
    string(const char *s);
    string(const string &source);
    string(string &&source);

    ~string();
};

} // namespace cod

#endif