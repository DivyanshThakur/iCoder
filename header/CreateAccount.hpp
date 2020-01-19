#ifndef CREATE_ACCOUNT_HPP
#define CREATE_ACCOUNT_HPP

#include <string>
#include "Account.hpp"

class CreateAccount : public Account
{
    friend std::string Account::get_pass2() const;

private:
    std::string pass2;

public:
    virtual bool input_data() override;

    virtual ~CreateAccount() = default;
};

#endif