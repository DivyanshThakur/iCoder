#ifndef UPDATE_HPP
#define UPDATE_HPP

#include "../base/AbstractMenu.hpp"

class Update
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

#endif