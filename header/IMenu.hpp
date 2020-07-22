#ifndef IMENU_HPP
#define IMENU_HPP

#include "../namespace/header/cod_scan.hpp"

class IMenu
{
protected:
    std::vector<int> menuIndex; // It stored the index of the string to display
    static cod::scan scan;
    static int ch;
    virtual void menuIndexer(size_t end, size_t start = 0, size_t val = 1);
    virtual void caller() const;

public:
    virtual std::string title() const = 0;
    virtual std::vector<std::string> getStats() const = 0;
    virtual std::vector<std::string> selector() = 0;
    virtual void controller() const = 0;
    static void player(IMenu &&iMenu);

    virtual ~IMenu() = default;
};

#endif