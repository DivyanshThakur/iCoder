#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include "../header/Account.hpp"
#include "../header/Settings.hpp"
#include "../header/FileHandler.hpp"
#include "../header/Security.hpp"
#include "../constant/Constants.hpp"
#include "../namespace/header/cod_scan.hpp"

/************************************ ISAVEABLE PURE VIRTUAL FUNCTION ****************************************/

std::vector<std::pair<std::string, std::string>> Account::save() const
{
    std::vector<std::pair<std::string, std::string>> vec;
    vec.push_back(pairBuffer);
    return vec;
}

void Account::load(const std::vector<std::pair<std::string, std::string>> &vec)
{
    Decrypter dc;

    this->userID = vec.at(0).first;
    this->pass = dc.decrypt(vec.at(0).second);
}

std::string Account::filename() const
{
    return Constant::Path::DB;
}

bool Account::generate() const
{
    std::ifstream inFile(Constant::Path::DB);

    if (inFile) // if file already exists returns else create a new file
    {
        inFile.close();
        return false;
    }

    std::ofstream outFile(Constant::Path::DB);

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

std::string Account::pass_to_asteric(const std::string &pass) const
{
    std::string ast;

    for (size_t i{0}; i < pass.length(); ++i)
        ast += "*";

    return ast;
}

std::ostream &operator<<(std::ostream &os, Account &acc)
{
    os << std::endl
       << " " << std::setw(Constant::Ui::INDEX_WIDTH) << std::left << ++acc.index
       << " | " << std::setw(Constant::Ui::USERNAME_WIDTH) << std::left << acc.userID
       << " | " << std::setw(Constant::Ui::PASSWORD_WIDTH) << std::left << acc.pass_to_asteric()
       << " |";
    return os;
}

Account::Account() : index(0)
{
}

void Account::input_data()
{
    cod::scan sc;
    Encrypter ec;

    animater(username);

    this->userID = sc.username(); // taking username from user

    animater(password);

    this->pass = sc.password(); // scanning password

    this->pairBuffer = std::pair<std::string, std::string>(this->userID, ec.encrypt(this->pass));
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

    Global::activeUser = this->userID;

    if (::tolower(c) == 'y')
        Settings::saveActiveUser();
}

void Account::check_account() const
{
    Decrypter dc;

    this->generate();

    auto vec = FileHandler::searchTag(*this);

    for (const auto &pair : vec)
    {
        if (pair.first == this->userID && dc.decrypt(pair.second) == this->pass)
            return;
    }

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