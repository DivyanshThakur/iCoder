#ifndef COD_STRING_HPP
#define COD_STRING_HPP

#include <iostream>
#include "cod_scan.hpp"

namespace cod
{
class string
{
    /*************************************** NON MEMBER FUNCTION OVERLOADS **********************************************/

    friend std::ostream &operator<<(std::ostream &os, const string &obj)
    {
        // for (auto const &c : obj)
        // {
        //     os << c;
        // }
        for (size_t i{0}; i < obj._size; i++)
        {
            os << obj.at(i);
        }
        return os;
    }

    friend cod::scan &operator>>(cod::scan &sc, string &obj)
    {
        char *buff = new char[1'02'400]; // 100 mb
        sc >> buff;

        string s = buff;
        std::cout << "[size: " << s.size() << "], [ capacity: " << s.capacity() << "]\n";
        obj = s;

        delete[] buff;
        return sc;
    }

    // cod::scan &getline(cod::scan &sc, string &obj)
    // {
    // }

private:
    void capacity_selecter();
    void capacity_updater(size_t n);
    void cat(const char *rhs, size_t len = npos);
    void cpy(const char *rhs, size_t len = npos);

    char *str;
    size_t _size, _capacity, _max_size;

public:
    static constexpr size_t npos = -1;

    /*************************************************** CONSTRUCTOR ***************************************************/
    string();                                                 // no-args
    string(const char *s);                                    // from c-string
    string(const char *s, size_t n);                          // from buffer
    string(size_t n, char c);                                 // fill
    string(const string &rhs);                                // copy
    string(string &&rhs);                                     // move
    string(const std::initializer_list<char> &list);          // initializer list
    string(const string &rhs, size_t pos, size_t len = npos); // substring
    // string(const iterator &first, const iterator &last);   // range

    /************************************************* ASSIGNMENT OPERATOR *********************************************/
    string &operator=(const string &rhs);                       // copy
    string &operator=(string &&rhs);                            // move
    string &operator=(const char *s);                           // c-string
    string &operator=(char c);                                  // character
    string &operator=(const std::initializer_list<char> &list); // initializer list

    /*************************************************** STRING ITERATOR ***********************************************/
    // iterator begin() const;
    // iterator end() const;
    // const const_iterator cbegin() const;
    // const const_iterator cend() const;

    /****************************************************** CAPACITY ***************************************************/
    size_t size() const;
    size_t length() const;
    size_t max_size() const;
    void resize(size_t n, char c = '\0');
    size_t capacity() const;
    void reserve(size_t n = 0);
    void clear();
    bool empty() const;
    void shrink_to_fit();

    /**************************************************** ELEMENT ACCESS ************************************************/
    char &operator[](size_t pos);
    const char &operator[](size_t pos) const;
    char &at(size_t pos);
    const char &at(size_t pos) const;
    char &back();
    const char &back() const;
    char &front();
    const char &front() const;

    /******************************************************* MODIFIERS **************************************************/
    string &operator+=(const string &rhs);                       // string
    string &operator+=(const char *s);                           // c-string
    string &operator+=(char c);                                  // character
    string &operator+=(const std::initializer_list<char> &list); // initilizer list

    string &append(const string &rhs);                                // string
    string &append(const string &rhs, size_t pos, size_t len = npos); // substring
    string &append(const char *s);                                    // c-string
    string &append(const char *s, size_t n);                          // buffer
    string &append(size_t n, char c);                                 // fill
    string &append(const std::initializer_list<char> &list);          // initializer list
    // string &append(const iterator &first, const iterator &last); // range

    void push_back(char c);
    void pop_back();

    /*************************************************** STRING OPERATIONS **********************************************/

    ~string();
};

} // namespace cod

#endif