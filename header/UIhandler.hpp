#ifndef UIHANDLER_HPP
#define UIHANDLER_HPP

#include <string>
#include <vector>
#include "../header/Constants.hpp"

/** FUNCTION PROTOTYPES **/

void load();
void title();
void menu(const std::vector<std::string> &vec_menu, const std::string &heading = " MENU ", bool showStatus = false, const std::string &statsVal = "Default", const std::string &statsStr = "Status: ");
void show_status(const std::string &statsVal, const std::string &statsStr = "Status: ");
std::string stats_selector();
void header(const std::string &menu_name);
void border(int size);
void emessage(const std::string &emessage);
void animater(const std::string &anime);
void igetch();
void print_message(const std::string &message = std::string{"TO BE IMPLEMENTED..."});
void press_key(const ReturnTo &rt = PRE, const std::string &message = "Press any key to continue");
void wait_message(const std::string &message);
bool confirm_the_change(const std::string &message, const std::string &txtConfirm = "Do you want to proceed?");

#endif