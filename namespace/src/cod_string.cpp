#include <cstring>
#include "../header/cod_string.hpp"
#include "../header/cod_limits.hpp"
#include "../header/cod_algorithm.hpp"

/*************************************************** CONSTRUCTOR *********************************************************/

cod::string::string() : string(nullptr)
{
}

cod::string::string(const char *s) : str(nullptr), _size(0), _max_size(cod::limits<size_t>::max())
{
    if (s == nullptr)
    {
        _size = 1;
        str = new char[_size];
        *str = '\0';
    }
    else
    {
        _size = strlen(s) + 1;
        str = new char[_size];
        strcpy(str, s);
    }
}

cod::string::string(const char *s, size_t n) : str(nullptr), _size(0), _max_size(cod::limits<size_t>::max())
{
    _size = n + 1;
    str = new char[_size];
    strncpy(str, s, n);
}

cod::string::string(size_t n, char c) : str(nullptr), _size(0), _max_size(cod::limits<size_t>::max())
{
    _size = n + 1;
    str = new char[_size];

    for (size_t i{0}; i < n; ++i)
        str[i] = c;

    str[n] = '\0';
}

cod::string::string(const string &rhs) : str(nullptr), _size(0), _max_size(cod::limits<size_t>::max())
{
    _size = rhs.size() + 1;
    str = new char[_size];
    strcpy(str, rhs.str);
}

cod::string::string(string &&rhs) : str(nullptr), _size(0), _max_size(cod::limits<size_t>::max())
{
    _size = rhs.size() + 1;
    str = rhs.str;
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
        _size = rhs.size() - pos + 1;
    else
        _size = cod::min(rhs.size(), len) + 1;

    str = new char[_size];

    size_t i{0};

    for (; i < _size - 1; ++i)
    {
        str[i] = rhs.str[pos + i];
    }

    str[i] = '\0';
}

/************************************************* ASSIGNMENT OPERATOR ***************************************************/

cod::string &cod::string::operator=(const string &rhs)
{
    if (_size < rhs._size)
    {
        delete[] str;
        _size = rhs._size;
        str = new char[_size];

        strcpy(str, rhs.str);
    }
    else
    {
        memcpy(str, rhs.str, rhs.size() + 1);
    }

    return *this;
}

cod::string &cod::string::operator=(string &&rhs)
{
    delete[] str;
    _size = rhs._size;

    str = rhs.str;
    rhs.str = nullptr;

    return *this;
}

cod::string &cod::string::operator=(const char *s)
{
    size_t rhsSize = strlen(s) + 1;

    if (_size < rhsSize)
    {
        delete[] str;

        if (2 * _size > rhsSize + 1)
            _size = 2 * _size - 1;
        else
            _size = rhsSize;

        str = new char[_size];
        strcpy(str, s);
    }
    else
    {
        memcpy(str, s, rhsSize);
    }

    return *this;
}

cod::string &cod::string::operator=(char c)
{
    if (_size < 2)
    {
        delete[] str;

        _size = 2;
        str = new char[_size];
    }

    str[0] = c;
    str[1] = '\0';

    return *this;
}

cod::string &cod::string::operator=(const std::initializer_list<char> &list)
{
    size_t rhsSize = list.size() + 1;

    if (_size < rhsSize)
    {
        delete[] str;

        _size = rhsSize;
        str = new char[_size];
    }

    size_t i{0};

    for (const auto &c : list)
        str[i++] = c;

    str[i] = '\0';

    return *this;
}

/*************************************************** STRING ITERATOR *****************************************************/

/****************************************************** CAPACITY *********************************************************/

size_t cod::string::size() const
{
    return strlen(str);
}

size_t cod::string::length() const
{
    return strlen(str);
}

cod::string::~string()
{
    delete[] str;
    _size = 0;
}