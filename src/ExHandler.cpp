#include "../header/ExHandler.hpp"
#include "../header/UIhandler.hpp"
#include "../header/Constants.hpp"

const char *NegativeValueException::what() const noexcept
{
    border(width_menu);
    return "Negative value not allowed!";
}

const char *InvalidChoiceException::what() const noexcept
{
    border(width_menu);
    return "Invalid choice!";
}

const char *InvalidInputException::what() const noexcept
{
    border(width_menu);
    return "Invalid input!";
}

const char *PasswordNotMatchedException::what() const noexcept
{
    border(width_menu);
    return "Password not matched!";
}

const char *UsernameAlreadyExistsException::what() const noexcept
{
    border(width_menu);
    return "Username already exists!";
}

const char *SavingUserException::what() const noexcept
{
    border(width_menu);
    return "Error saving user details!";
}

const char *InvalidUser::what() const noexcept
{
    border(width_menu);
    return "Invalid UserID/Password!";
}

const char *FileNotOpenedException::what() const noexcept
{
    border(width_menu);
    return "Error fetching data!";
}

const char *ArrayFullException::what() const noexcept
{
    border(width_menu);
    return "Array is full!";
}

const char *ArrayEmptyException::what() const noexcept
{
    border(width_menu);
    return "Array is empty!";
}

const char *InvalidPositionException::what() const noexcept
{
    border(width_menu);
    return "Invalid position!";
}

const char *OutofBoundsException::what() const noexcept
{
    border(width_menu);
    return "Invalid position!";
}