#include <iostream>
#include <windows.h>
#include "../header/ExHandler.hpp"
#include "../header/UIhandler.hpp"
#include "../header/Constants.hpp"
#include "../header/Settings.hpp"
#include "../header/Info.hpp"

const char *NegativeValueException::what() const noexcept
{
    border(widthMenu);
    return "Negative value not allowed!";
}

const char *InvalidChoiceException::what() const noexcept
{
    border(widthMenu);
    return "Invalid choice!";
}

const char *InvalidInputException::what() const noexcept
{
    border(widthMenu);
    return "Invalid input!";
}

const char *PasswordNotMatchedException::what() const noexcept
{
    border(widthMenu);
    return "Password not matched!";
}

const char *UsernameAlreadyExistsException::what() const noexcept
{
    border(widthMenu);
    return "Username already exists!";
}

const char *SavingUserException::what() const noexcept
{
    border(widthMenu);
    return "Error saving user details!";
}

const char *InvalidUser::what() const noexcept
{
    border(widthMenu);
    return "Invalid UserID/Password!";
}

const char *FileNotOpenedException::what() const noexcept
{
    border(widthMenu);
    return "Error fetching data!";
}

const char *ArrayFullException::what() const noexcept
{
    border(widthMenu);
    return "Array is full!";
}

const char *ArrayEmptyException::what() const noexcept
{
    border(widthMenu);
    return "Array is empty!";
}

const char *InvalidPositionException::what() const noexcept
{
    border(widthMenu);
    return "Invalid position!";
}

const char *OutofBoundsException::what() const noexcept
{
    border(widthMenu);
    return "Invalid position!";
}

void Exit::what() const noexcept
{
    exit(0);
}

void OpenSettings::what() const noexcept
{
    settings();
}

void OpenAbout::what() const noexcept
{
    about();
}

void OpenHelp::what() const noexcept
{
    help();
}

void OpenUpdate::what() const noexcept
{
    update();
}

void OpenChangelog::what() const noexcept
{
    changelog();
}

void OpenHintSetting::what() const noexcept
{
    std::string message{"4. "};
    message += (showHint ? std::string{"Disable "} : std::string{"Enable "});
    message += settingsMenu.at(3);

    show_me_first(message, 4);
}

void OpenLsearchSetting::what() const noexcept
{
    std::string message{"2. "};
    message += settingsMenu.at(1);

    show_me_first(message, 2);
}