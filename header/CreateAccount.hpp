#ifndef CREATE_ACCOUNT_HPP
#define CREATE_ACCOUNT_HPP

#include "Account.hpp"

class CreateAccount : public Account
{
private:
    static std::string rePass;

public:
    static void input();
    static void upload();
    static void isValidUser();

    static std::string rePassword();
};

#endif