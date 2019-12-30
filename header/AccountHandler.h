#ifndef ACCOUNTHANDLER_H
#define ACCOUNTHANDLER_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <conio.h>
#include "UIhandler.h"
#include "ScreenLoader.h"

/** FUNCTION PROTOTYPES **/

void login();
void create_account();
bool input_user_pass(std::string &userID, std::string &pass);
bool input_user_pass(std::string &userID, std::string &pass, std::string &pass2);
bool upload_account(const std::string &userID, const std::string &pass);
bool valid_user(const std::string &userID);
bool display_users();
std::string pass_to_asteric(const std::string &pass);
void exceed_error(const std::string &input_type, int default_size);

/** CONSTANTS **/
const extern int sleep_time;
const int width_index = 5;
const int width_username = 20;
const int width_password = 10;
const extern std::string txtString;
const extern std::string txtPassword;
const extern std::string txtUsername;
const extern std::string txtChar;
const std::string users{"./data/users.dat"};
const std::string username{"Username: "};
const std::string password{"Password: "};
const std::string RePassword{"Re-enter Password: "};

void login()
{
    system("cls");

    title(); // display the "iCoder" title

    std::string userID, pass;

    header(std::string{" LOGIN "});

    if (!(input_user_pass(userID, pass))) // taking username and password
        return;

    border(width_menu); // display the border '----'

    load(); // animate loading screen

    //home(username);             // calling the main menu (HOME) screen to show all program list
}

void create_account()
{
    system("cls");

    title(); // display the "iCoder" title

    header(std::string{" CREATE ACCOUNT "}); // display the header

    std::string userID, pass, pass2;

    if (!(input_user_pass(userID, pass, pass2))) // taking username and password
        return;

    border(width_menu); // display the border
    bool state = upload_account(userID, pass);

    if (!state || pass != pass2 || userID.size() > width_username || pass.size() > width_password)
    {
        if (!state)
            std::cout << "Username already exists!" << std::endl;

        else if (pass != pass2)
            std::cout << "Password not matched" << std::endl;

        else if (userID.size() > width_username)
            exceed_error(username, width_username);

        else if (pass.size() > width_password)
            exceed_error(password, width_password);

        // after these if else ,these code will be executed
        std::cout << "Press a key to continue";
        getch();
        create_account();
    }
    else
    { // go to home
        load();
        std::cout << "Welcome " << userID << std::endl;
    }
}

bool input_user_pass(std::string &userID, std::string &pass)
{
    for (auto c : username)
    {
        std::cout << c;
        Sleep(sleep_time);
    }

    userID = iscan(txtUsername); // taking username from user
    if (userID == "")
        return false;
    std::cout << std::endl;

    for (auto c : password)
    {
        std::cout << c;
        Sleep(sleep_time);
    }

    pass = iscan(txtPassword); // scanning password
    if (pass == "")
        return false;

    return true;
}

bool input_user_pass(std::string &userID, std::string &pass, std::string &pass2)
{
    if (!(input_user_pass(userID, pass)))
        return false;

    std::cout << std::endl;

    for (auto c : RePassword)
    {
        std::cout << c;
        Sleep(sleep_time);
    }

    pass2 = iscan(txtPassword); // scanning password
    if (pass2 == "")
        return false;

    return true;
}

bool upload_account(const std::string &userID, const std::string &pass)
{

    std::ofstream file{users, std::ios::app};

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

    std::ifstream file(users);

    if (!file)
    {
        std::cerr << "Error validating user details" << std::endl;
        getch();
        exit(1);
    }

    std::string fname;

    while (file >> fname) // if the name matches in file return false
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

    std::ifstream file(users);

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
    for (auto p : pass)
        ast += "*";
    return ast;
}

void exceed_error(const std::string &input_type, int default_size)
{
    std::cout << input_type << " exceeds " << default_size << " characters" << std::endl;
    create_account();
}

#endif