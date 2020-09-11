#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include <vector>
#include <string>

class Global
{
public:
    // static std::string activeUser;
    static std::vector<std::string> openedScreen;
    static bool showHint;
    // static bool showQuit;
};
class Constant
{
public:
    // static const std::string NULL_STR;
    // static const int sleepTime = 25;
    static constexpr int ESC = 27;

    class iCoder
    {
    public:
        static const std::string DEV;
        static const std::string VERSION;
    };

    /***************************************************** REMOTE URL ****************************************************/

    class Url
    {
    public:
        static const std::string SRC;
        static const std::string STABLE;
        static const std::string BETA;
    };

    /****************************************************** DATA PATH *****************************************************/

    class Path
    {
    public:
        static std::string PATH;
        static std::string USER;
        static std::string DB;
        static std::string SETTINGS;
    };

    class Menu
    {
    public:
        static const std::vector<std::string> ARRAY;
        // static const std::vector<std::string> CHANGELOG;
        static const std::vector<std::string> DATA_STRUCTURE;
        static const std::vector<std::string> DATA_TYPE;
        // static const std::vector<std::string> GAMES;
        static const std::vector<std::string> MAIN;
        // static const std::vector<std::string> MORE;
        static const std::vector<std::string> SETTINGS;
        static const std::vector<std::string> STRING;
        static const std::vector<std::string> UPDATES;
    };
    class SubMenu // Menu Constant
    {
    public:
        class Settings
        {
        public:
            static const std::vector<std::string> HINTS;
        };

        // help
        static const std::vector<std::string> HELP_DATA;
        static const std::vector<std::string> HELP_DESC;

        // settings
        // static const std::vector<std::string> LSEARCH_TYPE;
        // static const std::vector<std::string> ANIME_SO_STYLE;

        // array
        static const std::vector<std::string> AVERAGE;
        static const std::vector<std::string> SUM;
        static const std::vector<std::string> SET;
        static const std::vector<std::string> REVERSE;
        static const std::vector<std::string> SHIFT_ROTATE;
        static const std::vector<std::string> FIND_VALUE;

        // string
        static const std::vector<std::string> UPDATE_STRING;
        static const std::vector<std::string> CHANGE_CASE_STRING;
        static const std::vector<std::string> RANGE_STRING;
    };

    class Title
    {
    public:
        static const std::string ABOUT;
        static const std::string ARRAY;
        // static const std::string CHANGE_LINEAR_SEARCH_TYPE;
        // static const std::string CHANGELOG;
        // static const std::string CREATE_ACCOUNT;
        static const std::string DATA_STRUCTURE;
        // static const std::string GAMES;
        static const std::string HELP;
        static const std::string HINT;
        static const std::string LINKS;
        // static const std::string LOGIN;
        static const std::string MAIN;
        static const std::string CP;
        static const std::string SETTINGS;
        static const std::string STATS;
        static const std::string STRING;
        // static const std::string TIC_TAC_TOE;
        static const std::string TIP;
        // static const std::string UPCOMING;
        static const std::string UPDATES;
        // static const std::string USERS;
    };

    class Ui // Ui Constant
    {
    public:
        static const int CONSOLE_HEIGHT;
        static const int CONSOLE_WIDTH;
        static const int INDEX_WIDTH;
        static const int MENU_WIDTH;
        static const int PASSWORD_WIDTH;
        static const int RELATIVE_TITLE_WIDTH;
        static const int TITLE_WIDTH;
        static const int USERNAME_WIDTH;
    };

    class File // File Constant
    {
    public:
        // static const std::string ACTIVE_USER;
        // static const std::string LSEARCH_STATUS;
        // static const std::string ANIME_SIGN_OUT_STATUS;
        // static const std::string SHOW_QUIT;
        static const std::string SHOW_HINT;
    };

    class DataFile
    {
    public:
        static const std::string TITLE;
        static const std::string NAME;
        static const std::string DATA;
        static const std::string SUB_DATA1;
        static const std::string SUB_DATA2;
        static const std::string SUB_DATA3;
    };
};

#endif