#ifndef ANIME_HANDLER_HPP
#define ANIME_HANDLER_HPP

#include <list>

void signout_anime_switcher();

class SignOutAnime1
{
    static void print();

public:
    static void start();
};

class SignOutAnime2
{
    static std::list<std::string> listMenu;
    static void print();

public:
    static void start();
};

#endif