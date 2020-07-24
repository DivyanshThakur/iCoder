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

extern enum Status lSearchStats, shortcutStats, animeSignOutStats;

#endif