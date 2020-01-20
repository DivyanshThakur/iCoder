#include <iostream>
#include <fstream>
#include <conio.h>
#include <iomanip>
#include "../header/CreateAccount.hpp"
#include "../header/Constants.hpp"
#include "../header/UIhandler.hpp"

bool CreateAccount::input_data()
{
    if (!(Account::input_data()))
        return false;

    std::cout << std::endl;

    animater(RePassword);

    pass2 = iscan(txtPassword); // scanning password
    if (pass2 == "")
        return false;

    return true;
}

bool CreateAccount::upload_account()
{
    std::ofstream file{fuser, std::ios::app};

    if (!file)
    {
        std::cerr << "Error saving user details" << std::endl;
        getch();
        exit(1);
    }

    if (!isValidUser())
    {
        // user account already exists
        file.close();
        return false;
    }

    file << std::setw(width_username) << std::left << userID << std::setw(width_password) << std::left << pass << std::endl;

    file.close();
    return true;
}

bool CreateAccount::isValidUser()
{
    std::ifstream file(fuser);

    if (!file)
    {
        std::cerr << "Error validating user details" << std::endl;
        getch();
        exit(1);
    }

    std::string fname, fpass;

    while (file >> fname && file >> fpass) // if the name matches in file return false
    {
        if (fname == userID)
        {
            file.close();
            return false;
        }
    }

    file.close(); /// close the file
    return true;
}

std::string CreateAccount::get_pass2() const
{
    return pass2;
}
