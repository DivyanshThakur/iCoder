#ifndef UIHANDLER_HPP
#define UIHANDLER_HPP

#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>
#include <string>
#include <conio.h>

/** FUNCTION PROTOTYPES **/

void load();
void title();
bool menu(std::string menu_str, bool flag);
std::string iscan(const std::string &stype, bool isMultiple = false);
void header(const std::string &menu_name);
void border(int size);
void emessage(const std::string &emessage);
void animater(const std::string &anime, int speed = sleep_time);
void igetch();
void press_key();

#endif