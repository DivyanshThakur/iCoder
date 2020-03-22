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

class ArrayFullException : public std::exception
{
public:
    ArrayFullException() noexcept = default;
    ~ArrayFullException() = default;

    virtual const char *what() const noexcept;
};

class ArrayEmptyException : public std::exception
{
public:
    ArrayEmptyException() noexcept = default;
    ~ArrayEmptyException() = default;

    virtual const char *what() const noexcept;
};

class InvalidPositionException : public std::exception
{
public:
    InvalidPositionException() noexcept = default;
    ~InvalidPositionException() = default;

    virtual const char *what() const noexcept;
};

class OutofBoundsException : public std::exception
{
public:
    OutofBoundsException() noexcept = default;
    ~OutofBoundsException() = default;

    virtual const char *what() const noexcept;
};

class EscPressed
{
};

class ReturnHome
{
};

class Exit
{
public:
    void what() const noexcept;
};

class OpenSettings
{
public:
    void what() const noexcept;
};

class OpenAbout
{
public:
    void what() const noexcept;
};

class OpenHelp
{
public:
    void what() const noexcept;
};

class OpenUpdate
{
public:
    void what() const noexcept;
};

class OpenChangelog
{
public:
    void what() const noexcept;
};

class OpenHintSetting
{
public:
    void what() const noexcept;
};

#endif