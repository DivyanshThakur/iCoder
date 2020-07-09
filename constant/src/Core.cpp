#include "../Constants.hpp"
#include "../header/Core.hpp"

/**********************************************************************************************************************
 * 
 *             THIS FILE INCLUDES ALL THE CONSTANTS INVOLVED IN THE WHOLE PROGRAM AND ALL THE HEADER FILES
 * 
 * *******************************************************************************************************************/

// used for temporary conditions
bool isquitConditionEnabled{false};

//accounthandler.h
// const std::string username{"Username: "};
// const std::string password{"Password: "};
// const std::string RePassword{"Re-enter Password: "};

/*************************************************** GLOBAL CLASS ****************************************************/
std::string Global::activeUser;
bool Global::showWelcome;
bool Global::showHint;
bool Global::showQuit;

/*************************************************** ICODER CLASS ****************************************************/

const std::string Constant::iCoder::DEV{"Divyansh Singh Thakur"};
const std::string Constant::iCoder::VERSION{"1.9.20.5.20-beta"};

/***************************************************** REMOTE URL ****************************************************/

const std::string Constant::Url::SRC{"https://github.com/DivyanshThakur/iCoder"};
const std::string Constant::Url::STABLE{"https://github.com/DivyanshThakur/iCoder/raw/master/iCoder.exe"};
const std::string Constant::Url::BETA{"https://github.com/DivyanshThakur/iCoder/raw/Development/iCoder.exe"};

/****************************************************** DATA PATH *****************************************************/

std::string Constant::Path::PATH;
std::string Constant::Path::USER;
std::string Constant::Path::DB;
std::string Constant::Path::SETTINGS;