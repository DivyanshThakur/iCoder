#ifndef ICODER_H
#define ICODER_H

#include <iostream>
#include <string>

/** THIS FILE INCLUDES ALL THE CONSTANTS INVOLVED IN THE WHOLE PROGRAM AND ALL THE HEADER FILES **/

/** CONSTANTS **/

// uihandler.h
const int width_menu = 25;
const int width_title = 30;
const int width_index = 5;
const extern int width_username = 20;
const extern int width_password = 10;
const char ESC = 27;
const std::string txtPassword{"Password"};
const std::string txtUsername{"Username"};
const std::string txtChar{"Char"};
const std::string txtString{"String"};

// menuhandler.h
const std::string menu1_data{"1. Log In\n2. Create Account\n3. Try (Anonymous)\n4. Users\n5. About\n6. Settings\n7. Exit"};
const std::string menu2_data{"1. Array\n2. Recursion\n3. Linked List\n4. Main Menu (Sign Out)\n5. Exit"};

//accounthandler.h
const std::string fuser{"./data/users.dat"};
const std::string fsetting{"./data/settings.dat"};
const std::string username{"Username: "};
const std::string password{"Password: "};
const std::string RePassword{"Re-enter Password: "};

#include "AccountHandler.h"
#include "UIhandler.h"
#include "Menuhandler.h"
#include "Settings.h"

#endif ICODER_H