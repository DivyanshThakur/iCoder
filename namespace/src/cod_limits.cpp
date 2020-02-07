#include "../header/cod_limits.hpp"
#include <bits/stdc++.h>
#include <float.h>
#include <string>

/** MIN VALUES **/

template <>
int cod::limits<int>::min()
{
    return INT_MIN;
}

template <>
long cod::limits<long>::min()
{
    return LONG_MIN;
}

template <>
double cod::limits<double>::min()
{
    return DBL_MIN;
}

template <>
char cod::limits<char>::min()
{
    return CHAR_MIN;
}

template <>
std::string cod::limits<std::string>::min()
{
    return std::string{""};
}

/** MAX VALUES **/

// template <>
// int cod::limits<int>::max()
// {
//     return INT_MAX;
// }

// template <>
// long cod::limits<long>::max()
// {
//     return LONG_MAX;
// }

// template <>
// double cod::limits<double>::max()
// {
//     return DBL_MAX;
// }

// template <>
// char cod::limits<char>::max()
// {
//     return CHAR_MAX;
// }

// template <>
// std::string cod::limits<std::string>::max()
// {
//     return std::string{""};
// }

template class cod::limits<int>;
template class cod::limits<long>;
template class cod::limits<double>;
template class cod::limits<char>;
template class cod::limits<std::string>;