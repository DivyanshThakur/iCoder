#include "../header/ExHandler.hpp"

const char *NegativeValueException::what() const noexcept
{
    return "Negative value not allowed!";
}

const char *InvalidChoiceException::what() const noexcept
{
    return "Invalid choice!";
}

const char *InvalidInputException::what() const noexcept
{
    return "Invalid input!";
}

const char *NouserException::what() const noexcept
{
    return "No user in database!";
}

const char *PasswordNotMatchedException::what() const noexcept
{
    return "Password not matched!";
}

const char *UsernameAlreadyExistsException::what() const noexcept
{
    return "Username already exists!";
}

const char *SavingUserException::what() const noexcept
{
    return "Error saving user details!";
}

const char *InvalidUser::what() const noexcept
{
    return "Invalid UserID/Pass!";
}

const char *FileNotOpenedException::what() const noexcept
{
    return "Error fetching data!";
}

const char *ArrayFullException::what() const noexcept
{
    return "Array is full!";
}

const char *ArrayEmptyException::what() const noexcept
{
    return "Array is empty!";
}

const char *InvalidPositionException::what() const noexcept
{
    return "Invalid position!";
}

const char *OutofBoundsException::what() const noexcept
{
    return "Invalid Index";
}