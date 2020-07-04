#include "../header/Constants.hpp"

/**********************************************************************************************************************
 * 
 *             THIS FILE INCLUDES ALL THE CONSTANTS INVOLVED IN THE WHOLE PROGRAM AND ALL THE HEADER FILES
 * 
 * *******************************************************************************************************************/

// used for temporary conditions
bool showedOneTime{true};
bool isquitConditionEnabled{false};

//accounthandler.h
// const std::string username{"Username: "};
// const std::string password{"Password: "};
// const std::string RePassword{"Re-enter Password: "};

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

const std::string Constant::NULL_STR{"NULL"};

/*************************************************** Constant::Ui Constant *****************************************************/
const int Constant::Ui::consoleWidth = 850;
const int Constant::Ui::consoleHeight = 600;
const int Constant::Ui::relativeTitleWidth = (113 - widthTitle) / 2;
const int Constant::Ui::widthMenu = 32;
const int Constant::Ui::widthTitle = 30;
const int Constant::Ui::widthIndex = 5;
const int Constant::Ui::widthUsername = 20;
const int Constant::Ui::widthPassword = 10;

/******************************************************* ENUMS ********************************************************/
LastScreen lstScreen;
OpenedScreen opnScreen;
Status lSearchStats, shortcutStats, animeSignOutStats;