#include <string>
#include "../header/Constants.hpp"

/** THIS FILE INCLUDES ALL THE CONSTANTS INVOLVED IN THE WHOLE PROGRAM AND ALL THE HEADER FILES **/

/*** GLOBAL VARIABLES ***/
std::string signedUserID; // this will be initialized at runtime
int sleep_time;
int emessage_timer = 25;

/** CONSTANTS **/

// uihandler.h
const int width_menu = 30;
const int width_title = 30;
const int width_index = 5;
const int width_username = 20;
const int width_password = 10;
const std::string txtPassword{"Password"};
const std::string txtUsername{"Username"};
const std::string txtChar{"Char"};
const std::string txtString{"String"};

// menuhandler.h
const std::string main_menu_data{"1. Log In\n2. Create Account\n3. Try (Anonymous)\n4. Users\n5. About\n6. Settings\n7. Exit"};
const std::string home_data{"1. Array\n2. Strings ~ TO BE IMPLEMENTED\n3. Matrices\n4. Sparse Matrix\n5. Polynomial  Representation\n6. Linked List\n7. Main Menu (Sign Out)\n8. Exit"};
const std::string settings_data{"1. Change menu speed\n2. Change warning speed\n3. Main Menu\n4. Exit"};

//accounthandler.h
const std::string fuser{"./data/users.dat"};
const std::string fsetting{"./data/settings.dat"};
const std::string username{"Username: "};
const std::string password{"Password: "};
const std::string RePassword{"Re-enter Password: "};
