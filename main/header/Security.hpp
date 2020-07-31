#ifndef SECURITY_HPP
#define SECURITY_HPP

#include <string>

class Encrypter
{
    static std::string key;
    static const int noOfChars = 95;
    static const int minChar = 33;

public:
    static std::string encrypt(const std::string &value);
};

class Decrypter
{
    static std::string value;

public:
    static std::string decrypt(const std::string &value);
};

#endif