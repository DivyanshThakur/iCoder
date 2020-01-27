#ifndef SCANNER_HPP
#define SCANNER_HPP

#include <string>

class Scanner
{
private:
    char c;
    std::string value;
    bool isLimitExceed;

    int checkChar(const int &size_limit);

public:
    Scanner(); // type of string - usrname, pass, char

    char scanChar();
    char scanMultiChar();
    std::string scanUsername();
    std::string scanPassword();

    void reset(); // reset the values of scanner class
};

#endif