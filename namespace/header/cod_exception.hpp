#ifndef COD_EXCEPTION_HPP
#define COD_EXCEPTION_HPP

namespace cod
{
    class exception
    {
    public:
        virtual void what() const noexcept;
        virtual ~exception() = default;
    };
}; // namespace cod

class NegativeValueException : public cod::exception
{
public:
    virtual void what() const noexcept override;
};

class InvalidChoiceException : public cod::exception
{
public:
    virtual void what() const noexcept override;
};

class InvalidInputException : public cod::exception
{
public:
    virtual void what() const noexcept override;
};

class PasswordNotMatchedException : public cod::exception
{
public:
    virtual void what() const noexcept override;
};

class UsernameAlreadyExistsException : public cod::exception
{
public:
    virtual void what() const noexcept override;
};

class InvalidUser : public cod::exception
{
public:
    virtual void what() const noexcept override;
};

class ArrayFullException : public cod::exception
{
public:
    virtual void what() const noexcept override;
};

class ArrayEmptyException : public cod::exception
{
public:
    virtual void what() const noexcept override;
};

class InvalidPositionException : public cod::exception
{
public:
    virtual void what() const noexcept override;
};

class EscPressed
{
};

class Exit : public cod::exception
{
public:
    virtual void what() const noexcept override;
};

class OpenSettings : public cod::exception
{
public:
    virtual void what() const noexcept override;
};

class OpenAbout : public cod::exception
{
public:
    virtual void what() const noexcept override;
};

class OpenHelp : public cod::exception
{
public:
    virtual void what() const noexcept override;
};

class OpenUpdate : public cod::exception
{
public:
    virtual void what() const noexcept override;
};

class OpenChangelog : public cod::exception
{
public:
    virtual void what() const noexcept override;
};

class OpenMoreScreen : public cod::exception
{
public:
    virtual void what() const noexcept override;
};

class OpenAnimeSetting : public cod::exception
{
    size_t pos;

public:
    OpenAnimeSetting(size_t pos);
    virtual void what() const noexcept override;
};

#endif