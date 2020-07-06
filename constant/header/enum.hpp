#ifndef ENUM_HPP
#define ENUM_HPP

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