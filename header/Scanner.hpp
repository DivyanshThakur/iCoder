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

    void scan(int &choice, bool isNeedLine = true);
    void scan(long long &choice);
    void scan(double &choice, bool isNeedLine = true);
    void scan(char &choice);
    void scan(std::string &choice);

    std::string scanUsername();
    std::string scanPassword();

    void reset(); // reset the values of scanner class
};

#endif