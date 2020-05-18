#include <iostream>
#include <iomanip>
#include <fstream>
#include "../header/Account.hpp"
#include "../header/AccountHandler.hpp"
#include "../header/FileHandler.hpp"
#include "../header/Security.hpp"
#include "../namespace/header/cod_scan.hpp"

/************************************ ISAVABLE PURE VIRTUAL FUNCTION ****************************************/

std::vector<cod::pair<std::string, std::string>> Account::save() const
{
    std::vector<cod::pair<std::string, std::string>> vecData;

    return vecData;
}

void Account::load(const std::vector<cod::pair<std::string, std::string>> &vecData)
{
    // for (const auto &pair : vecData)
    // {
    //     if (pair.first() == DataFile::NAME)
    //         std::cout << 'H';
    // }
}

/************************************** MEMBER FUNCTION OVERLOADS *******************************************/

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

    this->userID = sc.username(); // taking username from user

    animater(password);

    this->pass = sc.password(); // scanning password
}

void Account::display_remember_me() const
{
    cod::scan sc;
    char c;

    border(Ui::widthMenu);
    animater(std::string{"Remember me? (Y/N): "});

    // scanning character
    sc >> c;

    Path::userFilePath = Path::dataPath + this->userID + ".dat";

    if (::tolower(c) == 'y')
        save_active_user(this->userID); // save the current user
    else
        Global::signedUserID = this->userID;
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
        if (this->userID == fusername && this->pass == dc.decrypt(fpassword))
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
    return this->userID;
}
std::string Account::get_pass() const
{
    return this->pass;
}