#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <string>

class Account
{
private:
    std::string userID, pass;

public:
    virtual bool input_data();
    std::string get_userID() const;
    std::string get_pass() const;
    std::string get_pass2() const;

    virtual ~Account() = default;
};

#endif