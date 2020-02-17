#include <iostream>
#include "../header/cod_limits.hpp"
#include "../header/cod_array.hpp"
#include "../../header/UIhandler.hpp"
#include "../../header/ExHandler.hpp"

template <typename T>
cod::array<T>::array() : A(nullptr), size(0), len(0), MIN_VALUE(cod::limits<T>::min()), DEF_VALUE(cod::limits<T>::def()) {}

template <typename T>
cod::array<T>::array(size_t size) : A(nullptr), size(size), len(0), MIN_VALUE(cod::limits<T>::min()), DEF_VALUE(cod::limits<T>::def())
{
    if (size < 0)
        throw NegativeValueException();
    else
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

        for (size_t i = 0; i < len; ++i)
        {
            A[i] = rhs[i];
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

        rhs.A = nullptr;
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
        throw OutofBoundsException();

    return A[x];
}

template <typename T>
T &cod::array<T>::at(size_t x)
{
    if (x < 0 || x >= size)
        throw OutofBoundsException();

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
        for (size_t i = 0; i < len; ++i)
        {
            A[i] = rhs[i];
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

        rhs.A = nullptr;
    }
    return *this;
}

template <typename T>
void cod::array<T>::insert(T &x, size_t pos)
{
    if (pos > len || pos <= 0)
        throw InvalidPositionException();

    if (len >= size)
        throw ArrayFullException();

    size_t i;

    for (i = len++; i >= pos; --i)
    {
        A[i] = A[i - 1];
    }
    A[i] = x;
}

template <typename T>
T cod::array<T>::remove(size_t pos)
{
    T value;

    if (pos > len || pos <= 0)
        throw InvalidPositionException();

    size_t i = pos - 1;

    value = A[i];

    --len;

    while (i < len)
    {
        A[i] = A[i + 1];
        ++i;
    }

    return value;
}

template <typename T>
cod::array<T> cod::array<T>::remove(size_t pos, size_t n)
{
    cod::array<T> values(n);

    if (pos > len || pos <= 0)
        throw InvalidPositionException();

    size_t i, j;
    i = pos - 1;
    for (j = 0; j < n; ++j, ++i)
    {
        if (pos + j > len)
            break;
        values.push_back(A[i]);
    }
    for (i = pos - 1; i + n < len; ++i)
        A[i] = A[i + n];

    len -= values.length();

    return values;
}

template <typename T>
void cod::array<T>::push_back(T &x)
{
    if (len >= size)
        throw ArrayFullException();

    A[len++] = x;
}

template <typename T>
T cod::array<T>::front() const
{
    if (len == 0)
        throw ArrayEmptyException();

    return A[0];
}

template <typename T>
T cod::array<T>::back() const
{
    if (len <= 0)
        throw ArrayEmptyException();

    return A[len - 1];
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
void cod::array<T>::update_size(int x)
{
    if (x < 0)
        throw NegativeValueException();

    if (static_cast<int>(size) == x)
        return;

    if (x < static_cast<int>(len))
    {
        bool in;

        in = confirm_the_change(std::string{"Entered size is less than actual\nSome elements might get deleted!"});

        if (!in)
            return;
    }

    size = x;

    if (len > size)
        len = size;

    T *temp_Arr = new T[size];

    for (size_t i{0}; i < len; ++i)
        temp_Arr[i] = A[i];

    delete[] A;
    A = temp_Arr;
}

template <typename T>
void cod::array<T>::fill(const T &x)
{
    fill(x, 0, size);
}

template <typename T>
void cod::array<T>::fill(const T &x, size_t start, size_t end)
{
    for (size_t i{start}; i < end; ++i)
    {
        ++len;
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
    cod::array<T> temp{*this};
    *this = rhs;
    rhs = temp;
}

template <typename T>
cod::array<T>::~array()
{
    delete[] A;
    size = len = 0;
}

template class cod::array<int>;
template class cod::array<long long>;
template class cod::array<double>;
template class cod::array<char>;
template class cod::array<std::string>;