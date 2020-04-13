#include <cstring>
#include "../header/cod_string.hpp"
#include "../header/cod_limits.hpp"
#include "../header/cod_algorithm.hpp"

cod::scan &cod::getline(cod::scan &sc, cod::string &s)
{
    std::string temp;

    sc >> temp;

    s = temp.c_str();

    return sc;
}

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

void cod::string::cat(const char *rhs, size_t len) // use true ,false for str[_size]=0;
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
    _size = rhs._size;
    _capacity = rhs._capacity;

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
    size_t refSize = (len == npos) ? (rhs._size - pos) : (cod::min(rhs._size - pos, len));

    _size = refSize;
    _capacity = rhs._capacity;

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
    size_t refSize = (len == npos) ? (rhs._size - pos) : (cod::min(rhs._size - pos, len));

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

cod::string &cod::string::assign(const string &rhs)
{
    return (*this = rhs);
}

cod::string &cod::string::assign(const string &rhs, size_t pos, size_t len)
{
    size_t refSize = (len == npos) ? (rhs._size - pos) : (cod::min(rhs._size - pos, len));

    if (refSize > _capacity)
    {
        _size = _capacity = refSize;

        this->capacity_selecter();

        delete[] str;
        str = new char[_capacity + 1];
    }

    size_t i{0};

    for (; i < refSize; ++i)
    {
        str[i] = rhs.str[pos + i];
    }

    str[i] = '\0';

    return *this;
}

cod::string &cod::string::assign(string &&rhs)
{
    delete[] str;

    _capacity = rhs._capacity;
    _size = rhs._size;

    str = rhs.str;
    rhs.str = nullptr;

    return *this;
}

cod::string &cod::string::assign(const char *s)
{
    return (*this = s);
}

cod::string &cod::string::assign(const char *s, size_t n)
{
    if (n > _capacity)
    {
        delete[] str;

        _size = _capacity = n;

        this->capacity_selecter();

        str = new char[_capacity + 1];
    }

    this->cpy(s, n);

    return *this;
}

cod::string &cod::string::assign(size_t n, char c)
{
    if (n > _capacity)
    {
        delete[] str;
        _size = _capacity = n;

        this->capacity_selecter();

        str = new char[_capacity + 1];
    }

    for (size_t i{0}; i < n; ++i)
        str[i] = c;

    str[n] = '\0';

    return *this;
}

cod::string &cod::string::assign(const std::initializer_list<char> &list)
{
    return (*this = list);
}

cod::string &cod::string::insert(size_t pos, const string &rhs)
{
    if (pos > _size)
        throw OutofBoundsException();

    size_t newSize = _size + rhs._size;

    if (newSize > _capacity)
    {
        string temp(*this);

        delete[] str;

        this->capacity_updater(newSize);

        str = new char[_capacity + 1];

        this->cpy(temp.str, pos);

        this->cat(rhs.str);

        for (size_t i{0}; pos + i < temp._size; i++)
        {
            str[pos + rhs._size + i] = temp.str[pos + i];
        }
    }
    else
    {
        string remainingValues(*this, pos);

        size_t i{0};

        for (; i < rhs._size; i++)
        {
            str[pos + i] = rhs.str[i];
        }

        for (i = 0; i < remainingValues._size; i++)
        {
            str[pos + rhs._size + i] = remainingValues.str[i];
        }
    }

    _size = newSize;
    str[_size] = '\0';

    return *this;
}

cod::string &cod::string::insert(size_t pos, const string &rhs, size_t subpos, size_t sublen)
{
    if (pos > _size)
        throw OutofBoundsException();

    size_t refSize = (sublen == npos) ? (rhs._size - subpos) : (cod::min(rhs._size - subpos, sublen));

    size_t newSize = _size + refSize;

    if (newSize > _capacity)
    {
        string temp(*this);

        delete[] str;

        this->capacity_updater(newSize);

        str = new char[_capacity + 1];

        this->cpy(temp.str, pos);

        size_t i{0};

        for (; i < refSize; ++i)
        {
            str[pos + i] = rhs.str[subpos + i];
        }

        for (i = 0; pos + i < temp._size; ++i)
        {
            str[pos + refSize + i] = temp.str[pos + i];
        }
    }
    else
    {
        string remainingValues(*this, pos);

        size_t i{0};

        for (; i < refSize; ++i)
        {
            str[pos + i] = rhs.str[subpos + i];
        }

        for (i = 0; i < remainingValues._size; i++)
        {
            str[pos + refSize + i] = remainingValues.str[i];
        }
    }

    _size = newSize;
    str[_size] = '\0';

    return *this;
}

