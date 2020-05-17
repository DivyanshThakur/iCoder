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
template class cod::pair<int, size_t>;
template class cod::pair<int, long long>;
template class cod::pair<int, char>;
template class cod::pair<int, double>;
template class cod::pair<int, std::string>;
template class cod::pair<std::string, std::string>;