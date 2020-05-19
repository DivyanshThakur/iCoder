#include <iostream>
#include <iomanip>
#include "../header/AccountHandler.hpp"
#include "../iCoder.hpp"
#include "../header/UIhandler.hpp"
#include "../header/ExHandler.hpp"
#include "../header/CreateAccount.hpp"

void AccountHandler::login()
{
    header(std::string{" LOGIN "});

    Account acc;

    try
    {
        acc.input_data(); // taking username and password

        acc.check_account();

        acc.display_remember_me(); // it will display remember me message

        border(Ui::widthMenu);  // display the border
        load();                 // animate loading screen
        home(acc.get_userID()); // calling the main menu (HOME) screen to show all program list
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
    catch (const std::exception &e)
    {
        print_message(e.what(), true);
    }
}

void AccountHandler::create_account()
{
    header(std::string{" CREATE ACCOUNT "}); // display the header

    CreateAccount acc;

    try
    {
        acc.input_data(); // taking userID, pass and confirmed password from the user

        if (acc.get_pass() != acc.get_pass2()) // validating same password or not
            throw PasswordNotMatchedException();

        acc.upload_account();

        acc.display_remember_me(); // it will display remember me message

        border(Ui::widthMenu);  // display the border
        load();                 // animate loading screen
        home(acc.get_userID()); // calling the main menu (HOME) screen to show all program list
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
    catch (const std::exception &e)
    {
        print_message(e.what(), true);
    }
}

void AccountHandler::display_users()
{
    Account acc;

    if (FileHandler::is_empty(acc))
    {
        print_message("No user in database!", true);
        return;
    }

    header(" USERS ");

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

    auto vec = FileHandler::search_all(acc);

    for (const auto &pair : vec)
    {
        std::vector<cod::pair<std::string, std::string>> vec;
        vec.push_back(pair);
        acc.load(vec);
        std::cout << acc;
    }

    border(Ui::widthIndex * 3 + Ui::widthUsername + Ui::widthPassword - 1);

    press_key();
}