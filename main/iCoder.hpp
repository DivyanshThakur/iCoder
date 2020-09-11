#ifndef ICODER_HPP
#define ICODER_HPP

#include "../base/AbstractMenu.hpp"

class iCoder
{
private:
    /**
 * Menu has all the methods necessary for showing menu
 * and controlling the flow of program as per user choice
 * It inherit the AbstractMenu abstract class
 **/
    class Menu : public AbstractMenu
    {
        virtual const std::string &title() const override;
        virtual const std::string &list() const override;
        virtual void printStats() const override;
        virtual void controller() const override;
    };

    /**
 * iCoder class static fields and methods are declared here
 * These adjust the behaviour of the program based on
 * user configuration for better experience
 **/

    static void load();
    static void createPath();
    static bool checkDirectory();
    static void adjustConsoleSize();

public:
    /**
 * A start method in each class to start its execution
 **/
    static void start();
};

#endif