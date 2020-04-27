#include <iostream>
#include <iomanip>
#include <windows.h>
#include "../header/AnimeHandler.hpp"
#include "../header/UIhandler.hpp"

void signout_anime_switcher()
{
}

/***********************************************************************************************************************
 * 
 *                                                SIGN OUT ANIMATION - 1
 * 
 * *********************************************************************************************************************/

/***********************************************************************************************************************
 * 
 *                                                SIGN OUT ANIMATION - 2
 * 
 * *********************************************************************************************************************/

std::list<std::string> SignOutAnime2::listMenu; // Declaring the static listMenu variable

// start function assigns the menu to the listMenu static variable
// The logic behind this is -
// In first iteration , it changes the first menu option and print it with no change to sign out option
// When repeatFor is equals to 2, i.e the next iteration. The sign out option gets poped out and
// the menu option in Menu::main vector of index 'repeatFor' is pushed to listMenu and the menu is printed
// The third and last iteration is executed with above itr 2 logic
// At last the animation stops and the last menu option (index 0) is printed normally using default menu function

void SignOutAnime2::start()
{
    for (size_t i{3}; i < Menu::main.size(); i++)
    {
        listMenu.push_back(Menu::main.at(i));
    }

    listMenu.push_back(std::string{"Sign Out"});

    int repeatFor = 3;

    while (--repeatFor)
    {
        listMenu.push_front(Menu::main.at(repeatFor));

        print();
        Sleep(300);

        if (repeatFor == 2)
            listMenu.pop_back();
    }

    Sleep(300);
}

// The print menu static function uses iteration to print next menu option
// It's easy to push value in start position while using list.
// This is the reason list was prefered over vector
// The logic of print function is -
// It simply print the whole list

void SignOutAnime2::print()
{
    title();

    if (Global::showHint) // display hint in every screen
        show_hint();

    header(std::string{" MENU "}, false);

    auto itr = listMenu.begin();

    // Here, the listMenu contains the menu options in list of string
    for (size_t index{0}; index < listMenu.size(); ++index)
    {
        // Print the index starting 1 till list size
        std::cout << std::setw(2) << std::right << index + 1 << ". " << *itr++;

        if (index < listMenu.size() - 1) // New line is not printed at last menu option
            std::cout << std::endl;
    }

    print_message(std::string{"Your Choice: "}); // ask user for input
}