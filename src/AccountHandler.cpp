#include <iostream>
#include <iomanip>
#include "../header/AccountHandler.hpp"
#include "../iCoder.hpp"
#include "../header/UIhandler.hpp"
#include "../header/ExHandler.hpp"
#include "../header/CreateAccount.hpp"
#include "../animation/header/AnimeHandler.hpp"
#include "../constant/Constants.hpp"

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

    // try
    // {
    //     acc.input_data(); // taking username and password

    //     acc.check_account();

    //     acc.display_remember_me(); // it will display remember me message

    //     border(Ui::widthMenu);        // display the border
    //     load();                       // animate loading screen
    //     Main::home(acc.get_userID()); // calling the main menu (HOME) screen to show all program list
    // }
    // catch (const EscPressed &e)
    // {
    //     return;
    // }
    // catch (const ReturnMain &e)
    // {
    //     return;
    // }
    // catch (const InvalidUser &e)
    // {
    //     e.what(false);

    //     press_key(PRE, "Press ESC to return");

    //     login();
    // }
    // catch (const std::exception &e)
    // {
    //     print_message(e.what(), true);
    // }
}

void AccountHandler::createAccount()
{
    Ui::header(Constant::Title::CREATE_ACCOUNT);

    try
    {
        CreateAccount::input();

        if (CreateAccount::password() != CreateAccount::rePassword())
            throw PasswordNotMatchedException();

        CreateAccount::upload();
        CreateAccount::rememberMe();
        AnimeHandler::load();
        Main::home();
    }
    catch (const cod::exception &e)
    {
        e.what();
    }

    // try
    // {
    //     acc.input_data(); // taking userID, pass and confirmed password from the user

    // if (acc.get_pass() != acc.get_pass2()) // validating same password or not
    //     throw PasswordNotMatchedException();

    // acc.upload_account();

    // acc.display_remember_me(); // it will display remember me message

    // border(Ui::widthMenu);        // display the border
    // load();                       // animate loading screen
    // Main::home(acc.get_userID()); // calling the main menu (HOME) screen to show all program list
    // }
    // catch (const EscPressed &e)
    // {
    //     return;
    // }
    // catch (const ReturnMain &e)
    // {
    //     return;
    // }
    // catch (const PasswordNotMatchedException &e)
    // {
    //     e.what(false);

    //     press_key(PRE, "Press ESC to return");

    //     create_account();
    // }
    // catch (const SavingUserException &e)
    // {
    //     e.what();
    // }
    // catch (const UsernameAlreadyExistsException &e)
    // {
    //     e.what(false);

    //     press_key(PRE, "Press ESC to return");

    //     create_account();
    // }
    // catch (const std::exception &e)
    // {
    //     print_message(e.what(), true);
    // }
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