#include <string>
#include "../header/cod_algorithm.hpp"

template <typename T>
T cod::min(const T &lhs, const T &rhs)
{
    if (lhs < rhs)
        return lhs;
    else
        return rhs;
}

// template declaration
// min
template int cod::min(const int &lhs, const int &rhs);
template size_t cod::min(const size_t &lhs, const size_t &rhs);
template long long cod::min(const long long &lhs, const long long &rhs);
template double cod::min(const double &lhs, const double &rhs);
template char cod::min(const char &lhs, const char &rhs);
template std::string cod::min(const std::string &lhs, const std::string &rhs);