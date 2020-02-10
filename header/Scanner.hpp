#ifndef SCANNER_HPP
#define SCANNER_HPP

#include <string>

class Scanner
{
private:
    char c;
    std::string value;
    bool isLimitExceed;

    int checkChar(bool isPassword = false);
    bool print(const std::string &s = "") const;

public:
    Scanner(); // type of string - username, pass, char

    void scanChoice(int &choice);
    bool scan(size_t &choice);
    bool scan(int &choice);
    bool scan(long long &choice);
    bool scan(double &choice);
    bool scan(char &choice);
    bool scan(std::string &choice);

    std::string scanUsername();
    std::string scanPassword();

    void reset(); // reset the values of scanner class
};

#endif