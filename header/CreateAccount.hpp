#ifndef CREATE_ACCOUNT_HPP
#define CREATE_ACCOUNT_HPP

#include <string>
#include "Account.hpp"

class CreateAccount : public Account
{
private:
    std::string pass2;

public:
    virtual bool input_data() override;
    std::string get_pass2() const;

    virtual ~CreateAccount() = default;
};

#endif