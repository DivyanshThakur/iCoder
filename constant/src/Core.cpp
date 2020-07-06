#include "../Constants.hpp"
#include "../header/Core.hpp"

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
std::string Constant::Global::signedUserID;
int Constant::Global::sleepTime;
bool Constant::Global::showWelcome;
bool Constant::Global::showHint;
bool Constant::Global::showQuit;

/*************************************************** ICODER CLASS ****************************************************/

const std::string Constant::iCoder::devName{"Divyansh Singh Thakur"};
const std::string Constant::iCoder::versionInfo{"1.9.20.5.20-beta"};

/***************************************************** REMOTE URL ****************************************************/

const std::string Constant::Url::source{"https://github.com/DivyanshThakur/iCoder"};
const std::string Constant::Url::iStable{"https://github.com/DivyanshThakur/iCoder/raw/master/iCoder.exe"};
const std::string Constant::Url::iBeta{"https://github.com/DivyanshThakur/iCoder/raw/Development/iCoder.exe"};

/****************************************************** DATA PATH *****************************************************/

std::string Constant::Path::dataPath;
std::string Constant::Path::userFilePath;
std::string Constant::Path::fUser;
std::string Constant::Path::fSetting;