cod::string &cod::string::insert(size_t pos, const char *s)
{
    if (pos > _size)
        throw OutofBoundsException();

    size_t strSize = strlen(s);
    size_t newSize = _size + strSize;

    if (newSize > _capacity)
    {
        string temp(*this);

        delete[] str;

        this->capacity_updater(newSize);

        str = new char[_capacity + 1];

        this->cpy(temp.str, pos);

        this->cat(s);

        for (size_t i{0}; pos + i < temp._size; i++)
        {
            str[pos + strSize + i] = temp.str[pos + i];
        }
    }
    else
    {
        string remainingValues(*this, pos);

        size_t i{0};

        for (; i < strSize; i++)
        {
            str[pos + i] = s[i];
        }

        for (i = 0; i < remainingValues._size; i++)
        {
            str[pos + strSize + i] = remainingValues.str[i];
        }
    }

    _size = newSize;
    str[_size] = '\0';

    return *this;
}

cod::string &cod::string::insert(size_t pos, const char *s, size_t n)
{
    if (pos > _size)
        throw OutofBoundsException();

    size_t newSize = _size + n;

    if (newSize > _capacity)
    {
        string temp(*this);

        delete[] str;

        this->capacity_updater(newSize);

        str = new char[_capacity + 1];

        this->cpy(temp.str, pos);

        _size = pos + n; // temporary changing size for concat
        this->cat(s, n);

        for (size_t i{0}; pos + i < temp._size; i++)
        {
            str[_size + i] = temp.str[pos + i];
        }
    }
    else
    {
        string remainingValues(*this, pos);

        size_t i{0};

        for (; i < n; i++)
        {
            str[pos + i] = s[i];
        }

        for (i = 0; i < remainingValues._size; i++)
        {
            str[pos + n + i] = remainingValues.str[i];
        }
    }

    _size = newSize;
    str[_size] = '\0';

    return *this;
}

cod::string &cod::string::insert(size_t pos, size_t n, char c)
{
    if (pos > _size)
        throw OutofBoundsException();

    size_t newSize = _size + n;

    if (newSize > _capacity)
    {
        string temp(*this);

        delete[] str;

        this->capacity_updater(newSize);

        str = new char[_capacity + 1];

        this->cpy(temp.str, pos);

        size_t i{0};

        for (; i < n; i++)
        {
            str[pos + i] = c;
        }

        for (i = 0; pos + i < temp._size; i++)
        {
            str[pos + n + i] = temp.str[pos + i];
        }
    }
    else
    {
        string remainingValues(*this, pos);

        size_t i{0};

        for (; i < n; i++)
        {
            str[pos + i] = c;
        }

        for (i = 0; i < remainingValues._size; i++)
        {
            str[pos + n + i] = remainingValues.str[i];
        }
    }

    _size = newSize;
    str[_size] = '\0';

    return *this;
}

cod::string &cod::string::erase(size_t pos, size_t len)
{
    if (pos > _size)
        throw OutofBoundsException();

    size_t i{pos};

    for (; i < pos + len; i++)
    {
        if (i + len == _size)
            break;

        str[i] = str[i + len];
    }

    _size = i;
    str[_size] = '\0';

    return *this;
}

cod::string &cod::string::replace(size_t pos, size_t len, const string &rhs)
{
    if (pos > _size)
        throw OutofBoundsException();

    size_t validLength = cod::min(len, _size);
    size_t newSize = _size - validLength + rhs._size;

    if (newSize > _capacity)
    {
        string temp1(*this, 0, pos);
        string temp2(*this, validLength);
        delete[] str;

        this->capacity_updater(newSize);

        str = new char[_capacity + 1];

        _size = newSize;

        this->cpy(temp1.str);
        this->cat(rhs.str);
        this->cat(temp2.str);
    }
    else
    {
        string temp(*this, validLength);

        for (size_t i{0}; i < rhs._size; ++i)
        {
            str[pos + i] = rhs.str[i];
        }

        str[pos + rhs._size] = '\0';
        this->cat(temp.str);

        if (_size < newSize)
            _size = newSize;
    }

    return *this;
}

