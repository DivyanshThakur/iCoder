#include "../header/cod_array.hpp"

template <typename T>
cod::array<T>::array() : array(0) {}

template <typename T>
cod::array<T>::array(int size) : arr(nullptr), size(size), length(0)
{
    arr = new T[size];
    fill(M)
}

template <typename T>
void cod::array<T>::fill(const T &x)
{
    for (auto &ele : arr)
    {
        ele = x;
    }
}