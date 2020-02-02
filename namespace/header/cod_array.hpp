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

    T operator[](size_t x) const;
    T &operator[](size_t x);

    void fill(const T &x);

    ~array();
};
} // namespace cod

#endif