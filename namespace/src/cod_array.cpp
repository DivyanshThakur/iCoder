#include <iostream>
#include "../header/cod_array.hpp"

// template <typename T>
// std::ostream &operator<<(std::ostream &os, const cod::array<T> &arr)
// {
//     for (const auto &e : arr)
//     {
//         os << e;
//     }
//     os << std::endl;

//     return os;
// }

// template <typename T>
// std::istream &operator>>(std::istream &is, cod::array<T> &arr)
// {
//     for (auto &e : arr)
//     {
//         is >> e;
//     }

//     return is;
// }

template <typename T>
cod::array<T>::array() : array(0) {}

template <typename T>
cod::array<T>::array(int size) : arr(nullptr), size(size), length(0)
{
    arr = new T[size];
}

template <typename T>
void cod::array<T>::fill(const T &x)
{
    for (auto &e : arr)
    {
        e = x;
    }
}

template <typename T>
cod::array<T>::~array()
{
    delete[] arr;
    size = length = 0;
}