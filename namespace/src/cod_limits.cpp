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
long cod::limits<long>::min() const
{
    return LONG_MIN;
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

/** MAX VALUES **/

template <>
int cod::limits<int>::max() const
{
    return INT_MAX;
}

template <>
long cod::limits<long>::max() const
{
    return LONG_MAX;
}

template <>
double cod::limits<double>::max() const
{
    return DBL_MAX;
}

template <>
char cod::limits<char>::max() const
{
    return CHAR_MAX;
}

template <>
std::string cod::limits<std::string>::max() const
{
    return std::string{""};
}