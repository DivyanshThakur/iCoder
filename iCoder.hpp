#ifndef ICODER_HPP
#define ICODER_HPP

#include "header/IMenu.hpp"

class Main
{
private:
    /**
 * Menu has all the methods necessary for showing menu
 * and controlling the flow of program as per user choice
 * It inherit the IMenu abstract class
 **/
    class Menu : public IMenu
    {
        virtual std::string title() const override;

        virtual std::vector<std::string> selector() override;
        virtual void caller() const override;
        virtual void controller() const override;
    };

    /**
 * Main class static fields and methods are declared here
 * These adjust the behaviour of the program based on
 * user configuration for better experience
 **/

    static bool welcomeFlag;

    static void load();
    static void home();
    static void sign_out();
    static void create_path();
    static bool check_directory();
    static void adjust_console_size();

public:
    /**
 * A start method in each class to start its execution
 **/
    static void start();
};

#endif