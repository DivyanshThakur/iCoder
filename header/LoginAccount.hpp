#ifndef LOGIN_ACCOUNT_HPP
#define LOGIN_ACCOUNT_HPP

#include "Account.hpp"

class LoginAccount : public Account
{
public:
    virtual bool input_data() override;
    virtual ~LoginAccount() = default;
};

#endif