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
    void print(const std::string &s = "") const;

public:
    Scanner(); // type of string - username, pass, char

    void scanChoice(int &choice);

    std::string scanUsername();
    std::string scanPassword();

    template <typename T>
    void scan(T &data, bool isLast = true);

    void reset(); // reset the values of scanner class
};

#endif