cod::string &cod::string::replace(size_t pos, size_t len, const string &rhs, size_t subpos, size_t sublen)
{
    if (pos > _size)
        throw OutofBoundsException();

    size_t refSize = (sublen == npos) ? (rhs._size - subpos) : (cod::min(rhs._size - subpos, sublen));
    size_t validLength = cod::min(len, _size);
    size_t newSize = _size - validLength + refSize;
    size_t tempSize = pos + refSize;

    if (newSize > _capacity)
    {
        string temp1(*this, 0, pos);
        string temp2(*this, validLength);
        delete[] str;

        this->capacity_updater(newSize);

        str = new char[_capacity + 1];

        _size = newSize;

        this->cpy(temp1.str);

        for (size_t i{0}; i < refSize; ++i)
        {
            str[pos + i] = rhs.str[subpos + i];
        }
        str[tempSize] = '\0';

        this->cat(temp2.str);
    }
    else
    {
        string temp(*this, validLength);

        size_t i{0};

        for (; i < refSize; ++i)
        {
            str[pos + i] = rhs.str[subpos + i];
        }

        str[tempSize] = '\0';

        this->cat(temp.str);

        if (_size < newSize)
            _size = newSize;
    }

    return *this;
}

cod::string &cod::string::replace(size_t pos, size_t len, const char *s)
{
    if (pos > _size)
        throw OutofBoundsException();

    size_t rhsSize = strlen(s);
    size_t validLength = cod::min(len, _size);
    size_t newSize = _size - validLength + rhsSize;

    if (newSize > _capacity)
    {
        string temp1(*this, 0, pos);
        string temp2(*this, validLength);
        delete[] str;

        this->capacity_updater(newSize);

        str = new char[_capacity + 1];

        _size = newSize;

        this->cpy(temp1.str);
        this->cat(s);
        this->cat(temp2.str);
    }
    else
    {
        string temp(*this, validLength);

        for (size_t i{0}; i < rhsSize; ++i)
        {
            str[pos + i] = s[i];
        }

        str[pos + rhsSize] = '\0';
        this->cat(temp.str);

        if (_size < newSize)
            _size = newSize;
    }

    return *this;
}

cod::string &cod::string::replace(size_t pos, size_t len, const char *s, size_t n)
{
    if (pos > _size)
        throw OutofBoundsException();

    size_t refSize = cod::min(strlen(s), n);
    size_t validLength = cod::min(len, _size);
    size_t newSize = _size - validLength + refSize;

    if (newSize > _capacity)
    {
        string temp1(*this, 0, pos);
        string temp2(*this, validLength);
        delete[] str;

        this->capacity_updater(newSize);

        str = new char[_capacity + 1];

        this->cpy(temp1.str);

        _size = pos + refSize;
        this->cat(s, refSize);
        this->cat(temp2.str);
        _size = newSize;
    }
    else
    {
        string temp(*this, validLength);

        for (size_t i{0}; i < refSize; ++i)
        {
            str[pos + i] = s[i];
        }

        str[pos + refSize] = '\0';
        this->cat(temp.str);

        if (_size < newSize)
            _size = newSize;
    }

    return *this;
}

cod::string &cod::string::replace(size_t pos, size_t len, size_t n, char c)
{
    if (pos > _size)
        throw OutofBoundsException();

    size_t validLength = cod::min(len, _size);
    size_t newSize = _size - validLength + n;

    if (newSize > _capacity)
    {
        string temp1(*this, 0, pos);
        string temp2(*this, validLength);
        delete[] str;

        this->capacity_updater(newSize);

        str = new char[_capacity + 1];

        this->cpy(temp1.str);

        for (size_t i{0}; i < n; ++i)
        {
            str[pos + i] = c;
        }

        str[pos + n] = '\0';
        this->cat(temp2.str);
        _size = newSize;
    }
    else
    {
        string temp(*this, validLength);

        for (size_t i{0}; i < n; ++i)
        {
            str[pos + i] = c;
        }

        str[pos + n] = '\0';
        this->cat(temp.str);

        if (_size < newSize)
            _size = newSize;
    }

    return *this;
}

