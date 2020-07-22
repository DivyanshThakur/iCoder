#include <iostream>
#include <windows.h>
#include "../header/AnimeHandler.hpp"
#include "../header/SignOutAnime.hpp"
#include "../../header/Ui.hpp"

void AnimeHandler::load()
{
    srand(time(nullptr)); // It will generate unique random numbers each time

    std::string loader{"LOADING..."};
    size_t loadLimit = loader.size(); // It will return the length of the string "loader"

    // Here, it prints the text from loader to console in time gaps
    // and on reaching the length of string it erases the text and loops again for random times
    for (size_t i{0}; i <= rand() % (2 * loadLimit) + (rand() % loadLimit) * 2 + loadLimit; ++i)
    {
        if (i % loadLimit == 0) // Checks, if all letters are printed or not
            std::cout << "\r" << std::setw(loadLimit) << " "
                      << "\r";                 // Erasing current line
        std::cout << loader.at(i % loadLimit); // Display char one by one
        Sleep(150);                            // Delay
    }
}

void AnimeHandler::sign_out()
{
    switch (animeSignOutStats)
    {
    case DEFAULT:
        SignOutAnime1::start();
        break;

    case EASY:
        SignOutAnime2::start();
        break;

    case ADV:
        break;
    }
}

void AnimeHandler::speed_updater(int &speed)
{
    SYSTEM_POWER_STATUS status;

    GetSystemPowerStatus(&status); // checking different state of battery

    if (status.Reserved1 == 1) // if battery saver is ON the speed is increased to 10
        speed = 10;

    if (status.ACLineStatus == 1) // if AC power supper is enabled, speed is decreased by 20%
        speed += (0.5 * speed);
}