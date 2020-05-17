#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <string>
#include "FileHandler.hpp"

class Account : ISaveable
{
    friend std::ostream &operator<<(std::ostream &os, Account &acc);
    friend std::ifstream &operator>>(std::ifstream &is, Account &acc);

private:
    int index;

protected:
    std::string userID, pass;

public:
    /************************************ ISAVABLE PURE VIRTUAL FUNCTION ****************************************/

    virtual std::vector<cod::pair<std::string, std::string>> save() const override;
    virtual void load(const std::vector<cod::pair<std::string, std::string>> &vecData) override;

    /************************************** MEMBER FUNCTION OVERLOADS *******************************************/

    void input_data();
    void display_remember_me() const;
    void check_account() const;

    std::string get_userID() const;
    std::string get_pass() const;
};

#endif