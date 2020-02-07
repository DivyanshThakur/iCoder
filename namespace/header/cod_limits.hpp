#ifndef COD_LIMITS_HPP
#define COD_LIMITS_HPP

#include <limits>
namespace cod
{
template <typename T>
class limits : public std::numeric_limits
{
public:
    T min() override;
};
} // namespace cod
#endif