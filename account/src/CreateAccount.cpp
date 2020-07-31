#include <iostream>
#include <fstream>
#include <conio.h>
#include <iomanip>
#include "../header/CreateAccount.hpp"
#include "../../main/header/Security.hpp"
#include "../../exception/header/Exception.hpp"
#include "../../namespace/header/cod_scan.hpp"

std::string CreateAccount::rePass;

void CreateAccount::input()
{
    cod::scan sc;

    Account::input();

    std::cout << "Confirm Password: ";
    rePass = sc.password();
}

void CreateAccount::upload()
{
    isValidUser();
    File::save(Account::data());
}

void CreateAccount::isValidUser()
{
    if (password() != rePass)
        throw PasswordNotMatchedException();

    bool isUserExist = File::find(Account::data(), Account::username());

    if (isUserExist)
        throw UsernameAlreadyExistsException();
}