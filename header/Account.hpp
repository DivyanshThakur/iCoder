#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>

class Account
{
private:
    std::string userID, pass;

public:
    Account() = default;
    Account(std::string userID, std::string pass);
    std::string get_userID();
    std::string get_pass();
};

#endif