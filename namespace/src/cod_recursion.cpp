#include "../header/cod_recursion.hpp"

int cod::recursion::sum_to_n(int n)
{
    if (n == 0)
        return n;

    return sum_to_n(n - 1) + n;
}