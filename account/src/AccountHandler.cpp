#include <iostream>
#include <iomanip>
#include "../header/AccountHandler.hpp"
#include "../../main/header/iCoder.hpp"
#include "../../main/header/Ui.hpp"
#include "../header/CreateAccount.hpp"
// #include "../animation/header/AnimeHandler.hpp"
#include "../../constant/Constants.hpp"

void AccountHandler::login()
{
    Ui::header(Constant::Title::LOGIN);

    try
    {
        Account::input();
        Account::check();
        Account::rememberMe();
        // AnimeHandler::load();
        Main::home();
    }
    catch (const std::exception &e)
    {
        e.what();
    }
}

void AccountHandler::createAccount()
{
    Ui::header(Constant::Title::CREATE_ACCOUNT);

    try
    {
        CreateAccount::input();
        CreateAccount::upload();
        CreateAccount::rememberMe();
        // AnimeHandler::load();
        Main::home();
    }
    catch (const std::exception &e)
    {
        e.what();
    }
}

void AccountHandler::showUsers()
{
    if (File::empty(Account::data()))
    {
        Ui::println("No user in database!");
        return;
    }

    Ui::header(Constant::Title::USERS);

    auto userNames = File::searchTag(Account::data());

    for (size_t i{0}; i < userNames.size(); i++)
    {
        std::cout << std::setw(2) << (i + 1)
                  << " " << static_cast<char>(175) << " " << userNames.at(i).first;
        if (i < userNames.size() - 1)
            std::cout << std::endl;
    }

    Ui::pressKey();
}