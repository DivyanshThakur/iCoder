#ifndef HINT_HPP
#define HINT_HPP

#include "Settings.hpp"

class Hint : public Settings
{
    /**
 * Menu has all the methods necessary for showing menu
 * and controlling the flow of program as per user choice
 * It inherit the AbstractMenu abstract class.
 **/
    class Menu : public AbstractMenu
    {
        virtual std::string title() const override;
        virtual std::vector<std::string> getStats() const override;
        virtual std::vector<std::string> selector() override;
        virtual void controller() const override;
    };

    /**
 * Data has all the methods necessary for saving
 * and retreiving user data from the files
 * It inherit the Settings::Data class.
 **/
    class Data : public Settings::Data
    {
        virtual std::vector<std::pair<std::string, std::string>> save() const override;
    };

    /**
 * Settings class static fields and methods are declared here
 * These change the Ui & working of the software based on the
 * user choices and provide the user with many customizations.
 **/

    static Data userData;

public:
    /**
 * A start method in each class to start its execution
 * A data method returns the Data object by value
 **/
    static void start();
    static Data &data();
};

#endif