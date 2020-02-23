#ifndef COD_ARRAY_HPP
#define COD_ARRAY_HPP

#include <iostream>
#include "../../header/Scanner.hpp"

namespace cod
{
template <typename T>
class array
{
    friend std::ostream &operator<<(std::ostream &os, const array &arr)
    {

        os << "Max size: " << arr.max_size()
           << std::endl
           << "Elements stored: " << arr.length() << std::endl
           << "Array: ";

        if (arr.length())
        {
            for (size_t i = 0; i < arr.length(); ++i)
                os << arr[i] << " ";
        }
        else
            os << "No elements to display";

        return os;
    }

private:
    T *A;
    size_t size;
    size_t len;
    T DEF_VAL;

public:
    array();
    array(size_t size);
    array(const array &rhs);
    array(array &&rhs);

    T operator[](size_t x) const;
    T &operator[](size_t x);

    T at(size_t x) const;
    T &at(size_t x);

    array &operator=(const array &rhs);
    array &operator=(array &&rhs);

    void insert(T &x, size_t pos);
    T remove(size_t pos);
    array remove(size_t pos, size_t n);

    void push_back(T &x);

    T front() const;
    T back() const;
    size_t max_size() const;
    size_t length() const;
    void update_size(int x);
    void fill(const T &x);
    void fill(const T &x, size_t start, size_t end);
    bool empty() const;
    void clear();
    void swap(array &rhs);
    void swap(size_t i, size_t j);
    T average(size_t start, int n) const;

    ~array();
};
} // namespace cod

#endif