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
    size_t _size, _max_size;

public:
    static constexpr size_t npos = -1;

    /*************************************************** CONSTRUCTOR *****************************************************/
    string();                                                 // no-args
    string(const char *s);                                    // from c-string
    string(const char *s, size_t n);                          // from buffer
    string(size_t n, char c);                                 // fill
    string(const string &rhs);                                // copy
    string(string &&rhs);                                     // move
    string(const std::initializer_list<char> &list);          // initializer list
    string(const string &rhs, size_t pos, size_t len = npos); // substring
    // string(const iterator &first, const iterator &last);   // range

    /************************************************* ASSIGNMENT OPERATOR ***********************************************/
    string &operator=(const string &rhs);                       // copy
    string &operator=(string &&rhs);                            // move
    string &operator=(const char *s);                           // c-string
    string &operator=(char c);                                  // character
    string &operator=(const std::initializer_list<char> &list); // initializer list

    /*************************************************** STRING ITERATOR **************************************************/
    // iterator begin() const;
    // iterator end() const;
    // const const_iterator cbegin() const;
    // const const_iterator cend() const;

    /****************************************************** CAPACITY *******************************************************/
    size_t size() const;
    size_t length() const;
    // size_t max_size() const;
    // bool empty() const;
    // void update_size(int x);
    // void clear();

    ~string();
};

} // namespace cod

#endif