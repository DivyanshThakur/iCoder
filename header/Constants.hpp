#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include <string>
#include <vector>

/** THIS FILE INCLUDES ALL THE CONSTANTS INVOLVED IN THE WHOLE PROGRAM AND ALL THE HEADER FILES **/

/*** GLOBAL VARIABLES ***/
extern std::string signedUserID; // this will be initialized at runtime
extern int sleepTime;
extern bool showWelcome;
extern bool showHint;
extern bool showQuit;
// extern bool isShortcutEnabled;
extern bool showedOneTime;
extern bool isConditionEnabled;
extern const std::string devName;
extern const std::string versionInfo;
extern const std::string sCodeUrl;
extern const std::string iCoderUrl;
extern const std::string iCoderBetaUrl;
extern std::string path;
extern std::string fUser;
extern std::string fSetting;

/** CONSTANTS **/

// uihandler.h
extern const int consoleWidth;
extern const int consoleHeight;
extern const int relativeTitleWidth;
extern const int widthMenu;
extern const int widthTitle;
extern const int widthIndex;
extern const int widthUsername;
extern const int widthPassword;
constexpr int ESC = 27;
extern const std::string txtPassword;
extern const std::string txtUsername;
extern const std::string txtChar;
extern const std::string txtString;

// menuhandler.h
extern const std::vector<std::string> mainMenu;
extern const std::vector<std::string> settingsMenu;
extern const std::vector<std::string> getDataTypeMenu;
extern const std::vector<std::string> homeMenu;
extern const std::vector<std::string> arrayMenu;

// small menu funtions
extern const std::vector<std::string> updatesMenu;
extern const std::vector<std::string> averageMenu;
extern const std::vector<std::string> sumMenu;
extern const std::vector<std::string> setMenu;
extern const std::vector<std::string> reverseMenu;
extern const std::vector<std::string> shiftRotateMenu;
extern const std::vector<std::string> lSearchTypeMenu;
extern const std::vector<std::string> findValueMenu;
extern const std::vector<std::string> logVersionData;
extern const std::vector<std::string> logVersionDesc;
extern const std::vector<std::string> helpCharData;
extern const std::vector<std::string> helpCharDesc;

//accounthandler.h
extern const std::string username;
extern const std::string password;
extern const std::string RePassword;

// enums
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

extern enum Status stats;

#endif