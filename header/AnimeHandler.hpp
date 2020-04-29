#ifndef ANIME_HANDLER_HPP
#define ANIME_HANDLER_HPP

void signout_anime_switcher();
void speed_updater(int &speed);

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