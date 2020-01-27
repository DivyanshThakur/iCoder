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
    Scanner(); // type of string - usrname, pass, char

    char scanChar();
    int scanChoice();
    std::string scanUsername();
    std::string scanPassword();

    void reset(); // reset the values of scanner class
};

#endif