#include "../header/Account.hpp"

Account::Account(const std::string userID, const std::string pass)
    : userID(userID), pass(pass) {}
std::string Account::get_userID()
{
    return userID;
}
std::string Account::get_pass()
{
    return pass;
}
