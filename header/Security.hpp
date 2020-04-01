#include <string>

class Encrypter
{
    std::string key;
    const int noOfChars = 95;
    const int minChar = 33;

public:
    std::string encrypt(const std::string &value);
};

class Decrypter
{
    std::string value;

public:
    std::string decrypt(const std::string &value);
};