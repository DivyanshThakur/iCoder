#ifndef MENU_HPP
#define MENU_HPP

#include <vector>
#include <string>

class Constant::Menu
{
public:
    static const std::vector<std::string> ARRAY;
    static const std::vector<std::string> DATA_STRUCTURE;
    static const std::vector<std::string> DATA_TYPE;
    static const std::vector<std::string> GAMES;
    static const std::vector<std::string> MAIN;
    static const std::vector<std::string> MORE;
    static const std::vector<std::string> SETTINGS;
    static const std::vector<std::string> STRING;
};
class Constant::SubMenu // Menu Constant
{
public:
    // info
    static const std::vector<std::string> UPDATES;
    static const std::vector<std::string> logVersionData;
    static const std::vector<std::string> logVersionDesc;
    static const std::vector<std::string> helpCharData;
    static const std::vector<std::string> helpCharDesc;

    // settings
    static const std::vector<std::string> lSearchType;
    static const std::vector<std::string> shortcutsType;
    static const std::vector<std::string> animeSignOutStyle;

    // array
    static const std::vector<std::string> average;
    static const std::vector<std::string> sum;
    static const std::vector<std::string> set;
    static const std::vector<std::string> reverse;
    static const std::vector<std::string> shiftRotate;
    static const std::vector<std::string> findValue;

    // string
    static const std::vector<std::string> updateString;
    static const std::vector<std::string> changeCaseString;
    static const std::vector<std::string> rangeString;
};

class Constant::Ui // Ui Constant
{
public:
    static constexpr int ESC = 27;
    static const int CONSOLE_HEIGHT;
    static const int CONSOLE_WIDTH;
    static const int INDEX_WIDTH;
    static const int MENU_WIDTH;
    static const int PASSWORD_WIDTH;
    static const int RELATIVE_TITLE_WIDTH;
    static const int TITLE_WIDTH;
    static const int USERNAME_WIDTH;
};

#endif