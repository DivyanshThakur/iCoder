#ifndef ACCOUNTHANDLER_HPP
#define ACCOUNTHANDLER_HPP

#include <string>

/** FUNCTION PROTOTYPES **/

void restore_saved_changes();
void update_stats(int c);
void login();
void display_users();
bool check_new_user();
void create_account();
void save_active_user(const std::string &userID);
std::string pass_to_asteric(const std::string &pass);

template <typename T>
void save_to_file(const std::string &file_name, const std::string &title, const T &data);

template <typename T>
void print_to_file(std::ofstream &out_file, const std::string &title, const T &data);

#endif