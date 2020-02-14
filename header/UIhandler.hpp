#ifndef UIHANDLER_HPP
#define UIHANDLER_HPP

#include <string>

/** FUNCTION PROTOTYPES **/

void mod(int &x);
void load();
void title();
void menu(std::string menu_str, const std::string heading = " MENU ");
void header(const std::string &menu_name);
void border(int size, bool isNeedLine = true);
void emessage(const std::string &emessage);
void animater(const std::string &anime);
void igetch();
void print_message(const std::string &message = std::string{"TO BE IMPLEMENTED..."});
void press_key();

#endif