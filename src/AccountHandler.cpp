#include <iostream>
#include <fstream>
#include <sstream>
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
    {
        signedUserID = std::string{"NULL"};
        sleep_time = 25;
        showWelcome = true;
        stats = DEFAULT;

        std::ofstream out_file(fsetting);

        print_to_file(out_file, std::string{"CURRENT_USER"}, signedUserID);
        print_to_file(out_file, std::string{"ANIMATION_SPEED"}, sleep_time);
        print_to_file(out_file, std::string{"LSEARCH_STATUS"}, stats);
        print_to_file(out_file, std::string{"SHOW_WELCOME_MESSAGE"}, showWelcome);

        out_file.close();

        return;
    }

    std::string title;
    int c;

    while (file >> title)
    {
        if (title == std::string{"CURRENT_USER"})
            file >> signedUserID;
        else if (title == std::string{"ANIMATION_SPEED"})
            file >> sleep_time;
        else if (title == std::string{"LSEARCH_STATUS"})
        {
            file >> c;
            update_stats(c);
        }
        else if (title == std::string{"SHOW_WELCOME_MESSAGE"})
            file >> showWelcome;
    }

    file.close();
}

void update_stats(int c)
{
    switch (c)
    {
    case 0:
        stats = DEFAULT;
        break;

    case 1:
        stats = EASY;
        break;

    case 2:
        stats = ADV;
        break;
    }
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
    signedUserID = userID;

    save_to_file(fsetting, std::string{"CURRENT_USER"}, signedUserID);
}

void login()
{
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

        press_key(PRE, "Press ESC to return");

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

        press_key(PRE, "Press ESC to return");

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

        press_key(PRE, "Press ESC to return");

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
void save_to_file(const std::string &file_name, const std::string &title, const T &data)
{
    std::ifstream in_file(file_name);

    std::string file_str, file_title, line, val;

    if (!in_file)
    {
        std::cerr << "Error saving user details!" << std::endl;
        return;
    }

    while (std::getline(in_file, line))
    {
        file_str += line;
    }

    in_file.close();
    std::ofstream out_file(file_name);
    std::stringstream ss{file_str};
    bool isSaved{false};

    while (ss >> file_title)
    {
        ss >> val;

        if (file_title == title)
        {
            print_to_file(out_file, title, data);
            isSaved = true;
        }
        else
            print_to_file(out_file, file_title, val);
    }

    if (!isSaved)
        print_to_file(out_file, title, data);
}

template <typename T>
void print_to_file(std::ofstream &out_file, const std::string &title, const T &data)
{
    out_file << std::setw(width_username * 2) << std::left << title
             << std::setw(width_username) << std::left << data << std::endl;
}

template void save_to_file<std::string>(const std::string &file_name, const std::string &title, const std::string &data);
template void save_to_file<int>(const std::string &file_name, const std::string &title, const int &data);
template void save_to_file<bool>(const std::string &file_name, const std::string &title, const bool &data);
template void save_to_file<Status>(const std::string &file_name, const std::string &title, const Status &data);