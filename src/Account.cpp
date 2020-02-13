#include <iostream>
#include <iomanip>
#include <fstream>
#include "../header/Account.hpp"
#include "../header/Constants.hpp"
#include "../header/UIhandler.hpp"
#include "../header/AccountHandler.hpp"
#include "../header/Scanner.hpp"

std::ostream &operator<<(std::ostream &os, Account &acc)
{
    os << std::endl
       << " " << std::setw(width_index) << std::left << ++acc.index
       << " | " << std::setw(width_username) << std::left << acc.userID
       << " | " << std::setw(width_password) << std::left << pass_to_asteric(acc.pass)
       << " |";
    return os;
}

std::ifstream &operator>>(std::ifstream &ifs, Account &acc)
{
    ifs >> acc.userID >> acc.pass;
    return ifs;
}

bool Account::input_data()
{
    animater(username);

    Scanner sc;

    userID = sc.scanUsername(); // taking username from user

    if (userID == "")
        return false;

    animater(password);

    pass = sc.scanPassword(); // scanning password

    if (pass == "")
        return false;

    return true;
}

bool Account::display_remember_me() const
{
    Scanner sc;
    animater(std::string{"Remember me? (Y/N): "});

    // scanning character
    char c;
    sc.scan(c);
    std::cout << std::endl;

    if (c == ESC)
        return false;

    if (c == 'y' || c == 'Y')
        save_active_user(userID); // save the current user

    return true;
}

bool Account::check_account() const
{
    std::ifstream file(fuser);
    std::string fusername, fpassword;

    if (!file)
    {
        return false;
    }

    while (file >> fusername && file >> fpassword)
    {
        if (userID == fusername && pass == fpassword)
        {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

void Account::reset_index()
{
    index = 0;
}

std::string Account::get_userID() const
{
    return userID;
}
std::string Account::get_pass() const
{
    return pass;
}