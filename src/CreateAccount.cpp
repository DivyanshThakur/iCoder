#include <iostream>
#include <fstream>
#include <conio.h>
#include <iomanip>
#include "../header/CreateAccount.hpp"
#include "../header/Security.hpp"
#include "../namespace/header/cod_scan.hpp"

void CreateAccount::input()
{
    cod::scan sc;

    Account::input();

    Ui::print("Confirm Password: ");
    rePass = sc.password();
}

void CreateAccount::upload()
{
    isValidUser();
    FileHandler::save(Account::data());
}

void CreateAccount::isValidUser()
{
    bool isUserExist = FileHandler::find(Account::data(), Account::username());

    if (isUserExist)
        throw UsernameAlreadyExistsException();
}

std::string CreateAccount::rePassword()
{
    return rePass;
}