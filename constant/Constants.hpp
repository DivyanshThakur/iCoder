#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include <vector>
#include <string>

class Constant
{
public:
    static const std::string NULL_STR;

    class Global
    {
    public:
        static std::string signedUserID;
        static int sleepTime;
        static bool showWelcome;
        static bool showHint;
        static bool showQuit;
    };

    class iCoder
    {
    public:
        static const std::string devName;
        static const std::string versionInfo;
    };

    /***************************************************** REMOTE URL ****************************************************/

    class Url
    {
    public:
        static const std::string source;
        static const std::string iStable;
        static const std::string iBeta;
    };

    /****************************************************** DATA PATH *****************************************************/

    class Path
    {
    public:
        static std::string dataPath;
        static std::string userFilePath;
        static std::string fUser;
        static std::string fSetting;
    };

    class Menu
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
    class SubMenu // Menu Constant
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

    class Ui // Ui Constant
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

    class File // File Constant
    {
    public:
        static const std::string CURRENT_USER;
        static const std::string ANIMATION_SPEED;
        static const std::string LSEARCH_STATUS;
        static const std::string SHORTCUT_STATUS;
        static const std::string ANIME_SIGN_OUT_STATUS;
        static const std::string SHOW_WELCOME_MESSAGE;
        static const std::string SHOW_QUIT_MESSAGE;
        static const std::string SHOW_HINT;
        static const std::string SHOW_ONE_TIME_HINT;
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

    class Tag
    {
    public:
        // DATA STRUCTURE
        static const std::string MAIN;
        static const std::string ARRAY;
        static const std::string STRING;

        // GAMES
        static const std::string TIC_TAC_TOE;
    };
};

#endif