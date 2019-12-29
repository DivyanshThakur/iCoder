#ifndef ACCOUNTHANDLER_H
#define ACCOUNTHANDLER_H

#include <iostream>
#include <iomanip>
#include <string>
#include <conio.h>
#include "UIhandler.h"
#include "ScreenLoader.h"

/** FUNCTION PROTOTYPES **/

void login();
void create_account();
bool input_user_pass(std::string &userID, std::string &pass);

/** CONSTANTS **/
const extern int sleep_time;
const extern std::string txtString;
const extern std::string txtPassword;
const extern std::string txtChar;
const std::string username{"Username: "};
const std::string password{"Password: "};

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

    //mainMenu(username);             // calling the main menu screen to show all program list
}

void create_account()
{
    system("cls");

    title(); // display the "iCoder" title

    header(std::string{" CREATE ACCOUNT "});

    std::string userID, pass;

    if (!(input_user_pass(userID, pass))) // taking username and password
        return;

    footer(); // display footer

    load();
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

#endif