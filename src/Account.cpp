#include <iostream>
#include <iomanip>
#include <fstream>
#include "../header/Account.hpp"
#include "../header/Constants.hpp"
#include "../header/UIhandler.hpp"
#include "../header/ExHandler.hpp"
#include "../header/AccountHandler.hpp"
#include "../namespace/header/cod_scan.hpp"

std::ostream &operator<<(std::ostream &os, Account &acc)
{
    os << std::endl
       << " " << std::setw(widthIndex) << std::left << ++acc.index
       << " | " << std::setw(widthUsername) << std::left << acc.userID
       << " | " << std::setw(widthPassword) << std::left << pass_to_asteric(acc.pass)
       << " |";
    return os;
}

std::ifstream &operator>>(std::ifstream &ifs, Account &acc)
{
    ifs >> acc.userID >> acc.pass;
    return ifs;
}

void Account::input_data()
{
    cod::scan sc;

    animater(username);

    userID = sc.username(); // taking username from user

    if (userID == "")
        throw EscPressed();

    animater(password);

    pass = sc.password(); // scanning password

    if (pass == "")
        throw EscPressed();
}

void Account::display_remember_me() const
{
    cod::scan sc;

    border(widthMenu);

    animater(std::string{"Remember me? (Y/N): "});

    // scanning character
    char c;
    // sc.scan(c);
    sc >> c;

    if (c == ESC)
        throw EscPressed();

    if (::tolower(c) == 'y')
        save_active_user(userID); // save the current user
    else
        signedUserID = userID;
}

void Account::check_account() const
{
    std::ifstream file(fUser);
    std::string fusername, fpassword;

    if (!file)
        throw FileNotOpenedException();

    while (file >> fusername && file >> fpassword)
    {
        if (userID == fusername && pass == fpassword)
        {
            file.close();
            return;
        }
    }

    file.close();
    throw InvalidUser();
}

std::string Account::get_userID() const
{
    return userID;
}
std::string Account::get_pass() const
{
    return pass;
}