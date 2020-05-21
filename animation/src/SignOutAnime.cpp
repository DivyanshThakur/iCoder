#include <iostream>
#include <iomanip>
#include <windows.h>
#include "../header/SignOutAnime.hpp"
#include "../header/AnimeHandler.hpp"
#include "../../header/UIhandler.hpp"

/***********************************************************************************************************************
 * 
 *                                                SIGN OUT ANIMATION - 1
 * 
 * *********************************************************************************************************************/

int SignOutAnime1::speed{0}; // Declaring the static variables
size_t SignOutAnime1::startPos{0};

/**
* start function assigns the value 2 to variable startPos and repeatFor
* The logic behind this is -
* In first iteration , it prints the menu from index 2
* Each time the startPos is decremented by 1 to include the previous option each iteration
* At last the animation stops and the last menu option (index 0) is printed normally using default menu function
**/

void SignOutAnime1::start()
{
    int repeatFor = startPos = 2;
    speed = 100;

    while (repeatFor--)
    {
        print();
        Sleep(speed);

        startPos--; // Starting position is decreased to include the previous option also
    }

    Sleep(speed);
}

// The print menu static function print the menu normally
// Only at startPos = 2, the signOut option is printed for proper animation

void SignOutAnime1::print()
{
    logo();

    if (Global::showHint) // display hint in every screen
        show_hint();

    header(std::string{" MENU "}, false);

    size_t index;

    // Here, the index is started from startPos, i.e. 2 and from 1 at next iteration
    for (index = startPos; index < Constant::Menu::main.size(); ++index)
    {
        // Print the index starting 1 till menu size
        std::cout << std::setw(2) << std::right << index - startPos + 1 << ". " << Constant::Menu::main.at(index);

        if (index < Constant::Menu::main.size() - 1) // New line is not printed at last menu option
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

int SignOutAnime2::speed{0}; // Declaring the static variables
size_t SignOutAnime2::startPos{0};
size_t SignOutAnime2::count{0};
size_t SignOutAnime2::animeIndex{0};

/**
* The speed is firstly updated based on power status
* Then, animation is started with position 2 till size
* The loop is executed n-2 times to print all menu except the top option
* which will be automatically added in normal menu printer
* Each time pos is started with 2
* animeIndex represents the index of the menu options which is to be animated
* count represents the no of gaps to be printed for that index
* If main.size() -i <2, i.e. For second last index the startPos and count is decremented
* to print the second option in animation and after it the loop stops
**/

void SignOutAnime2::start()
{
    speed = 25;
    startPos = 2;
    count = 1;
    animeIndex = Constant::Menu::main.size() - 1;

    AnimeHandler::speed_updater(speed);

    for (size_t i{1}; i < Constant::Menu::main.size(); i++, count = 1, animeIndex--)
    {
        if (Constant::Menu::main.size() - i < 2)
        {
            startPos--;
            count--;
        }

        do
        {
            print();
            Sleep(speed);
        } while (count++ < startPos);
    }
}

/**
* loops through startPos till size
* index - The index of the main menu vector
* num - The Position printed in console.eg. 1,2,3...
* The num is incremented for each console line (menu Option + gaps)
* The index is incremented only when current index option is printed
* At each iteration 3 parts are executed
* 1. checking if the animeIndex which is to be animated is the current index or not
* if its true, temporary variable takes count value and prints the gap each time before the animeIndex option
* At first itr: for count as 1, 1 gap is printed
* At second itr: for count as 2, 2 gaps are printed
* Gaps include Line number only
* 2. The menu option is printed and a new line (leaving last index)
* 3. Again the index if checked for animeIndex equals index
* if true, the gaps after the animeIndex is printed
* At first itr: for count as 1, startPos - count (1) gap is printed
* At second itr: for count as 2, startPos - count (0) gaps is printed
**/

void SignOutAnime2::print()
{
    logo();

    if (Global::showHint) // display hint in every screen
        show_hint();

    header(std::string{" MENU "}, false);

    for (size_t index{startPos}, num = 1; index < Constant::Menu::main.size(); index++, num++)
    {
        if (index == animeIndex && count)
        {
            size_t temp = count;

            while (temp--)
                std::cout << std::setw(2) << std::right << num++ << ". " << std::endl;
        }

        std::cout << std::setw(2) << std::right << num << ". " << Constant::Menu::main.at(index);

        if (index < Constant::Menu::main.size() - 1) // New line is not printed at last menu option
            std::cout << std::endl;

        if (index == animeIndex && animeIndex != Constant::Menu::main.size() - 1)
        {
            size_t temp = startPos - count;

            while (temp--)
                std::cout << std::setw(2) << std::right << ++num << ". " << std::endl;
        }
    }
    print_message(std::string{"Your Choice: "}); // ask user for input
}