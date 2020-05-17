#include <iostream>
#include <windows.h>
#include "../header/ExHandler.hpp"
#include "../header/UIhandler.hpp"
#include "../header/Settings.hpp"
#include "../header/Help.hpp"
#include "../header/More.hpp"

void NegativeValueException::what(bool isPressKeyEnabled) const noexcept
{
    print_message("Negative value not allowed!", isPressKeyEnabled, NIL);
}

void InvalidChoiceException::what(bool isPressKeyEnabled) const noexcept
{
    print_message("Invalid choice!", isPressKeyEnabled, NIL);
}

void InvalidInputException::what(bool isPressKeyEnabled) const noexcept
{
    print_message("Invalid input!", isPressKeyEnabled, NIL);
}

void PasswordNotMatchedException::what(bool isPressKeyEnabled) const noexcept
{
    print_message("Password not matched!", isPressKeyEnabled, NIL);
}

void UsernameAlreadyExistsException::what(bool isPressKeyEnabled) const noexcept
{
    print_message("Username already exists!", isPressKeyEnabled, NIL);
}

void SavingUserException::what(bool isPressKeyEnabled) const noexcept
{
    print_message("Error saving user details!", isPressKeyEnabled, NIL);
}

void InvalidUser::what(bool isPressKeyEnabled) const noexcept
{
    print_message("Invalid UserID/Password!", isPressKeyEnabled, NIL);
}

// void FileNotOpenedException::what(bool isPressKeyEnabled) const noexcept
// {
//     print_message("Error fetching data!", isPressKeyEnabled, NIL);
// }

void ArrayFullException::what(bool isPressKeyEnabled) const noexcept
{
    print_message("Array is full!", isPressKeyEnabled, NIL);
}

void ArrayEmptyException::what(bool isPressKeyEnabled) const noexcept
{
    print_message("Array is empty!", isPressKeyEnabled, NIL);
}

void InvalidPositionException::what(bool isPressKeyEnabled) const noexcept
{
    print_message("Invalid position!", isPressKeyEnabled, NIL);
}

void OutofBoundsException::what(bool isPressKeyEnabled) const noexcept
{
    print_message("Invalid position!", isPressKeyEnabled, NIL);
}

void Exit::what() const noexcept
{
    if (Global::showQuit)
    {
        std::string message;

        if (opnScreen != CUR_SETTINGS)
        {
            isquitConditionEnabled = true;
            message = std::string{"Press d to disable this message!"};
        }

        bool toProceed = confirm_the_change(message, std::string{"Do you want to exit?"});

        if (toProceed)
            exit(0);
    }
    else
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

void OpenMoreScreen::what() const noexcept
{
    more();
}

OpenAnimeSetting::OpenAnimeSetting(size_t pos) : pos(pos)
{
}

void OpenAnimeSetting::what() const noexcept
{
    std::string message{". Disable "};
    message += Menu::settings.at(pos - 1);

    show_me_first(std::to_string(pos) + message, pos);
}