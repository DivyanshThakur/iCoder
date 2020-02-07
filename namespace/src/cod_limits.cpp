#include "../header/cod_limits.hpp"
#include <bits/stdc++.h>
#include <float.h>
#include <string>

/** MIN VALUES **/

template <>
int cod::limits<int>::min() const
{
    return INT_MIN;
}

template <>
long long cod::limits<long long>::min() const
{
    return LLONG_MIN;
}

template <>
double cod::limits<double>::min() const
{
    return DBL_MIN;
}

template <>
char cod::limits<char>::min() const
{
    return CHAR_MIN;
}

template <>
std::string cod::limits<std::string>::min() const
{
    return std::string{""};
}

template class cod::limits<int>;
template class cod::limits<long long>;
template class cod::limits<double>;
template class cod::limits<char>;
template class cod::limits<std::string>;