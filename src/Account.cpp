#include "../header/Account.hpp"

bool Account::input_data()
{
    std::cout << "Account class called" << std::endl;
    // animater(username);

    // userID = iscan(txtUsername); // taking username from user

    // if (userID == "")
    //     return false;

    // std::cout << std::endl;

    // animater(password);

    // pass = iscan(txtPassword); // scanning password
    // if (pass == "")
    //     return false;

    return true;
}

std::string Account::get_userID() const
{
    return userID;
}
std::string Account::get_pass() const
{
    return pass;
}
