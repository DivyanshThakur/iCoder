#include "../header/CreateAccount.hpp"

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