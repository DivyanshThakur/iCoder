#ifndef CREATE_ACCOUNT_H
#define CREATE_ACCOUNT_H

#include <iostream>
#include "Account.hpp"

class CreateAccount : public Account
{
private:
    std::string pass2;

public:
    virtual bool input_data() override;
    //void upload();

    virtual ~CreateAccount() = default;
};

#endif