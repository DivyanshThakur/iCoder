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
size_t cod::limits<size_t>::min()
{
    return 0;
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

/** DEFAULT VALUES **/

template <>
int cod::limits<int>::def()
{
    return INT_MIN;
}

template <>
size_t cod::limits<size_t>::def()
{
    return 0;
}

template <>
long long cod::limits<long long>::def()
{
    return LLONG_MIN;
}

template <>
double cod::limits<double>::def()
{
    return DBL_MIN;
}

template <>
char cod::limits<char>::def()
{
    return CHAR_MIN;
}

template <>
std::string cod::limits<std::string>::def()
{
    return std::string{""};
}
