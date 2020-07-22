#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
#include <fstream>
#include <sstream>
#include "../header/cod_string.hpp"
#include "../header/cod_limits.hpp"
#include "../../constant/Constants.hpp"

/************************************ ISAVEABLE PURE VIRTUAL FUNCTION ****************************************/

std::vector<std::pair<std::string, std::string>> cod::string::save() const
{
    std::vector<std::pair<std::string, std::string>> vec;

    vec.push_back({Constant::DataFile::NAME, this->_name});
    vec.push_back({Constant::DataFile::TITLE, Constant::Title::STRING});
    vec.push_back({Constant::DataFile::SUB_DATA1, std::to_string(this->_capacity)});
    vec.push_back({Constant::DataFile::SUB_DATA2, std::to_string(this->_size)});
    vec.push_back({Constant::DataFile::DATA, this->str});

    return vec;
}

void cod::string::load(const std::vector<std::pair<std::string, std::string>> &vec)
{
    for (const auto &pair : vec)
    {
        std::stringstream ss(pair.second);

        if (pair.first == Constant::DataFile::DATA)
        {
            delete[] str;

            this->str = new char[_capacity + 1];

            std::string tempStr;
            std::getline(ss, tempStr);

            this->cpy(tempStr.c_str());
        }
        else if (pair.first == Constant::DataFile::NAME)
            ss >> this->_name;
        else if (pair.first == Constant::DataFile::SUB_DATA1)
            ss >> this->_capacity;
        else if (pair.first == Constant::DataFile::SUB_DATA2)
            ss >> this->_size;
    }
}

std::string cod::string::getPath() const
{
    return Constant::Path::USER;
}

/************************************* NON MEMBER FUNCTION OVERLOADS ****************************************/

// The getline scans the whole line.
// Accepts cod::string and internally
// scans string in std::string and
// transfer the data back to cod::string

cod::scan &cod::getline(cod::scan &sc, cod::string &s)
{
    std::string temp;

    sc.is_string(true); // It enables the space to be accepted as string
    sc >> temp;
    sc.is_string(false); // disables it

    s = temp.c_str(); // c = style string is assigned to cod::string

    return sc;
}

// It select appropriate capacity based on new capacity
// Minimum capacity is 15, and if less than 30 assigns 30
// otherwise the capacity is not changed
// This function is only used when the string is declared

void cod::string::capacity_selecter()
{
    if (_capacity <= 15)
        _capacity = 15;
    else if (_capacity <= 30)
        _capacity = 30;
}

// This function is used when the string is updated after declaring
// Min cpacity is 15, else if the no of values stored in the string
// when twice greater than the arg n, is assigned to capacity
// else capacity is changed to n

void cod::string::capacity_updater(size_t n)
{
    if (_capacity <= 15 && n <= _capacity)
        _capacity = 15;
    else if (_size * 2 > n)
        _capacity = _size * 2;
    else
        _capacity = n;
}

void cod::string::validate(size_t pos, bool cmpSize) const
{
    if ((pos < 0 || pos > _size) || (cmpSize && pos == _size))
        throw InvalidPositionException();
}

// A simple function to calculate vowels, words and consonants
void cod::string::update_word_vowel_consonant()
{
    char c;

    _words = _vowels = _consonants = 0;

    for (size_t i{0}; i < _size; i++)
    {
        c = ::tolower(str[i]); // lower the char

        if (c == ' ') // Since. space indicate a new word
            ++_words;
        else if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            ++_vowels;
        else if (c > 'a' && c <= 'z')
            ++_consonants;
    }

    if (_size)    // check for null string
        ++_words; // to add the last word without space
}

// A recursive algorithm to find the permutation of the string
// Accepts the string, the starting pos and the last pos

void cod::string::perm(string &str, size_t l, size_t h)
{
    if (l == h) // If l==h, means pointing to same character,i.e. print the string and return
    {
        std::cout << std::setw(Ui::widthIndex) << std::left << index++ << " " << static_cast<char>(175) << " " << str << std::endl;
        return;
    }

    // loops from l to h
    // Firstly swaps the values of pos l and i
    // recursively calls itself
    // again swap back the values
    // This makes it to print all possible pattern
    // that a string can have

    for (size_t i{l}; i <= h; i++)
    {
        std::swap(str[l], str[i]);
        perm(str, l + 1, h);
        std::swap(str[l], str[i]);
    }
}

