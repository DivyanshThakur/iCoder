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

public:
    Scanner(); // type of string - username, pass, char

    int scanInt();
    long scanLong();
    double scanDouble();
    char scanChar();
    std::string scanString();
    std::string scanUsername();
    std::string scanPassword();

    void reset(); // reset the values of scanner class
};

#endif