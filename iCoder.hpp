#ifndef ICODER_HPP
#define ICODER_HPP

#include <vector>

/************************************************ FUNCTION PROTOTYPES **************************************************/
std::vector<std::string> menu_screen_selector(std::vector<int> &menuIndex);
void fn_caller(int ch, const std::vector<int> &menuIndex);
void main_menu_controller(int ch);
void home(const std::string &userID);
bool isDirectoryExists();
void adjust_console_size();
void create_path();
void sign_out();

#endif