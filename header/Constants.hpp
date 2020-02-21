#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include <string>

/** THIS FILE INCLUDES ALL THE CONSTANTS INVOLVED IN THE WHOLE PROGRAM AND ALL THE HEADER FILES **/

/*** GLOBAL VARIABLES ***/
extern std::string signedUserID; // this will be initialized at runtime
extern int sleep_time;
extern const std::string dev_name;
extern std::string version_info;
extern std::string scode_url;

/** CONSTANTS **/

// uihandler.h
extern const int console_width;
extern const int console_height;
extern const int console_title_relative_width;
extern const int width_menu;
extern const int width_title;
extern const int width_index;
extern const int width_username;
extern const int width_password;
constexpr int ESC = 27;
extern const std::string txtPassword;
extern const std::string txtUsername;
extern const std::string txtChar;
extern const std::string txtString;

// common menu option
extern const std::string menu_create_size;
extern const std::string menu_update_size;

// menuhandler.h
extern const std::string main_menu_data;
extern const std::string home_data;
extern const std::string settings_data;
extern const std::string get_dataType_data;
extern const std::string array_data;

//accounthandler.h
extern const std::string fuser;
extern const std::string fsetting;
extern const std::string username;
extern const std::string password;
extern const std::string RePassword;

#endif