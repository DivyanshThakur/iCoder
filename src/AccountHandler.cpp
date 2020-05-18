#include <iostream>
#include <fstream>
#include <iomanip>
#include "../header/AccountHandler.hpp"
#include "../iCoder.hpp"
#include "../header/UIhandler.hpp"
#include "../header/ExHandler.hpp"
#include "../header/CreateAccount.hpp"

void AccountHandler::login()
{
    header(std::string{" LOGIN "});

    auto acc = std::make_unique<Account>();

    try
    {
        acc->input_data(); // taking username and password

        acc->check_account();

        acc->display_remember_me(); // it will display remember me message

        border(Ui::widthMenu);   // display the border
        load();                  // animate loading screen
        home(acc->get_userID()); // calling the main menu (HOME) screen to show all program list
    }
    catch (const EscPressed &e)
    {
        return;
    }
    catch (const ReturnMain &e)
    {
        return;
    }
    catch (const InvalidUser &e)
    {
        e.what(false);

        press_key(PRE, "Press ESC to return");

        login();
    }
    catch (...)
    {
        print_message("(Log In) Unknown error occured!", true);
    }
}

void AccountHandler::create_account()
{
    header(std::string{" CREATE ACCOUNT "}); // display the header

    auto acc = std::make_unique<CreateAccount>(); // pointer to CreateAccount class

    try
    {
        acc->input_data(); // taking userID, pass and confirmed password from the user

        if (acc->get_pass() != acc->get_pass2()) // validating same password or not
            throw PasswordNotMatchedException();

        acc->upload_account();

        acc->display_remember_me(); // it will display remember me message

        border(Ui::widthMenu);   // display the border
        load();                  // animate loading screen
        home(acc->get_userID()); // calling the main menu (HOME) screen to show all program list
    }
    catch (const EscPressed &e)
    {
        return;
    }
    catch (const ReturnMain &e)
    {
        return;
    }
    catch (const PasswordNotMatchedException &e)
    {
        e.what(false);

        press_key(PRE, "Press ESC to return");

        create_account();
    }
    catch (const SavingUserException &e)
    {
        e.what();
    }
    catch (const UsernameAlreadyExistsException &e)
    {
        e.what(false);

        press_key(PRE, "Press ESC to return");

        create_account();
    }
    catch (...)
    {
        print_message("(Create Account) Unknown error occured!!!", true);
    }
}

void AccountHandler::display_users()
{
    std::ifstream file(Path::fUser);

    if (!file)
    {
        print_message("No user in database!", true);
        return;
    }

    header(" USERS ");

    auto acc = std::make_unique<Account>();

    border(Ui::widthIndex * 3 + Ui::widthUsername + Ui::widthPassword - 1);

    std::cout << " " << std::setw(Ui::widthIndex) << std::left << "INDEX"
              << " | " << std::setw(Ui::widthUsername) << std::left << "USERNAME"
              << " | " << std::setw(Ui::widthPassword) << std::left << "PASSWORD"
              << " |";

    border(Ui::widthIndex * 3 + Ui::widthUsername + Ui::widthPassword - 1);

    std::cout << std::setw(Ui::widthIndex + 1) << ""
              << " | " << std::setw(Ui::widthUsername) << ""
              << " | " << std::setw(Ui::widthPassword) << ""
              << " |";

    while (file >> *acc) // taking userID and pass from file to account class
    {
        std::cout << *acc; // display the id,pass to console using operator<< overloading
    }

    border(Ui::widthIndex * 3 + Ui::widthUsername + Ui::widthPassword - 1);

    file.close();

    press_key();
}

std::string AccountHandler::pass_to_asteric(const std::string &pass)
{
    std::string ast;
    for (size_t i{0}; i < pass.length(); ++i)
        ast += "*";
    return ast;
}