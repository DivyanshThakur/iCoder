#include <iostream>
#include "../header/cod_array.hpp"

template <typename T>
cod::array<T>::array() : array(0) {}

template <typename T>
cod::array<T>::array(size_t size) : arr(nullptr), size(size), length(0)
{
    arr = new T[size];
}

template <typename T>
T cod::array<T>::operator[](size_t x) const
{
    return arr[x];
}

template <typename T>
T &cod::array<T>::operator[](size_t x)
{
    return arr[x];
}

template <typename T>
void cod::array<T>::fill(const T &x)
{
    for (size_t i{0}; i < size; ++i)
    {
        arr[i] = x;
    }
}

template <typename T>
cod::array<T>::~array()
{
    delete[] arr;
    size = length = 0;
}

template class cod::array<int>;
template class cod::array<long>;
template class cod::array<double>;
template class cod::array<char>;
template class cod::array<std::string>;