#include "../header/Constants.hpp"

/** THIS FILE INCLUDES ALL THE CONSTANTS INVOLVED IN THE WHOLE PROGRAM AND ALL THE HEADER FILES **/

/*** GLOBAL VARIABLES ***/
std::string signedUserID; // this will be initialized at runtime
int sleep_time;
bool showWelcome;
bool showedOneTime{true};
const std::string dev_name{"Divyansh Singh Thakur"};
const std::string version_info{"1.7.20.3.19-beta"};
const std::string scode_url{"https://github.com/DivyanshThakur/iCoder"};
const std::string icoder_url{"https://github.com/DivyanshThakur/iCoder/raw/master/iCoder.exe"};
const std::string icoder_beta_url{"https://github.com/DivyanshThakur/iCoder/raw/Development/iCoder.exe"};
std::string path;
std::string fuser;
std::string fsetting;

/** CONSTANTS **/

// uihandler.h
const int console_width = 850;
const int console_height = 600;
const int console_title_relative_width = (113 - width_title) / 2;
const int width_menu = 32;
const int width_title = 30;
const int width_index = 5;
const int width_username = 20;
const int width_password = 10;
const std::string txtPassword{"Password"};
const std::string txtUsername{"Username"};
const std::string txtChar{"Char"};
const std::string txtString{"String"};

// menuhandler.h
const std::vector<std::string> main_menu_data{"Log In", "Create Account", "Try (Anonymous)", "Users", "Help", "About", "ChangeLog", "Updates", "Settings"};
const std::vector<std::string> settings_data{"Text animation speed", "Linear search type", "Enable welcome messages", "Disable welcome messages", "Reset"};
const std::vector<std::string> get_dataType_data{"Int", "Long", "Double", "Char", "String"};
const std::vector<std::string> home_data{"Array (NEW)", "Strings", "Matrices", "Sparse Matrix", "Polynomial  Representation", "Linked List and more...", "Main Menu (Sign Out)"};
const std::vector<std::string> array_data{"Update max size", "Add max size", "Add elements", "Insert at a position", "Delete multiple elements", "Delete from a position", "Display array", "Advanced Operations", "Linear Search", "Binary Search", "Merge", "SET", "Check is the array sorted", "Reverse the Array", "Shift/Rotation", "Find duplicate values", "Find missing values", "Find a pair with sum K", "Max and Min value", "Get value", "Set value", "Average", "Sum"};

// small menu funtions
const std::vector<std::string> download_data{"Stable Version", "Beta Version"};
const std::vector<std::string> average_data{"Average of all elements", "Select a range"};
const std::vector<std::string> sum_data{"Sum of all elements", "Select a range"};
const std::vector<std::string> set_data{"Union", "Intersection", "Difference"};
const std::vector<std::string> reverse_data{"Reverse the array", "Select a range"};
const std::vector<std::string> shift_rotate_data{"Left Shift", "Right Shift", "Left Rotation", "Right Rotation"};
const std::vector<std::string> lsearch_data{"Default", "Transposition", "Move to front"};
const std::vector<std::string> find_val_data{"Search the array", "Select a range"};
const std::vector<std::string> log_version_data{"1.6", "1.4", "1.2", "1.0"};
const std::vector<std::string> log_vdescription_data{"Added shortcuts for faster switching", "Added more features to settings", "User can now directly download the updates from GitHub", "\n", "Complete array operations added", "Increased user experience", "\n", "Added code to save changes made by the user for future use", "\n", "Basic array features added"};
const std::vector<std::string> help_char_data{"Esc", "a", /* "c",*/ "h", /* "i",*/ "l", "q", "s", "u"};
const std::vector<std::string> help_desc_data{"Return to last screen", "About the software", /* "Show code",*/ "Help", /* "Analyse the code",*/ "Changelog", "Quit", "Open settings", "Get Updates"};

// const std::string array_data_titleView{"  2. Display array\n  3. Home\n  4. Exit\n\nInsertion & Deletion\n  5. Add elements\n  6. Insert at a position\n  7. Delete multiple elements\n  8. Delete from a position\n\nSearch\n  9. Linear Search\n 10. Binary Search"};

//accounthandler.h
const std::string username{"Username: "};
const std::string password{"Password: "};
const std::string RePassword{"Re-enter Password: "};

// enums
Status stats;