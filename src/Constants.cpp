#include "../header/Constants.hpp"
#include "../namespace/header/cod_array.hpp"

/** THIS FILE INCLUDES ALL THE CONSTANTS INVOLVED IN THE WHOLE PROGRAM AND ALL THE HEADER FILES **/

/************************************************** GLOBAL VARIABLES **************************************************/
// saved for future use
std::string signedUserID; // this will be initialized at runtime
int sleepTime;
bool showWelcome;
bool showHint;
bool showQuit;
bool wsAllowed;

// used for temporary conditions
bool showedOneTime{true};
bool isquitConditionEnabled{false};

// software details
const std::string devName{"Divyansh Singh Thakur"};
const std::string versionInfo{"1.7.20.4.10-beta"};

// remote url
const std::string sCodeUrl{"https://github.com/DivyanshThakur/iCoder"};
const std::string iCoderUrl{"https://github.com/DivyanshThakur/iCoder/raw/master/iCoder.exe"};
const std::string iCoderBetaUrl{"https://github.com/DivyanshThakur/iCoder/raw/Development/iCoder.exe"};

// software database path
std::string path;
std::string fUser;
std::string fSetting;

/***************************************************** CONSTANTS *****************************************************/

// file constant
const std::string CURRENT_USER = std::string{"CURRENT_USER"};
const std::string ANIMATION_SPEED = std::string{"ANIMATION_SPEED"};
const std::string LSEARCH_STATUS = std::string{"LSEARCH_STATUS"};
const std::string SHORTCUT_STATUS = std::string{"SHORTCUT_STATUS"};
const std::string WS_ALLOWED = std::string{"WS_ALLOWED"};
const std::string SHOW_WELCOME_MESSAGE = std::string{"SHOW_WELCOME_MESSAGE"};
const std::string SHOW_QUIT_MESSAGE = std::string{"SHOW_QUIT_MESSAGE"};
const std::string SHOW_HINT = std::string{"SHOW_HINT"};

// uihandler.h
const int consoleWidth = 850;
const int consoleHeight = 600;
const int relativeTitleWidth = (113 - widthTitle) / 2;
const int widthMenu = 32;
const int widthTitle = 30;
const int widthIndex = 5;
const int widthUsername = 20;
const int widthPassword = 10;
const std::string txtPassword{"Password"};
const std::string txtUsername{"Username"};
const std::string txtChar{"Char"};
const std::string txtString{"String"};

// menuhandler.h
const std::vector<std::string> mainMenu{"Log In", "Create Account", "Try (Anonymous)", "Users", "Help", "About", "ChangeLog", "Updates", "Settings"};
const std::vector<std::string> settingsMenu{"Text animation speed", "Linear search type", "Shortcut access", "Themes", "Display style", "Allow whitespace", "welcome messages", "quit confirmation", "hints", "Reset"};
const std::vector<std::string> getDataTypeMenu{"Int", "Long", "Double", "Char", "String"};
const std::vector<std::string> homeMenu{"Array (NEW)", "Strings", "Matrices", "Sparse Matrix", "Polynomial  Representation", "Linked List and more...", "Main Menu (Sign Out)"};
const std::vector<std::string> arrayMenu{"Update max size", "Add max size", "Add values", "Insert at a position", "Delete multiple values", "Delete from a position", "Display array", "Advanced Operations", "Linear Search", "Binary Search", "Merge", "SET", "Check is the array sorted", "Reverse the Array", "Shift/Rotation", "Find duplicate values", "Find missing values", "Find a pair with sum K", "Max and Min value", "Get value", "Set value", "Average", "Sum"};

// small menu funtions
const std::vector<std::string> updatesMenu{"Stable Version", "Beta Version"};
const std::vector<std::string> averageMenu{"Average of all elements", "Select a range"};
const std::vector<std::string> sumMenu{"Sum of all elements", "Select a range"};
const std::vector<std::string> setMenu{"Union", "Intersection", "Difference"};
const std::vector<std::string> reverseMenu{"Reverse the array", "Select a range"};
const std::vector<std::string> shiftRotateMenu{"Left Shift", "Right Shift", "Left Rotation", "Right Rotation"};
const std::vector<std::string> lSearchTypeMenu{"Default", "Transposition", "Move to front"};
const std::vector<std::string> shortcutsTypeMenu{"Only key", "Ctrl + key", "Disable"};
const std::vector<std::string> findValueMenu{"Search the array", "Select a range"};
const std::vector<std::string> logVersionData{"1.6", "1.4", "1.2", "1.0"};
const std::vector<std::string> logVersionDesc{"Added shortcuts for faster switching", "Added more features to settings", "User can now directly download the updates from GitHub", "\n", "Complete array operations added", "Increased user experience", "\n", "Added code to save changes made by the user for future use", "\n", "Basic array features added"};
const std::vector<std::string> helpCharData{"Esc", "a", /* "c",*/ "d", "h", /* "i",*/ "l", /* "p",*/ "q", "s", "u"};
const std::vector<std::string> helpCharDesc{"Return to last screen", "About the software", /* "Show code",*/ "Disable hint/warning", "Help", /* "Analyse the code",*/ "Changelog", /* "Save",*/ "Quit", "Open settings", "Get Updates"};

// const std::string array_data_titleView{"  2. Display array\n  3. Home\n  4. Exit\n\nInsertion & Deletion\n  5. Add elements\n  6. Insert at a position\n  7. Delete multiple elements\n  8. Delete from a position\n\nSearch\n  9. Linear Search\n 10. Binary Search"};

//accounthandler.h
const std::string username{"Username: "};
const std::string password{"Password: "};
const std::string RePassword{"Re-enter Password: "};

/******************************************************* ENUMS *******************************************************/
LastScreen lstScreen;
OpenedScreen opnScreen;
Status lSearchStats, shortcutStats;