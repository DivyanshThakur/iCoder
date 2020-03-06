#ifndef UIHANDLER_HPP
#define UIHANDLER_HPP

#include <string>
#include <vector>

/** FUNCTION PROTOTYPES **/

void load();
void title();
void menu(const std::vector<std::string> &vec_menu, const std::string &heading = " MENU ");
void header(const std::string &menu_name);
void border(int size);
void emessage(const std::string &emessage);
void animater(const std::string &anime);
void igetch();
void print_message(const std::string &message = std::string{"TO BE IMPLEMENTED..."});
void press_key();
void wait_message(const std::string &message);
bool press_esc();
bool confirm_the_change(const std::string &message, const std::string &txtConfirm = "Do you want to proceed?");

#endif