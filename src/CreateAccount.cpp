#include <iostream>
#include <fstream>
#include <conio.h>
#include <iomanip>
#include "../header/CreateAccount.hpp"
#include "../header/Constants.hpp"
#include "../header/ExHandler.hpp"
#include "../header/UIhandler.hpp"
#include "../namespace/header/cod_scan.hpp"
#include "../header/Security.hpp"

void CreateAccount::input_data()
{
    cod::scan sc;

    Account::input_data();

    std::cout << std::endl;

    animater(RePassword);

    pass2 = sc.password(); // scanning password
}

void CreateAccount::upload_account()
{
    std::ofstream file{Path::fUser, std::ios::app};
    Encrypter ec;

    if (!file)
        throw SavingUserException();

    try
    {
        isValidUser();
    }
    catch (...)
    {
        file.close();
        throw;
    }

    file << std::setw(Ui::widthUsername) << std::left << userID << std::setw(Ui::widthPassword) << std::left << ec.encrypt(pass) << std::endl;

    file.close();
}

void CreateAccount::isValidUser()
{
    std::ifstream file(Path::fUser);

    if (!file)
    {
        throw FileNotOpenedException();
    }

    std::string fname, fpass;

    while (file >> fname && file >> fpass) // if the name matches in file return false
    {
        if (fname == userID)
        {
            file.close();
            throw UsernameAlreadyExistsException();
        }
    }

    file.close(); /// close the file
}

std::string CreateAccount::get_pass2() const
{
    return pass2;
}