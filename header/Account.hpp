#ifndef ACCOUNT_H
#define ACCOUNT_H

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