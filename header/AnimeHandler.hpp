#ifndef ANIME_HANDLER_HPP
#define ANIME_HANDLER_HPP

void signout_anime_switcher();

class SignOutAnime1
{
    static size_t startPos;

    static void print();

public:
    static void start();
};

class SignOutAnime2
{
    static size_t startPos, count, animeIndex;

    static void print();

public:
    static void start();
};

#endif