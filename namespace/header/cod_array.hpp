#ifndef COD_ARRAY_HPP
#define COD_ARRAY_HPP

#include <iostream>

namespace cod
{
// template <typename T>
// class array;

// template <typename T>
// std::ostream &operator<<(std::ostream &os, const cod::array<T> &arr);

// template <typename T>
// std::istream &operator>>(std::istream &is, cod::array<T> &arr);

template <typename T>
class array
{
    // friend std::ostream &operator<<<T>(std::ostream &os, const cod::array<T> &arr);
    // friend std::istream &operator>><T>(std::istream &is, cod::array<T> &arr);

private:
    T *arr;
    size_t size;
    size_t length;
    T MIN_VALUE;

public:
    array();
    array(size_t size);

    T operator[](size_t x) const;
    T &operator[](size_t x);

    void fill(const T &x);

    ~array();
};
} // namespace cod

#endif