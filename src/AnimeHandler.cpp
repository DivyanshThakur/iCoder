#include <iostream>
#include <iomanip>
#include <windows.h>
#include "../header/AnimeHandler.hpp"
#include "../header/UIhandler.hpp"

void signout_anime_switcher()
{
    SignOutAnime2::start();
}

/***********************************************************************************************************************
 * 
 *                                                SIGN OUT ANIMATION - 1
 * 
 * *********************************************************************************************************************/

size_t SignOutAnime1::startPos{0}; // Declaring the static startPos variable

// start function assigns the value 2 to variable startPos and repeatFor
// The logic behind this is -
// In first iteration , it prints the menu from index 2
// Each time the startPos is decremented by 1 to include the previous option each iteration
// At last the animation stops and the last menu option (index 0) is printed normally using default menu function

void SignOutAnime1::start()
{
    int repeatFor = startPos = 2;

    while (repeatFor--)
    {
        print();
        Sleep(100);

        startPos--; // Starting position is decreased to include the previous option also
    }

    Sleep(100);
}

// The print menu static function print the menu normally
// Only at startPos = 2, the signOut option is printed for proper animation

void SignOutAnime1::print()
{
    title();

    if (Global::showHint) // display hint in every screen
        show_hint();

    header(std::string{" MENU "}, false);

    size_t index;

    // Here, the index is started from startPos, i.e. 2 and from 1 at next iteration
    for (index = startPos; index < Menu::main.size(); ++index)
    {
        // Print the index starting 1 till menu size
        std::cout << std::setw(2) << std::right << index - startPos + 1 << ". " << Menu::main.at(index);

        if (index < Menu::main.size() - 1) // New line is not printed at last menu option
            std::cout << std::endl;
    }

    if (startPos == 2) // At first iteration the sign out option is printed and gets overlapped at second iteration
    {
        std::cout << std::endl
                  << std::setw(2) << std::right << index - startPos + 1 << ". Sign Out";
    }

    print_message(std::string{"Your Choice: "}); // ask user for input
}

/***********************************************************************************************************************
 * 
 *                                                SIGN OUT ANIMATION - 2
 * 
 * *********************************************************************************************************************/

size_t SignOutAnime2::startPos{0}; // static variable declarations
size_t SignOutAnime2::count{0};
size_t SignOutAnime2::animeIndex{0};

void SignOutAnime2::start()
{
    startPos = 2;
    count = 1;
    animeIndex = Menu::main.size() - 1;

    for (size_t i{1}; i < Menu::main.size(); i++, count = 1, animeIndex--)
    {
        if (Menu::main.size() - i < 2)
        {
            startPos--;
            count--;
        }

        do
        {
            print();
            Sleep(25);
        } while (count++ < startPos);
    }
}

void SignOutAnime2::print()
{
    title();

    if (Global::showHint) // display hint in every screen
        show_hint();

    header(std::string{" MENU "}, false);

    for (size_t index{startPos}, num = 1; index < Menu::main.size(); index++, num++)
    {
        if (index == animeIndex && count)
        {
            size_t temp = count;

            while (temp--)
                std::cout << std::setw(2) << std::right << num++ << ". " << std::endl;
        }

        std::cout << std::setw(2) << std::right << num << ". " << Menu::main.at(index);

        if (index < Menu::main.size() - 1) // New line is not printed at last menu option
            std::cout << std::endl;

        if (index == animeIndex && animeIndex != Menu::main.size() - 1)
        {
            size_t temp = startPos - count;

            while (temp--)
                std::cout << std::setw(2) << std::right << ++num << ". " << std::endl;
        }
    }
    print_message(std::string{"Your Choice: "}); // ask user for input
}