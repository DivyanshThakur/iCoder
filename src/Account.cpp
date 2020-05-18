#include <iostream>
#include <iomanip>
#include <fstream>
#include "../header/Account.hpp"
#include "../header/FileHandler.hpp"
#include "../header/Security.hpp"
#include "../namespace/header/cod_scan.hpp"

/************************************ ISAVABLE PURE VIRTUAL FUNCTION ****************************************/

std::vector<cod::pair<std::string, std::string>> Account::save() const
{
    std::vector<cod::pair<std::string, std::string>> vec;
    vec.push_back(pairBuffer);
    return vec;
}

void Account::load(const std::vector<cod::pair<std::string, std::string>> &vec)
{
    this->userID = vec.at(0).first();
    this->pass = vec.at(0).second();
}

std::string Account::filename() const
{
    return Path::fUser;
}

bool Account::generate() const
{
    std::ifstream inFile(Path::fUser);

    if (inFile) // if file already exists returns else create a new file
    {
        inFile.close();
        return false;
    }

    std::ofstream outFile(Path::fUser);

    outFile.close();

    return true;
}

/************************************** MEMBER FUNCTION OVERLOADS *******************************************/

std::string Account::pass_to_asteric() const
{
    std::string ast;

    for (size_t i{0}; i < this->pass.length(); ++i)
        ast += "*";

    return ast;
}

std::ostream &operator<<(std::ostream &os, Account &acc)
{
    os << std::endl
       << " " << std::setw(Ui::widthIndex) << std::left << ++acc.index
       << " | " << std::setw(Ui::widthUsername) << std::left << acc.userID
       << " | " << std::setw(Ui::widthPassword) << std::left << acc.pass_to_asteric()
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

Account::Account() : index(0)
{
}

void Account::input_data()
{
    cod::scan sc;

    animater(username);

    this->userID = sc.username(); // taking username from user

    animater(password);

    this->pass = sc.password(); // scanning password

    this->pairBuffer = cod::pair<std::string, std::string>(this->userID, this->pass);
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
        FileHandler::save_active_user(this->userID); // save the current user
    else
        Global::signedUserID = this->userID;
}

void Account::check_account() const
{
    this->generate();

    std::ifstream file(Path::fUser);

    std::string fusername, fpassword;
    Decrypter dc;

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