void cod::string::swap(string &rhs)
{
    // temporary copying this data
    string temp(string(*this));

    // copying rhs to this
    *this = string(rhs);

    // copying this to rhs
    rhs = string(temp);
}

void cod::string::pop_back()
{
    str[--_size] = '\0';
}

/**************************************************** STRING OPERATIONS *************************************************/
const char *cod::string::c_str() const
{
    return str;
}

const char *cod::string::data() const
{
    return str;
}

size_t cod::string::copy(char *s, size_t len, size_t pos) const
{
    if (pos > _size)
        throw OutofBoundsException();

    size_t validLength = cod::min(len, _size);

    for (size_t i{0}; i < validLength; ++i)
    {
        s[i] = str[pos + i];
    }

    return validLength;
}

size_t cod::string::find(const string &rhs, size_t pos) const
{
    for (size_t i{pos}, j{0}; i < _size; i++, j = 0)
    {
        if (str[i] == rhs.str[j])
        {
            for (size_t k{i}; j < rhs._size; k++, j++)
            {
                if (str[k] != rhs.str[j])
                    break;
            }

            if (j == rhs._size)
                return i;
        }
    }

    return npos;
}

size_t cod::string::find(const char *s, size_t pos) const
{
    size_t rhsSize = strlen(s);

    for (size_t i{pos}, j{0}; i < _size; i++, j = 0)
    {
        if (str[i] == s[j])
        {
            for (size_t k{i}; j < rhsSize; k++, j++)
            {
                if (str[k] != s[j])
                    break;
            }

            if (j == rhsSize)
                return i;
        }
    }

    return npos;
}

size_t cod::string::find(const char *s, size_t pos, size_t n) const
{
    for (size_t i{pos}, j{0}; i < _size; i++, j = 0)
    {
        if (str[i] == s[j])
        {
            for (size_t k{i}; j < n; k++, j++)
            {
                if (str[k] != s[j])
                    break;
            }

            if (j == n)
                return i;
        }
    }

    return npos;
}

size_t cod::string::find(char c, size_t pos) const
{
    for (size_t i{pos}; i < _size; i++)
    {
        if (str[i] == c)
            return i;
    }

    return npos;
}

size_t cod::string::rfind(const string &rhs, size_t pos) const
{
    size_t validPos = (pos == npos) ? _size : cod::min(pos, _size);

    for (size_t i{validPos}, j{0}; i != npos; i--, j = 0)
    {
        if (str[i] == rhs.str[j])
        {
            for (size_t k{i}; j < rhs._size; k++, j++)
            {
                if (str[k] != rhs.str[j])
                    break;
            }

            if (j == rhs._size)
                return i;
        }
    }

    return npos;
}

size_t cod::string::rfind(const char *s, size_t pos) const
{
    size_t validPos = (pos == npos) ? _size : cod::min(pos, _size);
    size_t rhsSize = strlen(s);

    for (size_t i{validPos}, j{0}; i != npos; i--, j = 0)
    {
        if (str[i] == s[j])
        {
            for (size_t k{i}; j < rhsSize; k++, j++)
            {
                if (str[k] != s[j])
                    break;
            }

            if (j == rhsSize)
                return i;
        }
    }

    return npos;
}

size_t cod::string::rfind(const char *s, size_t pos, size_t n) const
{
    size_t validPos = (pos == npos) ? _size : cod::min(pos, _size);

    for (size_t i{validPos}, j{0}; i != npos; i--, j = 0)
    {
        if (str[i] == s[j])
        {
            for (size_t k{i}; j < n; k++, j++)
            {
                if (str[k] != s[j])
                    break;
            }

            if (j == n)
                return i;
        }
    }

    return npos;
}

size_t cod::string::rfind(char c, size_t pos) const
{
    size_t validPos = (pos == npos) ? _size : cod::min(pos, _size);

    for (size_t i{validPos}; i != npos; i--)
    {
        if (str[i] == c)
            return i;
    }

    return npos;
}

size_t cod::string::find_first_of(const string &rhs, size_t pos) const
{
    for (size_t i{pos}; i < _size; i++)
    {
        for (size_t j{0}; j < rhs._size; j++)
        {
            if (str[i] == rhs.str[j])
                return i;
        }
    }

    return npos;
}

