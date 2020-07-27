#ifndef MORE_HPP
#define MORE_HPP

#include "../base/header/AbstractMenu.hpp"
class More
{
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
 * More class static fields and methods are declared here
 * These adjust the behaviour of the program based on
 * user configuration for better experience
 **/

public:
    /**
 * A start method in each class to start its execution
 **/
    static void start();
};

#endif