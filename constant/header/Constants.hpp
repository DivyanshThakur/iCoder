#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include <string>
#include <vector>

/************ THIS FILE INCLUDES ALL THE CONSTANTS INVOLVED IN THE WHOLE PROGRAM AND ALL THE HEADER FILES ************/

// used for temporary conditions
extern bool showedOneTime;
extern bool isquitConditionEnabled;

//accounthandler.h
// extern const std::string username;
// extern const std::string password;
// extern const std::string RePassword;
/************************************************** GLOBAL VARIABLES *************************************************/

class Global
{
public:
    static std::string signedUserID;
    static int sleepTime;
    static bool showWelcome;
    static bool showHint;
    static bool showQuit;
};

/************************************************* TEMPORARY CONDITION ***********************************************/

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

/***************************************************** CONSTANTS *****************************************************/

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
    static const std::string ARRAY;
    static const std::string STRING;

    // GAMES
    static const std::string TIK_TAC_TOE;
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

class Constant
{
public:
    static const std::string NULL_STR;

    class Ui;
    class Menu;
    class SubMenu;
};

class Constant::Ui // Ui Constant
{
public:
    static constexpr int ESC = 27;
    static const int CONSOLE_WIDTH;
    static const int CONSOLE_HEIGHT;
    static const int RELATIVE_TITLE_WIDTH;
    static const int MENU_WIDTH;
    static const int TITLE_WIDTH;
    static const int INDEX_WIDTH;
    static const int USERNAME_WIDTH;
    static const int PASSWORD_WIDTH;
};

/******************************************************* ENUMS *******************************************************/
enum Side
{
    LEFT,
    RIGHT
};

enum Status
{
    DEFAULT,
    EASY,
    ADV
};

enum ReturnTo
{
    PRE,
    HOME,
    NIL
};

enum LastScreen
{
    LAST_ARRAY,
    LAST_DS,
    LAST_GAMES,
    LAST_MORE,
    LAST_MENU,
    LAST_SETTINGS,
    LAST_STRING,
    LAST_UPDATES
};

enum OpenedScreen
{
    CUR_ARRAY,
    CUR_DS,
    CUR_GAMES,
    CUR_MORE,
    CUR_MENU,
    CUR_SETTINGS,
    CUR_STRING,
    CUR_UPDATES
};

extern enum LastScreen lstScreen;
extern enum OpenedScreen opnScreen;
extern enum Status lSearchStats, shortcutStats, animeSignOutStats;

#endif