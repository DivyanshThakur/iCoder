#include <iostream>

#include "../header/Recursion.hpp"
#include "../namespace/header/cod_recursion.hpp"

void recursion()
{
    long sum{0};
    cod::recursion r;
    sum = r.sum_to_n(5);
    std::cout << sum;
}