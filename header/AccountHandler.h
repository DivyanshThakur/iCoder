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

/** CONSTANTS **/
const extern int sleep_time;
const extern std::string txtString;
const extern std::string txtPassword;
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

    footer(); // display the footer '----'

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

    if (pass != pass2)
    {
        footer(); // display the footer
        std::cout << "Password not matched" << std::endl
                  << "Press a key to continue";
        getch();
        create_account();
    }
    else
    {
        footer(); // display footer

        if (!upload_account(userID, pass))
        {
            std::cout << "Username already exists!" << std::endl;
        }
        else
        { // go to home
            load();
            std::cout << "Welcome " << userID << std::endl;
        }
    }
}

bool input_user_pass(std::string &userID, std::string &pass)
{
    for (auto c : username)
    {
        std::cout << c;
        Sleep(sleep_time);
    }

    userID = iscan(txtString); // taking username from user
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
    if (pass == "")
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

    file << std::setw(width_title) << std::left << userID << std::setw(width_title) << std::left << pass << std::endl;

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

#endif