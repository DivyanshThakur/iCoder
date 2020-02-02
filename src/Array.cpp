#include <iostream>

#include "../header/Array.hpp"
#include "../namespace/header/cod_array.hpp"

void Arrays()
{
    cod::array<long> arr(10);
    std::cout << arr[0] << std::endl;
    arr[0] = 25;
    std::cout << arr[0] << std::endl;
    std::cin >> arr;
    std::cout << arr;
}