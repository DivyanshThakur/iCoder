#ifndef COD_ALGORITHM_HPP
#define COD_ALGORITHM_HPP

#include <string>

namespace cod
{
/***************************************************** MIN FUNCTION *****************************************************/
template <typename T>
T min(const T &lhs, const T &rhs);

/*************************************************** STRING FUNCTIONS ***************************************************/
std::string toupper(const std::string &str);
std::string tolower(const std::string &str);

} // namespace cod

#endif