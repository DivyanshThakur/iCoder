#include <iostream>
#include <fstream>
#include <conio.h>
#include <iomanip>
#include "../header/CreateAccount.hpp"
#include "../header/Constants.hpp"
#include "../header/ExHandler.hpp"
#include "../header/UIhandler.hpp"
#include "../header/Scanner.hpp"

void CreateAccount::input_data()
{
    Scanner sc;

    Account::input_data();

    std::cout << std::endl;

    animater(RePassword);

    pass2 = sc.scanPassword(); // scanning password

    if (pass2 == "")
        throw EscPressed();
}

void CreateAccount::upload_account()
{
    std::ofstream file{fUser, std::ios::app};

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

    file << std::setw(widthUsername) << std::left << userID << std::setw(widthPassword) << std::left << pass << std::endl;

    file.close();
}

void CreateAccount::isValidUser()
{
    std::ifstream file(fUser);

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