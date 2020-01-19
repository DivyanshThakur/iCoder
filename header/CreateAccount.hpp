#ifndef CREATE_ACCOUNT_HPP
#define CREATE_ACCOUNT_HPP

#include <string>
#include "Account.hpp"

class CreateAccount : public Account
{
private:
    std::string pass2;

public:
    bool input_data();
    bool upload_account();
    bool isValidUser();

    std::string get_pass2() const;
};

#endif