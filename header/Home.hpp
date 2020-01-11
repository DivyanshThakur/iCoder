#ifndef HOME_HPP
#define HOME_HPP

#include <iostream>
#include <string>
#include "iCoder.hpp"

/** FUNCTION PROTOTYPES **/
void home(const std::string &userID);
void home_controller(char ch);
void extern save_active_user(const std::string &userID); // defined in AccountHandler.h

#endif