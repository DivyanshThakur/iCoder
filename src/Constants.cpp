#include "../namespace/header/cod_array.hpp" // Constatns.hpp is included in it

/**********************************************************************************************************************
 * 
 *             THIS FILE INCLUDES ALL THE CONSTANTS INVOLVED IN THE WHOLE PROGRAM AND ALL THE HEADER FILES
 * 
 * *******************************************************************************************************************/

// used for temporary conditions
bool showedOneTime{true};
bool isquitConditionEnabled{false};

//accounthandler.h
const std::string username{"Username: "};
const std::string password{"Password: "};
const std::string RePassword{"Re-enter Password: "};

/*************************************************** GLOBAL CLASS ****************************************************/
std::string Global::signedUserID;
int Global::sleepTime;
bool Global::showWelcome;
bool Global::showHint;
bool Global::showQuit;

/*************************************************** ICODER CLASS ****************************************************/

const std::string iCoder::devName{"Divyansh Singh Thakur"};
const std::string iCoder::versionInfo{"1.9.20.5.20-beta"};

/***************************************************** REMOTE URL ****************************************************/

const std::string Url::source{"https://github.com/DivyanshThakur/iCoder"};
const std::string Url::iStable{"https://github.com/DivyanshThakur/iCoder/raw/master/iCoder.exe"};
const std::string Url::iBeta{"https://github.com/DivyanshThakur/iCoder/raw/Development/iCoder.exe"};

/****************************************************** DATA PATH *****************************************************/

std::string Path::dataPath;
std::string Path::userFilePath;
std::string Path::fUser;
std::string Path::fSetting;

/**********************************************************************************************************************
 * 
 *                                                      CONSTANTS
 * 
 * *******************************************************************************************************************/

/************************************************* Data File Constant ************************************************/
const std::string DataFile::TITLE{"__TITLE__"};
const std::string DataFile::NAME{"__NAME__"};
const std::string DataFile::DATA{"__DATA__"};
const std::string DataFile::SUB_DATA1{"__SUB_DATA1__"};
const std::string DataFile::SUB_DATA2{"__SUB_DATA2__"};
const std::string DataFile::SUB_DATA3{"__SUB_DATA3__"};

/************************************************ FILE TAG Constant **************************************************/

// DATA STRUCTURE
const std::string Tag::ARRAY{"ARRAY"};
const std::string Tag::STRING{"STRING"};

// GAMES
const std::string Tag::TIK_TAC_TOE{"TIC_TAC_TOE"};

/*************************************************** File Constant ***************************************************/
const std::string File::CURRENT_USER{"CURRENT_USER"};
const std::string File::ANIMATION_SPEED{"ANIMATION_SPEED"};
const std::string File::LSEARCH_STATUS{"LSEARCH_STATUS"};
const std::string File::SHORTCUT_STATUS{"SHORTCUT_STATUS"};
const std::string File::ANIME_SIGN_OUT_STATUS{"ANIME_SIGN_OUT_STATUS"};
const std::string File::SHOW_WELCOME_MESSAGE{"SHOW_WELCOME_MESSAGE"};
const std::string File::SHOW_QUIT_MESSAGE{"SHOW_QUIT_MESSAGE"};
const std::string File::SHOW_HINT{"SHOW_HINT"};
const std::string File::SHOW_ONE_TIME_HINT{"SHOW_ONE_TIME_HINT"};

/*************************************************** Ui Constant *****************************************************/
const int Ui::consoleWidth = 850;
const int Ui::consoleHeight = 600;
const int Ui::relativeTitleWidth = (113 - widthTitle) / 2;
const int Ui::widthMenu = 32;
const int Ui::widthTitle = 30;
const int Ui::widthIndex = 5;
const int Ui::widthUsername = 20;
const int Ui::widthPassword = 10;
const std::string Ui::txtPassword{"Password"};
const std::string Ui::txtUsername{"Username"};
const std::string Ui::txtChar{"Char"};
const std::string Ui::txtString{"String"};

