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

template <typename T>
T cod::limits<T>::def()
{
    return 0;
}

template int cod::limits<int>::def();
template size_t cod::limits<size_t>::def();
template long long cod::limits<long long>::def();
template double cod::limits<double>::def();
template char cod::limits<char>::def();

template <>
std::string cod::limits<std::string>::def()
{
    return std::string{""};
}

/** MAX VALUES **/

template <>
int cod::limits<int>::max()
{
    return INT_MAX;
}

template <>
size_t cod::limits<size_t>::max()
{
    return UINT_MAX;
}

template <>
long long cod::limits<long long>::max()
{
    return LLONG_MAX;
}

template <>
double cod::limits<double>::max()
{
    return DBL_MAX;
}

template <>
char cod::limits<char>::max()
{
    return CHAR_MAX;
}

template <>
std::string cod::limits<std::string>::max()
{
    return std::string{"" + LLONG_MAX};
}
