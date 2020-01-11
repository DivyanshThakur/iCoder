#ifndef ACCOUNTHANDLER_HPP
#define ACCOUNTHANDLER_HPP

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <conio.h>
#include "iCoder.hpp"

/** FUNCTION PROTOTYPES **/

void login();
bool display_users();
bool check_new_user();
void create_account();
bool check_signed_user();
bool valid_user(const std::string &userID);
void save_active_user(const std::string &userID);
bool display_remember_me(const std::string &userID);
std::string pass_to_asteric(const std::string &pass);
bool input_user_pass(std::string &userID, std::string &pass);
bool check_account(const std::string &userID, const std::string &pass);
bool upload_account(const std::string &userID, const std::string &pass);
bool input_user_pass(std::string &userID, std::string &pass, std::string &pass2);

#endif