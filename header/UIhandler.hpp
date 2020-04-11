#ifndef UIHANDLER_HPP
#define UIHANDLER_HPP

#include <string>
#include <vector>
#include "Constants.hpp"

/** FUNCTION PROTOTYPES **/

void load();
void title();
void menu(const std::vector<std::string> &vecMenu, const std::string &heading = " MENU ", bool showStatus = false, const std::string &statsVal = "Default", const std::string &statsStr = "Current Status: ");
void show_status(const std::string &statsStr, const std::string &statsVal);
std::string stats_selector(const enum Status &stats, const std::vector<std::string> &statsData);
void update_screen(const std::string &heading);
void header(const std::string &menuTitle, bool showTitle = true);
void show_hint();
void border(int size);
void emessage(const std::string &emessage);
void animater(const std::string &anime);
void igetch();
void print_message(const std::string &message = std::string{"TO BE IMPLEMENTED..."});
void press_key(const ReturnTo &rt = PRE, const std::string &message = "Press any key to continue");
bool press_i(const std::string &message);
void wait_message(const std::string &message);
bool confirm_the_change(const std::string &message, const std::string &txtConfirm = "Do you want to proceed?");

#endif