void cod::string::cat(const char *rhs, size_t len) // use true ,false for str[_size]=0;
{
    if (len == npos) // concats whole rhs to current string
    {
        strcat(str, rhs);
    }
    else // concats a length len of rhs to current string
    {
        strncat(str, rhs, len);
        str[_size] = '\0';
    }
}

void cod::string::cpy(const char *rhs, size_t len)
{
    if (len == npos) // copy whole rhs to current string
    {
        strcpy(str, rhs);
    }
    else // copy a length len of rhs to current string
    {
        strncpy(str, rhs, len);
        str[len] = '\0';
    }
}

/*************************************************** CONSTRUCTOR ********************************************************/
cod::string::string() : string(nullptr)
{
}

cod::string::string(const char *s) : str(nullptr), index{0}, _name(FileHandler::name_generator(*this, Constant::Title::STRING)), _size(0), _capacity(0), _maxSize(cod::limits<size_t>::max()), _words(0), _vowels(0), _consonants(0)
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

cod::string::string(const char *s, size_t n) : str(nullptr), index{0}, _name(FileHandler::name_generator(*this, Constant::Title::STRING)), _size(0), _capacity(0), _maxSize(cod::limits<size_t>::max()), _words(0), _vowels(0), _consonants(0)
{
    _size = _capacity = n;

    this->capacity_selecter();

    str = new char[_capacity + 1];
    this->cpy(s, n);
}

cod::string::string(size_t n, char c) : str(nullptr), index{0}, _name(FileHandler::name_generator(*this, Constant::Title::STRING)), _size(0), _capacity(0), _maxSize(cod::limits<size_t>::max()), _words(0), _vowels(0), _consonants(0)
{
    _size = _capacity = n;

    this->capacity_selecter();

    str = new char[_capacity + 1];

    for (size_t i{0}; i < n; ++i)
        str[i] = c;

    str[n] = '\0';
}

cod::string::string(const string &rhs) : str(nullptr), index{0}, _name(FileHandler::name_generator(*this, Constant::Title::STRING)), _size(0), _capacity(0), _maxSize(cod::limits<size_t>::max()), _words(0), _vowels(0), _consonants(0)
{
    _size = rhs._size;
    _capacity = rhs._capacity;

    this->capacity_selecter();

    str = new char[_capacity + 1];
    this->cpy(rhs.str, rhs._size);
}

cod::string::string(string &&rhs) : str(nullptr), index{0}, _name(FileHandler::name_generator(*this, Constant::Title::STRING)), _size(0), _capacity(0), _maxSize(cod::limits<size_t>::max()), _words(0), _vowels(0), _consonants(0)
{
    _capacity = rhs._capacity;
    _size = rhs._size;
    str = rhs.str;
    rhs.str = nullptr;
}

cod::string::string(const std::initializer_list<char> &list) : str(nullptr), index{0}, _name(FileHandler::name_generator(*this, Constant::Title::STRING)), _size(0), _capacity(0), _maxSize(cod::limits<size_t>::max()), _words(0), _vowels(0), _consonants(0)
{
    _size = _capacity = list.size();

    this->capacity_selecter();

    str = new char[_capacity + 1];

    size_t i{0};

    for (const auto &c : list)
        str[i++] = c;

    str[i] = '\0';
}

