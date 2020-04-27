#include <iostream>
#include <iomanip>
#include <windows.h>
#include "../header/AnimeHandler.hpp"
#include "../header/UIhandler.hpp"

void signout_anime_switcher()
{
}

std::list<std::string> SignOutAnime2::listMenu;

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
        Sleep(100);

        if (repeatFor == 2)
            listMenu.pop_back();
    }

    Sleep(100);
}

void SignOutAnime2::print()
{
    title();

    if (Global::showHint) // display hint in every screen
        show_hint();

    header(std::string{" MENU "}, false);

    auto itr = listMenu.begin();

    // Here, the listMenu passed from function contains the menu options in list of string
    for (size_t index{0}; index < listMenu.size(); ++index)
    {
        // Print the index starting 1 till list size
        std::cout << std::setw(2) << std::right << index + 1 << ". " << *itr++;

        if (index < listMenu.size() - 1) // New line is not printed at last menu option
            std::cout << std::endl;
    }

    print_message(std::string{"Your Choice: "}); // ask user for input
}