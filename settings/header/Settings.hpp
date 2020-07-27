#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include <vector>
#include "../../base/header/AbstractMenu.hpp"
#include "../../base/header/AbstractSaveable.hpp"
#include "../../constant/enum.hpp"

class Settings
{
private:
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
 * It inherit the AbstractSaveable abstract class.
 **/
    class Data : public AbstractSaveable
    {
        virtual std::vector<std::pair<std::string, std::string>> save() const override;
        virtual void load(const std::vector<std::pair<std::string, std::string>> &vecData) override;
        virtual std::string getPath() const override;

    public:
        virtual bool generate() const override;
    };

    /**
 * Settings class static fields and methods are declared here
 * These change the Ui & working of the software based on the
 * user choices and provide the user with many customizations.
 **/

    static std::pair<std::string, std::string> pairBuffer;
    static Data userData;

    static void updateStats(enum Status &stats, int c);

    static void settings_controller(char ch);
    static std::vector<std::string> settings_screen_selector();
    // static void change_text_anime_speed();
    static void change_lsearch_type();
    // static void change_shortcuts_type();
    static void change_home_screen();
    static void change_theme_type();
    static void change_anime_style();
    static void change_display_style();
    static void welcome_message();
    static void quit_message();
    static void hint_message();
    static void reset();

    static bool isDefault();
    static void save(const std::pair<std::string, std::string> &pair);

    // // move below code to anime class
    // static void show_me_first(const std::string &message, int repeatFor);

public:
    /**
 * A start method in each class to start its execution
 * A data method returns the Data object by value
 **/
    static void start();
    static Data &data();

    static void saveActiveUser();
};

#endif