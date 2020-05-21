#ifndef IMENU_HPP
#define IMENU_HPP

#include <vector>
#include <string>

class IMenu
{
protected:
    std::vector<int> menuIndex; // It stored the index of the string to display
    int ch;

public:
    virtual std::string title() const = 0;

    virtual std::vector<std::string> selector() = 0;
    virtual void caller() const = 0;
    virtual void controller() const = 0;

    static void player(const IMenu &iMenu);

    virtual ~IMenu() = default;
};

#endif