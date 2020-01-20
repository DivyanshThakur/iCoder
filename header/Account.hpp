#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <string>

class Account
{
    friend std::ostream &operator<<(std::ostream &os, const Account &acc);
    friend std::ifstream &operator>>(std::ifstream &is, Account &acc);

protected:
    std::string userID, pass;

public:
    bool input_data();
    bool display_remember_me() const;
    bool check_account() const;

    std::string get_userID() const;
    std::string get_pass() const;
};

#endif