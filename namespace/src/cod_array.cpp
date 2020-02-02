#include <iostream>
#include "../header/cod_array.hpp"

// template <typename T>
// std::ostream &cod::operator<<(std::ostream &os, const cod::array<T> &arr)
// {
//     for (size_t i{0}; i < arr.size; ++i)
//     {
//         os << arr[i];
//     }
//     os << std::endl;

//     return os;
// }

// template <typename T>
// std::istream &cod::operator>>(std::istream &is, cod::array<T> &arr)
// {
//     for (size_t i{0}; i < arr.size; ++i)
//     {
//         is >> arr[i];
//     }

//     return is;
// }

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

// template std::ostream &cod::operator<<<long>(std::ostream &os, const cod::array<long> &arr);
// template std::ostream &cod::operator<<<double>(std::ostream &os, const cod::array<double> &arr);
// template std::ostream &cod::operator<<<char>(std::ostream &os, const cod::array<char> &arr);
// template std::ostream &cod::operator<<<std::string>(std::ostream &os, const cod::array<std::string> &arr);

// template std::istream &cod::operator>><long>(std::istream &is, cod::array<long> &arr);
// template std::istream &cod::operator>><double>(std::istream &is, cod::array<double> &arr);
// template std::istream &cod::operator>><char>(std::istream &is, cod::array<char> &arr);
// template std::istream &cod::operator>><std::string>(std::istream &is, cod::array<std::string> &arr);