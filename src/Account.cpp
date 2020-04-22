#include <iostream>
#include <iomanip>
#include <fstream>
#include "../header/Account.hpp"
#include "../header/AccountHandler.hpp"
#include "../header/FileHandler.hpp"
#include "../header/Security.hpp"
#include "../namespace/header/cod_scan.hpp"

std::ostream &operator<<(std::ostream &os, Account &acc)
{
    os << std::endl
       << " " << std::setw(Ui::widthIndex) << std::left << ++acc.index
       << " | " << std::setw(Ui::widthUsername) << std::left << acc.userID
       << " | " << std::setw(Ui::widthPassword) << std::left << pass_to_asteric(acc.pass)
       << " |";
    return os;
}

std::ifstream &operator>>(std::ifstream &ifs, Account &acc)
{
    std::string key;
    Decrypter dc;

    ifs >> acc.userID >> key;
    acc.pass = dc.decrypt(key);

    return ifs;
}

void Account::input_data()
{
    cod::scan sc;

    animater(username);

    userID = sc.username(); // taking username from user

    animater(password);

    pass = sc.password(); // scanning password
}

void Account::display_remember_me() const
{
    cod::scan sc;

    border(Ui::widthMenu);

    animater(std::string{"Remember me? (Y/N): "});

    // scanning character
    char c;

    sc >> c;

    if (::tolower(c) == 'y')
        save_active_user(userID); // save the current user
    else
        Global::signedUserID = userID;
}

void Account::check_account() const
{
    std::ifstream file(Path::fUser);
    std::string fusername, fpassword;
    Decrypter dc;

    if (!file)
        throw FileNotOpenedException();

    while (file >> fusername && file >> fpassword)
    {
        if (userID == fusername && pass == dc.decrypt(fpassword))
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