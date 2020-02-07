#ifndef COD_LIMITS_HPP
#define COD_LIMITS_HPP

namespace cod
{
template <typename T>
class limits
{
public:
    T min() const;
    T max() const;
};
} // namespace cod
#endif