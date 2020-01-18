#include <iostream>
#include "../header/CreateAccount.hpp"
#include "../header/Constants.hpp"
#include "../header/UIhandler.hpp"

bool CreateAccount::input_data()
{
    std::cout << "CreateAccount called" << std::endl;
    if (!(Account::input_data()))
        return false;

    std::cout << std::endl;

    animater(RePassword);

    pass2 = iscan(txtPassword); // scanning password
    if (pass2 == "")
        return false;

    return true;
}