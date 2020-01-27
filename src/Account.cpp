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

    // userID = iscan(txtUsername); // taking username from user
    userID = sc.scanUsername();

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