size_t cod::string::find_first_of(const char *s, size_t pos) const
{
    size_t rhsSize = strlen(s);

    for (size_t i{pos}; i < _size; i++)
    {
        for (size_t j{0}; j < rhsSize; j++)
        {
            if (str[i] == s[j])
                return i;
        }
    }

    return npos;
}

size_t cod::string::find_first_of(const char *s, size_t pos, size_t n) const
{
    for (size_t i{pos}; i < _size; i++)
    {
        for (size_t j{0}; j < n; j++)
        {
            if (str[i] == s[j])
                return i;
        }
    }

    return npos;
}

size_t cod::string::find_first_of(char c, size_t pos) const
{
    return (this->find(c, pos));
}

size_t cod::string::find_last_of(const string &rhs, size_t pos) const
{
    size_t validPos = (pos == npos) ? _size : cod::min(pos, _size);

    for (size_t i{validPos}; i != npos; i--)
    {
        for (size_t j{0}; j < rhs._size; j++)
        {
            if (str[i] == rhs.str[j])
                return i;
        }
    }

    return npos;
}

size_t cod::string::find_last_of(const char *s, size_t pos) const
{
    size_t validPos = (pos == npos) ? _size : cod::min(pos, _size);
    size_t rhsSize = strlen(s);

    for (size_t i{validPos}; i != npos; i--)
    {
        for (size_t j{0}; j < rhsSize; j++)
        {
            if (str[i] == s[j])
                return i;
        }
    }

    return npos;
}

size_t cod::string::find_last_of(const char *s, size_t pos, size_t n) const
{
    size_t validPos = (pos == npos) ? _size : cod::min(pos, _size);

    for (size_t i{validPos}; i != npos; i--)
    {
        for (size_t j{0}; j < n; j++)
        {
            if (str[i] == s[j])
                return i;
        }
    }

    return npos;
}

size_t cod::string::find_last_of(char c, size_t pos) const
{
    return (this->rfind(c, pos));
}

size_t cod::string::find_first_not_of(const string &rhs, size_t pos) const
{
    for (size_t i{pos}; i < _size; i++)
    {
        for (size_t j{0}; j < rhs._size; j++)
        {
            if (str[i] != rhs.str[j])
                return i;
        }
    }

    return npos;
}

size_t cod::string::find_first_not_of(const char *s, size_t pos) const
{
    size_t rhsSize = strlen(s);

    for (size_t i{pos}; i < _size; i++)
    {
        for (size_t j{0}; j < rhsSize; j++)
        {
            if (str[i] != s[j])
                return i;
        }
    }

    return npos;
}

size_t cod::string::find_first_not_of(const char *s, size_t pos, size_t n) const
{
    for (size_t i{pos}; i < _size; i++)
    {
        for (size_t j{0}; j < n; j++)
        {
            if (str[i] != s[j])
                return i;
        }
    }

    return npos;
}

size_t cod::string::find_first_not_of(char c, size_t pos) const
{
    for (size_t i{pos}; i < _size; i++)
    {
        if (str[i] != c)
            return i;
    }

    return npos;
}

size_t cod::string::find_last_not_of(const string &rhs, size_t pos) const
{
    size_t validPos = (pos == npos) ? _size : cod::min(pos, _size);

    for (size_t i{validPos}; i != npos; i--)
    {
        for (size_t j{0}; j < rhs._size; j++)
        {
            if (str[i] != rhs.str[j])
                return i;
        }
    }

    return npos;
}

size_t cod::string::find_last_not_of(const char *s, size_t pos) const
{
    size_t validPos = (pos == npos) ? _size : cod::min(pos, _size);
    size_t rhsSize = strlen(s);

    for (size_t i{validPos}; i != npos; i--)
    {
        for (size_t j{0}; j < rhsSize; j++)
        {
            if (str[i] != s[j])
                return i;
        }
    }

    return npos;
}

size_t cod::string::find_last_not_of(const char *s, size_t pos, size_t n) const
{
    size_t validPos = (pos == npos) ? _size : cod::min(pos, _size);

    for (size_t i{validPos}; i != npos; i--)
    {
        for (size_t j{0}; j < n; j++)
        {
            if (str[i] != s[j])
                return i;
        }
    }

    return npos;
}

