#include <cstring>
#include "../header/cod_string.hpp"
#include "../header/cod_limits.hpp"
#include "../header/cod_algorithm.hpp"

void cod::string::capacity_selecter()
{
    if (_capacity <= 15)
        _capacity = 15;
    else if (_capacity <= 30)
        _capacity = 30;
}

void cod::string::capacity_updater(size_t n)
{
    if (_capacity <= 15 && n <= _capacity)
        _capacity = 15;
    else if (_size * 2 > n)
        _capacity = _size * 2;
    else
        _capacity = n;
}

void cod::string::cat(const char *rhs, size_t len)
{
    if (len == npos)
    {
        strcat(str, rhs);
    }
    else
    {
        strncat(str, rhs, len);
        str[_size] = '\0';
    }
}

void cod::string::cpy(const char *rhs, size_t len)
{
    if (len == npos)
    {
        strcpy(str, rhs);
    }
    else
    {
        strncpy(str, rhs, len);
        str[len] = '\0';
    }
}

/*************************************************** CONSTRUCTOR ********************************************************/
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
        this->cpy(s);
    }
}

cod::string::string(const char *s, size_t n) : str(nullptr), _size(0), _capacity(0), _max_size(cod::limits<size_t>::max())
{
    _size = _capacity = n;

    this->capacity_selecter();

    str = new char[_capacity + 1];
    this->cpy(s, n);
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
    this->cpy(rhs.str, rhs._size);
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
    this->cpy(rhs.str, rhs._size);

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
    this->cpy(s);

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
    if (n > _capacity)
    {
        string temp(*this);

        delete[] str;

        this->capacity_updater(n);

        str = new char[_capacity + 1];

        this->cpy(temp.str);
        _size = n;

        if (c != '\0')
        {
            for (size_t i = temp._size; i < _size; i++)
                str[i] = c;

            str[_size] = '\0';
        }
    }
    else
    {
        if (n < _size)
            str[n] = '\0';

        _size = n;
    }
}

size_t cod::string::capacity() const
{
    return _capacity;
}

void cod::string::reserve(size_t n)
{

    if (n > _capacity)
    {
        string temp(*this);

        delete[] str;

        _capacity = n;
        str = new char[_capacity + 1];

        _size = temp._size;
        this->cpy(temp.str);
    }
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

void cod::string::shrink_to_fit()
{
    string temp(*this);

    delete[] str;

    _capacity = _size;
    str = new char[_capacity + 1];
    this->cpy(temp.str);
}

/***************************************************** ELEMENT ACCESS ***************************************************/
char &cod::string::operator[](size_t pos)
{
    return str[pos];
}

const char &cod::string::operator[](size_t pos) const
{
    return str[pos];
}

char &cod::string::at(size_t pos)
{
    if (pos < 0 || pos >= _size)
        throw OutofBoundsException();

    return str[pos];
}

const char &cod::string::at(size_t pos) const
{
    if (pos < 0 || pos >= _size)
        throw OutofBoundsException();

    return str[pos];
}

char &cod::string::back()
{
    return str[_size - 1];
}

const char &cod::string::back() const
{
    return str[_size - 1];
}

char &cod::string::front()
{
    return str[0];
}

const char &cod::string::front() const
{
    return str[0];
}

/******************************************************* MODIFIERS ******************************************************/
cod::string &cod::string::operator+=(const string &rhs)
{
    if (rhs._size > (_capacity - _size))
    {
        string temp(*this);

        delete[] str;

        this->capacity_updater(rhs._size + _size);

        str = new char[_capacity + 1];

        this->cpy(temp.str);
    }

    _size += rhs._size;
    this->cat(rhs.str, rhs._size);

    return *this;
}

cod::string &cod::string::operator+=(const char *s)
{
    size_t rhsSize = strlen(s);

    if (rhsSize > (_capacity - _size))
    {
        string temp(*this);

        delete[] str;

        this->capacity_updater(rhsSize + _size);

        str = new char[_capacity + 1];

        this->cpy(temp.str);
    }

    _size += rhsSize;
    this->cat(s);

    return *this;
}

cod::string &cod::string::operator+=(char c)
{
    if (1 > (_capacity - _size))
    {
        string temp(*this);

        delete[] str;

        this->capacity_updater(_size + 1);

        str = new char[_capacity + 1];

        this->cpy(temp.str);
    }

    str[_size++] = c;
    str[_size] = '\0';

    return *this;
}

cod::string &cod::string::operator+=(const std::initializer_list<char> &list)
{
    size_t rhsSize = list.size();

    if (rhsSize > (_capacity - _size))
    {
        string temp(*this);

        delete[] str;

        this->capacity_updater(_size + rhsSize);

        str = new char[_capacity + 1];

        this->cpy(temp.str);
    }

    for (const auto &c : list)
    {
        str[_size++] = c;
    }

    str[_size] = '\0';

    return *this;
}

cod::string &cod::string::append(const string &rhs)
{
    return (*this += rhs);
}

cod::string &cod::string::append(const string &rhs, size_t pos, size_t len)
{
    size_t refSize;

    if (len == npos)
        refSize = rhs._size - pos;
    else
        refSize = cod::min(rhs._size, len);

    if (refSize > (_capacity - _size))
    {
        string temp(*this);

        delete[] str;

        this->capacity_updater(_size + refSize);

        str = new char[_capacity + 1];

        this->cpy(temp.str);
    }

    for (size_t i{0}; i < refSize; i++)
    {
        str[_size++] = rhs.str[pos + i];
    }

    str[_size] = '\0';

    return *this;
}

cod::string &cod::string::append(const char *s)
{
    return (*this += s);
}

cod::string &cod::string::append(const char *s, size_t n)
{
    if (n > (_capacity - _size))
    {
        string temp(*this);

        delete[] str;

        this->capacity_updater(n + _size);

        str = new char[_capacity + 1];

        this->cpy(temp.str);
    }
    _size += n;
    this->cat(s, n);

    return *this;
}

cod::string &cod::string::append(size_t n, char c)
{

    if (n > (_capacity - _size))
    {
        string temp(*this);

        delete[] str;

        this->capacity_updater(n + _size);

        str = new char[_capacity + 1];

        this->cpy(temp.str);
    }

    for (size_t i{0}; i < n; i++)
    {
        str[_size++] = c;
    }

    str[_size] = '\0';

    return *this;
}

cod::string &cod::string::append(const std::initializer_list<char> &list)
{
    return (*this += list);
}

void cod::string::push_back(char c)
{

    if (_capacity - _size < 1)
    {
        string temp(*this);

        delete[] str;

        _capacity *= 2;

        str = new char[_capacity + 1];

        this->cpy(temp.str);
    }

    str[_size++] = c;
}

void cod::string::pop_back()
{
    str[--_size] = '\0';
}

/**************************************************** STRING OPERATIONS *************************************************/

cod::string::~string()
{
    delete[] str;
}