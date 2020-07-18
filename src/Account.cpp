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

/**************************************************************************************************************
 * 
 *                                       ISAVEABLE IMPLEMENTATIONS
 * 
 * ***********************************************************************************************************/

std::vector<std::pair<std::string, std::string>> Account::Data::save() const
{
    std::vector<std::pair<std::string, std::string>> vec;
    vec.push_back(pairBuffer);
    return vec;
}

void Account::Data::load(const std::vector<std::pair<std::string, std::string>> &vecData)
{
    if (generate()) // Create a new file if not created
        return;

    userId = vecData.at(0).first;
    pass = Decrypter::decrypt(vecData.at(0).second);
}

std::string Account::Data::getPath() const
{
    return Constant::Path::DB;
}

bool Account::Data::generate() const
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

/**************************************************************************************************************
 * 
 *                                         SETTINGS IMPLEMENTATIONS
 * 
 * ***********************************************************************************************************/

Account::Data &Account::data()
{
    return userData;
}

void Account::input()
{
    cod::scan sc;

    Ui::print("Username: ");
    userId = sc.username(); // taking username from user

    Ui::print("Password: ");
    pass = sc.password(); // scanning password

    pairBuffer = std::pair<std::string, std::string>(userId, Encrypter::encrypt(pass));
}

void Account::rememberMe()
{
    cod::scan sc;
    char c;

    Constant::Path::USER = Constant::Path::PATH + userId + ".dat";
    Global::activeUser = userId;

    Ui::print("Remember me? (Y/N): ");

    sc >> c;

    if (::tolower(c) == 'y')
        Settings::saveActiveUser();
}

void Account::check()
{
    auto vec = FileHandler::searchTag(data());

    for (const auto &pair : vec)
        if (pair.first == userId && Decrypter::decrypt(pair.second) == pass)
            return;

    throw InvalidUser();
}

std::string Account::username()
{
    return userId;
}
std::string Account::password()
{
    return pass;
}