#ifndef IMENU_HPP
#define IMENU_HPP

#include "../namespace/header/cod_scan.hpp"

class IMenu
{
protected:
    std::vector<int> menuIndex; // It stored the index of the string to display
    static cod::scan scan;
    static int ch;

    virtual void check() const;
    virtual void stats(const std::vector<std::string> &vec) const;

public:
    virtual std::string title() const = 0;
    virtual std::vector<std::string> selector() = 0;
    virtual void caller() const = 0;
    virtual void controller() const = 0;

    static void player(IMenu &&iMenu);

    virtual ~IMenu() = default;
};

#endif