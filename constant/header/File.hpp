#ifndef FILE_HPP
#define FILE_HPP

#include <string>

class Constant::File // File Constant
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

class Constant::DataFile
{
public:
    static const std::string TITLE;
    static const std::string NAME;
    static const std::string DATA;
    static const std::string SUB_DATA1;
    static const std::string SUB_DATA2;
    static const std::string SUB_DATA3;
};

class Constant::Tag
{
public:
    // DATA STRUCTURE
    static const std::string MAIN;
    static const std::string ARRAY;
    static const std::string STRING;

    // GAMES
    static const std::string TIC_TAC_TOE;
};

#endif