#include <iostream>
#include <limits>
#include "../header/cod_array.hpp"

template <typename T>
cod::array<T>::array() : A(nullptr), size(0), len(0) {}

template <typename T>
cod::array<T>::array(size_t size) : A(nullptr), size(size), len(0)
{
    A = new T[size];
}

template <typename T>
cod::array<T>::array(const cod::array<T> &rhs)
{
    if (this != &rhs)
    {
        clear();

        size = rhs.size;
        len = rhs.len;
        A = new T[size];

        for (size_t i = 0; i < rhs.size; ++i)
        {
            A[i] = rhs.A[i];
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
T cod::array<T>::operator[](size_t x) const
{
    return A[x];
}

template <typename T>
T &cod::array<T>::operator[](size_t x)
{
    return A[x];
}

template <typename T>
T cod::array<T>::at(size_t x) const
{
    if (x < 0 || x >= size)
    {
        std::cerr << "Out of bounds exception";
    }
    return A[x];
}

template <typename T>
T &cod::array<T>::at(size_t x)
{
    if (x < 0 || x >= size)
    {
        std::cerr << "Out of bounds exception";
    }
    return A[x];
}

template <typename T>
cod::array<T> &cod::array<T>::operator=(const cod::array<T> &rhs)
{
    if (this != &rhs)
    {
        clear();

        size = rhs.size;
        len = rhs.len;
        A = new T[size];

        for (size_t i = 0; i < rhs.size; ++i)
        {
            A[i] = rhs.A[i];
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

        A = rhs.A;
        size = rhs.size;
        len = rhs.len;

        rhs.clear();
    }
    return *this;
}

template <typename T>
T cod::array<T>::front() const
{
    return A[0];
}

template <typename T>
T cod::array<T>::back() const
{
    return ((len > 0) ? A[len - 1] : MIN_VALUE);
}

template <typename T>
size_t cod::array<T>::max_size() const
{
    return size;
}

template <typename T>
size_t cod::array<T>::length() const
{
    return len;
}

template <typename T>
T cod::array<T>::get_min_val() const
{
    return MIN_VALUE;
}

template <typename T>
void cod::array<T>::set_size(int x)
{
    if (x >= 0)
        size = x;
}

template <typename T>
void cod::array<T>::fill(const T &x)
{
    for (size_t i{0}; i < size; ++i)
    {
        A[i] = x;
    }
}

template <typename T>
bool cod::array<T>::empty() const
{
    return (len > 0);
}

template <typename T>
void cod::array<T>::clear()
{
    delete[] A;
    size = len = 0;
}

template <typename T>
void cod::array<T>::swap(cod::array<T> &rhs)
{
    cod::array<T> temp;
}

template <typename T>
cod::array<T>::~array()
{
    delete[] A;
    size = len = 0;
}

template class cod::array<int>;
template class cod::array<long>;
template class cod::array<double>;
template class cod::array<char>;
template class cod::array<std::string>;