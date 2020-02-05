#include <iostream>
#include <limits>
#include "../header/cod_array.hpp"

template <typename T>
cod::array<T>::array() : arr(nullptr), size(0), length(0), MIN_VALUE(std::numeric_limits<T>::min()) {}

template <typename T>
cod::array<T>::array(size_t size) : arr(nullptr), size(size), length(0), MIN_VALUE(std::numeric_limits<T>::min())
{
    arr = new T[size];
}

template <typename T>
cod::array<T>::array(const cod::array<T> &rhs)
{
    if (this != &rhs)
    {
        clear();

        size = rhs.size;
        length = rhs.length;
        arr = new T[size];

        for (size_t i = 0; i < rhs.length; ++i)
        {
            arr[i] = rhs.arr[i];
        }
    }
}

template <typename T>
cod::array<T>::array(cod::array<T> &&rhs)
{
    if (this != &rhs)
    {
        clear();

        *this = rhs;

        rhs.clear();
    }
}

template <typename T>
T &cod::array<T>::operator[](size_t x)
{
    return arr[x];
}

template <typename T>
cod::array<T> &cod::array<T>::operator=(const cod::array<T> &rhs)
{
    if (this != &rhs)
    {
        clear();

        size = rhs.size;
        length = rhs.length;
        arr = new T[size];

        for (size_t i = 0; i < rhs.length; ++i)
        {
            arr[i] = rhs.arr[i];
        }
    }
    return *this;
}

template <typename T>
cod::array<T> &cod::array<T>::operator=(cod::array<T> &&rhs)
{
    if (this != &rhs)
    {
        clear();

        arr = rhs.arr;
        size = rhs.size;
        length = rhs.length;

        rhs.clear();
    }
    return *this;
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
void cod::array<T>::clear()
{
    delete[] arr;
    size = length = 0;
}

template <typename T>
void cod::array<T>::swap(cod::array<T> &rhs)
{
    cod::array<T> temp;
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