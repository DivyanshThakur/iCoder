#include <iostream>
#include <iomanip>
#include <fstream>
#include "../header/Account.hpp"
#include "../header/Constants.hpp"
#include "../header/UIhandler.hpp"
#include "../header/AccountHandler.hpp"

std::ostream &operator<<(std::ostream &os, const Account &acc)
{
    static int index{0};

    os << std::endl
       << " " << std::setw(width_index) << std::left << ++index
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

    userID = iscan(txtUsername); // taking username from user

    if (userID == "")
        return false;

    std::cout << std::endl;

    animater(password);

    pass = iscan(txtPassword); // scanning password
    if (pass == "")
        return false;

    return true;
}

bool Account::display_remember_me() const
{

    animater(std::string{"Remember me? (Y/N): "});

    // taking character from string
    std::string str = iscan(txtChar);
    if (str == "")
        return false;

    char c = std::tolower(str.at(0));
    if (c == 'y')
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

std::string Account::get_userID() const
{
    return userID;
}
std::string Account::get_pass() const
{
    return pass;
}