#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <string>

class Account
{
    friend std::ostream &operator<<(std::ostream &os, Account &acc);
    friend std::ifstream &operator>>(std::ifstream &is, Account &acc);

private:
    int index;

protected:
    std::string userID, pass;

public:
    void input_data();
    void display_remember_me() const;
    void check_account() const;

    std::string get_userID() const;
    std::string get_pass() const;
};

#endif