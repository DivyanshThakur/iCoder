#ifndef ACCOUNTHANDLER_HPP
#define ACCOUNTHANDLER_HPP

#include <string>

/** FUNCTION PROTOTYPES **/

void login();
void display_users();
bool check_new_user();
void create_account();
bool check_active_user();
void save_active_user(const std::string &userID);
std::string pass_to_asteric(const std::string &pass);

#endif