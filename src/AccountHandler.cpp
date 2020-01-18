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

bool check_signed_user()
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

    std::string userID, pass;

    header(std::string{" LOGIN "});

    // if (!(input_user_pass(userID, pass))) // taking username and password
    //     return;

    border(width_menu); // display the border '----'

    if (!check_account(userID, pass))
    {
        std::cout << "UserID/Pass is incorrect";
        press_key();
        login();
    }
    else
    {
        if (!display_remember_me(userID)) // it will display remember me message
            return;

        border(width_menu); // display the border
        load();             // animate loading screen
        home(userID);       // calling the main menu (HOME) screen to show all program list
    }
}

void create_account()
{
    system("cls");

    title(); // display the "iCoder" title

    header(std::string{" CREATE ACCOUNT "}); // display the header

    std::unique_ptr<Account> acc = std::make_unique<CreateAccount>();
    std::string pass2;

    if (!(acc->input_data()))
        return;

    border(width_menu); // display the border

    if (acc->get_pass() != pass2)
    {
        std::cout << "Password not matched";
        press_key();
        create_account();
    }
    else if (!upload_account(acc->get_userID(), acc->get_pass()))
    {
        std::cout << "Username already exists!";
        press_key();
        create_account();
    }
    else
    { // go to home

        if (!display_remember_me(acc->get_userID())) // it will display remember me message
            return;

        border(width_menu);      // display the border
        load();                  // animate loading screen
        home(acc->get_userID()); // calling the main menu (HOME) screen to show all program list
    }
}

bool check_account(const std::string &userID, const std::string &pass)
{
    std::ifstream file(fuser);
    std::string fusername, fpassword;

    if (!file)
    {
        return false;
    }

    while (file >> fusername && file >> fpassword)
    {
        if (userID == fusername && pass == fpassword)
        {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

bool upload_account(const std::string &userID, const std::string &pass)
{

    std::ofstream file{fuser, std::ios::app};

    if (!file)
    {
        std::cerr << "Error saving user details" << std::endl;
        getch();
        exit(1);
    }

    if (!valid_user(userID))
    {
        // user account already exists
        file.close();
        return false;
    }

    file << std::setw(width_username) << std::left << userID << std::setw(width_password) << std::left << pass << std::endl;

    file.close();
    return true;
}

bool valid_user(const std::string &userID)
{

    std::ifstream file(fuser);

    if (!file)
    {
        std::cerr << "Error validating user details" << std::endl;
        getch();
        exit(1);
    }

    std::string fname, fpass;

    while (file >> fname && file >> fpass) // if the name matches in file return false
    {
        if (fname == userID)
        {
            file.close();
            return false;
        }
    }

    file.close(); /// close the file
    return true;
}

bool display_users()
{

    system("cls");

    title(); // display "iCoder"

    header(" USERS ");

    std::ifstream file(fuser);

    if (!file)
        return false;

    std::string userID, pass;
    int index{1};

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

    while (file >> userID && file >> pass)
    {
        std::cout << std::endl
                  << " " << std::setw(width_index) << std::left << index++
                  << " | " << std::setw(width_username) << std::left << userID
                  << " | " << std::setw(width_password) << std::left << pass_to_asteric(pass)
                  << " |";
    }

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

bool display_remember_me(const std::string &userID)
{

    animater(std::string{"Remember me? (Y/N): "});

    // taking character from string
    std::string str = iscan(txtChar);
    if (str == "")
        return false;

    char c = std::tolower(str.at(0));
    if (c == 'y')
        save_active_user(userID); // save the current user
    return true;
}