cod::string::string(const string &rhs, size_t pos, size_t len) : str(nullptr), index{0}, _name(FileHandler::name_generator(*this, Constant::Title::STRING)), _size(0), _capacity(0), _maxSize(cod::limits<size_t>::max()), _words(0), _vowels(0), _consonants(0)
{
    // Initializing valid size by taking references of size and pos with different len condtition
    // if len equals npos, it returns the difference of rhs.size and pos
    // else it gives the minimum of len and difference of rhs.size and pos

    size_t refSize = (len == npos) ? (rhs._size - pos) : (cod::min(rhs._size - pos, len));

    _size = refSize;
    _capacity = rhs._capacity;

    this->capacity_selecter();

    str = new char[_capacity + 1];

    for (size_t i{0}; i < refSize; ++i)
        str[i] = rhs.str[pos + i];

    str[_size] = '\0';
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

size_t cod::string::size(size_t pos, size_t len) const
{
    if (!pos && len == npos) // returns the size when no args are passed
        return _size;

    this->validate(pos, true);

    // If pos or len are passed, then the size is calculated based on below formula
    return ((len == npos) ? (_size - pos) : (cod::min(_size - pos, len)));
}

size_t cod::string::length() const
{
    return _size; // size of current values stored
}

size_t cod::string::max_size() const
{
    return _maxSize; // maximum possible size of string
}

std::string cod::string::name() const
{
    return this->_name;
}

size_t cod::string::words()
{
    this->update_word_vowel_consonant(); // updates words, vowels & consonants
    return _words;
}

size_t cod::string::vowels()
{
    return _vowels;
}

size_t cod::string::consonants()
{
    return _consonants;
}

void cod::string::resize(size_t n, char c)
{
    if (n > _capacity)
    {
        // If n is grater than capacity, means we need to increased the capacity of the string
        // to store larger chars. So based on value of n, we calculate value of capacity
        // update the string with new size restore the values back and for c not equals null
        // fill the remaining values of string from char c.

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
        // If n is less than capacity and size, simply insert null to position n
        // and update the size to n

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
    // reserve, allocates n number of bytes to the string
    // If greater than capacity it adds remaining free spaces to the string
    // for new chars to add in constant time

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
    delete[] str; // deallocate the string

    // reset the values to default
    _capacity = 15;
    _size = 0;
    str = new char[_capacity + 1];
    str[_size] = '\0';
}

bool cod::string::empty() const
{
    return (_size == 0); // returns true if string is empty
}

void cod::string::shrink_to_fit()
{
    // It removes extra space by deallocating previous memory and by adding new memory by capacity equals size
    string temp(*this);

    delete[] str;

    _capacity = _size;
    str = new char[_capacity + 1];
    this->cpy(temp.str);
}

/***************************************************** ELEMENT ACCESS ***************************************************/
char &cod::string::operator[](size_t pos)
{
    return str[pos]; // returns value at index pos
}

const char &cod::string::operator[](size_t pos) const
{
    return str[pos]; // returns const value at index pos
}

char &cod::string::at(size_t pos)
{
    this->validate(pos, true);

    return str[pos];
}

const char &cod::string::at(size_t pos) const
{
    this->validate(pos, true);

    return str[pos];
}

char &cod::string::back()
{
    return str[_size - 1]; // returns the second last value of array of chars, i.e last letter of string
}

const char &cod::string::back() const
{
    return str[_size - 1]; // const last value is returned
}

char &cod::string::front()
{
    return str[0]; // first char is returned
}

const char &cod::string::front() const
{
    return str[0]; // const first char is returned
}

/******************************************************* MODIFIERS ******************************************************/

// Adds new string after the current string
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
    if ((_capacity - _size) < 1)
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

// append function equals operator+=()
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

// Insert a character at last position
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
    str[_size] = '\0';
}

// assing equals operator=()
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

    for (size_t i{0}; i < refSize; ++i)
        str[i] = rhs.str[pos + i];

    str[_size] = '\0';

    return *this;
}

