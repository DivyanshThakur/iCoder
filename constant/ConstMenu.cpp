#include "Constants.hpp"

// const std::string Constant::NULL_STR{"NULL"};

/*************************************************** Constant::Menu Constant **************************************************/
const std::vector<std::string> Constant::Menu::ARRAY{"Update max size", "Add max size", "Add values", "Insert at a position", "Delete multiple values", "Delete from a position", "Display array", "Linear Search", "Binary Search", "Merge", "SET", "Check is the array sorted", "Reverse the Array", "Shift/Rotation", "Find duplicate values", "Find missing values", "Find a pair with sum K", "Max and Min value", "Get value", "Set value", "Average", "Sum"};
// const std::vector<std::string> Constant::Menu::CHANGELOG{"2.0", "1.8", "1.6", "1.4", "1.2", "1.0"};
const std::vector<std::string> Constant::Menu::DATA_STRUCTURE{"Array", "Strings (NEW)", "Matrices", "Sparse Matrix", "Polynomial  Representation", "Linked List and more..."};
const std::vector<std::string> Constant::Menu::DATA_TYPE{"Int", "Long", "Double", "Char", "String"};
// const std::vector<std::string> Constant::Menu::GAMES{"Tic Tac Toe"};
const std::vector<std::string> Constant::Menu::MAIN{"DS", "CP", "Help", "About", "Updates", "Settings"};
// const std::vector<std::string> Constant::Menu::MORE{"Games"};
const std::vector<std::string> Constant::Menu::SETTINGS{"Hints", "Reset"};
const std::vector<std::string> Constant::Menu::STRING{"Update string", "Add string", "Insert sub-string", "Delete sub-string", "Change case", "Display string", "Reverse", "Compare", "Merge", "Anagram", "Palindrome", "Permutation", "Find unique", "Find duplicates"};
const std::vector<std::string> Constant::Menu::UPDATES{"Stable", "Beta"};

/************************************************ Constant::SubMenu Constant ************************************************/
const std::vector<std::string> Constant::SubMenu::Settings::HINTS{"Enable", "Disable"};
// info
const std::vector<std::string> Constant::SubMenu::HELP_DATA{"Esc", "a", /* "c",*/ "d", "h", /* "i",*/ "l", "m", /* "p",*/ "q", "s", "u"};
const std::vector<std::string> Constant::SubMenu::HELP_DESC{"Return to last screen", "About the software", /* "Show code",*/ "Disable hint/warning", "Help", /* "Analyse the code",*/ "Changelog", "More features", /* "Save",*/ "Quit", "Open settings", "Get Updates"};

// settings
// const std::vector<std::string> Constant::SubMenu::LSEARCH_TYPE{"Default", "Transposition", "Move to front"};
// const std::vector<std::string> Constant::SubMenu::ANIME_SO_STYLE{"Style 1", "Style 2", "Disable"};

// array
const std::vector<std::string> Constant::SubMenu::AVERAGE{"Average of all values", "Select a range"};
const std::vector<std::string> Constant::SubMenu::SUM{"Sum of all values", "Select a range"};
const std::vector<std::string> Constant::SubMenu::SET{"Union", "Intersection", "Difference"};
const std::vector<std::string> Constant::SubMenu::REVERSE{"Reverse the array", "Select a range"};
const std::vector<std::string> Constant::SubMenu::SHIFT_ROTATE{"Left Shift", "Right Shift", "Left Rotation", "Right Rotation"};
const std::vector<std::string> Constant::SubMenu::FIND_VALUE{"Search the array", "Select a range"};

// string
const std::vector<std::string> Constant::SubMenu::UPDATE_STRING{"Add new string", "Extend current string"};
const std::vector<std::string> Constant::SubMenu::CHANGE_CASE_STRING{"Toggle case", "To lower", "To upper"};
const std::vector<std::string> Constant::SubMenu::RANGE_STRING{"Full string", "Select a range"};

/*************************************** TITLE *****************************************/
const std::string Constant::Title::ABOUT{"ABOUT"};
const std::string Constant::Title::ARRAY{"ARRAY"};
// const std::string Constant::Title::CHANGE_LINEAR_SEARCH_TYPE{"CHANGE LINEAR SEARCH TYPE"};
// const std::string Constant::Title::CHANGELOG{"CHANGELOG"};
// const std::string Constant::Title::CREATE_ACCOUNT{"CREATE ACCOUNT"};
const std::string Constant::Title::DATA_STRUCTURE{"DATA STRUCTURE"};
// const std::string Constant::Title::GAMES{"GAMES"};
const std::string Constant::Title::HELP{"HELP"};
const std::string Constant::Title::HINT{"HINT"};
const std::string Constant::Title::LINKS{"LINKS"};
// const std::string Constant::Title::LOGIN{"LOGIN"};
const std::string Constant::Title::MAIN{"MAIN"};
const std::string Constant::Title::CP{"CP"};
const std::string Constant::Title::SETTINGS{"SETTINGS"};
const std::string Constant::Title::STATS{"STATS"};
const std::string Constant::Title::STRING{"STRING"};
// const std::string Constant::Title::TIC_TAC_TOE{"TIC TAC TOE"};
const std::string Constant::Title::TIP{"TIP"};
// const std::string Constant::Title::UPCOMING{"UPCOMING"};
const std::string Constant::Title::UPDATES{"UPDATES"};
// const std::string Constant::Title::USERS{"USERS"};

/*************************************************** Constant::Ui Constant *****************************************************/
const int Constant::Ui::CONSOLE_HEIGHT = 600;
const int Constant::Ui::CONSOLE_WIDTH = 850;
const int Constant::Ui::INDEX_WIDTH = 5;
const int Constant::Ui::MENU_WIDTH = 32;
const int Constant::Ui::PASSWORD_WIDTH = 10;
const int Constant::Ui::RELATIVE_TITLE_WIDTH = (113 - Constant::Ui::TITLE_WIDTH) / 2;
const int Constant::Ui::TITLE_WIDTH = 30;
const int Constant::Ui::USERNAME_WIDTH = 20;
