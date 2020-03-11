#include "../header/Constants.hpp"

/** THIS FILE INCLUDES ALL THE CONSTANTS INVOLVED IN THE WHOLE PROGRAM AND ALL THE HEADER FILES **/

/*** GLOBAL VARIABLES ***/
std::string signedUserID; // this will be initialized at runtime
int sleep_time;
const std::string dev_name{"Divyansh Singh Thakur"};
const std::string version_info{"1.4"};
const std::string scode_url{"https://github.com/DivyanshThakur/iCoder"};
const std::string icoder_url{"https://github.com/DivyanshThakur/iCoder/raw/master/iCoder.exe"};
const std::string icoder_beta_url{"https://github.com/DivyanshThakur/iCoder/raw/Development/iCoder.exe"};
std::string path;
std::string fuser;
std::string fsetting;
// int pos_anime_speed;

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
const std::vector<std::string> main_menu_data{"Log In", "Create Account", "Try (Anonymous)", "Users", "About", "Settings", "Exit"};
const std::vector<std::string> settings_data{"Change text animation speed", "Change linear search type"};
const std::vector<std::string> get_dataType_data{"Int", "Long", "Double", "Char", "String"};
const std::vector<std::string> home_data{"Array (NEW)", "Strings", "Matrices", "Sparse Matrix", "Polynomial  Representation", "Linked List and more...", "Main Menu (Sign Out)"};
const std::vector<std::string> array_data{"Update max size", "Add max size", "Add elements", "Insert at a position", "Delete multiple elements", "Delete from a position", "Display array", "Advanced Operations", "Linear Search", "Binary Search", "Merge", "SET", "Check is the array sorted", "Reverse the Array", "Shift/Rotation", "Find duplicate values", "Find missing values", "Find a pair with sum K", "Max and Min value", "Get value", "Set value", "Average", "Sum"};

// small menu funtions
const std::vector<std::string> average_data{"Average of all elements", "Select a range"};
const std::vector<std::string> sum_data{"Sum of all elements", "Select a range"};
const std::vector<std::string> set_data{"Union", "Intersection", "Difference"};
const std::vector<std::string> reverse_data{"Reverse the array", "Select a range"};
const std::vector<std::string> shift_rotate_data{"Left Shift", "Right Shift", "Left Rotation", "Right Rotation"};
const std::vector<std::string> lsearch_data{"Default", "Transposition", "Move to front"};
const std::vector<std::string> find_missing_val_data{"Search the array", "Select a range"};
const std::vector<std::string> find_duplicate_val_dataL{"d"};
const std::vector<std::string> find_pair_sum_data{"d"};

// const std::string array_data_titleView{"  2. Display array\n  3. Home\n  4. Exit\n\nInsertion & Deletion\n  5. Add elements\n  6. Insert at a position\n  7. Delete multiple elements\n  8. Delete from a position\n\nSearch\n  9. Linear Search\n 10. Binary Search"};

//accounthandler.h
const std::string username{"Username: "};
const std::string password{"Password: "};
const std::string RePassword{"Re-enter Password: "};

// enums
Status stats;