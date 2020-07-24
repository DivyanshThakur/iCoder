#include "../Constants.hpp"

/*************************************************** GLOBAL CLASS ****************************************************/
std::string Global::activeUser;
std::vector<std::string> Global::openedScreen;
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