/*************************************************** Constant::Menu Constant **************************************************/
const std::vector<std::string> Constant::Menu::main{"Log In", "Create Account", "Try (Anonymous)", "More Features", "Users", "Help", "About", "ChangeLog", "Updates", "Settings"};
const std::vector<std::string> Constant::Menu::more{"Games"};
const std::vector<std::string> Constant::Menu::settings{"Text animation speed", "Linear search type", "Shortcut access", "Themes", "Animation style", "Display style", "welcome messages", "quit confirmation", "hints", "Reset"};
const std::vector<std::string> Constant::Menu::dataType{"Int", "Long", "Double", "Char", "String"};
const std::vector<std::string> Constant::Menu::games{"Tic Tac Toe"};
const std::vector<std::string> Constant::Menu::dataStructure{"Array", "Strings (NEW)", "Matrices", "Sparse Matrix", "Polynomial  Representation", "Linked List and more..."};
const std::vector<std::string> Constant::Menu::array{"Update max size", "Add max size", "Add values", "Insert at a position", "Delete multiple values", "Delete from a position", "Display array", "Linear Search", "Binary Search", "Merge", "SET", "Check is the array sorted", "Reverse the Array", "Shift/Rotation", "Find duplicate values", "Find missing values", "Find a pair with sum K", "Max and Min value", "Get value", "Set value", "Average", "Sum"};
const std::vector<std::string> Constant::Menu::string{"Update string", "Add string", "Insert sub-string", "Delete sub-string", "Change case", "Display string", "Reverse", "Compare", "Merge", "Anagram", "Palindrome", "Permutation", "Find unique", "Find duplicates"};

/************************************************ Small Constant::Menu Constant ************************************************/
// info
const std::vector<std::string> SmallMenu::updates{"Stable Version", "Beta Version"};
const std::vector<std::string> SmallMenu::logVersionData{"1.8", "1.6", "1.4", "1.2", "1.0"};
const std::vector<std::string> SmallMenu::logVersionDesc{"Added Strings with advanced operations", "Increased password secuity with encryption", "Ui changes & bug fixes", "Hints-added for new users", "New falling animation added", "More customization in settings", "\n", "Added shortcuts for faster switching", "Added more features to settings", "User can now directly download the updates from GitHub", "\n", "Complete array operations added", "Increased user experience", "\n", "Added code to save changes made by the user for future use", "\n", "Basic array features added"};
const std::vector<std::string> SmallMenu::helpCharData{"Esc", "a", /* "c",*/ "d", "h", /* "i",*/ "l", "m", /* "p",*/ "q", "s", "u"};
const std::vector<std::string> SmallMenu::helpCharDesc{"Return to last screen", "About the software", /* "Show code",*/ "Disable hint/warning", "Help", /* "Analyse the code",*/ "Changelog", "More features", /* "Save",*/ "Quit", "Open settings", "Get Updates"};

// settings
const std::vector<std::string> SmallMenu::lSearchType{"Default", "Transposition", "Move to front"};
const std::vector<std::string> SmallMenu::shortcutsType{"Only key", "Ctrl + key", "Disable"};
const std::vector<std::string> SmallMenu::animeSignOutStyle{"Style 1", "Style 2", "Disable"};

// array
const std::vector<std::string> SmallMenu::average{"Average of all values", "Select a range"}; // array
const std::vector<std::string> SmallMenu::sum{"Sum of all values", "Select a range"};         // array
const std::vector<std::string> SmallMenu::set{"Union", "Intersection", "Difference"};
const std::vector<std::string> SmallMenu::reverse{"Reverse the array", "Select a range"};
const std::vector<std::string> SmallMenu::shiftRotate{"Left Shift", "Right Shift", "Left Rotation", "Right Rotation"};
const std::vector<std::string> SmallMenu::findValue{"Search the array", "Select a range"};

// string
const std::vector<std::string> SmallMenu::updateString{"Add new string", "Extend current string"};
const std::vector<std::string> SmallMenu::changeCaseString{"Toggle case", "To lower", "To upper"};
const std::vector<std::string> SmallMenu::rangeString{"Full string", "Select a range"};

// const std::string array_data_titleView{"  2. Display array\n  3. Home\n  4. Exit\n\nInsertion & Deletion\n  5. Add elements\n  6. Insert at a position\n  7. Delete multiple elements\n  8. Delete from a position\n\nSearch\n  9. Linear Search\n 10. Binary Search"};

/******************************************************* ENUMS ********************************************************/
LastScreen lstScreen;
OpenedScreen opnScreen;
Status lSearchStats, shortcutStats, animeSignOutStats;