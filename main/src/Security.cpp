#include <stdlib.h>
#include <time.h>
#include "../header/Security.hpp"

std::string Encrypter::key;
std::string Decrypter::value;

std::string Encrypter::encrypt(const std::string &value)
{
    srand(time(NULL));
    key.clear();

    int rVal = rand() % noOfChars;

    for (const auto &ch : value)
    {
        key += static_cast<char>((ch + 27) % noOfChars + minChar);
        key += static_cast<char>((7 * ch + 3 * rVal) % noOfChars + minChar);
        key += static_cast<char>((11 * ch + 17 * rVal) % noOfChars + minChar);
    }

    return key;
}

std::string Decrypter::decrypt(const std::string &key)
{
    for (size_t i{0}; i < key.size(); i += 3)
    {
        char c = key.at(i);

        if (c > 92)
            c -= 60;
        else
            c += 35;

        value += c;
    }

    return value;
}