#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include <string>
#include <vector>

/** THIS FILE INCLUDES ALL THE CONSTANTS INVOLVED IN THE WHOLE PROGRAM AND ALL THE HEADER FILES **/

/*** GLOBAL VARIABLES ***/
extern std::string signedUserID; // this will be initialized at runtime
extern int sleep_time;
extern bool showWelcome;
extern bool showedOneTime;
extern const std::string dev_name;
extern const std::string version_info;
extern const std::string scode_url;
extern const std::string icoder_url;
extern const std::string icoder_beta_url;
extern std::string path;
extern std::string fuser;
extern std::string fsetting;

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

// menuhandler.h
extern const std::vector<std::string> main_menu_data;
extern const std::vector<std::string> settings_data;
extern const std::vector<std::string> get_dataType_data;
extern const std::vector<std::string> home_data;
extern const std::vector<std::string> array_data;

// small menu funtions
extern const std::vector<std::string> download_data;
extern const std::vector<std::string> average_data;
extern const std::vector<std::string> sum_data;
extern const std::vector<std::string> set_data;
extern const std::vector<std::string> reverse_data;
extern const std::vector<std::string> shift_rotate_data;
extern const std::vector<std::string> lsearch_data;
extern const std::vector<std::string> find_missing_val_data;
// extern const std::vector<std::string> find_duplicate_val_data;
// extern const std::vector<std::string> find_pair_sum_data;

//accounthandler.h
extern const std::string username;
extern const std::string password;
extern const std::string RePassword;

// enums
enum Side
{
    LEFT,
    RIGHT
};

enum Status
{
    DEFAULT,
    EASY,
    ADV
};

enum ReturnTo
{
    PRE,
    HOME,
    NIL
};

extern enum Status stats;

#endif