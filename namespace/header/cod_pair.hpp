#ifndef COD_PAIR_HPP
#define COD_PAIR_HPP

#include <iomanip>
#include "../header/cod_limits.hpp"

namespace cod
{
template <typename T1, typename T2>
class pair
{

    friend std::ostream &operator<<(std::ostream &os, const pair &pair)
    {
        os << std::setw(12) << std::left << pair.second() << pair.first();
        return os;
    }

    T1 val1;
    T2 val2;

public:
    pair();
    pair(const T1 &first, const T2 &second);

    T1 first() const;
    T2 second() const;
};
} // namespace cod

#endif