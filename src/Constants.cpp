#include <iostream>
#include <string>
#include "../header/Constants.hpp"

/** THIS FILE INCLUDES ALL THE CONSTANTS INVOLVED IN THE WHOLE PROGRAM AND ALL THE HEADER FILES **/

/*** GLOBAL VARIABLES ***/
std::string signedUserID; // this will be initialized at runtime
int sleep_time;
const std::string dev_name{"Divyansh Singh Thakur"};
std::string version_info{"1.2-BETA"};
std::string scode_url{"https://github.com/DivyanshThakur/iCoder"};
int pos_anime_speed;

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

// common menu option
const std::string menu_create_size{" 1. Add max size\n"};
const std::string menu_update_size{" 1. Update max size\n"};

// menuhandler.h
const std::string main_menu_data{" 1. Log In\n 2. Create Account\n 3. Try (Anonymous)\n 4. Users\n 5. About\n 6. Settings\n 7. Exit"};
const std::string settings_data{" 1. Change text animation speed\n 2. Main Menu\n 3. Exit"};
const std::string get_dataType_data{" 1. Int\n 2. Long\n 3. Double\n 4. Char\n 5. String\n 6. Home"};

// THEME - LIST VIEW
const std::string home_data{" 1. Array (New)\n 2. Strings\n 3. Matrices\n 4. Sparse Matrix\n 5. Polynomial  Representation\n 6. Linked List and more...\n 7. Main Menu (Sign Out)\n 8. Exit"};
const std::string array_data_listView{" 2. Add elements\n 3. Insert at a position\n 4. Delete multiple elements\n 5. Delete from a position\n 6. Display array\n 7. Linear Search\n 8. Binary Search\n 9. Average\n10. Sum\n11. Max and Min value\n12. Merge\n13. Shift/Rotation\n14. Reverse the Array\n15. SET Operations\n16. Find missing elements\n17. Finding Duplicates\n18. Find a pair with sum K\n19. Home\n20. Exit"};

// THEME - TITLE VIEW
const std::string array_data_titleView{"  2. Display array\n  3. Home\n  4. Exit\n\nInsertion & Deletion\n  5. Add elements\n  6. Insert at a position\n  7. Delete multiple elements\n  8. Delete from a position\n\nSearch\n  9. Linear Search\n 10. Binary Search"};

// THEME - GRID VIEW

//accounthandler.h
const std::string fuser{"./data/users.dat"};
const std::string fsetting{"./data/settings.dat"};
const std::string username{"Username: "};
const std::string password{"Password: "};
const std::string RePassword{"Re-enter Password: "};