#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <conio.h>
#include <memory>
#include "../header/AccountHandler.hpp"
#include "../header/Constants.hpp"
#include "../header/UIhandler.hpp"
#include "../header/Home.hpp"
#include "../header/CreateAccount.hpp"

bool check_new_user()
{
    std::ifstream file(fuser);
    if (!file)
        return true;

    file.close();
    return false;
}

bool check_active_user()
{
    std::ifstream file(fsetting);
    if (!file)
        return false;

    file >> signedUserID;
    if (signedUserID == std::string{"NULL"})
    {
        file.close();
        return false;
    }
    file.close();
    return true;
}

void save_active_user(const std::string &userID)
{
    std::ofstream file(fsetting, std::ios::ate);

    if (!file)
    {
        std::cerr << "Error Saving current user" << std::endl;
        getch();
        exit(1);
    }

    signedUserID = userID;

    file.seekp(0, std::ios::beg);
    file << std::setw(width_username + width_password) << std::left << signedUserID << std::endl
         << std::endl;

    file.close();
    return;
}

void login()
{
    system("cls");

    title(); // display the "iCoder" title

    auto acc = std::make_unique<Account>();

    header(std::string{" LOGIN "});

    if (!acc->input_data()) // taking username and password
        return;

    border(width_menu); // display the border '----'

    if (!acc->check_account())
    {
        std::cout << "UserID/Pass is incorrect";

        if (press_esc())
            return;

        login();
    }
    else
    {
        if (!acc->display_remember_me()) // it will display remember me message
            return;

        border(width_menu);      //, false); // display the border
        load();                  // animate loading screen
        home(acc->get_userID()); // calling the main menu (HOME) screen to show all program list
    }
}

void create_account()
{
    system("cls");

    title(); // display the "iCoder" title

    header(std::string{" CREATE ACCOUNT "}); // display the header

    auto acc = std::make_unique<CreateAccount>(); // pointer to CreateAccount class

    if (!(acc->input_data())) // taking userID, pass and confirmed password from the user
        return;

    border(width_menu); // display the border

    if (acc->get_pass() != acc->get_pass2()) // validating same password or not
    {
        std::cout << "Password not matched";

        if (press_esc())
            return;

        create_account();
    }
    else if (!acc->upload_account())
    {
        std::cout << "Username already exists!";

        if (press_esc())
            return;

        create_account();
    }
    else
    { // go to home

        if (!acc->display_remember_me()) // it will display remember me message
            return;

        border(width_menu);      // display the border
        load();                  // animate loading screen
        home(acc->get_userID()); // calling the main menu (HOME) screen to show all program list
    }
}

bool display_users()
{

    system("cls");

    title(); // display "iCoder"

    header(" USERS ");

    std::ifstream file(fuser);

    if (!file)
        return false;

    auto acc = std::make_unique<Account>();

    border(width_index * 3 + width_username + width_password - 1);

    std::cout << " " << std::setw(width_index) << std::left << "INDEX"
              << " | " << std::setw(width_username) << std::left << "USERNAME"
              << " | " << std::setw(width_password) << std::left << "PASSWORD"
              << " |";

    border(width_index * 3 + width_username + width_password - 1);

    std::cout << std::setw(width_index + 1) << ""
              << " | " << std::setw(width_username) << ""
              << " | " << std::setw(width_password) << ""
              << " |";

    while (file >> *acc) // taking userID and pass from file to account class
    {
        std::cout << *acc; // display the id,pass to console using operator<< overloading
    }
    acc->reset_index(); // to reset the index back to 0 in the Account class

    border(width_index * 3 + width_username + width_password - 1);

    file.close();

    return true;
}

std::string pass_to_asteric(const std::string &pass)
{
    std::string ast;
    for (size_t i{0}; i < pass.length(); ++i)
        ast += "*";
    return ast;
}