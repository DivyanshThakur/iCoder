#ifndef COD_ARRAY_HPP
#define COD_ARRAY_HPP

#include <iostream>

namespace cod
{
template <typename T>
class array
{
    // friend std::ostream &operator<<(std::ostream &os, const cod::array<T> &arr);
    // friend std::istream &operator>>(std::istream &is, cod::array<T> &arr);

private:
    T *arr;
    int size;
    int length;
    T MIN_VALUE;

public:
    array();
    array(int size);

    void fill(const T &x);

    ~array();
};
} // namespace cod

#endif