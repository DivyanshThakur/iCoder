#include <iostream>
#include <windows.h>
#include "../header/ExHandler.hpp"
#include "../header/UIhandler.hpp"
#include "../header/Settings.hpp"
#include "../header/Help.hpp"
#include "../header/Home.hpp"

const char *NegativeValueException::what() const noexcept
{
    border(Ui::widthMenu);
    return "Negative value not allowed!";
}

const char *InvalidChoiceException::what() const noexcept
{
    border(Ui::widthMenu);
    return "Invalid choice!";
}

const char *InvalidInputException::what() const noexcept
{
    border(Ui::widthMenu);
    return "Invalid input!";
}

const char *PasswordNotMatchedException::what() const noexcept
{
    border(Ui::widthMenu);
    return "Password not matched!";
}

const char *UsernameAlreadyExistsException::what() const noexcept
{
    border(Ui::widthMenu);
    return "Username already exists!";
}

const char *SavingUserException::what() const noexcept
{
    border(Ui::widthMenu);
    return "Error saving user details!";
}

const char *InvalidUser::what() const noexcept
{
    border(Ui::widthMenu);
    return "Invalid UserID/Password!";
}

const char *FileNotOpenedException::what() const noexcept
{
    border(Ui::widthMenu);
    return "Error fetching data!";
}

const char *ArrayFullException::what() const noexcept
{
    border(Ui::widthMenu);
    return "Array is full!";
}

const char *ArrayEmptyException::what() const noexcept
{
    border(Ui::widthMenu);
    return "Array is empty!";
}

const char *InvalidPositionException::what() const noexcept
{
    border(Ui::widthMenu);
    return "Invalid position!";
}

const char *OutofBoundsException::what() const noexcept
{
    border(Ui::Ui::widthMenu);
    return "Invalid position!";
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

OpenAnimeSetting::OpenAnimeSetting(size_t pos) : pos(pos)
{
}

void OpenAnimeSetting::what() const noexcept
{
    std::string message{". Disable "};
    message += Menu::settings.at(pos - 1);

    show_me_first(std::to_string(pos) + message, pos);
}