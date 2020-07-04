#ifndef SIGN_OUT_ANIME_HPP
#define SIGN_OUT_ANIME_HPP

class SignOutAnime1
{
    static int speed;
    static size_t startPos;

    static void print();

public:
    static void start();
};

class SignOutAnime2
{
    static int speed;
    static size_t startPos, count, animeIndex;

    static void print();

public:
    static void start();
};

#endif