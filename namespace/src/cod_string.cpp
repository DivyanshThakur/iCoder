#include <cstring>
#include "../header/cod_string.hpp"
#include "../header/cod_limits.hpp"
#include "../header/cod_algorithm.hpp"

cod::string::string() : string(nullptr)
{
}

cod::string::string(const char *s) : str(nullptr), _size(0), _max_size(cod::limits<size_t>::max())
{
    if (s == nullptr)
    {
        str = new char[1];
        *str = '\0';
    }
    else
    {
        _size = strlen(s) + 1;
        str = new char[_size];
        strcpy(str, s);
    }
}

cod::string::string(const string &rhs) : str(nullptr), _size(0), _max_size(cod::limits<size_t>::max())
{
    _size = strlen(rhs.str) + 1;
    str = new char[_size];
    strcpy(str, rhs.str);
}

cod::string::string(string &&rhs) : str(nullptr), _size(0), _max_size(cod::limits<size_t>::max())
{
    str = rhs.str;
    _size = rhs._size;
    rhs.str = nullptr;
}

cod::string::string(const std::initializer_list<char> &list) : str(nullptr), _size(0), _max_size(cod::limits<size_t>::max())
{
    _size = list.size() + 1;
    str = new char[_size];

    size_t i{0};

    for (const auto &c : list)
        str[i++] = c;

    str[i] = '\0';
}

cod::string::string(const string &rhs, size_t pos, size_t len) : str(nullptr), _size(0), _max_size(cod::limits<size_t>::max())
{
    if (len == npos)
        _size = rhs._size - pos;
    else
        _size = cod::min(rhs._size, len + 1);

    str = new char[_size];

    size_t i{0};

    for (; i < _size - 1; ++i)
    {
        str[i] = rhs.str[pos + i];
    }
    str[i] = '\0';
}

cod::string &cod::string::operator=(const string &rhs)
{
    delete[] str;

    str = new char[strlen(rhs.str) + 1];
    strcpy(str, rhs.str);

    return *this;
}

cod::string &cod::string::operator=(string &&rhs)
{
    strcpy(str, rhs.str);
    rhs.str = nullptr;

    return *this;
}

cod::string::~string()
{
    delete[] str;
}