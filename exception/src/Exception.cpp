#include "../header/Exception.hpp"

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

const char *PasswordNotMatchedException::what() const noexcept
{
    return "Password not matched!";
}

const char *UsernameAlreadyExistsException::what() const noexcept
{
    return "Username already exists!";
}

const char *InvalidUser::what() const noexcept
{
    return "Invalid username/password!";
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