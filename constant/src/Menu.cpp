#include "../header/Menu.hpp"

/*************************************************** Constant::Menu Constant **************************************************/
const std::vector<std::string> Constant::Menu::MAIN{"Log In", "Create Account", "Try (Anonymous)", "More Features", "Users", "Help", "About", "ChangeLog", "Updates", "Settings"};
const std::vector<std::string> Constant::Menu::MORE{"Games"};
const std::vector<std::string> Constant::Menu::SETTINGS{"Text animation speed", "Linear search type", "Shortcut access", "Themes", "Animation style", "Display style", "welcome messages", "quit confirmation", "hints", "Reset"};
const std::vector<std::string> Constant::Menu::DATA_TYPE{"Int", "Long", "Double", "Char", "String"};
const std::vector<std::string> Constant::Menu::GAMES{"Tic Tac Toe"};
const std::vector<std::string> Constant::Menu::DATA_STRUCTURE{"Array", "Strings (NEW)", "Matrices", "Sparse Matrix", "Polynomial  Representation", "Linked List and more..."};
const std::vector<std::string> Constant::Menu::ARRAY{"Update max size", "Add max size", "Add values", "Insert at a position", "Delete multiple values", "Delete from a position", "Display array", "Linear Search", "Binary Search", "Merge", "SET", "Check is the array sorted", "Reverse the Array", "Shift/Rotation", "Find duplicate values", "Find missing values", "Find a pair with sum K", "Max and Min value", "Get value", "Set value", "Average", "Sum"};
const std::vector<std::string> Constant::Menu::STRING{"Update string", "Add string", "Insert sub-string", "Delete sub-string", "Change case", "Display string", "Reverse", "Compare", "Merge", "Anagram", "Palindrome", "Permutation", "Find unique", "Find duplicates"};

/************************************************ Constant::SubMenu Constant ************************************************/
// info
const std::vector<std::string> Constant::SubMenu::updates{"Stable Version", "Beta Version"};
const std::vector<std::string> Constant::SubMenu::logVersionData{"1.8", "1.6", "1.4", "1.2", "1.0"};
const std::vector<std::string> Constant::SubMenu::logVersionDesc{"Added Strings with advanced operations", "Increased password secuity with encryption", "Ui changes & bug fixes", "Hints-added for new users", "New falling animation added", "More customization in settings", "\n", "Added shortcuts for faster switching", "Added more features to settings", "User can now directly download the updates from GitHub", "\n", "Complete array operations added", "Increased user experience", "\n", "Added code to save changes made by the user for future use", "\n", "Basic array features added"};
const std::vector<std::string> Constant::SubMenu::helpCharData{"Esc", "a", /* "c",*/ "d", "h", /* "i",*/ "l", "m", /* "p",*/ "q", "s", "u"};
const std::vector<std::string> Constant::SubMenu::helpCharDesc{"Return to last screen", "About the software", /* "Show code",*/ "Disable hint/warning", "Help", /* "Analyse the code",*/ "Changelog", "More features", /* "Save",*/ "Quit", "Open settings", "Get Updates"};

// settings
const std::vector<std::string> Constant::SubMenu::lSearchType{"Default", "Transposition", "Move to front"};
const std::vector<std::string> Constant::SubMenu::shortcutsType{"Only key", "Ctrl + key", "Disable"};
const std::vector<std::string> Constant::SubMenu::animeSignOutStyle{"Style 1", "Style 2", "Disable"};

// array
const std::vector<std::string> Constant::SubMenu::average{"Average of all values", "Select a range"}; // array
const std::vector<std::string> Constant::SubMenu::sum{"Sum of all values", "Select a range"};         // array
const std::vector<std::string> Constant::SubMenu::set{"Union", "Intersection", "Difference"};
const std::vector<std::string> Constant::SubMenu::reverse{"Reverse the array", "Select a range"};
const std::vector<std::string> Constant::SubMenu::shiftRotate{"Left Shift", "Right Shift", "Left Rotation", "Right Rotation"};
const std::vector<std::string> Constant::SubMenu::findValue{"Search the array", "Select a range"};

// string
const std::vector<std::string> Constant::SubMenu::updateString{"Add new string", "Extend current string"};
const std::vector<std::string> Constant::SubMenu::changeCaseString{"Toggle case", "To lower", "To upper"};
const std::vector<std::string> Constant::SubMenu::rangeString{"Full string", "Select a range"};

// const std::string array_data_titleView{"  2. Display array\n  3. Home\n  4. Exit\n\nInsertion & Deletion\n  5. Add elements\n  6. Insert at a position\n  7. Delete multiple elements\n  8. Delete from a position\n\nSearch\n  9. Linear Search\n 10. Binary Search"};
