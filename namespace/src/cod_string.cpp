#include <cstring>
#include "../header/cod_string.hpp"
#include "../header/cod_limits.hpp"
#include "../header/cod_algorithm.hpp"

/*************************************************** CONSTRUCTOR *********************************************************/

void cod::string::capacity_selecter()
{
    if (_capacity <= 15)
        _capacity = 15;
    else if (_capacity <= 30)
        _capacity = 30;
}

cod::string::string() : string(nullptr)
{
}

cod::string::string(const char *s) : str(nullptr), _size(0), _capacity(0), _max_size(cod::limits<size_t>::max())
{
    if (s == nullptr)
    {
        _capacity = 15;
        _size = 0;
        str = new char[_capacity + 1];
        *str = '\0';
    }
    else
    {
        _size = _capacity = strlen(s);

        this->capacity_selecter();

        str = new char[_capacity + 1];
        strcpy(str, s);
    }
}

cod::string::string(const char *s, size_t n) : str(nullptr), _size(0), _capacity(0), _max_size(cod::limits<size_t>::max())
{
    _size = _capacity = n;

    this->capacity_selecter();

    str = new char[_capacity + 1];
    strncpy(str, s, n);
    str[n] = '\0';
}

cod::string::string(size_t n, char c) : str(nullptr), _size(0), _capacity(0), _max_size(cod::limits<size_t>::max())
{
    _size = _capacity = n;

    this->capacity_selecter();

    str = new char[_capacity + 1];

    for (size_t i{0}; i < n; ++i)
        str[i] = c;

    str[n] = '\0';
}

cod::string::string(const string &rhs) : str(nullptr), _size(0), _capacity(0), _max_size(cod::limits<size_t>::max())
{
    _size = _capacity = rhs.size();

    this->capacity_selecter();

    str = new char[_capacity + 1];

    strcpy(str, rhs.str);
}

cod::string::string(string &&rhs) : str(nullptr), _size(0), _capacity(0), _max_size(cod::limits<size_t>::max())
{
    _capacity = rhs._capacity;
    _size = rhs._size;
    str = rhs.str;
    rhs.str = nullptr;
}

cod::string::string(const std::initializer_list<char> &list) : str(nullptr), _size(0), _capacity(0), _max_size(cod::limits<size_t>::max())
{
    _size = _capacity = list.size();

    this->capacity_selecter();

    str = new char[_capacity + 1];

    size_t i{0};

    for (const auto &c : list)
        str[i++] = c;

    str[i] = '\0';
}

cod::string::string(const string &rhs, size_t pos, size_t len) : str(nullptr), _size(0), _capacity(0), _max_size(cod::limits<size_t>::max())
{
    size_t refSize;

    if (len == npos)
        refSize = rhs.size() - pos;
    else
        refSize = cod::min(rhs.size(), len);

    _size = _capacity = refSize;

    this->capacity_selecter();

    str = new char[_capacity + 1];

    size_t i{0};

    for (; i < refSize; ++i)
    {
        str[i] = rhs.str[pos + i];
    }

    str[i] = '\0';
}

/************************************************* ASSIGNMENT OPERATOR ***************************************************/

cod::string &cod::string::operator=(const string &rhs)
{
    if (_capacity < rhs._capacity)
    {
        delete[] str;

        _capacity = rhs._capacity;

        this->capacity_selecter();

        str = new char[_capacity + 1];
    }

    _size = rhs._size;
    strcpy(str, rhs.str);

    return *this;
}

cod::string &cod::string::operator=(string &&rhs)
{
    delete[] str;

    _capacity = rhs._capacity;
    _size = rhs._size;

    str = rhs.str;
    rhs.str = nullptr;

    return *this;
}

cod::string &cod::string::operator=(const char *s)
{
    size_t rhsSize = strlen(s);

    if (_capacity < rhsSize)
    {
        delete[] str;

        _capacity = rhsSize;

        this->capacity_selecter();

        str = new char[_capacity + 1];
    }

    _size = rhsSize;
    strcpy(str, s);

    return *this;
}

cod::string &cod::string::operator=(char c)
{
    str[0] = c;
    str[1] = '\0';

    _size = 1;

    return *this;
}

cod::string &cod::string::operator=(const std::initializer_list<char> &list)
{
    size_t rhsSize = list.size();

    if (_capacity < rhsSize)
    {
        delete[] str;

        _capacity = rhsSize;

        this->capacity_selecter();

        str = new char[_capacity];
    }

    size_t i{0};

    for (const auto &c : list)
        str[i++] = c;

    str[i] = '\0';

    _size = rhsSize;

    return *this;
}

/*************************************************** STRING ITERATOR *****************************************************/

/****************************************************** CAPACITY *********************************************************/

size_t cod::string::size() const
{
    return _size;
}

size_t cod::string::length() const
{
    return _size;
}

size_t cod::string::max_size() const
{
    return _max_size;
}

void cod::string::resize(size_t n, char c)
{
    // if (n > _capacity)
    // {
    //     string temp(*this);

    //     delete[] str;

    //     _capacity = n;

    //     this->capacity_selecter();

    //     str = new char[_capacity + 1];

    //     strncpy(str, temp.str, temp.size());

    //     for (size_t i = temp.size(); i < _size; i++)
    //         str[i] = c;

    //     str[_size] = '\0';
    // }
    // else
    // {
    //     _size = n;
    //     str[n] = '\0';
    // }
}

size_t cod::string::capacity() const
{
    return _capacity;
}

void cod::string::reserve(size_t n)
{

    // if (n > _capacity)
    // {
    //     string temp(*this);

    //     delete[] str;

    //     _capacity = n;
    //     str = new char[_capacity + 1];

    //     strcpy(str, temp.str);
    // }
}

void cod::string::clear()
{
    delete[] str;

    _capacity = 15;
    _size = 0;
    str = new char[_capacity + 1];
    str[0] = '\0';
}

bool cod::string::empty() const
{
    return (_size == 0);
}

cod::string::~string()
{
    delete[] str;
    _size = 0;
    _capacity = 0;
}