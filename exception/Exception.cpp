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