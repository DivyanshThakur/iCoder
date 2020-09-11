#ifndef ABSTRACT_MENU_HPP
#define ABSTRACT_MENU_HPP

#include <vector>
#include <string>

class AbstractMenu
{
protected:
    static int ch;
    virtual void caller() const;

public:
    virtual const std::string &title() const = 0;
    virtual const std::string &list() const = 0;
    virtual void printStats() const = 0;
    virtual void controller() const = 0;

    static void player(AbstractMenu &&AbstractMenu);

    virtual ~AbstractMenu();
};

#endif