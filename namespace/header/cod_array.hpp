#ifndef COD_ARRAY_HPP
#define COD_ARRAY_HPP

#include <iostream>

namespace cod
{
template <typename T>
class array
{
private:
    T *arr;
    size_t size;
    size_t length;
    T MIN_VALUE;

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

    T front() const;
    T back() const;
    void fill(const T &x);
    bool empty() const;
    void clear();
    void swap(array &rhs);

    ~array();
};
} // namespace cod

#endif