size_t cod::string::find_last_not_of(char c, size_t pos) const
{
    size_t validPos = (pos == npos) ? _size : cod::min(pos, _size);

    for (size_t i{validPos}; i != npos; i--)
    {
        if (str[i] != c)
            return i;
    }

    return npos;
}

cod::string cod::string::substr(size_t pos, size_t len) const
{
    return string(*this, pos, len);
}

int cod::string::compare(const string &rhs) const
{
    size_t validLength = cod::min(_size, rhs._size);

    if (str[0] != rhs.str[0])
        return (str[0] - rhs.str[0]);

    for (size_t i{1}; i < validLength; i++)
    {
        if (str[i] != rhs.str[i])
            return 256 * (str[i] - rhs.str[i]); // converting to bits
    }

    if (_size != rhs._size)
        return (_size - rhs._size);

    return 0;
}

int cod::string::compare(size_t pos, size_t len, const string &rhs) const
{
    if (pos > _size)
        throw OutofBoundsException();

    size_t lSize = (len == npos) ? _size - pos : cod::min(_size - pos, len);
    size_t validLength = cod::min(lSize, rhs._size);

    if (str[pos] != rhs.str[0])
        return (str[pos] - rhs.str[0]);

    for (size_t i{1}; i < validLength; i++)
    {
        if (str[pos + i] != rhs.str[i])
            return 256 * (str[pos + i] - rhs.str[i]); // converting to bits
    }

    if (lSize != rhs._size)
        return (lSize - rhs._size);

    return 0;
}

int cod::string::compare(size_t pos, size_t len, const string &rhs, size_t subpos, size_t sublen) const
{
    if (pos > _size)
        throw OutofBoundsException();

    size_t lSize = (len == npos) ? _size - pos : cod::min(_size - pos, len);
    size_t rSize = (sublen == npos) ? rhs._size - pos : cod::min(rhs._size - pos, sublen);
    size_t validLength = cod::min(lSize, rSize);

    if (str[pos] != rhs.str[subpos])
        return (str[pos] - rhs.str[subpos]);

    for (size_t i{1}; i < validLength; i++)
    {
        if (str[pos + i] != rhs.str[subpos + i])
            return 256 * (str[pos + i] - rhs.str[subpos + i]); // converting to bits
    }

    if (lSize != rSize)
        return (lSize - rSize);

    return 0;
}

int cod::string::compare(const char *s) const
{
    size_t rSize = strlen(s);

    size_t validLength = cod::min(_size, rSize);

    if (str[0] != s[0])
        return (str[0] - s[0]);

    for (size_t i{1}; i < validLength; i++)
    {
        if (str[i] != s[i])
            return 256 * (str[i] - s[i]); // converting to bits
    }

    if (_size != rSize)
        return (_size - rSize);

    return 0;
}

int cod::string::compare(size_t pos, size_t len, const char *s) const
{
    if (pos > _size)
        throw OutofBoundsException();

    size_t lSize = (len == npos) ? _size - pos : cod::min(_size - pos, len);
    size_t rSize = strlen(s);
    size_t validLength = cod::min(lSize, rSize);

    if (str[pos] != s[0])
        return (str[pos] - s[0]);

    for (size_t i{1}; i < validLength; i++)
    {
        if (str[pos + i] != s[i])
            return 256 * (str[pos + i] - s[i]); // converting to bits
    }

    if (lSize != rSize)
        return (lSize - rSize);

    return 0;
}

int cod::string::compare(size_t pos, size_t len, const char *s, size_t n) const
{
    if (pos > _size)
        throw OutofBoundsException();

    size_t lSize = (len == npos) ? _size - pos : cod::min(_size - pos, len);
    size_t rSize = cod::min(n, strlen(s));
    size_t validLength = cod::min(lSize, rSize);

    if (str[pos] != s[0])
        return (str[pos] - s[0]);

    for (size_t i{1}; i < validLength; i++)
    {
        if (str[pos + i] != s[i])
            return 256 * (str[pos + i] - s[i]); // converting to bits
    }

    if (lSize != rSize)
        return (lSize - rSize);

    return 0;
}

cod::string::~string()
{
    delete[] str;
}