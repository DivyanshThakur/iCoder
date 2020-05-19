#include <iostream>
#include <fstream>
#include <conio.h>
#include <iomanip>
#include "../header/CreateAccount.hpp"
#include "../header/Security.hpp"
#include "../namespace/header/cod_scan.hpp"

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
    this->generate();

    isValidUser();

    FileHandler::save(*this);
}

void CreateAccount::isValidUser()
{
    bool isUserExist = FileHandler::find(*this, userID);

    if (isUserExist)
        throw UsernameAlreadyExistsException();
}

std::string CreateAccount::get_pass2() const
{
    return pass2;
}