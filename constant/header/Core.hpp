#ifndef CORE_HPP
#define CORE_HPP

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

class Constant::Global
{
public:
    static std::string signedUserID;
    static int sleepTime;
    static bool showWelcome;
    static bool showHint;
    static bool showQuit;
};

/************************************************* TEMPORARY CONDITION ***********************************************/

class Constant::iCoder
{
public:
    static const std::string devName;
    static const std::string versionInfo;
};

/***************************************************** REMOTE URL ****************************************************/

class Constant::Url
{
public:
    static const std::string source;
    static const std::string iStable;
    static const std::string iBeta;
};

/****************************************************** DATA PATH *****************************************************/

class Constant::Path
{
public:
    static std::string dataPath;
    static std::string userFilePath;
    static std::string fUser;
    static std::string fSetting;
};

#endif