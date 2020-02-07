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
long long cod::limits<long long>::min()
{
    return LLONG_MIN;
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

template class cod::limits<int>;
template class cod::limits<long long>;
template class cod::limits<double>;
template class cod::limits<char>;
template class cod::limits<std::string>;