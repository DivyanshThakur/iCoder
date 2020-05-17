#ifndef EXHANDLER_HPP
#define EXHANDLER_HPP

class NegativeValueException
{
public:
    void what(bool isPressKeyEnabled = true) const noexcept;
};

class InvalidChoiceException
{
public:
    void what(bool isPressKeyEnabled = true) const noexcept;
};

class InvalidInputException
{
public:
    void what(bool isPressKeyEnabled = true) const noexcept;
};

class PasswordNotMatchedException
{
public:
    void what(bool isPressKeyEnabled = true) const noexcept;
};

class UsernameAlreadyExistsException
{
public:
    void what(bool isPressKeyEnabled = true) const noexcept;
};

class SavingUserException
{
public:
    void what(bool isPressKeyEnabled = true) const noexcept;
};

class InvalidUser
{
public:
    void what(bool isPressKeyEnabled = true) const noexcept;
};

// class FileNotOpenedException
// {
// public:
//     void what(bool isPressKeyEnabled = true) const noexcept;
// };

class ArrayFullException
{
public:
    void what(bool isPressKeyEnabled = true) const noexcept;
};

class ArrayEmptyException
{
public:
    void what(bool isPressKeyEnabled = true) const noexcept;
};

class InvalidPositionException
{
public:
    void what(bool isPressKeyEnabled = true) const noexcept;
};

class OutofBoundsException
{
public:
    void what(bool isPressKeyEnabled = true) const noexcept;
};

class EscPressed
{
};

class ReturnHome
{
};

class ReturnMain
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

class OpenMoreScreen
{
public:
    void what() const noexcept;
};

class OpenAnimeSetting
{
    size_t pos;

public:
    OpenAnimeSetting(size_t pos);
    void what() const noexcept;
};

#endif