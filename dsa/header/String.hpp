#ifndef STRING_HPP
#define STRING_HPP

#include "../../namespace/header/cod_string.hpp"
#include "../../header/AbstractMenu.hpp"

class StringHandler
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
 * StringHandler class static fields and methods are declared here
 * These adjust the behaviour of the program based on
 * user configuration for better experience
 **/

    static cod::string str;
    static cod::scan sc;

public: /**
 * A start method in each class to start its execution
 **/
    static void start();
};

// void String();

// class StringHandler
// {
//     cod::string str;
//     cod::scan sc;
//     bool show_adv_opn{false};
//     std::vector<int> menuIndex; // It stored the index of the string to display

//     void input_data(const std::string &heading, size_t &pos);
//     void input_data(const std::string &heading, size_t &pos, size_t &len);
//     void input_data(const std::string &heading, size_t &pos, cod::string &val);

//     void pressi_display(bool isStringUpdated = false);

//     std::vector<std::string> menu_screen_selector();
//     void fn_caller(int ch);
//     void string_controller(int ch);
//     void update_string();
//     void insert_substr();
//     void remove_substr();
//     bool is_range(const std::string &heading);
//     void change_case();
//     void display();
//     void reverse();
//     void compare();
//     void merge();
//     void anagram();
//     void palindrome();
//     void permutation();
//     void find_unique();
//     void find_duplicates();

// public:
//     void start();
// };

#endif