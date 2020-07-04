#ifndef CREATE_ACCOUNT_HPP
#define CREATE_ACCOUNT_HPP

#include "Account.hpp"

class CreateAccount : public Account
{
private:
    std::string pass2;

public:
    void input();
    void upload();
    void isValidUser();

    std::string getPass2() const;
};

#endif