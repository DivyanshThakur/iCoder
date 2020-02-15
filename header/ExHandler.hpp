#ifndef EXHANDLER_HPP
#define EXHANDLER_HPP

#include <exception>

class NegativeValueException : public std::exception
{
public:
    NegativeValueException() noexcept = default;
    ~NegativeValueException() = default;

    virtual const char *what() const noexcept;
};

class InvalidChoiceException : public std::exception
{
public:
    InvalidChoiceException() noexcept = default;
    ~InvalidChoiceException() = default;

    virtual const char *what() const noexcept;
};

class InvalidInputException : public std::exception
{
public:
    InvalidInputException() noexcept = default;
    ~InvalidInputException() = default;

    virtual const char *what() const noexcept;
};

class NouserException : public std::exception
{
public:
    NouserException() noexcept = default;
    ~NouserException() = default;

    virtual const char *what() const noexcept;
};

class PasswordNotMatchedException : public std::exception
{
public:
    PasswordNotMatchedException() noexcept = default;
    ~PasswordNotMatchedException() = default;

    virtual const char *what() const noexcept;
};

class UsernameAlreadyExistsException : public std::exception
{
public:
    UsernameAlreadyExistsException() noexcept = default;
    ~UsernameAlreadyExistsException() = default;

    virtual const char *what() const noexcept;
};

class SavingUserException : public std::exception
{
public:
    SavingUserException() noexcept = default;
    ~SavingUserException() = default;

    virtual const char *what() const noexcept;
};

class InvalidUser : public std::exception
{
public:
    InvalidUser() noexcept = default;
    ~InvalidUser() = default;

    virtual const char *what() const noexcept;
};

class FileNotOpenedException : public std::exception
{
public:
    FileNotOpenedException() noexcept = default;
    ~FileNotOpenedException() = default;

    virtual const char *what() const noexcept;
};

class EscPressed : public std::exception
{
};

#endif