#ifndef COD_LIMITS_HPP
#define COD_LIMITS_HPP

namespace cod
{
template <typename T>
class limits
{
public:
    static T min();
    static T def();
    static T max();
};
} // namespace cod
#endif