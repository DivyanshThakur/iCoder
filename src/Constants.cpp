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
const std::string menu_create_size{"1. Add max size\n"};
const std::string menu_update_size{"1. Update max size\n"};

// menuhandler.h
const std::string main_menu_data{"1. Log In\n2. Create Account\n3. Try (Anonymous)\n4. Users\n5. About\n6. Settings\n7. Exit"};
const std::string home_data{"1. Array (New)\n2. Strings\n3. Matrices\n4. Sparse Matrix\n5. Polynomial  Representation\n6. Linked List and more...\n7. Main Menu (Sign Out)\n8. Exit"};
const std::string settings_data{"1. Change text animation speed\n2. Main Menu\n3. Exit"};
const std::string get_dataType_data{"1. Int\n2. Long\n3. Double\n4. Char\n5. String\n6. Home"};
const std::string array_data{"2. Add elements\n3. Insert at a position\n4. Delete multiple elements\n5. Delete from a position\n6. Display array\n7. Home\n8. Exit"};

//accounthandler.h
const std::string fuser{"./data/users.dat"};
const std::string fsetting{"./data/settings.dat"};
const std::string username{"Username: "};
const std::string password{"Password: "};
const std::string RePassword{"Re-enter Password: "};