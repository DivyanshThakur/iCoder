#include <string>
#include "../header/cod_pair.hpp"
#include "../header/cod_limits.hpp"

template <typename T1, typename T2>
cod::pair<T1, T2>::pair() : pair(cod::limits<T1>::def(), cod::limits<T2>::def())
{
}

template <typename T1, typename T2>
cod::pair<T1, T2>::pair(const T1 &first, const T2 &second) : val1(first), val2(second)
{
}

template <typename T1, typename T2>
T1 cod::pair<T1, T2>::first() const
{
    return val1;
}

template <typename T1, typename T2>
T2 cod::pair<T1, T2>::second() const
{
    return val2;
}

template class cod::pair<int, int>;
template class cod::pair<size_t, int>;
template class cod::pair<long long, int>;
template class cod::pair<char, int>;
template class cod::pair<double, int>;
template class cod::pair<std::string, int>;
template class cod::pair<std::string, std::string>;