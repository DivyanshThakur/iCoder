#ifndef LOGIN_ACCOUNT_HPP
#define LOGIN_ACCOUNT_HPP

#include "Account.hpp"

class LoginAccount : public Account
{
public:
    bool input_data();
    virtual ~LoginAccount() = default;
};

#endif