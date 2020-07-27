#ifndef DATA_STRUCTURE_HPP
#define DATA_STRUCTURE_HPP

#include "../../header/AbstractMenu.hpp"

class DataStructure
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
 * DataStructure class static fields and methods are declared here
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