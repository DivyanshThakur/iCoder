#include <string>
#include "../header/cod_algorithm.hpp"
#include "../../header/ExHandler.hpp"

/***************************************************** MIN FUNCTION ****************************************************/
template <typename T>
T cod::min(const T &lhs, const T &rhs)
{
    if (lhs < rhs)
        return lhs;
    else
        return rhs;
}

template <typename T>
void cod::swap(T &lhs, T &rhs)
{
    T temp = rhs;
    rhs = lhs;
    lhs = temp;
}

/*************************************************** STRING FUNCTIONS **************************************************/
void cod::toupper(cod::string &str, size_t pos, size_t len)
{
    if (pos < 0 || pos >= str.size())
        throw InvalidPositionException();

    size_t refSize = (static_cast<int>(len) == -1) ? (str.size() - pos) : (cod::min(str.size() - pos, len));

    for (size_t i{0}; i < refSize; i++)
        str[pos + i] = ::toupper(str[pos + i]);
}

void cod::tolower(cod::string &str, size_t pos, size_t len)
{
    if (pos < 0 || pos >= str.size())
        throw InvalidPositionException();

    size_t refSize = (static_cast<int>(len) == -1) ? (str.size() - pos) : (cod::min(str.size() - pos, len));

    for (size_t i{0}; i < refSize; i++)
        str[pos + i] = ::tolower(str[pos + i]);
}

void cod::toggle(cod::string &str, size_t pos, size_t len)
{
    if (pos < 0 || pos >= str.size())
        throw InvalidPositionException();

    size_t refSize = (static_cast<int>(len) == -1) ? (str.size() - pos) : (cod::min(str.size() - pos, len));

    for (size_t i{0}; i < refSize; i++)
    {
        if (::islower(str[pos + i]))
            str[pos + i] = ::toupper(str[pos + i]);
        else
            str[pos + i] = ::tolower(str[pos + i]);
    }
}

std::string cod::toupper(const std::string &str)
{
    std::string temp;

    for (const auto &c : str)
        temp.push_back(::toupper(c));

    return temp;
}

std::string cod::tolower(const std::string &str)
{
    std::string temp;

    for (const auto &c : str)
        temp.push_back(::tolower(c));

    return temp;
}

/************************************************************************************************************************
 * 
 *                                                  TEMPLATE DECLARATION                                                  
 * 
 ***********************************************************************************************************************/

/***************************************************** MIN FUNCTION ****************************************************/
template int cod::min(const int &lhs, const int &rhs);
template size_t cod::min(const size_t &lhs, const size_t &rhs);
template long long cod::min(const long long &lhs, const long long &rhs);
template double cod::min(const double &lhs, const double &rhs);
template char cod::min(const char &lhs, const char &rhs);
template std::string cod::min(const std::string &lhs, const std::string &rhs);

/***************************************************** SWAP FUNCTION ****************************************************/
template void cod::swap(int &lhs, int &rhs);
template void cod::swap(size_t &lhs, size_t &rhs);
template void cod::swap(long long &lhs, long long &rhs);
template void cod::swap(double &lhs, double &rhs);
template void cod::swap(char &lhs, char &rhs);
template void cod::swap(std::string &lhs, std::string &rhs);