cod::string &cod::string::assign(string &&rhs)
{
    return (*this = string(rhs));
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

// Insert substring at position pos of current string
cod::string &cod::string::insert(size_t pos, const string &rhs)
{
    this->validate(pos);

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
    this->validate(pos);

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
    this->validate(pos);

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
    this->validate(pos);

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
    this->validate(pos);

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

// Remove a part of string
cod::string cod::string::erase(size_t pos, size_t len)
{
    this->validate(pos);

    size_t refSize = (len == npos) ? (_size - pos) : (cod::min(_size - pos, len));

    string remStr(*this, pos, refSize);

    for (size_t i{pos}; i < _size - refSize; i++)
        str[i] = str[i + refSize];

    _size -= refSize;
    str[_size] = '\0';

    return remStr;
}

// Replace a part of string
cod::string &cod::string::replace(size_t pos, size_t len, const string &rhs)
{
    this->validate(pos);

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
    this->validate(pos);

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
    this->validate(pos);

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
    this->validate(pos);

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
    this->validate(pos);

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

void cod::string::pop_back()
{
    str[--_size] = '\0';
}

/************************************************** ADVANCED OPERATIONS *********************************************/

void cod::string::swap(string &rhs)
{
    // temporary copying this data
    string temp(string(*this));

    // copying rhs to this
    *this = string(rhs);

    // copying this to rhs
    rhs = string(temp);
}

// Reverse a part of string
void cod::string::reverse(size_t pos, size_t len) const
{
    this->validate(pos, true);

    size_t lSize = (len == npos) ? _size - pos : cod::min(_size - pos, len);

    for (size_t i{pos}, j{pos + lSize - 1}; i < j; i++, j--)
    {
        cod::swap(str[i], str[j]);
    }
}

// Checking for palindrome
bool cod::string::ispalindrome(size_t pos, size_t len) const
{
    this->validate(pos, true);

    size_t lSize = (len == npos) ? _size - pos : cod::min(_size - pos, len);

    for (size_t i{pos}, j{pos + lSize - 1}; i < j; i++, j--)
    {
        if (str[i] != str[j])
            return false;
    }

    return true;
}

// Checking for anagram
bool cod::string::isanagram(size_t pos, size_t len, const string &rhs, size_t subpos, size_t sublen) const
{
    if (pos < 0 || pos >= _size || subpos < 0 || subpos >= rhs._size)
        throw InvalidPositionException();

    size_t lSize = (len == npos) ? _size - pos : cod::min(_size - pos, len);
    size_t rSize = (sublen == npos) ? rhs._size - subpos : cod::min(rhs._size - subpos, sublen);

    if (lSize != rSize)
        return false;

    int x = 0;

    for (size_t i{0}; i < lSize; i++)
    {
        x ^= static_cast<int>(str[i]);
        x ^= static_cast<int>(rhs.str[i]);
    }

    return (!x);
}

// Checking for permutations
void cod::string::permutation(size_t pos, size_t len)
{
    this->validate(pos, true);

    size_t lSize = (len == npos) ? _size - pos : cod::min(_size - pos, len);

    cod::string str(*this, pos, lSize);

    this->index = 1;

    std::cout << std::setw(Ui::widthIndex) << std::left << "Index"
              << "   Pattern" << std::endl;

    this->perm(str, 0, lSize - 1);
}

// Finding duplicates
std::vector<std::pair<int, char>> cod::string::find_duplicates(size_t pos, size_t len)
{
    this->validate(pos, true);

    size_t lSize = (len == npos) ? _size - pos : cod::min(_size - pos, len);
    std::vector<std::pair<int, char>> vec;

    int H[26]{0};

    for (size_t i{0}; i < lSize; i++)
    {
        if (::isalpha(str[i]))
            H[::tolower(str[pos + i]) - 97]++;
    }

    for (size_t i{0}; i < 26; i++)
    {
        if (H[i] > 1)
            vec.push_back(std::pair<int, char>{H[i], static_cast<char>(97 + i)});
    }

    return vec;
}

// Find uniques
std::vector<char> cod::string::find_unique(size_t pos, size_t len)
{
    this->validate(pos, true);

    size_t lSize = (len == npos) ? _size - pos : cod::min(_size - pos, len);
    std::vector<char> vec;

    int H[26]{0};

    for (size_t i{pos}; i < pos + lSize; i++)
    {
        if (::isalpha(str[i]))
            H[::tolower(str[i]) - 97]++;
    }

    for (size_t i{0}; i < 26; i++)
    {
        if (H[i] == 1)
            vec.push_back(97 + i);
    }

    return vec;
}

/**************************************************** STRING OPERATIONS *************************************************/
const char *cod::string::c_str() const
{
    return str; // return the char*
}

const char *cod::string::data() const
{
    return str; // same as above
}

// Copy a part of char array to current string
size_t cod::string::copy(char *s, size_t len, size_t pos) const
{
    this->validate(pos);

    size_t validLength = cod::min(len, _size);

    for (size_t i{0}; i < validLength; ++i)
    {
        s[i] = str[pos + i];
    }

    return validLength;
}

// Find a substring from start of string
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

// Find a substring from last
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

// Returns the index of the first char find in current string from rhs string
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

// Find substring from last position
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

// Find char not in rhs string
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

// Compare both string
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
    this->validate(pos);

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
    this->validate(pos);

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
    this->validate(pos); // validate the position

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
    this->validate(pos);

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
    delete[] str; // free the memory allocated
}