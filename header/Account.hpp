#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <string>

class Account
{
protected:
    std::string userID, pass;

public:
    bool input_data();

    std::string get_userID() const;
    std::string get_pass() const;
};

#endif