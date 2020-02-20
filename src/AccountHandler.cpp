#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <conio.h>
#include <memory>
#include "../header/AccountHandler.hpp"
#include "../header/Constants.hpp"
#include "../header/UIhandler.hpp"
#include "../header/ExHandler.hpp"
#include "../header/Home.hpp"
#include "../header/CreateAccount.hpp"

void restore_saved_changes()
{
    std::ifstream file(fsetting);

    if (!file)
        return;

    std::string title;

    while (file >> title)
    {
        if (title == std::string{"CURRENT_USER"})
            file >> signedUserID;
        else if (title == std::string{"ANIMATION_SPEED"})
            file >> sleep_time;
    }

    file.close();
}

bool check_new_user()
{
    std::ifstream file(fuser);
    if (!file)
        return true;

    file.close();
    return false;
}

void save_active_user(const std::string &userID)
{
    std::ofstream file(fsetting, std::ios::app);

    if (!file)
    {
        std::cerr << "Error Saving current user" << std::endl;
        press_key();
        return;
    }

    signedUserID = userID;

    save_to_file(file, std::string{"CURRENT_USER"}, signedUserID);

    file.close();
}

void login()
{
    system("cls");

    title(); // display the "iCoder" title

    header(std::string{" LOGIN "});

    auto acc = std::make_unique<Account>();

    try
    {
        acc->input_data(); // taking username and password

        acc->check_account();

        acc->display_remember_me(); // it will display remember me message

        border(width_menu);      // display the border
        load();                  // animate loading screen
        home(acc->get_userID()); // calling the main menu (HOME) screen to show all program list
    }
    catch (const EscPressed &e)
    {
        return;
    }
    catch (const InvalidUser &e)
    {
        std::cerr << e.what();

        if (press_esc())
            return;

        login();
    }
    catch (const FileNotOpenedException &e)
    {
        std::cerr << e.what();
        press_key();
    }
    catch (...)
    {
        std::cerr << "Unknown error occured!!!" << std::endl;
        press_key();
    }
}

void create_account()
{
    system("cls");

    title(); // display the "iCoder" title

    header(std::string{" CREATE ACCOUNT "}); // display the header

    auto acc = std::make_unique<CreateAccount>(); // pointer to CreateAccount class

    try
    {
        acc->input_data(); // taking userID, pass and confirmed password from the user

        if (acc->get_pass() != acc->get_pass2()) // validating same password or not
            throw PasswordNotMatchedException();

        acc->upload_account();

        acc->display_remember_me(); // it will display remember me message

        border(width_menu);      // display the border
        load();                  // animate loading screen
        home(acc->get_userID()); // calling the main menu (HOME) screen to show all program list
    }
    catch (const EscPressed &e)
    {
        return;
    }
    catch (const PasswordNotMatchedException &e)
    {
        std::cerr << e.what();
        if (press_esc())
            return;

        create_account();
    }
    catch (const SavingUserException &e)
    {
        std::cerr << e.what();
        press_key();
    }
    catch (const FileNotOpenedException &e)
    {
        std::cerr << e.what();
        press_key();
    }
    catch (const UsernameAlreadyExistsException &e)
    {
        std::cerr << e.what();

        if (press_esc())
            return;

        create_account();
    }
    catch (...)
    {
        std::cerr << "Unknown error occured!!!" << std::endl;
        press_key();
    }
}

void display_users()
{

    system("cls");

    title(); // display "iCoder"

    header(" USERS ");

    std::ifstream file(fuser);

    if (!file)
    {
        std::cout << "No user in database!";
        return;
    }

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

    border(width_index * 3 + width_username + width_password - 1);

    file.close();
}

std::string pass_to_asteric(const std::string &pass)
{
    std::string ast;
    for (size_t i{0}; i < pass.length(); ++i)
        ast += "*";
    return ast;
}

template <typename T>
void save_to_file(std::ofstream &file, const std::string &title, const T &data, int pos)
{

    file.seekp(pos);

    file << std::setw(width_username) << std::left << title
         << std::setw(width_username) << std::left << data
         << std::endl;
}

int nextLine()
{
    std::ifstream file(fsetting);

    if (!file)
        return 0;

    char c;
    int pos{0};
    while (file >> c)
    {
        if (c == '\n')
            return pos;
        ++pos;
    }
    return pos;
}

template void save_to_file<std::string>(std::ofstream &file, const std::string &title, const std::string &data, int pos);
template void save_to_file<int>(std::ofstream &file, const std::string &title, const int &data, int pos);