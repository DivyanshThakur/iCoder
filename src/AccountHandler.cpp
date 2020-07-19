#include <iostream>
#include <iomanip>
#include "../header/AccountHandler.hpp"
#include "../iCoder.hpp"
#include "../header/UIhandler.hpp"
#include "../header/CreateAccount.hpp"
#include "../animation/header/AnimeHandler.hpp"
#include "../constant/Constants.hpp"
#include "../namespace/header/cod_exception.hpp"

void AccountHandler::login()
{
    Ui::header(Constant::Title::LOGIN);

    try
    {
        Account::input();
        Account::check();
        Account::rememberMe();
        AnimeHandler::load();
        Main::home();
    }
    catch (const cod::exception &e)
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
        AnimeHandler::load();
        Main::home();
    }
    catch (const cod::exception &e)
    {
        e.what();
    }
}

void AccountHandler::showUsers()
{
    if (FileHandler::empty(Account::data()))
    {
        Ui::println("No user in database!");
        return;
    }

    Ui::header(Constant::Title::USERS);

    auto userNames = FileHandler::searchTag(Account::data());
    int index = 1;

    for (const auto &pair : userNames)
    {
        std::cout << std::setw(Constant::Ui::PASSWORD_WIDTH) << index++
                  << " " << static_cast<char>(175) << " " << pair.first << std::endl;
    }

    Ui::pressKey();
}