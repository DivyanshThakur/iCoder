#ifndef ACCOUNTHANDLER_H
#define ACCOUNTHANDLER_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <conio.h>
#include "UIhandler.h"
#include "ScreenLoader.h"
#include "Home.h"

/*** GLOBAL VARIABLES ***/
extern std::string signedUserID;
extern int sleep_time;

/** FUNCTION PROTOTYPES **/

bool check_signed_user();
bool check_new_user();
void save_active_user(const std::string &userID);
void login();
void create_account();
bool check_account(const std::string &userID, const std::string &pass);
bool input_user_pass(std::string &userID, std::string &pass);
bool input_user_pass(std::string &userID, std::string &pass, std::string &pass2);
bool upload_account(const std::string &userID, const std::string &pass);
bool valid_user(const std::string &userID);
bool display_users();
std::string pass_to_asteric(const std::string &pass);

/** CONSTANTS **/

const extern int width_index;
const extern int width_username;
const extern int width_password;
const extern std::string txtString;
const extern std::string txtPassword;
const extern std::string txtUsername;
const extern std::string txtChar;
const std::string users{"./data/users.dat"};
const std::string active_user{"./data/activeUser.dat"};
const std::string username{"Username: "};
const std::string password{"Password: "};
const std::string RePassword{"Re-enter Password: "};

bool check_new_user()
{
    std::ifstream file(users);
    if (!file)
        return true;

    file.close();
    return false;
}

bool check_signed_user()
{
    std::ifstream file(active_user, std::ios::in);
    if (!file)
        return false;
    file >> signedUserID;
    if (signedUserID == "")
    {
        file.close();
        return false;
    }
    file.close();
    return true;
}

void save_active_user(const std::string &userID)
{
    std::ofstream file(active_user);

    if (!file)
    {
        std::cerr << "Error Saving current user" << std::endl;
        getch();
        exit(1);
    }

    file << userID;
    signedUserID = userID;
    file.close();
    return;
}

void login()
{
    system("cls");

    title(); // display the "iCoder" title

    std::string userID, pass;

    header(std::string{" LOGIN "});

    if (!(input_user_pass(userID, pass))) // taking username and password
        return;

    border(width_menu); // display the border '----'

    if (!check_account(userID, pass))
    {
        std::cout << "UserID/Pass is incorrect";
        press_key();
        login();
    }
    else
    {
        animater(std::string{"Remember me? (Y/N): "});

        // taking character from string
        std::string str = iscan(txtChar);
        if (str == "")
            return;

        char c = std::tolower(str.at(0));
        if (c == 'y')
            save_active_user(userID); // save the current user

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

    std::string userID, pass, pass2;

    if (!(input_user_pass(userID, pass, pass2))) // taking username and password
        return;

    border(width_menu); // display the border

    if (pass != pass2)
    {
        std::cout << "Password not matched";
        press_key();
        create_account();
    }
    else if (!upload_account(userID, pass))
    {
        std::cout << "Username already exists!";
        press_key();
        create_account();
    }
    else
    { // go to home
        animater(std::string{"Remember me? (Y/N): "});

        // taking character from string
        std::string str = iscan(txtChar);
        if (str == "")
            return;

        char c = std::tolower(str.at(0));
        if (c == 'y')
            save_active_user(userID); // save the current user

        border(width_menu); // display the border
        load();             // animate loading screen
        home(userID);       // calling the main menu (HOME) screen to show all program list
    }
}

bool input_user_pass(std::string &userID, std::string &pass)
{
    animater(username);

    userID = iscan(txtUsername); // taking username from user
    if (userID == "")
        return false;
    std::cout << std::endl;

    animater(password);

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

    animater(RePassword);

    pass2 = iscan(txtPassword); // scanning password
    if (pass2 == "")
        return false;

    return true;
}

bool check_account(const std::string &userID, const std::string &pass)
{
    std::ifstream file(users);
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

#endif