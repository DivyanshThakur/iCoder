#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <iostream>
#include "iCoder.hpp"

class Account
{
private:
    std::string userID, pass;

public:
    virtual bool input_data();
    std::string get_userID() const;
    std::string get_pass() const;

    virtual ~Account() = default;
};

#endif