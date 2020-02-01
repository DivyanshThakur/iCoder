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
    size_t size;
    size_t length;
    T MIN_VALUE;

public:
    array();
    array(size_t size);

    T operator[](size_t x) const;
    T &operator[](size_t x);

    void fill(const T &x);
    size_t get_size() const;
    size_t get_length() const;

    ~array();
};
} // namespace cod

#endif