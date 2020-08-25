#ifndef ABSTRACT_MENU_HPP
#define ABSTRACT_MENU_HPP

#include "../../namespace/header/cod_scan.hpp"

class AbstractMenu
{
protected:
    // std::vector<int> menuIndex; // It stored the index of the string to display
    static cod::scan scan;
    static int ch;
    virtual void menuIndexer(size_t end, size_t start = 0, size_t val = 1);
    virtual void caller() const;

public:
    virtual std::string title() const = 0;
    virtual std::vector<std::string> getStats() const = 0;
    virtual std::vector<std::string> selector() = 0;
    virtual void controller() const = 0;
    static void player(AbstractMenu &&AbstractMenu);

    virtual ~AbstractMenu();
};

#endif