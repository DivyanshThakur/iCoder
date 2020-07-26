#include "../header/cod_exception.hpp"
#include "../../header/Ui.hpp"
#include "../../settings/header/Settings.hpp"
#include "../../extras/Extras.hpp"
#include "../../header/More.hpp"
#include "../../constant/Constants.hpp"

void cod::exception::what() const noexcept
{
    Ui::println("Unknown error occurred!");
}

void NegativeValueException::what() const noexcept
{
    Ui::println("Negative value not allowed!");
}

void InvalidChoiceException::what() const noexcept
{
    Ui::println("Invalid choice!");
}

void InvalidInputException::what() const noexcept
{
    Ui::println("Invalid input!");
}

void PasswordNotMatchedException::what() const noexcept
{
    Ui::println("Password not matched!");
}

void UsernameAlreadyExistsException::what() const noexcept
{
    Ui::println("Username already exists!");
}

void InvalidUser::what() const noexcept
{
    Ui::println("Invalid username/password!");
}

void ArrayFullException::what() const noexcept
{
    Ui::println("Array is full!");
}

void ArrayEmptyException::what() const noexcept
{
    Ui::println("Array is empty!");
}

void InvalidPositionException::what() const noexcept
{
    Ui::println("Invalid position!");
}

void Exit::what() const noexcept
{
    bool toProceed = true;

    if (Global::showQuit)
        toProceed = Ui::confirmChange("Do you want to exit?");

    if (toProceed)
        exit(0);
}

void OpenSettings::what() const noexcept
{
    Settings::start();
}

void OpenAbout::what() const noexcept
{
    Extras::about();
}

void OpenHelp::what() const noexcept
{
    Extras::help();
}

void OpenUpdate::what() const noexcept
{
    Update::start();
}

void OpenChangelog::what() const noexcept
{
    Changelog::start();
}

void OpenMoreScreen::what() const noexcept
{
    More::start();
}

// OpenAnimeSetting::OpenAnimeSetting(size_t pos) : pos(pos)
// {
// }

// void OpenAnimeSetting::what() const noexcept
// {
//     std::string message{". Disable "};
//     message += Constant::Menu::SETTINGS.at(pos - 1);

//     Settings mySetting;
//     // mySetting.show_me_first(std::to_string(pos) + message, pos);
// }
