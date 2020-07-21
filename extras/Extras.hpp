#ifndef EXTRAS_HPP
#define EXTRAS_HPP

#include "../header/IMenu.hpp"

class Extras
{
public:
    static void about();
    static void help();
};

class Update
{
    /**
 * Menu has all the methods necessary for showing menu
 * and controlling the flow of program as per user choice
 * It inherit the IMenu abstract class
 **/
    class Menu : public IMenu
    {
        virtual std::string title() const override;
        virtual std::vector<std::string> getStats() const override;
        virtual std::vector<std::string> selector() override;
        virtual void caller() const override;
        virtual void controller() const override;
    };

    /**
 * Update class static fields and methods are declared here
 * These adjust the behaviour of the program based on
 * user configuration for better experience
 **/

public:
    /**
 * A start method in each class to start its execution
 **/
    static void start();
};

class Changelog
{
    /**
 * Menu has all the methods necessary for showing menu
 * and controlling the flow of program as per user choice
 * It inherit the IMenu abstract class
 **/
    class Menu : public IMenu
    {
        virtual std::string title() const override;
        virtual std::vector<std::string> getStats() const override;
        virtual std::vector<std::string> selector() override;
        virtual void caller() const override;
        virtual void controller() const override;
    };

    /**
 * Changelog class static fields and methods are declared here
 * These adjust the behaviour of the program based on
 * user configuration for better experience
 **/

public: /**
 * A start method in each class to start its execution
 **/
    static void start();
};

#endif