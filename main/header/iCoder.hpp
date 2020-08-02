#ifndef ICODER_HPP
#define ICODER_HPP

#include "../../base/header/AbstractMenu.hpp"

class Main
{
private:
    /**
 * Menu has all the methods necessary for showing menu
 * and controlling the flow of program as per user choice
 * It inherit the AbstractMenu abstract class
 **/
    class Menu : public AbstractMenu
    {
        virtual std::string title() const override;
        virtual std::vector<std::string> getStats() const override;
        virtual std::vector<std::string> selector() override;
        virtual void controller() const override;
    };

    /**
 * Main class static fields and methods are declared here
 * These adjust the behaviour of the program based on
 * user configuration for better experience
 **/

    static bool welcomeFlag;

    static void load();
    static void signOut();
    static void createPath();
    static bool checkDirectory();
    static void adjustConsoleSize();

public:
    /**
 * A start method in each class to start its execution
 **/
    static void start();
    static void home();
};

#endif