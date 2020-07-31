#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <exception>
#include "Start.hpp"

class NegativeValueException : public std::exception
{
public:
    virtual const char *what() const noexcept override;
};

class InvalidChoiceException : public std::exception
{
public:
    virtual const char *what() const noexcept override;
};

class InvalidInputException : public std::exception
{
public:
    virtual const char *what() const noexcept override;
};

class PasswordNotMatchedException : public std::exception
{
public:
    virtual const char *what() const noexcept override;
};

class UsernameAlreadyExistsException : public std::exception
{
public:
    virtual const char *what() const noexcept override;
};

class InvalidUser : public std::exception
{
public:
    virtual const char *what() const noexcept override;
};

class ArrayFullException : public std::exception
{
public:
    virtual const char *what() const noexcept override;
};

class ArrayEmptyException : public std::exception
{
public:
    virtual const char *what() const noexcept override;
};

class InvalidPositionException : public std::exception
{
public:
    virtual const char *what() const noexcept override;
};

#endif