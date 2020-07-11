#include "../Constants.hpp"

const std::string Constant::NULL_STR{"NULL"};

/*************************************************** Constant::Menu Constant **************************************************/
const std::vector<std::string> Constant::Menu::ARRAY{"Update max size", "Add max size", "Add values", "Insert at a position", "Delete multiple values", "Delete from a position", "Display array", "Linear Search", "Binary Search", "Merge", "SET", "Check is the array sorted", "Reverse the Array", "Shift/Rotation", "Find duplicate values", "Find missing values", "Find a pair with sum K", "Max and Min value", "Get value", "Set value", "Average", "Sum"};
const std::vector<std::string> Constant::Menu::DATA_STRUCTURE{"Array", "Strings (NEW)", "Matrices", "Sparse Matrix", "Polynomial  Representation", "Linked List and more..."};
const std::vector<std::string> Constant::Menu::DATA_TYPE{"Int", "Long", "Double", "Char", "String"};
const std::vector<std::string> Constant::Menu::GAMES{"Tic Tac Toe"};
const std::vector<std::string> Constant::Menu::MAIN{"Log In", "Create Account", "Try (Anonymous)", "More Features", "Users", "Help", "About", "ChangeLog", "Updates", "Settings"};
const std::vector<std::string> Constant::Menu::MORE{"Games"};
const std::vector<std::string> Constant::Menu::SETTINGS{"Text animation speed", "Linear search type", "Shortcut access", "Themes", "Animation style", "Display style", "welcome messages", "quit confirmation", "hints", "Reset"};
const std::vector<std::string> Constant::Menu::STRING{"Update string", "Add string", "Insert sub-string", "Delete sub-string", "Change case", "Display string", "Reverse", "Compare", "Merge", "Anagram", "Palindrome", "Permutation", "Find unique", "Find duplicates"};

/************************************************ Constant::SubMenu Constant ************************************************/
// info
const std::vector<std::string> Constant::SubMenu::UPDATES{"Stable Version", "Beta Version"};
const std::vector<std::string> Constant::SubMenu::VERSION_DATA{"1.8", "1.6", "1.4", "1.2", "1.0"};
const std::vector<std::string> Constant::SubMenu::VERSION_DESC{"Added Strings with advanced operations", "Increased password secuity with encryption", "Ui changes & bug fixes", "Hints-added for new users", "New falling animation added", "More customization in settings", "\n", "Added shortcuts for faster switching", "Added more features to settings", "User can now directly download the updates from GitHub", "\n", "Complete array operations added", "Increased user experience", "\n", "Added code to save changes made by the user for future use", "\n", "Basic array features added"};
const std::vector<std::string> Constant::SubMenu::HELP_DATA{"Esc", "a", /* "c",*/ "d", "h", /* "i",*/ "l", "m", /* "p",*/ "q", "s", "u"};
const std::vector<std::string> Constant::SubMenu::HELP_DESC{"Return to last screen", "About the software", /* "Show code",*/ "Disable hint/warning", "Help", /* "Analyse the code",*/ "Changelog", "More features", /* "Save",*/ "Quit", "Open settings", "Get Updates"};

// settings
const std::vector<std::string> Constant::SubMenu::LSEARCH_TYPE{"Default", "Transposition", "Move to front"};
const std::vector<std::string> Constant::SubMenu::ANIME_SO_STYLE{"Style 1", "Style 2", "Disable"};

// array
const std::vector<std::string> Constant::SubMenu::AVERAGE{"Average of all values", "Select a range"}; // array
const std::vector<std::string> Constant::SubMenu::SUM{"Sum of all values", "Select a range"};         // array
const std::vector<std::string> Constant::SubMenu::SET{"Union", "Intersection", "Difference"};
const std::vector<std::string> Constant::SubMenu::REVERSE{"Reverse the array", "Select a range"};
const std::vector<std::string> Constant::SubMenu::SHIFT_ROTATE{"Left Shift", "Right Shift", "Left Rotation", "Right Rotation"};
const std::vector<std::string> Constant::SubMenu::FIND_VALUE{"Search the array", "Select a range"};

// string
const std::vector<std::string> Constant::SubMenu::UPDATE_STRING{"Add new string", "Extend current string"};
const std::vector<std::string> Constant::SubMenu::CHANGE_CASE_STRING{"Toggle case", "To lower", "To upper"};
const std::vector<std::string> Constant::SubMenu::RANGE_STRING{"Full string", "Select a range"};

/*************************************** TITLE *****************************************/

// DATA STRUCTURE
const std::string Constant::Title::ARRAY{"ARRAY"};
const std::string Constant::Title::TIP{"TIP"};
const std::string Constant::Title::TIP{"STATS"};
const std::string Constant::Title::LOGIN{"LOGIN"};

const std::string Constant::Title::USERS{"USERS"};

const std::string Constant::Title::CHANGE_LINEAR_SEARCH_TYPE{"CHANGE LINEAR SEARCH TYPE"};
const std::string Constant::Title::CREATE_ACCOUNT{"CREATE ACCOUNT"};
const std::string Constant::Title::DATA_STRUCTURE{"DATA STRUCTURE"};

const std::string Constant::Title::MAIN{"MAIN"};
const std::string Constant::Title::GAMES{"GAMES"};
const std::string Constant::Title::MORE{"MORE"};
const std::string Constant::Title::STRING{"STRING"};
const std::string Constant::Title::SETTINGS{"SETTINGS"};
const std::string Constant::Title::UPDATES{"UPDATES"};
const std::string Constant::Title::HINT{"HINT"};

// GAMES
const std::string Constant::Title::TIC_TAC_TOE{"TIC_TAC_TOE"};

/*************************************************** Constant::Ui Constant *****************************************************/
const int Constant::Ui::CONSOLE_HEIGHT = 600;
const int Constant::Ui::CONSOLE_WIDTH = 850;
const int Constant::Ui::INDEX_WIDTH = 5;
const int Constant::Ui::MENU_WIDTH = 32;
const int Constant::Ui::PASSWORD_WIDTH = 10;
const int Constant::Ui::RELATIVE_TITLE_WIDTH = (113 - Constant::Ui::TITLE_WIDTH) / 2;
const int Constant::Ui::TITLE_WIDTH = 30;
const int Constant::Ui::USERNAME_WIDTH = 20;
