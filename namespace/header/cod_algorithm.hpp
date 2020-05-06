#ifndef COD_ALGORITHM_HPP
#define COD_ALGORITHM_HPP

#include "cod_string.hpp"

namespace cod
{
    /************************************************** MIN FUNCTION **************************************************/
    template <typename T>
    T min(const T &lhs, const T &rhs);

    template <typename T>
    void swap(T &lhs, T &rhs);

    /*********************************************** FACTORIAL FUNCTION ***********************************************/
    long long fact(int x);

    /************************************************ STRING FUNCTIONS ************************************************/
    void toupper(cod::string &str, size_t pos = 0, size_t len = -1);
    void tolower(cod::string &str, size_t pos = 0, size_t len = -1);
    void toggle(cod::string &str, size_t pos = 0, size_t len = -1);

    std::string toupper(const std::string &str);
    std::string tolower(const std::string &str);
} // namespace cod

#endif